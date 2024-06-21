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

#if 1
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
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <chipmunk/chipmunk.h>
#include <stdio.h>
#include <math.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void DrawPolygon(SDL_Renderer *renderer, cpBody *body, cpVect *vertices, int vertexCount) {
    cpVect pos = cpBodyGetPosition(body);
    cpFloat angle = cpBodyGetAngle(body);

    cpTransform transform = cpTransformRigid(cpv(pos.x, pos.y), angle);

    for (int i = 0; i < vertexCount; i++) {
        cpVect v1 = cpTransformPoint(transform, vertices[i]);
        cpVect v2 = cpTransformPoint(transform, vertices[(i + 1) % vertexCount]);
        
        // Convert Chipmunk2D coordinates to SDL2 coordinates
        int x1 = (int)v1.x;
        int y1 = (int)(SCREEN_HEIGHT - v1.y);
        int x2 = (int)v2.x;
        int y2 = (int)(SCREEN_HEIGHT - v2.y);
        
        lineRGBA(renderer, x1, y1, x2, y2, 255, 255, 255, 255);
    }
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Chipmunk2D with SDL2 - Polygon Shape", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    cpVect gravity = cpv(0, -100);
    cpSpace *space = cpSpaceNew();
    cpSpaceSetGravity(space, gravity);

    // Ground
    cpShape *ground = cpSpaceAddShape(space, cpSegmentShapeNew(cpSpaceGetStaticBody(space), cpv(0, 50), cpv(SCREEN_WIDTH, 50), 0));
    cpShapeSetFriction(ground, 1.0);

    // Custom polygon (triangle)
    cpVect vertices[] = {
        cpv(-50, -50),
        cpv(50, 50),
        cpv(-50, 50)
    };
    int vertexCount = sizeof(vertices) / sizeof(vertices[0]);

    cpFloat mass = 1.0;
    cpFloat moment = cpMomentForPoly(mass, vertexCount, vertices, cpvzero, 0.0);
    cpBody *polygonBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPosition(polygonBody, cpv(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

    cpFloat radius = 5.0; // Set radius for rounded edges
    cpShape *polygonShape = cpSpaceAddShape(space, cpPolyShapeNew(polygonBody, vertexCount, vertices, cpTransformIdentity, radius));
    cpShapeSetFriction(polygonShape, 0.7);

    int quit = 0;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Update physics
        cpSpaceStep(space, 1.0 / 60.0);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw ground
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 50, SCREEN_WIDTH, SCREEN_HEIGHT - 50);

        // Draw polygon
        DrawPolygon(renderer, polygonBody, vertices, vertexCount);

        // Update screen
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // Roughly 60 FPS
    }

    // Cleanup
    cpShapeFree(polygonShape);
    cpBodyFree(polygonBody);
    cpShapeFree(ground);
    cpSpaceFree(space);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
#endif
