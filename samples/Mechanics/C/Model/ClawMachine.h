#ifndef __ClawMachine_H__
#define __ClawMachine_H__
typedef struct tagClawMachine ClawMachine;
typedef enum tagClawMachineEvent {
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
#define ClawMachineStm_ClawMachineTop           ( ClawMachineStm_ClawMachineTop_Dmy | ClawMachineStm_InitialPseudostate0 | ClawMachineStm_State0 )
#define ClawMachineStm_InitialPseudostate0      ( 1ULL <<  1 )
#define ClawMachineStm_State0                   ( 1ULL <<  2 )
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
