#ifndef __CarBody_H__
#define __CarBody_H__
#include "ImgSprite.h"
typedef struct tagCarBody CarBody;
typedef struct tagE1Params {
    EventParams base;
    int x;                                                      
}E1Params;
void CarBody_moveRight( CarBody* pCarBody );
void CarBody_moveLeft( CarBody* pCarBody );
void CarBody_turnOff( CarBody* pCarBody );
void CarBody_turnOn( CarBody* pCarBody );
typedef enum tagCarBodyEvent {
    CarBody_ACCEL_PRESSED,                                      
    CarBody_ACCEL_RELEASED,                                     
    CarBody_GEAR_DOWN,                                          
    CarBody_GEAR_UP,                                            
    CarBody_PWR_BTN,                                            
    CarBody_REVERSE,                                            
    CarBody_EVENT_NUM
}CarBody_EVENT;
const TCHAR* CarBodyEvent_toString( CarBody_EVENT value );
BOOL CarBody_Start( CarBody* pCarBody );
BOOL CarBody_EventProc( CarBody* pCarBody, CarBody_EVENT nEventId, void* pEventParams );
void CarBody_printTestCases( CarBody* pCarBody, int eventId, void* pParams );
#endif//__CarBody_H__
#if !defined( CarBody_Init ) && ( defined( __CarBody_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/* states' declaration */
#define MainTop_Reversed                        ( 1ULL <<  0 )
#define MainTop_Drive                           ( 1ULL <<  1 )
#define MainTop_GearEngaged                     ( MainTop_Reversed | MainTop_Drive )
#define MainTop_GearInit                        ( 1ULL <<  2 )
#define MainTop_Neutral                         ( 1ULL <<  3 )
#define MainTop_Parked                          ( 1ULL <<  4 )
#define MainTop_CarOnRgn1                       ( MainTop_GearEngaged | MainTop_GearInit | MainTop_Neutral | MainTop_Parked )
/* states' declaration */
#define MainTop_InfotainmentInit                ( 1ULL <<  0 )
#define MainTop_BackCamera                      ( 1ULL <<  1 )
#define MainTop_DisplayAvail                    ( 1ULL <<  2 )
#define MainTop_CarOnRgn2                       ( MainTop_InfotainmentInit | MainTop_BackCamera | MainTop_DisplayAvail )
/* states' declaration */
#define MainTop_CarOnRgn1Init                   ( 1ULL <<  0 )
#define MainTop_EngineIdle                      ( 1ULL <<  1 )
#define MainTop_EngineAccel                     ( 1ULL <<  2 )
#define MainTop_EngineDeccel                    ( 1ULL <<  3 )
#define MainTop_EngineMgmtInit                  ( 1ULL <<  4 )
#define MainTop_EngineManagement                ( MainTop_EngineIdle | MainTop_EngineAccel | MainTop_EngineDeccel | MainTop_EngineMgmtInit )
#define MainTop_CarOn                           ( MainTop_CarOnRgn1Init | MainTop_EngineManagement )
#define MainTop_CarOff                          ( 1ULL <<  5 )
#define MainTop_MainInit                        ( 1ULL <<  6 )
#define MainTop_MainStm                         ( MainTop_CarOn | MainTop_CarOff | MainTop_MainInit )
/** @class MainTop
 * @extends HdStateMachine
 */
typedef struct tagMainTop {
    HdStateMachine MainStmHsm;                                  
    HdStateMachine CarOnRgn1Hsm;                                
    HdStateMachine CarOnRgn2Hsm;                                
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}MainTop;
#define MainTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .MainStmHsm = { HdStateMachine_Init() },\
    .CarOnRgn1Hsm = { HdStateMachine_Init() },\
    .CarOnRgn2Hsm = { HdStateMachine_Init() },\
}

/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_spriteCoords, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_spriteCoords ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .x0 = 0,\
    .mainStm = MainTop_Init(),\

#define CarBody_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_spriteCoords, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( CarBody ){ \
    CarBody_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_spriteCoords ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* CarBody_Copy( CarBody* pCarBody, const CarBody* pSource );
/** @class CarBody
 * @extends ImgSprite
 */
struct tagCarBody{
#define CarBody_CLASS                                                                           \
    ImgSprite_CLASS                                                                             \
    int x0;                                                                                                                            \
    MainTop mainStm;                                            

    CarBody_CLASS    
};
#endif//__CarBody_INTERNAL__
