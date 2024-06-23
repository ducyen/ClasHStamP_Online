#define __Main_INTERNAL__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h> 
#include <pthread.h> 
#include <termios.h> 
#include <fcntl.h>
#include <png.h>
#include <sys/stat.h>

#include "CommonInclude.h"
#include "ObjsBuilder.h"

static char* g_sInputDir = "../Image/Design";
const char* getInputDir( void ) { return g_sInputDir; }
static char* g_sOutputDir = "../TransImg/Design";
const char* getOutputDir( void ) { return g_sOutputDir; }

int main(int argc, char **argv){
    printf("Number of arguments (argc): %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    if (argc >= 3) {
        g_sInputDir  = argv[ 1 ];
        g_sOutputDir = argv[ 2 ];
        printf( "arguments: %s %s\n", g_sInputDir, g_sOutputDir );
    }
    return ObjsBuilder_startSim();
}

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <chipmunk/chipmunk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SPRITE_WIDTH = 100;
const int SPRITE_HEIGHT = 200;

double crossProduct(cpVect a, cpVect b) {
    return a.x * b.y - a.y * b.x;
}

bool isConvex(cpVect prev, cpVect current, cpVect next) {
    cpVect edge1 = cpvsub(current, prev);
    cpVect edge2 = cpvsub(next, current);
    double crossProductValue = crossProduct(edge1, edge2);
    return crossProductValue > 0;
}

bool isPointInTriangle(cpVect p, cpVect a, cpVect b, cpVect c) {
    double areaOrig = fabs(crossProduct(cpvsub(b, a), cpvsub(c, a)));
    double area1 = fabs(crossProduct(cpvsub(a, p), cpvsub(b, p)));
    double area2 = fabs(crossProduct(cpvsub(b, p), cpvsub(c, p)));
    double area3 = fabs(crossProduct(cpvsub(c, p), cpvsub(a, p)));
    return (area1 + area2 + area3 <= areaOrig);
}

bool isEar(cpVect *polygon, int vertexCount, int i) {
    int prevIndex = (i == 0) ? vertexCount - 1 : i - 1;
    int nextIndex = (i == vertexCount - 1) ? 0 : i + 1;

    cpVect prev = polygon[prevIndex];
    cpVect current = polygon[i];
    cpVect next = polygon[nextIndex];

    if (!isConvex(prev, current, next)) {
        return false;
    }

    for (int j = 0; j < vertexCount; j++) {
        if (j == prevIndex || j == i || j == nextIndex) {
            continue;
        }
        if (isPointInTriangle(polygon[j], prev, current, next)) {
            return false;
        }
    }
    return true;
}

bool isPolygonConvex(cpVect *vertices, int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
        int prevIndex = (i == 0) ? vertexCount - 1 : i - 1;
        int nextIndex = (i == vertexCount - 1) ? 0 : i + 1;

        if (!isConvex(vertices[prevIndex], vertices[i], vertices[nextIndex])) {
            return false;
        }
    }
    return true;
}

Polygon* decomposeConcavePolygon(cpVect *vertices, int vertexCount) {
    if (isPolygonConvex(vertices, vertexCount)) {
        Polygon *polygon = malloc(sizeof(Polygon));
        polygon->vertices = malloc(vertexCount * sizeof(cpVect));
        memcpy(polygon->vertices, vertices, vertexCount * sizeof(cpVect));
        polygon->vertexCount = vertexCount;
        polygon->next = NULL;
        return polygon;
    }

    Polygon *result = NULL;
    Polygon *last = NULL;
    cpVect *polygon = malloc(vertexCount * sizeof(cpVect));
    memcpy(polygon, vertices, vertexCount * sizeof(cpVect));

    while (vertexCount > 3) {
        bool earFound = false;
        for (int i = 0; i < vertexCount; i++) {
            if (isEar(polygon, vertexCount, i)) {
                Polygon *ear = malloc(sizeof(Polygon));
                ear->vertices = malloc(3 * sizeof(cpVect));
                ear->vertexCount = 3;
                ear->vertices[0] = polygon[(i == 0) ? vertexCount - 1 : i - 1];
                ear->vertices[1] = polygon[i];
                ear->vertices[2] = polygon[(i == vertexCount - 1) ? 0 : i + 1];
                ear->next = NULL;

                if (last == NULL) {
                    result = ear;
                } else {
                    last->next = ear;
                }
                last = ear;

                for (int j = i; j < vertexCount - 1; j++) {
                    polygon[j] = polygon[j + 1];
                }
                vertexCount--;
                earFound = true;
                break;
            }
        }
        if (!earFound) {
            free(polygon);
            while (result != NULL) {
                Polygon *temp = result;
                result = result->next;
                free(temp->vertices);
                free(temp);
            }
            return NULL;
        }
    }

    Polygon *finalPolygon = malloc(sizeof(Polygon));
    finalPolygon->vertices = malloc(vertexCount * sizeof(cpVect));
    memcpy(finalPolygon->vertices, polygon, vertexCount * sizeof(cpVect));
    finalPolygon->vertexCount = vertexCount;
    finalPolygon->next = NULL;

    if (last == NULL) {
        result = finalPolygon;
    } else {
        last->next = finalPolygon;
    }

    free(polygon);
    return result;
}

