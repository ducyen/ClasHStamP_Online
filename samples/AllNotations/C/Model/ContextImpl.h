#ifndef __ContextImpl_H__
#define __ContextImpl_H__
#include "Context.h"
typedef struct tagContextImpl ContextImpl;
typedef enum tagAnEnum {
    One,                                                        
    Two,                                                        
    Three,                                                      
    AnEnum_NUM
}AnEnum;
const TCHAR* AnEnum_toString( AnEnum value );
typedef struct tagE1Params {
    EventParams base;
    AnEnum x;                                                   
}E1Params;
typedef enum tagContextImplEvent {
    ContextImpl_E0,                                             
    ContextImpl_E1,                                             
    ContextImpl_E2,                                             
    ContextImpl_E3,                                             
    ContextImpl_E4,                                             
    ContextImpl_E5,                                             
    ContextImpl_EVENT_NUM
}ContextImpl_EVENT;
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value );
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __AFriend_INTERNAL__ )  || defined( __Main_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
boolean ContextImpl_checkE1Params( EventParams* e );
/** @class S8_Region1
 * @extends HdStateMachine
 */
typedef struct tagS8_Region1 {
    HdStateMachine base;
#define S8_Region1_S8_Top_Dmy                   ( 1ULL <<  0 )
#define S8_Region1_S8_Top                       ( S8_Region1_S8_Top_Dmy | S8_Region1_S821 | S8_Region1_S822 )
#define S8_Region1_InitialPseudostate0          ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define S8_Region1_S821                         ( 1ULL <<  1 )
#define S8_Region1_S822                         ( 1ULL <<  2 )
}S8_Region1;
#define S8_Region1_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S8_Region1_S8_Top, S8_Region1_S8_Top), ),\
}
/** @class S8_Region2
 * @extends HdStateMachine
 */
typedef struct tagS8_Region2 {
    HdStateMachine base;
#define S8_Region2_S8_Top_Dmy                   ( 1ULL <<  3 )
#define S8_Region2_S8_Top                       ( S8_Region2_S8_Top_Dmy | S8_Region2_S831 | S8_Region2_S832 )
#define S8_Region2_ForkPseudostate2             ( 1ULL <<  4 )
#define S8_Region2_InitialPseudostate1          ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define S8_Region2_S831                         ( 1ULL <<  5 )
#define S8_Region2_S832                         ( 1ULL <<  6 )
}S8_Region2;
#define S8_Region2_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(S8_Region2_S8_Top, S8_Region2_S8_Top), ),\
}
/** @class SharedStm
 * @extends HdStateMachine
 */
typedef struct tagSharedStm {
    HdStateMachine base;
#define SharedStm_SharedTop_Dmy                 ( 1ULL <<  7 )
#define SharedStm_SharedTop                     ( SharedStm_SharedTop_Dmy | SharedStm_Shared1 | SharedStm_Shared2 )
#define SharedStm_Entry1                        ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define SharedStm_Exit1                         ( 1ULL << ( MAX_STATE_NUM -  1 ) )
#define SharedStm_InitPt                        ( 1ULL << ( MAX_STATE_NUM -  2 ) )
#define SharedStm_Shared1                       ( 1ULL <<  8 )
#define SharedStm_Shared2                       ( 1ULL <<  9 )
}SharedStm;
#define SharedStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(SharedStm_SharedTop, SharedStm_SharedTop), ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    SharedStm S6SharedStm;                                      
    S8_Region1 S8_TopS8_Region1;                                
    S8_Region2 S8_TopS8_Region2;                                
    SharedStm S9SharedStm;                                      
    uint64_t nS4History;
    uint64_t nS7History;
#define MainStm_MainTop_Dmy                     ( 1ULL << 10 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_S1 | MainStm_S2 | MainStm_S3 | MainStm_S4 | MainStm_Junction | MainStm_S6 | MainStm_S8 | MainStm_S7 | MainStm_S10 | MainStm_S5 | MainStm_S9 )
#define MainStm_InitPt                          ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define MainStm_S1                              ( 1ULL << 11 )
#define MainStm_S22                             ( 1ULL << 12 )
#define MainStm_S21                             ( 1ULL << 13 )
#define MainStm_S3                              ( 1ULL << 14 )
#define MainStm_S42                             ( 1ULL << 15 )
#define MainStm_S41                             ( 1ULL << 16 )
#define MainStm_Junction                        ( 1ULL << 17 )
#define MainStm_S6                              ( 1ULL << 18 )
#define MainStm_S812                            ( 1ULL << 19 )
#define MainStm_S813                            ( 1ULL << 20 )
#define MainStm_S811                            ( 1ULL << 21 )
#define MainStm_S72                             ( 1ULL << 22 )
#define MainStm_S711                            ( 1ULL << 23 )
#define MainStm_S712                            ( 1ULL << 24 )
#define MainStm_Initpseudostate0                ( 1ULL << ( MAX_STATE_NUM -  1 ) )
#define MainStm_S10                             ( 1ULL << 25 )
#define MainStm_S5                              ( 1ULL << 26 )
#define MainStm_S9                              ( 1ULL << 27 )
#define MainStm_S2_Dmy                          ( 1ULL << 28 )
#define MainStm_S2                              ( MainStm_S2_Dmy | MainStm_S22 | MainStm_S21 )
#define MainStm_S4_Dmy                          ( 1ULL << 29 )
#define MainStm_S4                              ( MainStm_S4_Dmy | MainStm_S42 | MainStm_S41 )
#define MainStm_S8_Dmy                          ( 1ULL << 30 )
#define MainStm_S8                              ( MainStm_S8_Dmy | MainStm_S812 | MainStm_S813 | MainStm_S811 )
#define MainStm_S71_Dmy                         ( 1ULL << 31 )
#define MainStm_S71                             ( MainStm_S71_Dmy | MainStm_S711 | MainStm_S712 )
#define MainStm_S7_Dmy                          ( 1ULL << 32 )
#define MainStm_S7                              ( MainStm_S7_Dmy | MainStm_S72 | MainStm_S71 )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(MainStm_MainTop, MainStm_MainTop), ),\
    .S6SharedStm = SharedStm_Init(),\
    .S8_TopS8_Region1 = S8_Region1_Init(),\
    .S8_TopS8_Region2 = S8_Region2_Init(),\
    .S9SharedStm = SharedStm_Init(),\
}
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams );
BOOL ContextImpl_Start( ContextImpl* pContextImpl );
/** @memberof ContextImpl
 * @brief ContextImpl auto-generated constructor
 */
#define ContextImpl_Init(_derivableAttribute, _publicAttribute, _privateAttribute, _internalAttribute, _readOnlyAttribute, _anAggregation, _aProtectedComposition)\
    Context_Init( P( _derivableAttribute ), P( _publicAttribute ), P( _privateAttribute ), P( _internalAttribute ), P( _readOnlyAttribute ), P( _anAggregation ), P( _aProtectedComposition ) )\
    .vTbl = &gContextImplVtbl,\
    .mainStm = MainStm_Init(),\

#define ContextImpl_Ctor( InitFunc, optionParams )    ( ContextImpl ){\
    InitFunc\
\
}
extern const BaseClassVtbl gContextImplVtbl;
Context* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource );
/** @class ContextImpl
 * @extends Context
 */
#define ContextImpl_CLASS                                                                       \
    Context_CLASS                                                                               \
    MainStm mainStm;                                            

typedef struct tagContextImpl{
    ContextImpl_CLASS    
}ContextImpl;
#endif//__ContextImpl_INTERNAL__
