#ifndef __CarBody_H__
#define __CarBody_H__
#include "ImgSprite.h"
typedef struct tagCarBody CarBody;
typedef enum tagAnEnum {
    One,                                                        
    Two,                                                        
    Three,                                                      
    AnEnum_NUM
}AnEnum;
const TCHAR* AnEnum_toString( AnEnum value );
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
    CarBody_EVENT_NUM
}CarBody_EVENT;
const TCHAR* CarBodyEvent_toString( CarBody_EVENT value );
#endif//__CarBody_H__
#if !defined( CarBody_Init ) && ( defined( __CarBody_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class Shared2_Region1
 * @extends HdStateMachine
 */
typedef struct tagShared2_Region1 {
    HdStateMachine base;
#define Shared2_Region1_Shared2_Dmy             ( 1ULL <<  0 )
#define Shared2_Region1_Shared2                 ( Shared2_Region1_Shared2_Dmy | Shared2_Region1_State22 | Shared2_Region1_InitialPseudostate1 )
#define Shared2_Region1_State22                 ( 1ULL <<  1 )
#define Shared2_Region1_InitialPseudostate1     ( 1ULL <<  2 )
}Shared2_Region1;
BOOL Shared2_Region1_Reset( CarBody* pShared2, Shared2_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define Shared2_Region1_Init() {\
    .base = { HdStateMachine_Init( Shared2_Region1_Shared2, Shared2_Region1_Shared2 ) },\
}
/** @class SharedStm
 * @extends HdStateMachine
 */
typedef struct tagSharedStm {
    HdStateMachine base;
    Shared2_Region1 Shared2Shared2_Region1;                     
#define SharedStm_SharedTop_Dmy                 ( 1ULL <<  3 )
#define SharedStm_SharedTop                     ( SharedStm_SharedTop_Dmy | SharedStm_Entry1 | SharedStm_InitPt | SharedStm_Shared1 | SharedStm_Shared2 )
#define SharedStm_Entry1                        ( 1ULL <<  4 )
#define SharedStm_Exit1                         ( 1ULL <<  5 )
#define SharedStm_InitPt                        ( 1ULL <<  6 )
#define SharedStm_Shared1                       ( 1ULL <<  7 )
#define SharedStm_SHared21                      ( 1ULL <<  8 )
#define SharedStm_InitialPseudostate0           ( 1ULL <<  9 )
#define SharedStm_Shared2_Dmy                   ( 1ULL << 10 )
#define SharedStm_Shared2                       ( SharedStm_Shared2_Dmy | SharedStm_SHared21 | SharedStm_InitialPseudostate0 )
}SharedStm;
BOOL SharedStm_Reset( CarBody* pSharedTop, SharedStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define SharedStm_Init() {\
    .base = { HdStateMachine_Init( SharedStm_SharedTop, SharedStm_SharedTop ) },\
    .Shared2Shared2_Region1 = Shared2_Region1_Init(),\
}
/** @class S8_Region1
 * @extends HdStateMachine
 */
typedef struct tagS8_Region1 {
    HdStateMachine base;
#define S8_Region1_S8_Dmy                       ( 1ULL << 11 )
#define S8_Region1_S8                           ( S8_Region1_S8_Dmy | S8_Region1_S82Init | S8_Region1_S821 | S8_Region1_S822 )
#define S8_Region1_S82Init                      ( 1ULL << 12 )
#define S8_Region1_S821                         ( 1ULL << 13 )
#define S8_Region1_S822                         ( 1ULL << 14 )
}S8_Region1;
BOOL S8_Region1_Reset( CarBody* pS8, S8_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define S8_Region1_Init() {\
    .base = { HdStateMachine_Init( S8_Region1_S8, S8_Region1_S8 ) },\
}
/** @class S832_Region1
 * @extends HdStateMachine
 */
typedef struct tagS832_Region1 {
    HdStateMachine base;
#define S832_Region1_S832_Dmy                   ( 1ULL << 15 )
#define S832_Region1_S832                       ( S832_Region1_S832_Dmy | S832_Region1_S8322 | S832_Region1_InitialPseudostate1 )
#define S832_Region1_S8322                      ( 1ULL << 16 )
#define S832_Region1_InitialPseudostate1        ( 1ULL << 17 )
}S832_Region1;
BOOL S832_Region1_Reset( CarBody* pS832, S832_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define S832_Region1_Init() {\
    .base = { HdStateMachine_Init( S832_Region1_S832, S832_Region1_S832 ) },\
}
/** @class S8_Region2
 * @extends HdStateMachine
 */
typedef struct tagS8_Region2 {
    HdStateMachine base;
    S832_Region1 S832S832_Region1;                              
#define S8_Region2_S8_Dmy                       ( 1ULL << 18 )
#define S8_Region2_S8                           ( S8_Region2_S8_Dmy | S8_Region2_S83Init | S8_Region2_S831 | S8_Region2_S832 )
#define S8_Region2_S83Init                      ( 1ULL << 19 )
#define S8_Region2_S831                         ( 1ULL << 20 )
#define S8_Region2_S8321                        ( 1ULL << 21 )
#define S8_Region2_InitialPseudostate0          ( 1ULL << 22 )
#define S8_Region2_S832_Dmy                     ( 1ULL << 23 )
#define S8_Region2_S832                         ( S8_Region2_S832_Dmy | S8_Region2_S8321 | S8_Region2_InitialPseudostate0 )
}S8_Region2;
BOOL S8_Region2_Reset( CarBody* pS8, S8_Region2* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define S8_Region2_Init() {\
    .base = { HdStateMachine_Init( S8_Region2_S8, S8_Region2_S8 ) },\
    .S832S832_Region1 = S832_Region1_Init(),\
}
/** @class S71_Region1
 * @extends HdStateMachine
 */
typedef struct tagS71_Region1 {
    HdStateMachine base;
#define S71_Region1_S71_Dmy                     ( 1ULL << 24 )
#define S71_Region1_S71                         ( S71_Region1_S71_Dmy | S71_Region1_S722 | S71_Region1_S721 | S71_Region1_S72Init )
#define S71_Region1_S722                        ( 1ULL << 25 )
#define S71_Region1_S721                        ( 1ULL << 26 )
#define S71_Region1_S72Init                     ( 1ULL << 27 )
}S71_Region1;
BOOL S71_Region1_Reset( CarBody* pS71, S71_Region1* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define S71_Region1_Init() {\
    .base = { HdStateMachine_Init( S71_Region1_S71, S71_Region1_S71 ) },\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    SharedStm S6SharedStm;                                      
    S8_Region1 S8S8_Region1;                                    
    S8_Region2 S8S8_Region2;                                    
    S71_Region1 S71S71_Region1;                                 
    SharedStm S9SharedStm;                                      
    uint64_t nS4History;
    uint64_t nS7History;
#define MainStm_MainTop_0_Dmy                   ( 1ULL << 28 )
#define MainStm_MainTop_0                       ( MainStm_MainTop_0_Dmy | MainStm_MainStmInit | MainStm_S1 | MainStm_S2 | MainStm_S3 | MainStm_S4 | MainStm_Junction | MainStm_S6 | MainStm_S8 | MainStm_S7 | MainStm_S10 | MainStm_S5 | MainStm_S9 )
#define MainStm_MainStmInit                     ( 1ULL << 29 )
#define MainStm_S1                              ( 1ULL << 30 )
#define MainStm_S2Init                          ( 1ULL << 31 )
#define MainStm_S22                             ( 1ULL << 32 )
#define MainStm_S21                             ( 1ULL << 33 )
#define MainStm_S3                              ( 1ULL << 34 )
#define MainStm_S4Init                          ( 1ULL << 35 )
#define MainStm_S42                             ( 1ULL << 36 )
#define MainStm_S41                             ( 1ULL << 37 )
#define MainStm_Junction                        ( 1ULL << 38 )
#define MainStm_S6                              ( 1ULL << 39 )
#define MainStm_S812                            ( 1ULL << 40 )
#define MainStm_S813                            ( 1ULL << 41 )
#define MainStm_S811                            ( 1ULL << 42 )
#define MainStm_S8Init                          ( 1ULL << 43 )
#define MainStm_S72                             ( 1ULL << 44 )
#define MainStm_S711                            ( 1ULL << 45 )
#define MainStm_S712                            ( 1ULL << 46 )
#define MainStm_S71Init                         ( 1ULL << 47 )
#define MainStm_S7Init                          ( 1ULL << 48 )
#define MainStm_S10                             ( 1ULL << 49 )
#define MainStm_S5                              ( 1ULL << 50 )
#define MainStm_S9                              ( 1ULL << 51 )
#define MainStm_S2_Dmy                          ( 1ULL << 52 )
#define MainStm_S2                              ( MainStm_S2_Dmy | MainStm_S2Init | MainStm_S22 | MainStm_S21 )
#define MainStm_S4_Dmy                          ( 1ULL << 53 )
#define MainStm_S4                              ( MainStm_S4_Dmy | MainStm_S4Init | MainStm_S42 | MainStm_S41 )
#define MainStm_S8_Dmy                          ( 1ULL << 54 )
#define MainStm_S8                              ( MainStm_S8_Dmy | MainStm_S812 | MainStm_S813 | MainStm_S811 | MainStm_S8Init )
#define MainStm_S71_Dmy                         ( 1ULL << 55 )
#define MainStm_S71                             ( MainStm_S71_Dmy | MainStm_S711 | MainStm_S712 | MainStm_S71Init )
#define MainStm_S7_Dmy                          ( 1ULL << 56 )
#define MainStm_S7                              ( MainStm_S7_Dmy | MainStm_S72 | MainStm_S71 | MainStm_S7Init )
}MainStm;
BOOL MainStm_Reset( CarBody* pMainTop_0, MainStm* pStm, HdStateMachine* pParentStm, uint64_t nEntryPoint );
#define MainStm_Init() {\
    .base = { HdStateMachine_Init( MainStm_MainTop_0, MainStm_MainTop_0 ) },\
    .S6SharedStm = SharedStm_Init(),\
    .S8S8_Region1 = S8_Region1_Init(),\
    .S8S8_Region2 = S8_Region2_Init(),\
    .S71S71_Region1 = S71_Region1_Init(),\
    .S9SharedStm = SharedStm_Init(),\
}
BOOL CarBody_EventProc( CarBody* pCarBody, CarBody_EVENT nEventId, void* pEventParams );
BOOL CarBody_Start( CarBody* pCarBody );
BOOL CarBody_Reset( CarBody* pCarBody, uint64_t nEntryPoint );
BOOL CarBody_IsIn( CarBody* pCarBody, uint64_t nState );
/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .x = 0,\
    .mainStm = MainStm_Init(),\

#define CarBody_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( CarBody ){ \
    CarBody_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* CarBody_Copy( CarBody* pCarBody, const CarBody* pSource );
/** @class CarBody
 * @extends ImgSprite
 */
struct tagCarBody{
#define CarBody_CLASS                                                                           \
    ImgSprite_CLASS                                                                             \
    int x;                                                                                                                              \
    MainStm mainStm;                                            

    CarBody_CLASS    
};
#endif//__CarBody_INTERNAL__