void DrawPolygonToTexture(SDL_Renderer *renderer, SDL_Texture *texture, cpVect *vertices, int vertexCount, int textureWidth, int textureHeight) {
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vertexCount; i++) {
        cpVect v1 = vertices[i];
        cpVect v2 = vertices[(i + 1) % vertexCount];

        int x1 = (int)(v1.x + textureWidth / 2);
        int y1 = (int)(textureHeight / 2 - v1.y);
        int x2 = (int)(v2.x + textureWidth / 2);
        int y2 = (int)(textureHeight / 2 - v2.y);

        lineRGBA(renderer, x1, y1, x2, y2, 255, 255, 255, 255);
    }

    SDL_SetRenderTarget(renderer, NULL);
}

void DrawSprite(SDL_Renderer *renderer, SDL_Texture *texture, cpBody *body) {
    cpVect pos = cpBodyGetPosition(body);
    cpFloat angle = cpBodyGetAngle(body);
    float degrees = -angle * (180.0 / M_PI);

    SDL_Rect dstrect;
    dstrect.x = (int)pos.x - SPRITE_WIDTH / 2;
    dstrect.y = (int)(SCREEN_HEIGHT - pos.y - SPRITE_HEIGHT / 2);
    dstrect.w = SPRITE_WIDTH;
    dstrect.h = SPRITE_HEIGHT;

    SDL_Point center = { SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2 };

    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, degrees, &center, SDL_FLIP_NONE);
}

bool InitializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Chipmunk2D with SDL2 - Polygon Shape", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    return true;
}

void Cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void printPolygons(Polygon *polygons) {
    Polygon *current = polygons;
    while (current != NULL) {
        printf("Polygon:\n");
        for (int i = 0; i < current->vertexCount; i++) {
            printf("  (%f, %f)\n", current->vertices[i].x, current->vertices[i].y);
        }
        current = current->next;
    }
}

void freePolygons(Polygon *polygons) {
    while (polygons != NULL) {
        Polygon *temp = polygons;
        polygons = polygons->next;
        free(temp->vertices);
        cpShapeFree(temp->shape);
        free(temp);
    }
}

#if 0
int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!InitializeSDL(&window, &renderer)) {
        return 1;
    }

    cpVect gravity = cpv(0, -100);
    cpSpace *space = cpSpaceNew();
    cpSpaceSetGravity(space, gravity);

    cpShape *ground = cpSpaceAddShape(space, cpSegmentShapeNew(cpSpaceGetStaticBody(space), cpv(0, 50), cpv(SCREEN_WIDTH, 50), 0));
    cpShapeSetFriction(ground, 1.0);

    cpVect concaveVertices[] = {
        cpv(-50, -50),
        cpv(10, -0),
        cpv(50, -40),
        cpv(0, 100)
    };
    int concaveVertexCount = sizeof(concaveVertices) / sizeof(concaveVertices[0]);

    Polygon *decomposedPolygons = decomposeConcavePolygon(concaveVertices, concaveVertexCount);

    if (decomposedPolygons == NULL) {
        printf("Failed to decompose polygon.\n");
        Cleanup(window, renderer);
        return 1;
    }

    cpFloat mass = 1.0;
    cpFloat totalMoment = 0.0;
    Polygon *current = decomposedPolygons;
    while (current != NULL) {
        totalMoment += cpMomentForPoly(mass / decomposedPolygons->vertexCount, current->vertexCount, current->vertices, cpvzero, 0.0);
        current = current->next;
    }

    cpBody *polygonBody = cpSpaceAddBody(space, cpBodyNew(mass, totalMoment));
    cpBodySetPosition(polygonBody, cpv(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

    current = decomposedPolygons;
    while (current != NULL) {
        cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(polygonBody, current->vertexCount, current->vertices, cpTransformIdentity, 0.0));
        cpShapeSetFriction(shape, 0.7);
        current = current->next;
    }

    int polygonCount = 0;
    current = decomposedPolygons;
    while (current != NULL) {
        polygonCount++;
        current = current->next;
    }

    SDL_Texture **polygonTextures = (SDL_Texture **)malloc(polygonCount * sizeof(SDL_Texture *));
    current = decomposedPolygons;
    for (int i = 0; i < polygonCount; i++) {
        polygonTextures[i] = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPRITE_WIDTH, SPRITE_HEIGHT);
        if (polygonTextures[i] == NULL) {
            printf("SDL_CreateTexture Error: %s\n", SDL_GetError());
            freePolygons(decomposedPolygons);
            cpShapeFree(ground);
            cpSpaceFree(space);
            Cleanup(window, renderer);
            return 1;
        }
        SDL_SetTextureBlendMode(polygonTextures[i], SDL_BLENDMODE_BLEND);
        DrawPolygonToTexture(renderer, polygonTextures[i], current->vertices, current->vertexCount, SPRITE_WIDTH, SPRITE_HEIGHT);
        current = current->next;
    }

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        cpSpaceStep(space, 1.0 / 60.0);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 50, SCREEN_WIDTH, SCREEN_HEIGHT - 50);

        current = decomposedPolygons;
        for (int i = 0; i < polygonCount; i++) {
            DrawSprite(renderer, polygonTextures[i], polygonBody);
            current = current->next;
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    for (int i = 0; i < polygonCount; i++) {
        SDL_DestroyTexture(polygonTextures[i]);
    }
    free(polygonTextures);

    freePolygons(decomposedPolygons);
    cpShapeFree(ground);
    cpSpaceFree(space);
    Cleanup(window, renderer);

    return 0;
}


#endif
