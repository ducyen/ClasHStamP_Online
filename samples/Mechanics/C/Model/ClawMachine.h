#ifndef __ClawMachine_H__
#define __ClawMachine_H__
#include "Sprite.h"
typedef struct tagClawMachine ClawMachine;
typedef enum tagClawMachineEvent {
    ClawMachine_ClawBtnPressed,                                 
    ClawMachine_LeftBtnDown,                                    
    ClawMachine_LeftBtnUp,                                      
    ClawMachine_RightBtnDown,                                   
    ClawMachine_RightBtnUp,                                     
    ClawMachine_TICK,                                           
    ClawMachine_EVENT_NUM
}ClawMachine_EVENT;
const TCHAR* ClawMachineEvent_toString( ClawMachine_EVENT value );
#endif//__ClawMachine_H__
#if !defined( ClawMachine_Init ) && ( defined( __ClawMachine_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class State0_Region1
 * @extends HdStateMachine
 */
typedef struct tagState0_Region1 {
    HdStateMachine base;
#define State0_Region1_State0_Dmy               ( 1ULL <<  0 )
#define State0_Region1_State0                   ( State0_Region1_State0_Dmy | State0_Region1_State0_Regtion1_Init | State0_Region1_CoutingDown )
#define State0_Region1_State0_Regtion1_Init     ( 1ULL <<  1 )
#define State0_Region1_CoutingDown              ( 1ULL <<  2 )
}State0_Region1;
#define State0_Region1_Init() {\
    .base = { HdStateMachine_Init( State0_Region1_State0, State0_Region1_State0 ) },\
}
/** @class ClawMachineStm
 * @extends HdStateMachine
 */
typedef struct tagClawMachineStm {
    HdStateMachine base;
    State0_Region1 State0State0_Region1;                        
#define ClawMachineStm_ClawMachineTop_Dmy       ( 1ULL <<  3 )
#define ClawMachineStm_ClawMachineTop           ( ClawMachineStm_ClawMachineTop_Dmy | ClawMachineStm_InitialPseudostate0 | ClawMachineStm_GoingDown | ClawMachineStm_Clawing | ClawMachineStm_GoingUp | ClawMachineStm_GoingToGate | ClawMachineStm_GoingHome | ClawMachineStm_Releasing | ClawMachineStm_State0 )
#define ClawMachineStm_InitialPseudostate0      ( 1ULL <<  4 )
#define ClawMachineStm_GoingDown                ( 1ULL <<  5 )
#define ClawMachineStm_Clawing                  ( 1ULL <<  6 )
#define ClawMachineStm_GoingUp                  ( 1ULL <<  7 )
#define ClawMachineStm_GoingToGate              ( 1ULL <<  8 )
#define ClawMachineStm_GoingHome                ( 1ULL <<  9 )
#define ClawMachineStm_Releasing                ( 1ULL << 10 )
#define ClawMachineStm_GoingLeft                ( 1ULL << 11 )
#define ClawMachineStm_Ready                    ( 1ULL << 12 )
#define ClawMachineStm_GoingRight               ( 1ULL << 13 )
#define ClawMachineStm_JunctionPoint0           ( 1ULL << 14 )
#define ClawMachineStm_State0_Init              ( 1ULL << 15 )
#define ClawMachineStm_State0_Dmy               ( 1ULL << 16 )
#define ClawMachineStm_State0                   ( ClawMachineStm_State0_Dmy | ClawMachineStm_GoingLeft | ClawMachineStm_Ready | ClawMachineStm_GoingRight | ClawMachineStm_JunctionPoint0 | ClawMachineStm_State0_Init )
}ClawMachineStm;
#define ClawMachineStm_Init() {\
    .base = { HdStateMachine_Init( ClawMachineStm_ClawMachineTop, ClawMachineStm_ClawMachineTop ) },\
    .State0State0_Region1 = State0_Region1_Init(),\
}
BOOL ClawMachine_EventProc( ClawMachine* pClawMachine, ClawMachine_EVENT nEventId, void* pEventParams );
BOOL ClawMachine_Start( ClawMachine* pClawMachine );
BOOL ClawMachine_Reset( ClawMachine* pClawMachine, uint64_t nEntryPoint );
BOOL ClawMachine_IsIn( ClawMachine* pClawMachine, uint64_t nState );
/** @memberof ClawMachine
 * @brief ClawMachine auto-generated constructor
 */
#define ClawMachine_Init(_m_iniRect, _m_name, _m_imgPath, _braking_force, _braking_decrement)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .braking_force = _braking_force,\
    .braking_decrement = _braking_decrement,\
    .arm_height = 50,\
    .playCountDown = 0,\
    .mainStm = ClawMachineStm_Init(),\

#define ClawMachine_Ctor( _m_iniRect, _m_name, _m_imgPath, _braking_force, _braking_decrement )    ( ClawMachine ){ \
    ClawMachine_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _braking_force ), P( _braking_decrement ) ) \
}
Sprite* ClawMachine_Copy( ClawMachine* pClawMachine, const ClawMachine* pSource );
/** @class ClawMachine
 * @extends Sprite
 */
#define ClawMachine_CLASS                                                                       \
    Sprite_CLASS                                                                                \
    cpFloat braking_force;                                                                                              \
    cpFloat braking_decrement;                                                                                      \
    cpFloat arm_height;                                                                                                    \
    int playCountDown;                                                                                                      \
    ClawMachineStm mainStm;                                     

typedef struct tagClawMachine{
    ClawMachine_CLASS    
}ClawMachine;
#endif//__ClawMachine_INTERNAL__
