#ifndef __ContextImpl_H__
#define __ContextImpl_H__
typedef struct tagContextImpl ContextImpl;
typedef struct tagE1Params {
    EventParams base;
    int x;                                                      
}E1Params;
typedef enum tagContextImplEvent {
    ContextImpl_TMOUT,                                          
    ContextImpl_TrainComeIn,                                    
    ContextImpl_TrainComeOut,                                   
    ContextImpl_EVENT_NUM
}ContextImpl_EVENT;
const TCHAR* ContextImplEvent_toString( ContextImpl_EVENT value );
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class ManagingThroughTraffic_Region1
 * @extends HdStateMachine
 */
typedef struct tagManagingThroughTraffic_Region1 {
    HdStateMachine base;
#define ManagingThroughTraffic_Region1_ManagingThroughTraffic_Top_Dmy ( 1ULL <<  0 )
#define ManagingThroughTraffic_Region1_ManagingThroughTraffic_Top ( ManagingThroughTraffic_Region1_ManagingThroughTraffic_Top_Dmy | ManagingThroughTraffic_Region1_SGreen | ManagingThroughTraffic_Region1_SYellow | ManagingThroughTraffic_Region1_ManagingThroughTrafficRegion1Init | ManagingThroughTraffic_Region1_SRedOn )
#define ManagingThroughTraffic_Region1_SGreen   ( 1ULL <<  1 )
#define ManagingThroughTraffic_Region1_SYellow  ( 1ULL <<  2 )
#define ManagingThroughTraffic_Region1_ManagingThroughTrafficRegion1Init ( 1ULL <<  3 )
#define ManagingThroughTraffic_Region1_SRed     ( 1ULL <<  4 )
#define ManagingThroughTraffic_Region1_PRedWait ( 1ULL <<  5 )
#define ManagingThroughTraffic_Region1_SRedOn_Dmy ( 1ULL <<  6 )
#define ManagingThroughTraffic_Region1_SRedOn   ( ManagingThroughTraffic_Region1_SRedOn_Dmy | ManagingThroughTraffic_Region1_SRed | ManagingThroughTraffic_Region1_PRedWait )
}ManagingThroughTraffic_Region1;
#define ManagingThroughTraffic_Region1_Init() {\
    .base = HdStateMachine_Ctor( ManagingThroughTraffic_Region1_ManagingThroughTraffic_Top, ManagingThroughTraffic_Region1_ManagingThroughTraffic_Top ),\
}
/** @class ManagingThroughTraffic_Region2
 * @extends HdStateMachine
 */
typedef struct tagManagingThroughTraffic_Region2 {
    HdStateMachine base;
#define ManagingThroughTraffic_Region2_ManagingThroughTraffic_Top_Dmy ( 1ULL <<  7 )
#define ManagingThroughTraffic_Region2_ManagingThroughTraffic_Top ( ManagingThroughTraffic_Region2_ManagingThroughTraffic_Top_Dmy | ManagingThroughTraffic_Region2_NoTrain | ManagingThroughTraffic_Region2_ManagingThroughTrafficRegion2Init | ManagingThroughTraffic_Region2_TrainCrossing )
#define ManagingThroughTraffic_Region2_NoTrain  ( 1ULL <<  8 )
#define ManagingThroughTraffic_Region2_ManagingThroughTrafficRegion2Init ( 1ULL <<  9 )
#define ManagingThroughTraffic_Region2_TrainCrossing ( 1ULL << 10 )
}ManagingThroughTraffic_Region2;
#define ManagingThroughTraffic_Region2_Init() {\
    .base = HdStateMachine_Ctor( ManagingThroughTraffic_Region2_ManagingThroughTraffic_Top, ManagingThroughTraffic_Region2_ManagingThroughTraffic_Top ),\
}
/** @class MainStm
 * @extends HdStateMachine
 */
typedef struct tagMainStm {
    HdStateMachine base;
    ManagingThroughTraffic_Region1 ManagingThroughTraffic_TopManagingThroughTraffic_Region1;
    ManagingThroughTraffic_Region2 ManagingThroughTraffic_TopManagingThroughTraffic_Region2;
#define MainStm_MainTop_Dmy                     ( 1ULL << 11 )
#define MainStm_MainTop                         ( MainStm_MainTop_Dmy | MainStm_MainStmInit | MainStm_Starting | MainStm_ManagingThroughTraffic )
#define MainStm_MainStmInit                     ( 1ULL << 12 )
#define MainStm_Starting                        ( 1ULL << 13 )
#define MainStm_PGreen1                         ( 1ULL << 14 )
#define MainStm_PGreenInit                      ( 1ULL << 15 )
#define MainStm_PYellow                         ( 1ULL << 16 )
#define MainStm_PRed                            ( 1ULL << 17 )
#define MainStm_SRedWait                        ( 1ULL << 18 )
#define MainStm_PRedOnInit                      ( 1ULL << 19 )
#define MainStm_ManagingThroughTrafficInit      ( 1ULL << 20 )
#define MainStm_PGreen_Dmy                      ( 1ULL << 21 )
#define MainStm_PGreen                          ( MainStm_PGreen_Dmy | MainStm_PGreen1 | MainStm_PGreenInit )
#define MainStm_PRedOn_Dmy                      ( 1ULL << 22 )
#define MainStm_PRedOn                          ( MainStm_PRedOn_Dmy | MainStm_PRed | MainStm_SRedWait | MainStm_PRedOnInit )
#define MainStm_ManagingThroughTraffic_Dmy      ( 1ULL << 23 )
#define MainStm_ManagingThroughTraffic          ( MainStm_ManagingThroughTraffic_Dmy | MainStm_PGreen | MainStm_PYellow | MainStm_PRedOn | MainStm_ManagingThroughTrafficInit )
}MainStm;
#define MainStm_Init() {\
    .base = HdStateMachine_Ctor( MainStm_MainTop, MainStm_MainTop ),\
    .ManagingThroughTraffic_TopManagingThroughTraffic_Region1 = ManagingThroughTraffic_Region1_Init(),\
    .ManagingThroughTraffic_TopManagingThroughTraffic_Region2 = ManagingThroughTraffic_Region2_Init(),\
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
