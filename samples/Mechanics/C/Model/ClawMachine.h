#ifndef __ClawMachine_H__
#define __ClawMachine_H__
typedef struct tagClawMachine ClawMachine;
typedef enum tagClawMachineEvent {
    ClawMachine_ClawBtnPressed,                                 
    ClawMachine_LeftBtnDown,                                    
    ClawMachine_LeftBtnUp,                                      
    ClawMachine_RightBtnDown,                                   
    ClawMachine_RightBtnUp,                                     
    ClawMachine_Trigger,                                        
    ClawMachine_EVENT_NUM
}ClawMachine_EVENT;
const TCHAR* ClawMachineEvent_toString( ClawMachine_EVENT value );
#endif//__ClawMachine_H__
#if !defined( ClawMachine_Init ) && ( defined( __ClawMachine_INTERNAL__ )  )
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class ClawMachineStm
 * @extends HdStateMachine
 */
typedef struct tagClawMachineStm {
    HdStateMachine base;
#define ClawMachineStm_ClawMachineTop_Dmy       ( 1ULL <<  0 )
#define ClawMachineStm_ClawMachineTop           ( ClawMachineStm_ClawMachineTop_Dmy | ClawMachineStm_InitialPseudostate0 | ClawMachineStm_Ready | ClawMachineStm_GoingLeft | ClawMachineStm_GoingRight | ClawMachineStm_JunctionPoint0 | ClawMachineStm_GoingDown | ClawMachineStm_Clawing | ClawMachineStm_GoingUp | ClawMachineStm_GoingToGate | ClawMachineStm_GoingHome )
#define ClawMachineStm_InitialPseudostate0      ( 1ULL <<  1 )
#define ClawMachineStm_Ready                    ( 1ULL <<  2 )
#define ClawMachineStm_GoingLeft                ( 1ULL <<  3 )
#define ClawMachineStm_GoingRight               ( 1ULL <<  4 )
#define ClawMachineStm_JunctionPoint0           ( 1ULL <<  5 )
#define ClawMachineStm_GoingDown                ( 1ULL <<  6 )
#define ClawMachineStm_Clawing                  ( 1ULL <<  7 )
#define ClawMachineStm_GoingUp                  ( 1ULL <<  8 )
#define ClawMachineStm_GoingToGate              ( 1ULL <<  9 )
#define ClawMachineStm_GoingHome                ( 1ULL << 10 )
}ClawMachineStm;
#define ClawMachineStm_Init() {\
    .base = { HdStateMachine_Init( ClawMachineStm_ClawMachineTop, ClawMachineStm_ClawMachineTop ) },\
}
BOOL ClawMachine_EventProc( ClawMachine* pClawMachine, ClawMachine_EVENT nEventId, void* pEventParams );
BOOL ClawMachine_Start( ClawMachine* pClawMachine );
BOOL ClawMachine_Reset( ClawMachine* pClawMachine, uint64_t nEntryPoint );
BOOL ClawMachine_IsIn( ClawMachine* pClawMachine, uint64_t nState );
/** @memberof ClawMachine
 * @brief ClawMachine auto-generated constructor
 */
#define ClawMachine_Init()\
    .mainStm = ClawMachineStm_Init(),\

#define ClawMachine_Ctor(  )    ( ClawMachine ){ \
    ClawMachine_Init(  ) \
}
ClawMachine* ClawMachine_Copy( ClawMachine* pClawMachine, const ClawMachine* pSource );
/** @class ClawMachine
 * @extends 
 */
#define ClawMachine_CLASS                                                                       \
    size_t cbSize;                                                                              \
    ClawMachineStm mainStm;                                     

typedef struct tagClawMachine{
    ClawMachine_CLASS    
}ClawMachine;
#endif//__ClawMachine_INTERNAL__
