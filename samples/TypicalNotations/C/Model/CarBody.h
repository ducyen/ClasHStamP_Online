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
typedef enum tagCarBodyEvent {
    CarBody_E0,                                                 
    CarBody_E1,                                                 
    CarBody_E2,                                                 
    CarBody_E3,                                                 
    CarBody_E4,                                                 
    CarBody_E5,                                                 
    CarBody_UPDATE,                                             
    CarBody_EVENT_NUM
}CarBody_EVENT;
const TCHAR* CarBodyEvent_toString( CarBody_EVENT value );
BOOL CarBody_Start( CarBody* pCarBody );
BOOL CarBody_EventProc( CarBody* pCarBody, CarBody_EVENT nEventId, void* pEventParams );
#endif//__CarBody_H__
#if !defined( CarBody_Init ) && ( defined( __CarBody_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class SharedTop
 * @extends HdStateMachine
 */
typedef struct tagSharedTop {
#define SharedTop_Charge                        ( 1ULL <<  0 )
#define SharedTop_Drain                         ( 1ULL <<  1 )
#define SharedTop_InitPt                        ( 1ULL <<  2 )
#define SharedTop_Discharging                   ( 1ULL <<  3 )
#define SharedTop_Charging                      ( 1ULL <<  4 )
#define SharedTop_Idle                          ( 1ULL <<  5 )
#define SharedTop_Discharge                     ( 1ULL <<  6 )
#define SharedTop_SharedStm                     ( SharedTop_Charge | SharedTop_Drain | SharedTop_InitPt | SharedTop_Discharging | SharedTop_Charging | SharedTop_Idle | SharedTop_Discharge )
    HdStateMachine SharedStmHsm;                                
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}SharedTop;
#define SharedTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .SharedStmHsm = { HdStateMachine_Init() },\
}
/** @class MainTop
 * @extends HdStateMachine
 */
