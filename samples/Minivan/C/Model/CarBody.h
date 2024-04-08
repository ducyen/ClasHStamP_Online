#ifndef __CarBody_H__
#define __CarBody_H__
#include "ImgSprite.h"
typedef struct tagCarBody CarBody;
void CarBody_moveRight( CarBody* pCarBody );
void CarBody_moveLeft( CarBody* pCarBody );
typedef enum tagCarBodyEvent {
    CarBody_E_PWR_BTN,                                          
    CarBody_EVENT_NUM
}CarBody_EVENT;
const TCHAR* CarBodyEvent_toString( CarBody_EVENT value );
#endif//__CarBody_H__
#if !defined( CarBody_Init ) && ( defined( __CarBody_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class CarStm
 * @extends HdStateMachine
 */
typedef struct tagCarStm {
    HdStateMachine base;
#define CarStm_CarTop_Dmy                       ( 1ULL <<  4 )
#define CarStm_CarTop                           ( CarStm_CarTop_Dmy | CarStm_InitialPseudostate0 | CarStm_PowerOff | CarStm_PowerOn )
#define CarStm_InitialPseudostate0              ( 1ULL <<  5 )
#define CarStm_PowerOff                         ( 1ULL <<  6 )
#define CarStm_PowerOn                          ( 1ULL <<  7 )
}CarStm;
#define CarStm_Init() {\
    .base = { HdStateMachine_Init( CarStm_CarTop, CarStm_CarTop ) },\
}
BOOL CarBody_EventProc( CarBody* pCarBody, CarBody_EVENT nEventId, void* pEventParams );
BOOL CarBody_Start( CarBody* pCarBody );
/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_imgPath, _m_constraints, _m_mouseListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ) )\
    .x = 0,\
    .mainStm = CarStm_Init(),\

#define CarBody_Ctor( _m_iniRect, _m_imgPath, _m_constraints, _m_mouseListeners )    ( CarBody ){ \
    CarBody_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ) ) \
}
ImgSprite* CarBody_Copy( CarBody* pCarBody, const CarBody* pSource );
/** @class CarBody
 * @extends ImgSprite
 */
#define CarBody_CLASS                                                                           \
    ImgSprite_CLASS                                                                             \
    int x;                                                                                                                             \
    CarStm mainStm;                                             

typedef struct tagCarBody{
    CarBody_CLASS    
}CarBody;
#endif//__CarBody_INTERNAL__
