﻿/* File generated by Đức's ClasHStamP */
#define __ObjsBuilder_INTERNAL__
#include "CommonInclude.h"
#include "ObjsBuilder.h"
#include "Primitive.h"                                          
#include "TranslationConstraint.h"                              
#include "AttachmentConstraint.h"                               
#include "RotationConstraint.h"                                 
#include "TrackToConstraint.h"                                  
#include "FlexButton.h"                                         
#include "MouseListener.h"                                      
#include "PhxSprite.h"                                          
/** @private @static @memberof ObjsBuilder */
static int hardwareAccelerationAvailable = SDL_RENDERER_SOFTWARE;
Sprite* g_objects[] = {
    &FlexButton_Ctor(                                           /* pushButton */
        P( { 0.056028795455243065, 0.8271639811357832, 0.022938418666529032, 0.027533292960755917 } )/* m_iniRect */,
        P( "pushButton" )                                       /* m_name */,
        P( "FlexButton.png" )                                   /* m_imgPath */,
        P( 1 )                                                  /* m_valueMax */,
        P( FlexBtnStm_PushStyle )                               /* m_style */,
        P( &MouseListener_Ctor( SDL_MOUSEBUTTONDOWN | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_DOWN, &MouseListener_Ctor( SDL_MOUSEBUTTONUP | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_UP, &MouseListener_Ctor( SDL_MOUSEMOTION | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_MOVE, null ) ) ) )/* m_mouseListeners */,
        P( null )                                               /* m_buttonListeners */
    ),
    &PhxSprite_Ctor(                                            /* prize0 */
        P( { 0.27433968539290254, 0.462930287376547, 0.0945993813962704, 0.16810294824414587 } )/* m_iniRect */,
        P( "prize0" )                                           /* m_name */,
        P( "crane_game_prize.png" )                             /* m_imgPath */,
        P( (cpVect[]){ {-0.19238599284905766, -0.46570042269359785}, {-0.019023741409532065, -0.49013210111665545}, {0.14965351370743632, -0.4738442535083112}, {0.219935413547758, -0.529222823789331}, {0.36518501205118514, -0.5047909593873561}, {0.38626936800322126, -0.40869286307493435}, {0.3159874681628996, -0.36471573032608023}, {0.4096970246167625, -0.19043600268938982}, {0.3136447025015454, -0.05687598706301863}, {0.505749079231904, 0.1222903366287677}, {0.505749079231904, 0.18581292370341837}, {0.42843888240752, 0.20210039935392776}, {0.2714754555973222, 0.13369177416093342}, {0.2808465182427387, 0.34543360709049076}, {0.2293064761931745, 0.4415317034029124}, {0.14731074804608218, 0.4431601348038038}, {0.018460241672058418, 0.2998272990250756}, {-0.0658779846363125, 0.4545615723359695}, {-0.1642730724128837, 0.46107678577087413}, {-0.25095433188268423, 0.3210015567095983}, {-0.2696961896734417, 0.15649446324634744}, {-0.3985466960474655, 0.2216458536797243}, {-0.47117162904921683, 0.21513064024481965}, {-0.4875707211786202, 0.1499792498114428}, {-0.2931235787869075, -0.04384593215104416}, {-0.4149457881768689, -0.1676333136039758}, {-0.3493491521591799, -0.35331447877283195}, {-0.4336876459676263, -0.39729161152168607}, {-0.39151839906340313, -0.49338970783410774}, {-0.25798236136667113, -0.5113063588011781} } )/* m_verts */,
        P( 30 )                                                 /* m_vertsCnt */,
        P( { 0.48757065516388165, 0.529223068091237 } )         /* m_center */,
        P( 1 )                                                  /* m_mass */
    )
};
Sprite* getobj( int id ){
    return g_objects[ id ];
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
    // Initialize SDL_ttf
    if (nResult == S_OK && TTF_Init() == -1) {
        printf("TTF could not initialize! TTF_Error: %s\n", TTF_GetError());
        nResult = S_FALSE;
    }
    int SCREEN_WIDTH = 640;
    int SCREEN_HEIGHT = 480;

    if (nResult == S_OK) {
        // Load image
        char sRelPath[1024];
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
        SDL_RendererInfo rendererInfo;
        int numRenderDrivers = SDL_GetNumRenderDrivers();

        for (int i = 0; i < numRenderDrivers; ++i) {
            if (SDL_GetRenderDriverInfo(i, &rendererInfo) == 0) {
                if (rendererInfo.flags & SDL_RENDERER_ACCELERATED) {
                    printf("Hardware acceleration is available for renderer: %s\n", rendererInfo.name);
                    hardwareAccelerationAvailable = SDL_RENDERER_ACCELERATED;
                    break;
                }
            }
        }

        window = SDL_CreateWindow("Model Driven Development", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            nResult = S_FALSE;
        } else {
            renderer = SDL_CreateRenderer(window, -1, hardwareAccelerationAvailable);
            if (renderer == NULL) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                nResult = S_FALSE;
            }
        }
    }

    if (nResult == S_OK && imageSurface != NULL) {
        // Create a texture from the loaded surface
        imageTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
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

    cpVect gravity = cpv(0, -100);
    cpSpace *space = ObjsBuilder_getPhxSpace();
    cpSpaceSetGravity(space, gravity);
    // Ground
    cpShape *ground = cpSpaceAddShape(space, cpSegmentShapeNew(cpSpaceGetStaticBody(space), cpv(0, 50), cpv(SCREEN_WIDTH, 50), 0));
    cpShapeSetFriction(ground, 1.0); 

    for( int i = 0; i < sizeof( g_objects ) / sizeof( g_objects[ 0 ] ) && nResult == S_OK; i++ ){
        if( Sprite_load( g_objects[ i ], renderer ) == false ){
            nResult = S_FALSE;
        }
    }

    if( nResult == S_OK ){
            // Set the new texture as the render target
        SDL_SetRenderTarget(renderer, imageTexture);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
        SDL_RenderClear(renderer);

        for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
            Sprite_draw0(g_objects[i], renderer);
        }

        // Reset the render target to the default
        SDL_SetRenderTarget(renderer, NULL);       
    }
    
    //carBody->m_stmShow = true;

    if (nResult == S_OK) {
        bool quit = false;
        SDL_Event e;

        while (!quit) {
            bool hasUpdated = true;
            while( hasUpdated ){
                for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                    if( Sprite_isUpdated(g_objects[i]) ){
                        Sprite_update(g_objects[i]);
                    }
                }
                hasUpdated = false;
                for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                    if( Sprite_isUpdated(g_objects[i]) ){
                        hasUpdated = true;
                    }
                }
            }

            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }else if (e.type == SDL_WINDOWEVENT) {
                    if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
                        for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                            Sprite* pSprite = g_objects[i];
                            if( SDL_GetWindowID( pSprite->m_stmWindow ) == e.window.windowID ){
                                if( pSprite->m_stmWindow != null ){
                                    int textureCount = (int)(intptr_t)SDL_GetWindowData(g_objects[i]->m_stmWindow, "textureCount");
                                    for (int j = 1; j <= textureCount; j++) {
                                        char key[20];
                                        snprintf(key, 20, "texture%d", j);
                                        SDL_Texture* texture = (SDL_Texture*)SDL_GetWindowData(g_objects[i]->m_stmWindow, key);
                                        SDL_DestroyTexture(texture);
                                        SDL_SetWindowData(g_objects[i]->m_stmWindow, key, NULL);
                                    }
                                    SDL_SetWindowData(g_objects[i]->m_stmWindow, "textureCount", (void*)(intptr_t)0);

                                    SDL_DestroyWindow( pSprite->m_stmWindow );
                                    SDL_Renderer* stmRenderer = SDL_GetRenderer( pSprite->m_stmWindow );
                                    SDL_DestroyRenderer( stmRenderer );
                                    SDL_DestroyTexture( pSprite->m_stmTexture );
                                    pSprite->m_stmWindow = null;
                                    pSprite->m_stmShow = false;
                                }
                            }
                        }
                    }
                } else if (e.type == SDL_MOUSEWHEEL 
                    || e.type == SDL_MOUSEBUTTONDOWN 
                    || e.type == SDL_MOUSEBUTTONUP 
                    || e.type == SDL_MOUSEMOTION 
                ){
                    for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                        int mouseX = e.button.x;
                        int mouseY = e.button.y;
                        Sprite_updateMouseState(g_objects[i], mouseX, mouseY, e.type | e.button.button);
                    }
                    break;
                } else if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_x) {
                    }else if (e.key.keysym.sym == SDLK_r) {
                    }else if (e.key.keysym.sym == SDLK_l) {
                    }
                }
            }
            // Update physics
            cpSpaceStep(space, 1.0 / 60.0);

            // Render the image texture
            if (imageTexture != NULL) {
                SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            }

            // Draw ground
            SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 50, SCREEN_WIDTH, SCREEN_HEIGHT - 50);

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw1(g_objects[i], renderer);
            }

            // Update the screen
            SDL_RenderPresent(renderer);
            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                if( g_objects[i]->m_stmShow && g_objects[i]->m_stmUpdated  ){
                    SDL_Renderer* stmRenderer = SDL_GetRenderer( g_objects[i]->m_stmWindow );
                    SDL_SetRenderTarget(stmRenderer, NULL);
                    SDL_RenderCopy(stmRenderer, g_objects[i]->m_stmTexture, NULL, NULL);
                    SDL_RenderPresent(stmRenderer);
                    g_objects[i]->m_stmUpdated = false;
                }
            }
            // Delay to control the animation speed
            SDL_Delay(16);
        }
    }

    for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
        if( g_objects[i]->m_stmWindow != null ){
            int textureCount = (int)(intptr_t)SDL_GetWindowData(g_objects[i]->m_stmWindow, "textureCount");
            for (int i = 1; i <= textureCount; i++) {
                char key[20];
                snprintf(key, 20, "texture%d", i);
                SDL_Texture* texture = (SDL_Texture*)SDL_GetWindowData(g_objects[i]->m_stmWindow, key);
                SDL_DestroyTexture(texture);
                SDL_SetWindowData(g_objects[i]->m_stmWindow, key, NULL);
            }
            SDL_SetWindowData(g_objects[i]->m_stmWindow, "textureCount", (void*)(intptr_t)0);
        }
        Sprite_free(g_objects[i]);
    }

    // Free resources and close SDL
    SDL_DestroyTexture(imageTexture);
    SDL_FreeSurface(imageSurface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();    
    IMG_Quit();
    SDL_Quit();

    // Clean up
    cpShapeFree(ground);
    cpSpaceFree(space);

    return 0;
} /* ObjsBuilder_startSim */

