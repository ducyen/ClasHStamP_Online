#ifndef __FlexButton_H__
#define __FlexButton_H__
#include "Sprite.h"
#include "EventListener.h"
typedef struct tagFlexButton FlexButton;
typedef struct tagMouseEventParams {
    SDL_Point pos;                                              
}MouseEventParams;
bool FlexButton_IsInRect( FlexButton* pFlexButton, MouseEventParams* pEventPrams );
bool FlexButton_OnPushBtnPressed( FlexButton* pFlexButton );
void FlexButton_OnHoldEntry( FlexButton* pFlexButton );
void FlexButton_OnHoldExit( FlexButton* pFlexButton );
void FlexButton_DrawPushStyle( FlexButton* pFlexButton, SDL_Renderer* renderer );
void FlexButton_DrawSelectStyle( FlexButton* pFlexButton, SDL_Renderer* renderer );
void FlexButton_DrawToggleStyle( FlexButton* pFlexButton, SDL_Renderer* renderer );
void FlexButton_DrawSlideStyle( FlexButton* pFlexButton, SDL_Renderer* renderer );
void FlexButton_DrawPressed( FlexButton* pFlexButton, SDL_Renderer* renderer );
void FlexButton_DrawKnob( FlexButton* pFlexButton, SDL_Renderer* renderer );
int FlexButton_GetValue( FlexButton* pFlexButton );
void FlexButton_SetValue( FlexButton* pFlexButton, int value );
typedef enum tagFlexButtonEvent {
    FlexButton_DRAW0,                                           
    FlexButton_DRAW1,                                           
    FlexButton_MOUSE_DOWN,                                      
    FlexButton_MOUSE_MOVE,                                      
    FlexButton_MOUSE_UP,                                        
    FlexButton_EVENT_NUM
}FlexButton_EVENT;
const TCHAR* FlexButtonEvent_toString( FlexButton_EVENT value );
BOOL FlexButton_Start( FlexButton* pFlexButton );
BOOL FlexButton_EventProc( FlexButton* pFlexButton, FlexButton_EVENT nEventId, void* pEventParams );
#endif//__FlexButton_H__
#if !defined( FlexButton_Init ) && ( defined( __FlexButton_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#include "EventListener.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class FlexBtnTop
 * @extends HdStateMachine
 */
typedef struct tagFlexBtnTop {
#define FlexBtnTop_InitialReadyRegion1          ( 1ULL <<  0 )
#define FlexBtnTop_Missed                       ( 1ULL <<  1 )
#define FlexBtnTop_Idle                         ( 1ULL <<  2 )
#define FlexBtnTop_UnPressed                    ( 1ULL <<  3 )
#define FlexBtnTop_Pressed                      ( 1ULL <<  4 )
#define FlexBtnTop_Hold                         ( FlexBtnTop_UnPressed | FlexBtnTop_Pressed )
#define FlexBtnTop_ReadyRgn1                    ( FlexBtnTop_InitialReadyRegion1 | FlexBtnTop_Missed | FlexBtnTop_Idle | FlexBtnTop_Hold )
#define FlexBtnTop_InitialReady                 ( 1ULL <<  0 )
#define FlexBtnTop_ToggleStyle                  ( 1ULL <<  1 )
#define FlexBtnTop_SlideStyle                   ( 1ULL <<  2 )
#define FlexBtnTop_SelectStyle                  ( 1ULL <<  3 )
#define FlexBtnTop_PushStyle                    ( 1ULL <<  4 )
#define FlexBtnTop_State1                       ( FlexBtnTop_InitialReady | FlexBtnTop_ToggleStyle | FlexBtnTop_SlideStyle | FlexBtnTop_SelectStyle | FlexBtnTop_PushStyle )
#define FlexBtnTop_InitialPseudostate0          ( 1ULL <<  5 )
#define FlexBtnTop_Ready                        ( FlexBtnTop_State1 | FlexBtnTop_InitialPseudostate0 )
#define FlexBtnTop_InitialMain                  ( 1ULL <<  6 )
#define FlexBtnTop_FlexBtnStm                   ( FlexBtnTop_Ready | FlexBtnTop_InitialMain )
    HdStateMachine FlexBtnStmHsm;                               
    uint64_t nReadyHistory;
    HdStateMachine ReadyRgn1Hsm;                                
    HdStateMachine* pParentStm;
    BOOL lastEnteredStateRecovering;
}FlexBtnTop;
#define FlexBtnTop_Init() {\
    .pParentStm = NULL,\
    .lastEnteredStateRecovering = FALSE,\
    .FlexBtnStmHsm = { HdStateMachine_Init() },\
    .nReadyHistory = STATE_UNDEF,\
    .ReadyRgn1Hsm = { HdStateMachine_Init() },\
}

/** @memberof FlexButton
 * @brief FlexButton auto-generated constructor
 */
#define FlexButton_Init(_m_iniRect, _m_name, _m_imgPath, _m_value, _m_valueMax, _m_style, _m_mouseListeners, _m_buttonListeners)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .vTbl = &gFlexButtonVtbl,\
    .m_value = _m_value,\
    .m_valueMax = _m_valueMax,\
    .m_valueTmp = 0,\
    .m_style = _m_style,\
    .m_knobPos = { 0 },\
    .m_mouseListeners = _m_mouseListeners,\
    .m_buttonListeners = _m_buttonListeners,\
    .mainStm = FlexBtnTop_Init(),\

#define FlexButton_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_value, _m_valueMax, _m_style, _m_mouseListeners, _m_buttonListeners )    ( FlexButton ){ \
    FlexButton_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_value ), P( _m_valueMax ), P( _m_style ), P( _m_mouseListeners ), P( _m_buttonListeners ) ) \
}
extern const SpriteVtbl gFlexButtonVtbl;
Sprite* FlexButton_Copy( FlexButton* pFlexButton, const FlexButton* pSource );
/** @class FlexButton
 * @extends Sprite
 */
struct tagFlexButton{
#define FlexButton_CLASS                                                                        \
    Sprite_CLASS                                                                                \
    int m_value;                                                                                                                  \
    int m_valueMax;                                                                                                            \
    int m_valueTmp;                                                                                                            \
    int m_style;                                                                                                                  \
    SDL_Point m_knobPos;                                                                                                  \
    EventListener* m_mouseListeners;                            \
    EventListener* m_buttonListeners;                           \
    FlexBtnTop mainStm;                                         

    FlexButton_CLASS    
};
#endif//__FlexButton_INTERNAL__