typedef struct tagMainTop {
#define MainTop_DrivingRgn1Init                 ( 1ULL <<  0 )
#define MainTop_SeatBeltsFastened               ( 1ULL <<  1 )
#define MainTop_SeatBeltsUnfastened             ( 1ULL <<  2 )
#define MainTop_SeatBeltInit                    ( 1ULL <<  3 )
#define MainTop_SeatBelts                       ( MainTop_SeatBeltsFastened | MainTop_SeatBeltsUnfastened | MainTop_SeatBeltInit )
#define MainTop_SeatBeltsTighten                ( 1ULL <<  4 )
#define MainTop_DrivingRgn1                     ( MainTop_DrivingRgn1Init | MainTop_SeatBelts | MainTop_SeatBeltsTighten )
#define MainTop_AirbagArmed                     ( 1ULL <<  0 )
#define MainTop_AirbagDeployed                  ( 1ULL <<  1 )
#define MainTop_AirbagInit                      ( 1ULL <<  2 )
#define MainTop_DrivingRgn2                     ( MainTop_AirbagArmed | MainTop_AirbagDeployed | MainTop_AirbagInit )
#define MainTop_CollisionDetectHit              ( 1ULL <<  0 )
#define MainTop_CollisionDetectAlert            ( 1ULL <<  1 )
#define MainTop_CollisionDetectClear            ( 1ULL <<  2 )
#define MainTop_CollisionDetectInit             ( 1ULL <<  3 )
#define MainTop_DrivingRgn3                     ( MainTop_CollisionDetectHit | MainTop_CollisionDetectAlert | MainTop_CollisionDetectClear | MainTop_CollisionDetectInit )
#define MainTop_EngineIdle                      ( 1ULL <<  0 )
#define MainTop_EngineAccel                     ( 1ULL <<  1 )
#define MainTop_EngineDeccel                    ( 1ULL <<  2 )
#define MainTop_EngineMgmtInit                  ( 1ULL <<  3 )
#define MainTop_EngineManagement                ( MainTop_EngineIdle | MainTop_EngineAccel | MainTop_EngineDeccel | MainTop_EngineMgmtInit )
#define MainTop_CarOnRgn1Init                   ( 1ULL <<  4 )
#define MainTop_CarOnRgn1                       ( MainTop_EngineManagement | MainTop_CarOnRgn1Init )
#define MainTop_MainBattery                     ( 1ULL <<  0 )
#define MainTop_BatteryMgmtInit                 ( 1ULL <<  1 )
#define MainTop_CarOnRgn2                       ( MainTop_MainBattery | MainTop_BatteryMgmtInit )
#define MainTop_InfotainmentOff                 ( 1ULL <<  0 )
#define MainTop_InfotainmentAV                  ( 1ULL <<  1 )
#define MainTop_InfotainmentNavi                ( 1ULL <<  2 )
#define MainTop_InfotainmentInit                ( 1ULL <<  3 )
#define MainTop_AdaptiveSystemRgn1              ( MainTop_InfotainmentOff | MainTop_InfotainmentAV | MainTop_InfotainmentNavi | MainTop_InfotainmentInit )
#define MainTop_ClimateCtrlOff                  ( 1ULL <<  0 )
#define MainTop_ClimateCtrlMan                  ( 1ULL <<  1 )
#define MainTop_ClimateCtrlAuto                 ( 1ULL <<  2 )
#define MainTop_ClimateCtrlInit                 ( 1ULL <<  3 )
#define MainTop_AdaptiveSystem                  ( MainTop_ClimateCtrlOff | MainTop_ClimateCtrlMan | MainTop_ClimateCtrlAuto | MainTop_ClimateCtrlInit )
#define MainTop_AdaptiveSystemInit              ( 1ULL <<  4 )
#define MainTop_CarOnRgn3                       ( MainTop_AdaptiveSystem | MainTop_AdaptiveSystemInit )
#define MainTop_CarOff                          ( 1ULL <<  0 )
#define MainTop_MainInit                        ( 1ULL <<  1 )
#define MainTop_Parked                          ( 1ULL <<  2 )
#define MainTop_Neutral                         ( 1ULL <<  3 )
#define MainTop_GearInit                        ( 1ULL <<  4 )
#define MainTop_Reversed                        ( 1ULL <<  5 )
#define MainTop_Drive                           ( 1ULL <<  6 )
#define MainTop_Moving                          ( MainTop_Reversed | MainTop_Drive )
#define MainTop_Driving                         ( MainTop_Parked | MainTop_Neutral | MainTop_GearInit | MainTop_Moving )
#define MainTop_CarOnInit                       ( 1ULL <<  7 )
#define MainTop_CarOn                           ( MainTop_Driving | MainTop_CarOnInit )
#define MainTop_MainStm                         ( MainTop_CarOff | MainTop_MainInit | MainTop_CarOn )
    HdStateMachine MainStmHsm;                                  
    HdStateMachine DrivingRgn1Hsm;                              
    HdStateMachine DrivingRgn2Hsm;                              
    HdStateMachine DrivingRgn3Hsm;                              
    HdStateMachine CarOnRgn1Hsm;                                
    HdStateMachine CarOnRgn2Hsm;                                
    SharedTop MainBatteryHsm;                                   
    HdStateMachine CarOnRgn3Hsm;                                
    HdStateMachine AdaptiveSystemRgn1Hsm;                       
    uint64_t DeepHistoryPseudostate0;
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}MainTop;
#define MainTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .MainStmHsm = { HdStateMachine_Init() },\
    .DrivingRgn1Hsm = { HdStateMachine_Init() },\
    .DrivingRgn2Hsm = { HdStateMachine_Init() },\
    .DrivingRgn3Hsm = { HdStateMachine_Init() },\
    .CarOnRgn1Hsm = { HdStateMachine_Init() },\
    .CarOnRgn2Hsm = { HdStateMachine_Init() },\
    .MainBatteryHsm = SharedTop_Init(),\
    .CarOnRgn3Hsm = { HdStateMachine_Init() },\
    .AdaptiveSystemRgn1Hsm = { HdStateMachine_Init() },\
    .DeepHistoryPseudostate0 = STATE_UNDEF,\
}

/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .x0 = 0,\
    .mainStm = MainTop_Init(),\

#define CarBody_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( CarBody ){ \
    CarBody_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
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
