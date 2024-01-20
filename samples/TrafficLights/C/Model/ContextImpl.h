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
    ContextImpl_TMOUT,                                          
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
/** @class ManagingThroughTraffic_Region1
 * @extends HdStateMachine
 */
typedef struct tagManagingThroughTraffic_Region1 {
    HdStateMachine base;
#define ManagingThroughTraffic_Region1_ManagingThroughTraffic_Rgn1_Dmy ( 1ULL <<  0 )
#define ManagingThroughTraffic_Region1_ManagingThroughTraffic_Rgn1 ( ManagingThroughTraffic_Region1_ManagingThroughTraffic_Rgn1_Dmy | ManagingThroughTraffic_Region1_SGreen | ManagingThroughTraffic_Region1_SYellow | ManagingThroughTraffic_Region1_PRedWait | ManagingThroughTraffic_Region1_SRed | ManagingThroughTraffic_Region1_PRedWaitFin )
#define ManagingThroughTraffic_Region1_SGreen   ( 1ULL <<  1 )
#define ManagingThroughTraffic_Region1_SYellow  ( 1ULL <<  2 )
#define ManagingThroughTraffic_Region1_PRedWait ( 1ULL <<  3 )
#define ManagingThroughTraffic_Region1_SRed     ( 1ULL <<  4 )
#define ManagingThroughTraffic_Region1_InitialPseudostate2 ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define ManagingThroughTraffic_Region1_PRedWaitFin ( 1ULL <<  5 )
}ManagingThroughTraffic_Region1;
#define ManagingThroughTraffic_Region1_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(ManagingThroughTraffic_Region1_ManagingThroughTraffic_Rgn1, ManagingThroughTraffic_Region1_ManagingThroughTraffic_Rgn1), ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    ManagingThroughTraffic_Region1 ManagingThroughTraffic_Rgn1ManagingThroughTraffic_Region1;
#define MainStm_MainTop_Dmy                     ( 1ULL <<  6 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_Starting | MainStm_ManagingThroughTraffic )
#define MainStm_InitialPseudostate0             ( 1ULL << ( MAX_STATE_NUM -  0 ) )
#define MainStm_Starting                        ( 1ULL <<  7 )
#define MainStm_InitialPseudostate1             ( 1ULL << ( MAX_STATE_NUM -  1 ) )
#define MainStm_PRed                            ( 1ULL <<  8 )
#define MainStm_PGreen                          ( 1ULL <<  9 )
#define MainStm_PYellow                         ( 1ULL << 10 )
#define MainStm_SRedWait                        ( 1ULL << 11 )
#define MainStm_ManagingThroughTraffic_Dmy      ( 1ULL << 12 )
#define MainStm_ManagingThroughTraffic          ( MainStm_ManagingThroughTraffic_Dmy | MainStm_PRed | MainStm_PGreen | MainStm_PYellow | MainStm_SRedWait )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( HdStateMachine_Init(MainStm_MainTop, MainStm_MainTop), ),\
    .ManagingThroughTraffic_Rgn1ManagingThroughTraffic_Region1 = ManagingThroughTraffic_Region1_Init(),\
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
