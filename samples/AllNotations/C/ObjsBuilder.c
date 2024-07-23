/* File generated by Đức's ClasHStamP */
#define __ObjsBuilder_INTERNAL__
#include "CommonInclude.h"
#include "ObjsBuilder.h"
#include "Primitive.h"                                          
#include "TranslationConstraint.h"                              
#include "AttachmentConstraint.h"                               
#include "RotationConstraint.h"                                 
#include "TrackToConstraint.h"                                  
#include "CarWheel.h"                                           
#include "CarBody.h"                                            
#include "WindscreenWiper.h"                                    
#include "MotorRotor.h"                                         
#include "Lever.h"                                              
#include "FlexButton.h"                                         
#include "Button.h"                                             
#include "MouseListener.h"                                      
#include "ContextImpl.h"                                        
Sprite* g_objects[] = {
    &CarBody_Ctor(                                              /* carBody */
        P( { 0.3920008267879289, 0.3645829478553404, 0.1807909604519774, 0.2206896551724138 } )/* m_iniRect */,
        P( "carBody" )                                          /* m_name */,
        P( "CarBody.png" )                                      /* m_imgPath */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */,
        P( &MouseListener_Ctor( 0, CarBody_Start, &carBody, 0, null ) )/* m_onDrawListeners */
    ),
    &FlexButton_Ctor(                                           /* toggleBtn */
        P( { 0.3460451977401129, 0.23900862068965517, 0.1101694915254239, 0.06896551724137931 } )/* m_iniRect */,
        P( "toggleBtn" )                                        /* m_name */,
        P( "FlexButton.png" )                                   /* m_imgPath */,
        1,
        P( FlexBtnStm_ToggleStyle )                             /* m_style */,
        P( &MouseListener_Ctor( SDL_MOUSEBUTTONDOWN | SDL_BUTTON_LEFT, FlexButton_EventProc, &toggleBtn, FlexButton_MOUSE_DOWN, &MouseListener_Ctor( SDL_MOUSEBUTTONUP | SDL_BUTTON_LEFT, FlexButton_EventProc, &toggleBtn, FlexButton_MOUSE_UP, &MouseListener_Ctor( SDL_MOUSEMOTION | SDL_BUTTON_LEFT, FlexButton_EventProc, &toggleBtn, FlexButton_MOUSE_MOVE, null ) ) ) )/* m_mouseListeners */,
        P( null )                                               /* m_buttonListeners */
    ),
    &Primitive_Ctor(                                            /* Text_1sh */
        P( { 0.21327683615819218, 0.7241379310344828, 0.536723163841808, 0.05969827586206897 } )/* 1sh-c8099ab49758debe3aa2523402f0bf52 */,
        P( "Text_1sh" )                                         /* Text_1sh */,
        P( "Text 000000 line 2 null 000000 null Monospaced 8 Press Number key for event trigger" )/* Text_1sh */
    )
};
Sprite* getobj( int id ){
    return g_objects[ id ];
}
int ObjsBuilder_startSim(
    void  
){
    carBody->m_stmShow = true;

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
        SDL_RendererFlags hardwareAccelerationAvailable = SDL_RENDERER_SOFTWARE;

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
                    if( e.key.keysym.sym == SDLK_r ){
                        CarBody_Start( carBody );
                    }else{
                        int n = e.key.keysym.sym;
                        EventParams* pParams = NULL;
                        E1Params e1Params = { .x = Two };
                        if (n == CarBody_E1) {
                            pParams = &e1Params;
                        }
                        CarBody_EventProc( carBody, (CarBody_EVENT)( n - SDLK_0 ), pParams);
                    }
                }
            }

            // Render the image texture
            if (imageTexture != NULL) {
                SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
            }

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

            /*
            char n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            EventParams* pParams = NULL;
            E1Params e1Params = { .x = Two };
            if (n == CarBody_E1) {
                pParams = &e1Params;
            }
            CarBody_EventProc( carBody, (CarBody_EVENT)( n - SDLK_0 ), pParams);
            */
            // Delay to control the animation speed
            //SDL_Delay(50);
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
        SDL_CreateRenderer(pSprite->m_stmWindow, -1, SDL_RENDERER_ACCELERATED);
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

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}
