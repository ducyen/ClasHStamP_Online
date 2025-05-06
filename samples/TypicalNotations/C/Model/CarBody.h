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
    CarBody_E10,                                                
    CarBody_E11,                                                
    CarBody_E2,                                                 
    CarBody_E3,                                                 
    CarBody_E4,                                                 
    CarBody_E5,                                                 
    CarBody_UPDATE,                                             
    CarBody_eLocal,                                             
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
#define SharedTop_InitialPseudostate2           ( 1ULL <<  0 )
#define SharedTop_State1                        ( 1ULL <<  1 )
#define SharedTop_State0                        ( 1ULL <<  2 )
#define SharedTop_EntryPt0                      ( 1ULL <<  3 )
#define SharedTop_ExitPoint0                    ( 1ULL <<  4 )
#define SharedTop_SharedStm                     ( SharedTop_InitialPseudostate2 | SharedTop_State1 | SharedTop_State0 | SharedTop_EntryPt0 | SharedTop_ExitPoint0 )
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
#define MainTop_S012                            ( 1ULL <<  0 )
#define MainTop_InitialPseudostate1             ( 1ULL <<  1 )
#define MainTop_S01Rgn1                         ( MainTop_S012 | MainTop_InitialPseudostate1 )
#define MainTop_S022                            ( 1ULL <<  0 )
#define MainTop_InitialPseudostate3             ( 1ULL <<  1 )
#define MainTop_S02Rgn1                         ( MainTop_S022 | MainTop_InitialPseudostate3 )
#define MainTop_S0_Rgn1_Init                    ( 1ULL <<  0 )
#define MainTop_S021                            ( 1ULL <<  1 )
#define MainTop_InitialPseudostate2             ( 1ULL <<  2 )
#define MainTop_S02                             ( MainTop_S021 | MainTop_InitialPseudostate2 )
#define MainTop_S04                             ( 1ULL <<  3 )
#define MainTop_S0Rgn1                          ( MainTop_S0_Rgn1_Init | MainTop_S02 | MainTop_S04 )
#define MainTop_SubmachineState0                ( 1ULL <<  0 )
#define MainTop_S0_Rgn2_Init                    ( 1ULL <<  1 )
#define MainTop_S0Rgn2                          ( MainTop_SubmachineState0 | MainTop_S0_Rgn2_Init )
#define MainTop_MainStm_Init                    ( 1ULL <<  0 )
#define MainTop_SubmachineState1                ( 1ULL <<  1 )
#define MainTop_S0_Init                         ( 1ULL <<  2 )
#define MainTop_S011                            ( 1ULL <<  3 )
#define MainTop_InitialPseudostate0             ( 1ULL <<  4 )
#define MainTop_S01                             ( MainTop_S011 | MainTop_InitialPseudostate0 )
#define MainTop_S03                             ( 1ULL <<  5 )
#define MainTop_S0                              ( MainTop_S0_Init | MainTop_S01 | MainTop_S03 )
#define MainTop_State2_Init                     ( 1ULL <<  6 )
#define MainTop_State2                          ( MainTop_S0 | MainTop_State2_Init )
#define MainTop_MainStm                         ( MainTop_MainStm_Init | MainTop_SubmachineState1 | MainTop_State2 )
    HdStateMachine MainStmHsm;                                  
    SharedTop SubmachineState1Hsm;                              
    HdStateMachine S01Rgn1Hsm;                                  
    uint64_t ShallowHistoryPseudostate0;
    HdStateMachine S0Rgn1Hsm;                                   
    HdStateMachine S02Rgn1Hsm;                                  
    uint64_t ShallowHistoryPseudostate1;
    HdStateMachine S0Rgn2Hsm;                                   
    SharedTop SubmachineState0Hsm;                              
    uint64_t DeepHistoryPseudostate0;
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}MainTop;
#define MainTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .MainStmHsm = { HdStateMachine_Init() },\
    .SubmachineState1Hsm = SharedTop_Init(),\
    .S01Rgn1Hsm = { HdStateMachine_Init() },\
    .ShallowHistoryPseudostate0 = STATE_UNDEF,\
    .S0Rgn1Hsm = { HdStateMachine_Init() },\
    .S02Rgn1Hsm = { HdStateMachine_Init() },\
    .ShallowHistoryPseudostate1 = STATE_UNDEF,\
    .S0Rgn2Hsm = { HdStateMachine_Init() },\
    .SubmachineState0Hsm = SharedTop_Init(),\
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
