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
#define SharedTop_State22                       ( 1ULL <<  0 )
#define SharedTop_InitialPseudostate1           ( 1ULL <<  1 )
#define SharedTop_Shared2Rgn1                   ( SharedTop_State22 | SharedTop_InitialPseudostate1 )
#define SharedTop_Entry1                        ( 1ULL <<  0 )
#define SharedTop_Exit1                         ( 1ULL <<  1 )
#define SharedTop_InitPt                        ( 1ULL <<  2 )
#define SharedTop_Shared1                       ( 1ULL <<  3 )
#define SharedTop_SHared21                      ( 1ULL <<  4 )
#define SharedTop_InitialPseudostate0           ( 1ULL <<  5 )
#define SharedTop_Shared2                       ( SharedTop_SHared21 | SharedTop_InitialPseudostate0 )
#define SharedTop_SharedStm                     ( SharedTop_Entry1 | SharedTop_Exit1 | SharedTop_InitPt | SharedTop_Shared1 | SharedTop_Shared2 )
    HdStateMachine SharedStmHsm;                                
    HdStateMachine Shared2Rgn1Hsm;                              
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}SharedTop;
#define SharedTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .SharedStmHsm = { HdStateMachine_Init() },\
    .Shared2Rgn1Hsm = { HdStateMachine_Init() },\
}
/** @class MainTop
 * @extends HdStateMachine
 */
typedef struct tagMainTop {
#define MainTop_S82Init                         ( 1ULL <<  0 )
#define MainTop_S821                            ( 1ULL <<  1 )
#define MainTop_S822                            ( 1ULL <<  2 )
#define MainTop_S8Rgn1                          ( MainTop_S82Init | MainTop_S821 | MainTop_S822 )
#define MainTop_S8322                           ( 1ULL <<  0 )
#define MainTop_InitialPseudostate1             ( 1ULL <<  1 )
#define MainTop_S832Rgn1                        ( MainTop_S8322 | MainTop_InitialPseudostate1 )
#define MainTop_S83Init                         ( 1ULL <<  0 )
#define MainTop_S831                            ( 1ULL <<  1 )
#define MainTop_S8321                           ( 1ULL <<  2 )
#define MainTop_InitialPseudostate0             ( 1ULL <<  3 )
#define MainTop_S832                            ( MainTop_S8321 | MainTop_InitialPseudostate0 )
#define MainTop_S8Rgn2                          ( MainTop_S83Init | MainTop_S831 | MainTop_S832 )
#define MainTop_S722                            ( 1ULL <<  0 )
#define MainTop_S721                            ( 1ULL <<  1 )
#define MainTop_S72Init                         ( 1ULL <<  2 )
#define MainTop_S71Rgn1                         ( MainTop_S722 | MainTop_S721 | MainTop_S72Init )
#define MainTop_MainStmInit                     ( 1ULL <<  0 )
#define MainTop_S1                              ( 1ULL <<  1 )
#define MainTop_S2Init                          ( 1ULL <<  2 )
#define MainTop_S22                             ( 1ULL <<  3 )
#define MainTop_S21                             ( 1ULL <<  4 )
#define MainTop_S2                              ( MainTop_S2Init | MainTop_S22 | MainTop_S21 )
#define MainTop_S3                              ( 1ULL <<  5 )
#define MainTop_S4Init                          ( 1ULL <<  6 )
#define MainTop_S42                             ( 1ULL <<  7 )
#define MainTop_S41                             ( 1ULL <<  8 )
#define MainTop_S4                              ( MainTop_S4Init | MainTop_S42 | MainTop_S41 )
#define MainTop_S6                              ( 1ULL <<  9 )
#define MainTop_S812                            ( 1ULL << 10 )
#define MainTop_S813                            ( 1ULL << 11 )
#define MainTop_S811                            ( 1ULL << 12 )
#define MainTop_S8Init                          ( 1ULL << 13 )
#define MainTop_S8                              ( MainTop_S812 | MainTop_S813 | MainTop_S811 | MainTop_S8Init )
#define MainTop_S72                             ( 1ULL << 14 )
#define MainTop_S711                            ( 1ULL << 15 )
#define MainTop_S712                            ( 1ULL << 16 )
#define MainTop_S71Init                         ( 1ULL << 17 )
#define MainTop_S71                             ( MainTop_S711 | MainTop_S712 | MainTop_S71Init )
#define MainTop_S7Init                          ( 1ULL << 18 )
#define MainTop_S7                              ( MainTop_S72 | MainTop_S71 | MainTop_S7Init )
#define MainTop_S101                            ( 1ULL << 19 )
#define MainTop_S102                            ( 1ULL << 20 )
#define MainTop_S10                             ( MainTop_S101 | MainTop_S102 )
#define MainTop_S5                              ( 1ULL << 21 )
#define MainTop_S9                              ( 1ULL << 22 )
#define MainTop_MainStm                         ( MainTop_MainStmInit | MainTop_S1 | MainTop_S2 | MainTop_S3 | MainTop_S4 | MainTop_S6 | MainTop_S8 | MainTop_S7 | MainTop_S10 | MainTop_S5 | MainTop_S9 )
    HdStateMachine MainStmHsm;                                  
    uint64_t ShallowHistoryPseudostate0;
    SharedTop S6Hsm;                                            
    HdStateMachine S8Rgn1Hsm;                                   
    HdStateMachine S8Rgn2Hsm;                                   
    HdStateMachine S832Rgn1Hsm;                                 
    HdStateMachine S71Rgn1Hsm;                                  
    uint64_t Deephistorypseudostate0;
    uint64_t ShallowHistoryPseudostate1;
    SharedTop S9Hsm;                                            
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}MainTop;
#define MainTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .MainStmHsm = { HdStateMachine_Init() },\
    .ShallowHistoryPseudostate0 = STATE_UNDEF,\
    .S6Hsm = SharedTop_Init(),\
    .S8Rgn1Hsm = { HdStateMachine_Init() },\
    .S8Rgn2Hsm = { HdStateMachine_Init() },\
    .S832Rgn1Hsm = { HdStateMachine_Init() },\
    .S71Rgn1Hsm = { HdStateMachine_Init() },\
    .Deephistorypseudostate0 = STATE_UNDEF,\
    .ShallowHistoryPseudostate1 = STATE_UNDEF,\
    .S9Hsm = SharedTop_Init(),\
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
