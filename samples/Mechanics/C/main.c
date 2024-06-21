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

#if 0
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
#elif 0
#include <SDL2/SDL.h>
#include <GLES2/gl2.h>
#include <stdio.h>

void PrintOpenGLInfo() {
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Try to set OpenGL ES attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_Window *window = SDL_CreateWindow("OpenGL Info", 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (glContext == NULL) {
        printf("SDL_GL_CreateContext (OpenGL ES) Error: %s\n", SDL_GetError());
        printf("Falling back to standard OpenGL context.\n");

        // Reset attributes for standard OpenGL
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

        glContext = SDL_GL_CreateContext(window);
        if (glContext == NULL) {
            printf("SDL_GL_CreateContext (OpenGL) Error: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return 1;
        }
    }

    PrintOpenGLInfo();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
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

const int SPRITE_WIDTH = 100;
const int SPRITE_HEIGHT = 100;

void DrawPolygonToTexture(SDL_Renderer *renderer, SDL_Texture *texture, cpVect *vertices, int vertexCount, int textureWidth, int textureHeight) {
    // Set render target to the texture
    SDL_SetRenderTarget(renderer, texture);

    // Clear the texture
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    // Draw the polygon on the texture
    for (int i = 0; i < vertexCount; i++) {
        cpVect v1 = vertices[i];
        cpVect v2 = vertices[(i + 1) % vertexCount];

        // Convert polygon coordinates to texture coordinates
        int x1 = (int)(v1.x + textureWidth / 2);
        int y1 = (int)(textureHeight / 2 - v1.y);
        int x2 = (int)(v2.x + textureWidth / 2);
        int y2 = (int)(textureHeight / 2 - v2.y);

        lineRGBA(renderer, x1, y1, x2, y2, 255, 255, 255, 255);
    }

    // Reset render target to default (the screen)
    SDL_SetRenderTarget(renderer, NULL);
}

void DrawSprite(SDL_Renderer *renderer, SDL_Texture *texture, cpBody *body) {
    cpVect pos = cpBodyGetPosition(body);
    cpFloat angle = cpBodyGetAngle(body);
    float degrees = -angle * (180.0 / M_PI); // Convert radians to degrees and invert the angle

    SDL_Rect dstrect;
    dstrect.x = (int)pos.x - SPRITE_WIDTH / 2; // Center the texture horizontally
    dstrect.y = (int)(SCREEN_HEIGHT - pos.y - SPRITE_HEIGHT / 2); // Convert y-coordinate and center the texture vertically
    dstrect.w = SPRITE_WIDTH;
    dstrect.h = SPRITE_HEIGHT;

    SDL_Point center = { SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2 };

    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, degrees, &center, SDL_FLIP_NONE);
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

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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
        cpv(-50, 50),
        cpv(50, 50)
    };
    int vertexCount = sizeof(vertices) / sizeof(vertices[0]);

    cpFloat mass = 1.0;
    cpFloat moment = cpMomentForPoly(mass, vertexCount, vertices, cpvzero, 0.0);
    cpBody *polygonBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPosition(polygonBody, cpv(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

    cpFloat radius = 0.0; // Set radius for rounded edges
    cpShape *polygonShape = cpSpaceAddShape(space, cpPolyShapeNew(polygonBody, vertexCount, vertices, cpTransformIdentity, radius));
    cpShapeSetFriction(polygonShape, 0.7);

    // Create a texture for the polygon
    SDL_Texture *polygonTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SPRITE_WIDTH, SPRITE_HEIGHT);
    if (polygonTexture == NULL) {
        printf("SDL_CreateTexture Error: %s\n", SDL_GetError());
        cpShapeFree(polygonShape);
        cpBodyFree(polygonBody);
        cpShapeFree(ground);
        cpSpaceFree(space);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Set the blend mode for the new texture to enable alpha blending
    SDL_SetTextureBlendMode(polygonTexture, SDL_BLENDMODE_BLEND);
    // Draw the polygon to the texture
    DrawPolygonToTexture(renderer, polygonTexture, vertices, vertexCount, SPRITE_WIDTH, SPRITE_HEIGHT);

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

        // Draw the sprite
        DrawSprite(renderer, polygonTexture, polygonBody);

        // Update screen
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // Roughly 60 FPS
    }

    // Cleanup
    SDL_DestroyTexture(polygonTexture);
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