void ObjsBuilder_showEntry(
    void* pObj,
    void* pStm_,
    char* pMsg
){
    ObjsBuilder_showDiagram( pObj, pStm_, pMsg, 0x00, 0xFF, 0x00 );
} /* ObjsBuilder_showEntry */

void ObjsBuilder_showDoing(
    void* pObj,
    void* pStm_,
    char* pMsg
){
    ObjsBuilder_showDiagram( pObj, pStm_, pMsg, 0x00, 0x00, 0xFF );
} /* ObjsBuilder_showDoing */

void ObjsBuilder_showExit(
    void* pObj,
    void* pStm_,
    char* pMsg
){
    ObjsBuilder_showDiagram( pObj, pStm_, pMsg, 0xFF, 0x00, 0x00 );
} /* ObjsBuilder_showExit */

void ObjsBuilder_showDiagram(
    void* pObj,
    void* pStm_,
    char* pMsg,
    char r,
    char g,
    char b
){
    Sprite* pSprite = ( Sprite* )pObj;
    if( pSprite->m_stmShow == false ){
        return;
    }
    HdStateMachine* pStm = ( HdStateMachine* )pStm_;
    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    if( pSprite->m_stmWindow == null ){
        int SCREEN_WIDTH = 0;
        int SCREEN_HEIGHT = 0;
        char windowName[255];
        sprintf(windowName, "%s - %s", s, pSprite->m_name);
        pSprite->m_stmWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        SDL_CreateRenderer(pSprite->m_stmWindow, -1, hardwareAccelerationAvailable);
    }
    SDL_Texture* stmImage = pStm->m_stmImage;
    SDL_Rect* stmRect = &pStm->m_stmRect;
    if( stmImage == null ){
        stmImage = SDL_GetWindowData(pSprite->m_stmWindow, s);
        if( stmImage != null){
            char rectKey[255];
            snprintf(rectKey, 255, "%s-rect", s);
            stmRect = SDL_GetWindowData(pSprite->m_stmWindow, rectKey);
        }
    }
    if( stmImage == null ){
        char sRelPath[256];
        sprintf(sRelPath, "%s/%s.png", getInputDir(), s);
        SDL_Surface *imageSurface = IMG_Load(sRelPath);
        pStm->m_stmRect.w = imageSurface->w;
        pStm->m_stmRect.h = imageSurface->h;
        SDL_Renderer* stmRenderer = SDL_GetRenderer( pSprite->m_stmWindow );
        pStm->m_stmImage = SDL_CreateTextureFromSurface(stmRenderer, imageSurface);
        int width, height;
        SDL_GetWindowSize( pSprite->m_stmWindow, &width, &height );
        pStm->m_stmRect.x = 0;
        pStm->m_stmRect.y = height;
        if( width < pStm->m_stmRect.w ){
            width = pStm->m_stmRect.w;
        }
        height = height + pStm->m_stmRect.h;
        SDL_SetWindowSize( pSprite->m_stmWindow, width, height );
        SDL_FreeSurface(imageSurface);

        Uint32 format;
        int dmyW, dmyH;
        SDL_QueryTexture(pStm->m_stmImage, &format, NULL, &dmyW, &dmyH);

        // Create a new texture with the same format and dimensions
        if( pSprite->m_stmTexture != null ){
            SDL_DestroyTexture(pSprite->m_stmTexture);
        }
        pSprite->m_stmTexture = SDL_CreateTexture(stmRenderer, format, SDL_TEXTUREACCESS_TARGET, width, height);

        // Get current texture count from window data
        int textureCount = (int)(intptr_t)SDL_GetWindowData(pSprite->m_stmWindow, "textureCount");
        textureCount++; // Increment texture count        
        // Store texture using a key based on new count
        char key[20];
        snprintf(key, 20, "texture%d", textureCount);
        SDL_SetWindowData(pSprite->m_stmWindow, key, pStm->m_stmImage);
        SDL_SetWindowData(pSprite->m_stmWindow, "textureCount", (void*)(intptr_t)textureCount);
        
        SDL_SetWindowData(pSprite->m_stmWindow, s, pStm->m_stmImage);
        char rectKey[255];
        snprintf(rectKey, 255, "%s-rect", s);
        SDL_SetWindowData(pSprite->m_stmWindow, rectKey, &pStm->m_stmRect);

        stmImage = pStm->m_stmImage;
        stmRect = &pStm->m_stmRect;
        pSprite->m_stmUpdated = false;
    }
    
    SDL_Renderer* stmRenderer = SDL_GetRenderer( pSprite->m_stmWindow );        
    if( !pSprite->m_stmUpdated ){
        SDL_SetRenderTarget(stmRenderer, pSprite->m_stmTexture);
        SDL_RenderCopy(stmRenderer, stmImage, NULL, stmRect);
    }

    int nTop = ( float )( t - dgrY ) + stmRect->y;
    int nLeft = ( float )( l - dgrX );
    int nHeight = ( float )h;
    int nWidth = ( float )w;
    UINT nDotSize = 3;

    rectangleRGBA( stmRenderer, nLeft, nTop, nLeft + nWidth, nTop + nHeight, r, g, b, 0xFF );

    pSprite->m_stmUpdated = true;     
} /* ObjsBuilder_showDiagram */

cpSpace* ObjsBuilder_getPhxSpace(
    void  
){
    static cpSpace* space = null;
    if( space == null ){
        space = cpSpaceNew();
    }
    return space;
} /* ObjsBuilder_getPhxSpace */

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}
