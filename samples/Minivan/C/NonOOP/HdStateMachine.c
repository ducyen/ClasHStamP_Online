/* File generated by Đức's ClasHStamP */
#define __HdStateMachine_INTERNAL__
#include "CommonInclude.h"
#include "HdStateMachine.h"
/** @public @memberof HdStateMachine */
int HdStateMachine_Enterable(
    HdStateMachine* pHdStateMachine,
    uint64_t nThisState
){
    BOOL isThisLCA = IS_IN( pHdStateMachine->nLCAState, nThisState );
    if( !isThisLCA || pHdStateMachine->nLCAState == STATE_UNDEF ){
        return TRUE;
    }
    return FALSE;
} /* HdStateMachine_Enterable */

/** @public @memberof HdStateMachine */
int HdStateMachine_Exitable(
    HdStateMachine* pHdStateMachine,
    uint64_t nThisState
){
    BOOL isThisLCA = IS_IN( pHdStateMachine->nSourceState, nThisState ) && IS_IN( pHdStateMachine->nTargetState, nThisState );
    if( !isThisLCA || pHdStateMachine->bIsExternTrans ){ 
        pHdStateMachine->bIsExternTrans &= !isThisLCA;
        return TRUE;
    } else { 
        pHdStateMachine->nLCAState = nThisState;
    }
    return FALSE;
} /* HdStateMachine_Exitable */

HdStateMachine* HdStateMachine_Copy( HdStateMachine* pHdStateMachine, const HdStateMachine* pSource ){
    pHdStateMachine->pParentStm = pSource->pParentStm;
    pHdStateMachine->nCurrentState = pSource->nCurrentState;
    pHdStateMachine->nLCAState = pSource->nLCAState;
    pHdStateMachine->nTargetState = pSource->nTargetState;
    pHdStateMachine->nSourceState = pSource->nSourceState;
    pHdStateMachine->nPseudostate = pSource->nPseudostate;
    pHdStateMachine->bIsExternTrans = pSource->bIsExternTrans;
    return ( HdStateMachine* )pHdStateMachine;
}