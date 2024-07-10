/* File generated by Đức's ClasHStamP */
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
#include "ImgSprite.h"                                          
#include "PhxSimpleMotor.h"                                     
#include "PhxDampedSpring.h"                                    
#include "PhxDampedRotarySpring.h"                              
#include "PhxRotaryLimitJoint.h"                                
#include "PhxRatchetJoint.h"                                    
#include "PhxGearJoint.h"                                       
#include "PhxSlideJoint.h"                                      
#include "PhxPinJoint.h"                                        
#include "PhxPivotJoint.h"                                      
#include "PhxGrooveJoint.h"                                     
#include "ClawMachine.h"                                        
/** @private @static @memberof ObjsBuilder */
static int hardwareAccelerationAvailable = SDL_RENDERER_SOFTWARE;
/** @private @static @memberof ObjsBuilder */
static int SCREEN_WIDTH = 640;                                  
/** @private @static @memberof ObjsBuilder */
static int SCREEN_HEIGHT = 480;                                 
/** @private @static @memberof ObjsBuilder */
static float g_x = 0;                                           
/** @private @static @memberof ObjsBuilder */
static float g_y = 0;                                           
Sprite* g_objects[] = {
    &FlexButton_Ctor(                                           /* pushButton */
        P( { 0.0747349964536908, 0.8263998812821528, 0.02373397075900981, 0.02772396673472237 } )/* m_iniRect */,
        P( "pushButton" )                                       /* m_name */,
        P( "FlexButton.png" )                                   /* m_imgPath */,
        P( 1 )                                                  /* m_valueMax */,
        P( FlexBtnStm_PushStyle )                               /* m_style */,
        P( &MouseListener_Ctor( SDL_MOUSEBUTTONDOWN | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_DOWN, &MouseListener_Ctor( SDL_MOUSEBUTTONUP | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_UP, &MouseListener_Ctor( SDL_MOUSEMOTION | SDL_BUTTON_LEFT, FlexButton_EventProc, &pushButton, FlexButton_MOUSE_MOVE, null ) ) ) )/* m_mouseListeners */,
        P( &EventListener_Ctor( MDD_ON_MOUSE_DOWN, ClawMachine_EventProc, &clawMachine, ClawMachine_RightBtnDown, null ) )/* m_buttonListeners */
    ),
    &PhxSprite_Ctor(                                            /* prize0 */
        P( { 0.3468601369094194, 0.7061811896436976, 0.09788028479729712, 0.1692670960851718 } )/* m_iniRect */,
        P( "prize0" )                                           /* m_name */,
        P( "crane_game_prize.png" )                             /* m_imgPath */,
        P( (cpVect[]){ {0.14308688309349385, -0.5102329444968342}, {-0.04205559741918127, -0.5232512808940586}, {-0.19907533886413867, -0.50209636811794}, {-0.28110048507107005, -0.5525425842400652}, {-0.4076536136639439, -0.5167420197909434}, {-0.43108914035502605, -0.4223590344588144}, {-0.3631253636819535, -0.38004939471558336}, {-0.42874553416670824, -0.21894722631254707}, {-0.3021921379777864, -0.07411802485829294}, {-0.4849912798981917, 0.11464813161497109}, {-0.46858630417601504, 0.17485823939176925}, {-0.37718700081186035, 0.18136694306786613}, {-0.27406939891006865, 0.11139368687241957}, {-0.2459463922463029, 0.3082962339155716}, {-0.17095206460432494, 0.4319705225937071}, {-0.07252167507916885, 0.4254608898725795}, {0.014190951100446188, 0.26273140619376445}, {0.15011796925449528, 0.41081523819957627}, {0.24151754021469793, 0.4026786618206821}, {0.2649530669057801, 0.28388631896988303}, {0.2743274916590513, 0.1048836825332797}, {0.4125986511935142, 0.15858452920696256}, {0.4969676711848114, 0.15207526810384725}, {0.5063415607459867, 0.09511997668761289}, {0.29776355354222944, -0.0920188645098723}, {0.40088062025192517, -0.2108113931696775}, {0.31885574164104175, -0.4028321801944992}, {0.3868192507180663, -0.4500237657650667}, {0.365727062619254, -0.5313884146999712}, {0.22745617068083906, -0.5623070333217566} } )/* m_verts */,
        P( 30 )                                                 /* m_vertsCnt */,
        P( { 0.4892497470437934, 0.5659437473266524 } )         /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 0 )                                                  /* m_group */,
        P( null )                                               /* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* prize1 */
        P( { 0.29961477089614913, 0.5198234072022161, 0.09788028479729712, 0.1692670960851718 } )/* m_iniRect */,
        P( "prize1" )                                           /* m_name */,
        P( "crane_game_prize.png" )                             /* m_imgPath */,
        P( (cpVect[]){ {0.14308688309349385, -0.5102329444968342}, {-0.04205559741918127, -0.5232512808940586}, {-0.19907533886413867, -0.50209636811794}, {-0.28110048507107005, -0.5525425842400652}, {-0.4076536136639439, -0.5167420197909434}, {-0.43108914035502605, -0.4223590344588144}, {-0.3631253636819535, -0.38004939471558336}, {-0.42874553416670824, -0.21894722631254707}, {-0.3021921379777864, -0.07411802485829294}, {-0.4849912798981917, 0.11464813161497109}, {-0.46858630417601504, 0.17485823939176925}, {-0.37718700081186035, 0.18136694306786613}, {-0.27406939891006865, 0.11139368687241957}, {-0.2459463922463029, 0.3082962339155716}, {-0.17095206460432494, 0.4319705225937071}, {-0.07252167507916885, 0.4254608898725795}, {0.014190951100446188, 0.26273140619376445}, {0.15011796925449528, 0.41081523819957627}, {0.24151754021469793, 0.4026786618206821}, {0.2649530669057801, 0.28388631896988303}, {0.2743274916590513, 0.1048836825332797}, {0.4125986511935142, 0.15858452920696256}, {0.4969676711848114, 0.15207526810384725}, {0.5063415607459867, 0.09511997668761289}, {0.29776355354222944, -0.0920188645098723}, {0.40088062025192517, -0.2108113931696775}, {0.31885574164104175, -0.4028321801944992}, {0.3868192507180663, -0.4500237657650667}, {0.365727062619254, -0.5313884146999712}, {0.22745617068083906, -0.5623070333217566} } )/* m_verts */,
        P( 30 )                                                 /* m_vertsCnt */,
        P( { 0.4892497470437934, 0.5659437473266524 } )         /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 0 )                                                  /* m_group */,
        P( null )                                               /* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* prize2 */
        P( { 0.2452795107805422, 0.7192693905817175, 0.09788028479729712, 0.1692670960851718 } )/* m_iniRect */,
        P( "prize2" )                                           /* m_name */,
        P( "crane_game_prize.png" )                             /* m_imgPath */,
        P( (cpVect[]){ {0.14308688309349385, -0.5102329444968342}, {-0.04205559741918127, -0.5232512808940586}, {-0.19907533886413867, -0.50209636811794}, {-0.28110048507107005, -0.5525425842400652}, {-0.4076536136639439, -0.5167420197909434}, {-0.43108914035502605, -0.4223590344588144}, {-0.3631253636819535, -0.38004939471558336}, {-0.42874553416670824, -0.21894722631254707}, {-0.3021921379777864, -0.07411802485829294}, {-0.4849912798981917, 0.11464813161497109}, {-0.46858630417601504, 0.17485823939176925}, {-0.37718700081186035, 0.18136694306786613}, {-0.27406939891006865, 0.11139368687241957}, {-0.2459463922463029, 0.3082962339155716}, {-0.17095206460432494, 0.4319705225937071}, {-0.07252167507916885, 0.4254608898725795}, {0.014190951100446188, 0.26273140619376445}, {0.15011796925449528, 0.41081523819957627}, {0.24151754021469793, 0.4026786618206821}, {0.2649530669057801, 0.28388631896988303}, {0.2743274916590513, 0.1048836825332797}, {0.4125986511935142, 0.15858452920696256}, {0.4969676711848114, 0.15207526810384725}, {0.5063415607459867, 0.09511997668761289}, {0.29776355354222944, -0.0920188645098723}, {0.40088062025192517, -0.2108113931696775}, {0.31885574164104175, -0.4028321801944992}, {0.3868192507180663, -0.4500237657650667}, {0.365727062619254, -0.5313884146999712}, {0.22745617068083906, -0.5623070333217566} } )/* m_verts */,
        P( 30 )                                                 /* m_vertsCnt */,
        P( { 0.4892497470437934, 0.5659437473266524 } )         /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 0 )                                                  /* m_group */,
        P( null )                                               /* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* arm_main */
        P( { 0.06782273603082854, 0.20440904893813486, 0.09161849710982663, 0.14173765699918797 } )/* m_iniRect */,
        P( "arm_main" )                                         /* m_name */,
        P( "crane_game_arm_main.png" )                          /* m_imgPath */,
        P( (cpVect[]){ {-3.1926496254977256E-4, -0.11904658595455851}, {-0.20021848292762712, -0.09389529054306192}, {-0.35014273179783745, -0.014002880789311088}, {-0.421260703811921, 0.09843827910862574}, {-0.4193385727335443, 0.2079204233270552}, {-0.315544811329984, 0.315923059705731}, {-0.16946482461652712, 0.38545908351336405}, {0.003524777722740015, 0.40321292419217125}, {0.21495634321515036, 0.37510261310116727}, {0.3418154580877675, 0.3055666737596132}, {0.42446577762918397, 0.20348198427387318}, {0.42446577762918397, 0.09843827910862574}, {0.36103632992860724, -0.012523372949557406}, {0.21687825482206344, -0.08797725918404718} } )/* m_verts */,
        P( 14 )                                                 /* m_vertsCnt */,
        P( { 0.4962441655295966, 0.554863466741726 } )          /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 3 )                                                  /* m_group */,
        P( &PhxGrooveJoint_Ctor( null, 1, &arm_main, &arm_main_hanger, null, null ) )/* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* arm_right */
        P( { 0.12109826589595375, 0.3002943213296399, 0.06011560693641618, 0.1018005540166205 } )/* m_iniRect */,
        P( "arm_right" )                                        /* m_name */,
        P( "crane_game_arm_right.png" )                         /* m_imgPath */,
        P( (cpVect[]){ {0.39808818357082587, 0.4417649576586646}, {-0.01434201148246342, 0.7262941453848002}, {-0.21345559190639124, 0.7834970810742284}, {0.0942649889150952, 0.826892644591639}, {0.7338414222849121, 0.4264708560121022}, {0.0942649889150952, -0.07652197786396635}, {-0.11993313633811009, -0.08243950351908685}, {-0.17725371774006882, 0.018159108301710088} } )/* m_verts */,
        P( 8 )                                                  /* m_vertsCnt */,
        P( { 0.24998743673952534, 0.1266524605357124 } )        /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 2 )                                                  /* m_group */,
        P( &PhxPivotJoint_Ctor( &arm_main, 1, null, &PhxRotaryLimitJoint_Ctor( &arm_main, 1, -30.0, 30.0, null ) ) )/* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* arm_left */
        P( { 0.04653179190751445, 0.29733536892470414, 0.06011560693641618, 0.10475950642155626 } )/* m_iniRect */,
        P( "arm_left" )                                         /* m_name */,
        P( "crane_game_arm_left.png" )                          /* m_imgPath */,
        P( (cpVect[]){ {-0.3873646561375531, 0.43389111042150647}, {0.18797710851665453, 0.00944803050038769}, {0.13065650641004445, -0.0913494082078489}, {-0.08354169621323272, -0.08542018693202294}, {-0.7231183606031603, 0.4185667809360949}, {-0.08354135173846045, 0.8197798653918567}, {0.224179340234155, 0.7762985332473578}, {0.02506568788881327, 0.7189825395201526} } )/* m_verts */,
        P( 8 )                                                  /* m_vertsCnt */,
        P( { 0.7355190028131329, 0.12690266291390603 } )        /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 1 )                                                  /* m_group */,
        P( &PhxPivotJoint_Ctor( &arm_main, 1, null, null ) )    /* m_joints */
    ),
    &PhxSprite_Ctor(                                            /* arm_main_hanger */
        P( { 0.1023121387283237, 0.07106994459833794, 0.023121387283236993, 0.027700831024930747 } )/* m_iniRect */,
        P( "arm_main_hanger" )                                  /* m_name */,
        P( "GreenLight.png" )                                   /* m_imgPath */,
        P( (cpVect[]){ {1.828279769160209, 2.696922782427791}, {1.828279769160209, 3.656844521799918}, {2.81273803553565, 3.656844521799918}, {2.81273803553565, 2.696922782427791} } )/* m_verts */,
        P( 4 )                                                  /* m_vertsCnt */,
        P( { -1.8180710658590873, -2.662044914487701 } )        /* m_center */,
        P( 1 )                                                  /* m_mass */,
        P( 3 )                                                  /* m_group */,
        P( &PhxGrooveJoint_Ctor( null, 1, &arm_main_hanger, &gate_position, null, null ) )/* m_joints */
    ),
    &ImgSprite_Ctor(                                            /* gate_position */
        P( { 0.7895953757225433, 0.07063711911357343, 0.023121387283236993, 0.027700831024930747 } )/* m_iniRect */,
        P( "gate_position" )                                    /* m_name */,
        P( "RedLight.png" )                                     /* m_imgPath */,
        P( { 0.0, 0.0 } )                                       /* m_center */,
        P( null )                                               /* m_constraints */,
        P( null )                                               /* m_mouseListeners */,
        P( null )                                               /* m_onDrawListeners */
    ),
    &ClawMachine_Ctor(                                          /* clawMachine */
        P( { 0.42947976878612726, 0.1520948753462604, 0.1676300578034682, 0.2027354570637119 } )/* m_iniRect */,
        P( "clawMachine" )                                      /* m_name */,
        P( "ClawMachine.png" )                                  /* m_imgPath */
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
            //nResult = S_FALSE;
        }
    }

    if( nResult == S_OK ){
            // Set the new texture as the render target
        SDL_SetRenderTarget(renderer, imageTexture);

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // White
        SDL_RenderClear(renderer);

        clawMachine->m_stmShow = true;
        
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

            //cpBodyApplyForceAtLocalPoint( PhxSprite_getBody( arm_main ), cpv( 100, 100 ), cpvzero);

            bool hasUpdated = true;

            while( hasUpdated ){
                for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                    Sprite_update(g_objects[i]);
                }
                hasUpdated = false;
                for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                    if( Sprite_isUpdated(g_objects[i]) ){
                        hasUpdated = true;
                    }
                }
            }

            cpBodySetTorque( PhxSprite_getBody( arm_right ), 100 );
            cpBodySetTorque( PhxSprite_getBody( arm_left ), -100 );

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

            for (int i = 0; i < sizeof(g_objects) / sizeof(g_objects[0]); i++) {
                Sprite_draw1(g_objects[i], renderer);
            }

            // Draw ground
            SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 50, SCREEN_WIDTH, SCREEN_HEIGHT - 50);

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
            SDL_Delay(1);
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
        char windowName[255];
        sprintf(windowName, "%s - %s", s, pSprite->m_name);
        pSprite->m_stmWindow = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1, 0, SDL_WINDOW_SHOWN);
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
        printf( "%s size: %dx%d\n", sRelPath, pStm->m_stmRect.w, pStm->m_stmRect.h );
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
        SDL_RenderPresent(stmRenderer);                         // Refresh Renderer
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

int ObjsBuilder_getScreenWidth(
    void  
){
    return SCREEN_WIDTH;
} /* ObjsBuilder_getScreenWidth */

int ObjsBuilder_getScreenHeight(
    void  
){
    return SCREEN_HEIGHT;
} /* ObjsBuilder_getScreenHeight */

ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource ){
    return ( ObjsBuilder* )pObjsBuilder;
}
