#ifndef __HdStateMachine_H__
#define __HdStateMachine_H__
typedef struct tagHdStateMachine HdStateMachine;
int HdStateMachine_Enterable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
int HdStateMachine_Exitable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
void HdStatemachine_DefaultEntryAction(void* pObj, void* pStm_, char* pMsg);
void HdStatemachine_DefaultDoingAction(void* pObj, void* pStm_, char* pMsg);
void HdStatemachine_DefaultExitAction(void* pObj, void* pStm_, char* pMsg);
#endif//__HdStateMachine_H__
#if !defined( HdStateMachine_Init ) && ( defined( __HdStateMachine_INTERNAL__ )  )
/** @memberof HdStateMachine
 * @brief HdStateMachine auto-generated constructor
 */
#define HdStateMachine_Init(_nCurrentState )\
    .pParentStm = NULL,\
    .nCurrentState = _nCurrentState,\
    .nLCAState = STATE_UNDEF,\
    .nTargetState = STATE_UNDEF,\
    .nSourceState = STATE_UNDEF,\
    .nPseudostate = STATE_UNDEF,\
    .bIsExternTrans = false,\
    .m_stmImage = null,\
    .m_stmRect = null,\
    .pOwner = NULL,\

#define HdStateMachine_Ctor( _nCurrentState, _nPseudostate )    ( HdStateMachine ){ \
    HdStateMachine_Init( P( _nCurrentState ), P( _nPseudostate ) ) \
}
HdStateMachine* HdStateMachine_Copy( HdStateMachine* pHdStateMachine, const HdStateMachine* pSource );
/** @class HdStateMachine
 * @extends 
 */
struct tagHdStateMachine{
#define HdStateMachine_CLASS                                                                    \
    size_t cbSize;                                                                              \
    HdStateMachine* pParentStm;                                 \
    uint64_t nCurrentState;                                                                                            \
    uint64_t nLCAState;                                                                                                    \
    uint64_t nTargetState;                                                                                              \
    uint64_t nSourceState;                                                                                              \
    uint64_t nPseudostate;                                                                                              \
    bool bIsExternTrans;                                                                                                  \
    SDL_Texture* m_stmImage;                                                                                          \
    SDL_Rect m_stmRect;                                                                                                    \
    HdStateMachine* pMain;                                     \
    BOOL lastEnteredStateRecovering;                            \
    uint64_t lastEnteredState;                                                \

    HdStateMachine_CLASS    
};
#endif//__HdStateMachine_INTERNAL__
