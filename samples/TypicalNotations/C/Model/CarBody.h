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
/** @class SharedStm
 * @extends HdStateMachine
 */
typedef struct tagSharedStm {
#define SharedStm_Charge                        ( 1ULL <<  0 )
#define SharedStm_Drain                         ( 1ULL <<  1 )
#define SharedStm_InitPt                        ( 1ULL <<  2 )
#define SharedStm_Discharging                   ( 1ULL <<  3 )
#define SharedStm_Charging                      ( 1ULL <<  4 )
#define SharedStm_Idle                          ( 1ULL <<  5 )
#define SharedStm_Discharge                     ( 1ULL <<  6 )
#define SharedStm_SharedTop                     ( SharedStm_Charge | SharedStm_Drain | SharedStm_InitPt | SharedStm_Discharging | SharedStm_Charging | SharedStm_Idle | SharedStm_Discharge )
    HdStateMachine SharedTopHsm;                                
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}SharedStm;
#define SharedStm_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .SharedTopHsm = { HdStateMachine_Init() },\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
#define MainStm_InitialPseudostate25            ( 1ULL <<  0 )
#define MainStm_SeatBeltsFastened               ( 1ULL <<  1 )
#define MainStm_SeatBeltsUnfastened             ( 1ULL <<  2 )
#define MainStm_InitialPseudostate29            ( 1ULL <<  3 )
#define MainStm_SeatBelts                       ( MainStm_SeatBeltsFastened | MainStm_SeatBeltsUnfastened | MainStm_InitialPseudostate29 )
#define MainStm_DrivingRgn1                     ( MainStm_InitialPseudostate25 | MainStm_SeatBelts )
#define MainStm_AirbagArmed                     ( 1ULL <<  0 )
#define MainStm_AirbagDeployed                  ( 1ULL <<  1 )
#define MainStm_InitialPseudostate24            ( 1ULL <<  2 )
#define MainStm_DrivingRgn2                     ( MainStm_AirbagArmed | MainStm_AirbagDeployed | MainStm_InitialPseudostate24 )
#define MainStm_CollisionDetectHit              ( 1ULL <<  0 )
#define MainStm_CollisionDetectAlert            ( 1ULL <<  1 )
#define MainStm_CollisionDetectClear            ( 1ULL <<  2 )
#define MainStm_InitialPseudostate26            ( 1ULL <<  3 )
#define MainStm_DrivingRgn3                     ( MainStm_CollisionDetectHit | MainStm_CollisionDetectAlert | MainStm_CollisionDetectClear | MainStm_InitialPseudostate26 )
#define MainStm_EngineIdle                      ( 1ULL <<  0 )
#define MainStm_EngineAccel                     ( 1ULL <<  1 )
#define MainStm_EngineDeccel                    ( 1ULL <<  2 )
#define MainStm_InitialPseudostate19            ( 1ULL <<  3 )
#define MainStm_EngineManagement                ( MainStm_EngineIdle | MainStm_EngineAccel | MainStm_EngineDeccel | MainStm_InitialPseudostate19 )
#define MainStm_InitialPseudostate30            ( 1ULL <<  4 )
#define MainStm_CarOnRgn1                       ( MainStm_EngineManagement | MainStm_InitialPseudostate30 )
#define MainStm_MainBattery                     ( 1ULL <<  0 )
#define MainStm_InitialPseudostate27            ( 1ULL <<  1 )
#define MainStm_CarOnRgn2                       ( MainStm_MainBattery | MainStm_InitialPseudostate27 )
#define MainStm_InfotainmentOff                 ( 1ULL <<  0 )
#define MainStm_InfotainmentAudio               ( 1ULL <<  1 )
#define MainStm_InfotainmentMediaPlayer         ( 1ULL <<  2 )
#define MainStm_InitialPseudostate22            ( 1ULL <<  3 )
#define MainStm_AdaptiveSystemRgn1              ( MainStm_InfotainmentOff | MainStm_InfotainmentAudio | MainStm_InfotainmentMediaPlayer | MainStm_InitialPseudostate22 )
#define MainStm_ClimateCtrlOff                  ( 1ULL <<  0 )
#define MainStm_ClimateCtrlMan                  ( 1ULL <<  1 )
#define MainStm_ClimateCtrlAuto                 ( 1ULL <<  2 )
#define MainStm_InitialPseudostate21            ( 1ULL <<  3 )
#define MainStm_AdaptiveSystem                  ( MainStm_ClimateCtrlOff | MainStm_ClimateCtrlMan | MainStm_ClimateCtrlAuto | MainStm_InitialPseudostate21 )
#define MainStm_InitialPseudostate20            ( 1ULL <<  4 )
#define MainStm_CarOnRgn3                       ( MainStm_AdaptiveSystem | MainStm_InitialPseudostate20 )
#define MainStm_CarOff                          ( 1ULL <<  0 )
#define MainStm_InitialPseudostate16            ( 1ULL <<  1 )
#define MainStm_Parked                          ( 1ULL <<  2 )
#define MainStm_Neutral                         ( 1ULL <<  3 )
#define MainStm_InitialPseudostate23            ( 1ULL <<  4 )
#define MainStm_Reversed                        ( 1ULL <<  5 )
#define MainStm_Drive                           ( 1ULL <<  6 )
#define MainStm_InitialPseudostate31            ( 1ULL <<  7 )
#define MainStm_Moving                          ( MainStm_Reversed | MainStm_Drive | MainStm_InitialPseudostate31 )
#define MainStm_Driving                         ( MainStm_Parked | MainStm_Neutral | MainStm_InitialPseudostate23 | MainStm_Moving )
#define MainStm_InitialPseudostate28            ( 1ULL <<  8 )
#define MainStm_CarOn                           ( MainStm_Driving | MainStm_InitialPseudostate28 )
#define MainStm_MainTop_0                       ( MainStm_CarOff | MainStm_InitialPseudostate16 | MainStm_CarOn )
    HdStateMachine MainTop_0Hsm;                                
    HdStateMachine DrivingRgn1Hsm;                              
    HdStateMachine DrivingRgn2Hsm;                              
    HdStateMachine DrivingRgn3Hsm;                              
    uint64_t DeepHistoryPseudostate0;
    HdStateMachine CarOnRgn1Hsm;                                
    HdStateMachine CarOnRgn2Hsm;                                
    SharedStm MainBatteryHsm;                                   
    HdStateMachine CarOnRgn3Hsm;                                
    HdStateMachine AdaptiveSystemRgn1Hsm;                       
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}MainStm;
#define MainStm_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .MainTop_0Hsm = { HdStateMachine_Init() },\
    .DrivingRgn1Hsm = { HdStateMachine_Init() },\
    .DrivingRgn2Hsm = { HdStateMachine_Init() },\
    .DrivingRgn3Hsm = { HdStateMachine_Init() },\
    .DeepHistoryPseudostate0 = STATE_UNDEF,\
    .CarOnRgn1Hsm = { HdStateMachine_Init() },\
    .CarOnRgn2Hsm = { HdStateMachine_Init() },\
    .MainBatteryHsm = SharedStm_Init(),\
    .CarOnRgn3Hsm = { HdStateMachine_Init() },\
    .AdaptiveSystemRgn1Hsm = { HdStateMachine_Init() },\
}

/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .x0 = 0,\
    .mainStm = MainStm_Init(),\

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
    MainStm mainStm;                                            

    CarBody_CLASS    
};
#endif//__CarBody_INTERNAL__
