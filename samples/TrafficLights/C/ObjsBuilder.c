/* File generated by Đức's ClasHStamP */
#define __ObjsBuilder_INTERNAL__
#include "CommonInclude.h"
#include "ObjsBuilder.h"
#include "ContextImpl.h"                                        
#include "GreenLight.h"                                         
#include "YellowLight.h"                                        
#include "RedLight.h"                                           
#include "Primitive.h"                                          
static Sprite g_objects[] = {
    { RedLight_Init(
        P( { 0.2069954128440367, 0.3883618551587302, 0.060206422018348624, 0.09365079365079365 } ),
        P( "RedLight.png" )
    ) },
    { RedLight_Init(
        P( { 0.6674311926605505, 0.5026475694444444, 0.060206422018348624, 0.09365079365079365 } ),
        P( "RedLight.png" )
    ) },
    { YellowLight_Init(
        P( { 0.1559633027522936, 0.3883618551587302, 0.060206422018348624, 0.09365079365079365 } ),
        P( "YellowLight.png" )
    ) },
    { GreenLight_Init(
        P( { 0.10550458715596331, 0.3883618551587302, 0.060206422018348624, 0.09365079365079365 } ),
        P( "GreenLight.png" )
    ) },
    { YellowLight_Init(
        P( { 0.716743119266055, 0.5026475694444444, 0.060206422018348624, 0.09365079365079365 } ),
        P( "YellowLight.png" )
    ) },
    { GreenLight_Init(
        P( { 0.7672018348623854, 0.5026475694444444, 0.060206422018348624, 0.09365079365079365 } ),
        P( "GreenLight.png" )
    ) },
    { RedLight_Init(
        P( { 0.5607798165137615, 0.21852058531746033, 0.060206422018348624, 0.09365079365079365 } ),
        P( "RedLight.png" )
    ) },
    { YellowLight_Init(
        P( { 0.5607798165137615, 0.15979042658730158, 0.060206422018348624, 0.09365079365079365 } ),
        P( "YellowLight.png" )
    ) },
    { GreenLight_Init(
        P( { 0.5607798165137615, 0.10423487103174603, 0.060206422018348624, 0.09365079365079365 } ),
        P( "GreenLight.png" )
    ) },
    { RedLight_Init(
        P( { 0.3956422018348624, 0.5661396329365079, 0.060206422018348624, 0.09365079365079365 } ),
        P( "RedLight.png" )
    ) },
    { YellowLight_Init(
        P( { 0.3956422018348624, 0.6216951884920635, 0.060206422018348624, 0.09365079365079365 } ),
        P( "YellowLight.png" )
    ) },
    { GreenLight_Init(
        P( { 0.3956422018348624, 0.6772507440476191, 0.060206422018348624, 0.09365079365079365 } ),
        P( "GreenLight.png" )
    ) },
    { Primitive_Init(
        P( { 0.3360091743119266, 0.09153645833333333, 0.1536697247706422, 0.15396825396825398 } ),
        P( "Rectangle 000000 line 1 true FF0000 round" )
    ) },
    { Primitive_Init(
        P( { 0.7006880733944955, 0.16455233134920635, 0.11123853211009174, 0.11904761904761904 } ),
        P( "Oval 000000 line 1 null FFFFFF oval" )
    ) },
    { Primitive_Init(
        P( { 0.10091743119266056, 0.12804439484126984, 0.12041284403669725, 0.10793650793650794 } ),
        P( "Rectangle 000000 dash2 1 null FFFFFF null" )
    ) }
};
Sprite* getobj( int id ){
    return &g_objects[ id ];
}
int ObjsBuilder_startSim(
    void  
){
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *imageSurface = NULL;
    SDL_Texture *imageTexture = NULL;

    int nResult = S_OK;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        nResult = S_FALSE;
    }

    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

    if (nResult == S_OK) {
        // Load image
        char sRelPath[256];
        sprintf(sRelPath, "%s/%s", getInputDir(), "ObjsBuilder/Main.png");
        imageSurface = IMG_Load(sRelPath);
        if (imageSurface == NULL) {
            printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
            nResult = S_FALSE;
        } else {
            SCREEN_WIDTH = imageSurface->w;
            SCREEN_HEIGHT = imageSurface->h;
        }
    }

    if (nResult == S_OK) {
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            nResult = S_FALSE;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                nResult = S_FALSE;
            }
        }
    }

    if (nResult == S_OK && imageSurface != NULL) {
        // Create a texture from the loaded surface
        imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        if (imageTexture == NULL) {
            printf("Unable to create texture! SDL_Error: %s\n", SDL_GetError());
            nResult = S_FALSE;
        }
    }

    // Initialize SDL_image
    if (nResult == S_OK && !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        nResult = S_FALSE;
    }

    for( int i = 0; i < sizeof( g_objects ) / sizeof( g_objects[ 0 ] ) && nResult == S_OK; i++ ){
        if( Sprite_load( &g_objects[ i ], renderer ) == false ){
            nResult = S_FALSE;
        }
    }

    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( ), );
    ContextImpl_Start( &context );
    SaveAllImages();
    ReleaseAllImages();

    if (nResult == S_OK) {
        bool quit = false;
        SDL_Event e;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                } else if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_x) {
                        ResetActionCounter();
                        ContextImpl_EventProc(&context, ContextImpl_TMOUT, NULL);
                        SaveAllImages();
                        ReleaseAllImages();
                    }
                }
            }

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
            SDL_RenderClear(renderer);

            // Render the image texture
            //if (imageTexture != NULL) {
            //    SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            //}

            eastRedLight->m_angle += 1.0;

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw0(&g_objects[i], renderer);
            }
            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw1(&g_objects[i], renderer);
            }

            // Update the screen
            SDL_RenderPresent(renderer);

            // Delay to control the animation speed
            SDL_Delay(50);
        }
    }

    for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
        Sprite_free(&g_objects[i]);
    }

    // Free resources and close SDL
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    ReleaseAllImages();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
} /* ObjsBuilder_startSim */

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}