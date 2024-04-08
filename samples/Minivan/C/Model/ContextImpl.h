#ifndef __ContextImpl_H__
#define __ContextImpl_H__
typedef struct tagContextImpl ContextImpl;
typedef struct tagE1Params {
    EventParams base;
    int x;                                                      
}E1Params;
typedef enum tagContextImplEvent {
    ContextImpl_E_PWR_OFF,                                      
    ContextImpl_E_PWR_ON,                                       
    ContextImpl_EVENT_NUM
}ContextImpl_EVENT;
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value );
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
#define MainStm_MainTop_Dmy                     ( 1ULL <<  0 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_InitialPseudostate0 | MainStm_PowerOff | MainStm_PowerOn )
#define MainStm_InitialPseudostate0             ( 1ULL <<  1 )
#define MainStm_PowerOff                        ( 1ULL <<  2 )
#define MainStm_PowerOn                         ( 1ULL <<  3 )
}MainStm;
#define MainStm_Init() {\
    .base = { HdStateMachine_Init( MainStm_MainTop, MainStm_MainTop ) },\
}
BOOL ContextImpl_EventProc( ContextImpl* pContextImpl, ContextImpl_EVENT nEventId, void* pEventParams );
BOOL ContextImpl_Start( ContextImpl* pContextImpl );
/** @memberof ContextImpl
 * @brief ContextImpl auto-generated constructor
 */
#define ContextImpl_Init()\
    .mainStm = MainStm_Init(),\

#define ContextImpl_Ctor(  )    ( ContextImpl ){ \
    ContextImpl_Init(  ) \
}
ContextImpl* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource );
/** @class ContextImpl
 * @extends 
 */
#define ContextImpl_CLASS                                                                       \
    size_t cbSize;                                                                              \
    MainStm mainStm;                                            

typedef struct tagContextImpl{
    ContextImpl_CLASS    
}ContextImpl;
#endif//__ContextImpl_INTERNAL__
