#ifndef __HdStateMachine_H__
#define __HdStateMachine_H__
typedef struct tagHdStateMachine HdStateMachine;
int HdStateMachine_Enterable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
int HdStateMachine_Exitable( HdStateMachine* pHdStateMachine, uint64_t nThisState );
void HdStateMachine_DefaultEntryAction( HdStateMachine* pHdStateMachine, void* pObj, char* pMsg );
void HdStateMachine_DefaultDoingAction( HdStateMachine* pHdStateMachine, void* pObj, char* pMsg );
void HdStateMachine_DefaultExitAction( HdStateMachine* pHdStateMachine, void* pObj, char* pMsg );
bool HdStateMachine_IsIn( HdStateMachine* pHdStateMachine, uint64_t targetState );
#endif//__HdStateMachine_H__
#if !defined( HdStateMachine_Init ) && ( defined( __HdStateMachine_INTERNAL__ )  )

/** @memberof HdStateMachine
 * @brief HdStateMachine auto-generated constructor
 */
#define HdStateMachine_Init()\
    .nCurrentState = STATE_UNDEF,\
    .nLCAState = STATE_UNDEF,\
    .nTargetState = STATE_UNDEF,\
    .nSourceState = STATE_UNDEF,\
    .nPseudostate = STATE_UNDEF,\
    .bIsExternTrans = false,\
    .m_stmImage = null,\
    .m_stmRect = null,\
    .pMain = NULL,\
    .lastEnteredState = STATE_UNDEF,\

#define HdStateMachine_Ctor(  )    ( HdStateMachine ){ \
    HdStateMachine_Init(  ) \
}
HdStateMachine* HdStateMachine_Copy( HdStateMachine* pHdStateMachine, const HdStateMachine* pSource );
/** @class HdStateMachine
 * @extends 
 */
struct tagHdStateMachine{
#define HdStateMachine_CLASS                                                                    \
    size_t cbSize;                                                                              \
    uint64_t nCurrentState;                                                                                            \
    uint64_t nLCAState;                                                                                                    \
    uint64_t nTargetState;                                                                                              \
    uint64_t nSourceState;                                                                                              \
    uint64_t nPseudostate;                                                                                              \
    bool bIsExternTrans;                                                                                                  \
    SDL_Texture* m_stmImage;                                                                                          \
    SDL_Rect m_stmRect;                                                                                                    \
    void* pMain;                                                                                                                  \
    uint64_t lastEnteredState;                                                                                      \

    HdStateMachine_CLASS    
};
#endif//__HdStateMachine_INTERNAL__
