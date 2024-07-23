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
#endif//__FlexButton_H__
#if !defined( FlexButton_Init ) && ( defined( __FlexButton_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#include "EventListener.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class Ready_Region1
 * @extends HdStateMachine
 */
typedef struct tagReady_Region1 {
    HdStateMachine base;
#define Ready_Region1_Ready_Dmy                 ( 1ULL <<  0 )
#define Ready_Region1_Ready                     ( Ready_Region1_Ready_Dmy | Ready_Region1_Hold | Ready_Region1_Idle | Ready_Region1_InitialReadyRegion1 | Ready_Region1_Missed )
#define Ready_Region1_UnPressed                 ( 1ULL <<  1 )
#define Ready_Region1_Pressed                   ( 1ULL <<  2 )
#define Ready_Region1_Idle                      ( 1ULL <<  3 )
#define Ready_Region1_InitialReadyRegion1       ( 1ULL <<  4 )
#define Ready_Region1_Missed                    ( 1ULL <<  5 )
#define Ready_Region1_Hold_Dmy                  ( 1ULL <<  6 )
#define Ready_Region1_Hold                      ( Ready_Region1_Hold_Dmy | Ready_Region1_UnPressed | Ready_Region1_Pressed )
}Ready_Region1;
#define Ready_Region1_Init() {\
    .base = { HdStateMachine_Init( Ready_Region1_Ready, Ready_Region1_Ready ) },\
}
/** @class FlexBtnStm
 * @extends HdStateMachine
 */
typedef struct tagFlexBtnStm {
    HdStateMachine base;
    Ready_Region1 ReadyReady_Region1;                           
    uint64_t nReadyHistory;
#define FlexBtnStm_StateMachine0_Dmy            ( 1ULL <<  7 )
#define FlexBtnStm_StateMachine0                ( FlexBtnStm_StateMachine0_Dmy | FlexBtnStm_Ready | FlexBtnStm_InitialMain )
#define FlexBtnStm_PushStyle                    ( 1ULL <<  8 )
#define FlexBtnStm_SelectStyle                  ( 1ULL <<  9 )
#define FlexBtnStm_SlideStyle                   ( 1ULL << 10 )
#define FlexBtnStm_ToggleStyle                  ( 1ULL << 11 )
#define FlexBtnStm_InitialReady                 ( 1ULL << 12 )
#define FlexBtnStm_InitialMain                  ( 1ULL << 13 )
#define FlexBtnStm_Ready_Dmy                    ( 1ULL << 14 )
#define FlexBtnStm_Ready                        ( FlexBtnStm_Ready_Dmy | FlexBtnStm_PushStyle | FlexBtnStm_SelectStyle | FlexBtnStm_SlideStyle | FlexBtnStm_ToggleStyle | FlexBtnStm_InitialReady )
}FlexBtnStm;
#define FlexBtnStm_Init() {\
    .base = { HdStateMachine_Init( FlexBtnStm_StateMachine0, FlexBtnStm_StateMachine0 ) },\
    .ReadyReady_Region1 = Ready_Region1_Init(),\
}
BOOL FlexButton_EventProc( FlexButton* pFlexButton, FlexButton_EVENT nEventId, void* pEventParams );
BOOL FlexButton_Start( FlexButton* pFlexButton );
BOOL FlexButton_Reset( FlexButton* pFlexButton, uint64_t nEntryPoint );
BOOL FlexButton_IsIn( FlexButton* pFlexButton, uint64_t nState );
/** @memberof FlexButton
 * @brief FlexButton auto-generated constructor
 */
#define FlexButton_Init(_m_iniRect, _m_name, _m_imgPath, _m_valueMax, _m_style, _m_mouseListeners, _m_buttonListeners)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .vTbl = &gFlexButtonVtbl,\
    .m_value = 0,\
    .m_valueMax = _m_valueMax,\
    .m_valueTmp = 0,\
    .m_style = _m_style,\
    .m_knobPos = { 0 },\
    .m_mouseListeners = _m_mouseListeners,\
    .m_buttonListeners = _m_buttonListeners,\
    .mainStm = FlexBtnStm_Init(),\

#define FlexButton_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_valueMax, _m_style, _m_mouseListeners, _m_buttonListeners )    ( FlexButton ){ \
    FlexButton_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_valueMax ), P( _m_style ), P( _m_mouseListeners ), P( _m_buttonListeners ) ) \
}
extern const SpriteVtbl gFlexButtonVtbl;
Sprite* FlexButton_Copy( FlexButton* pFlexButton, const FlexButton* pSource );
/** @class FlexButton
 * @extends Sprite
 */
#define FlexButton_CLASS                                                                        \
    Sprite_CLASS                                                                                \
    int m_value;                                                                                                                  \
    int m_valueMax;                                                                                                            \
    int m_valueTmp;                                                                                                            \
    int m_style;                                                                                                                  \
    SDL_Point m_knobPos;                                                                                                  \
    EventListener* m_mouseListeners;                            \
    EventListener* m_buttonListeners;                           \
    FlexBtnStm mainStm;                                         

typedef struct tagFlexButton{
    FlexButton_CLASS    
}FlexButton;
#endif//__FlexButton_INTERNAL__
