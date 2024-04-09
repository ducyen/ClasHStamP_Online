#ifndef __CarBody_H__
#define __CarBody_H__
#include "ImgSprite.h"
typedef struct tagCarBody CarBody;
void CarBody_moveRight( CarBody* pCarBody );
void CarBody_moveLeft( CarBody* pCarBody );
typedef enum tagCarBodyEvent {
    CarBody_E_PWR_BTN,                                          
    CarBody_E_WIPER_LEVER,                                      
    CarBody_TICK,                                               
    CarBody_EVENT_NUM
}CarBody_EVENT;
const TCHAR* CarBodyEvent_toString( CarBody_EVENT value );
#endif//__CarBody_H__
#if !defined( CarBody_Init ) && ( defined( __CarBody_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
#define __HdStateMachine_INTERNAL__
#include "HdStateMachine.h"
/** @class PowerOn_Region1
 * @extends HdStateMachine
 */
typedef struct tagPowerOn_Region1 {
    HdStateMachine base;
#define PowerOn_Region1_PowerOn_Top_Dmy         ( 1ULL <<  0 )
#define PowerOn_Region1_PowerOn_Top             ( PowerOn_Region1_PowerOn_Top_Dmy | PowerOn_Region1_WiperIdle | PowerOn_Region1_InitialPseudostate0 | PowerOn_Region1_State7 )
#define PowerOn_Region1_WiperIdle               ( 1ULL <<  1 )
#define PowerOn_Region1_InitialPseudostate0     ( 1ULL <<  2 )
#define PowerOn_Region1_WipingCW                ( 1ULL <<  3 )
#define PowerOn_Region1_WipingCCW               ( 1ULL <<  4 )
#define PowerOn_Region1_State7_Dmy              ( 1ULL <<  5 )
#define PowerOn_Region1_State7                  ( PowerOn_Region1_State7_Dmy | PowerOn_Region1_WipingCW | PowerOn_Region1_WipingCCW )
}PowerOn_Region1;
#define PowerOn_Region1_Init() {\
    .base = { HdStateMachine_Init( PowerOn_Region1_PowerOn_Top, PowerOn_Region1_PowerOn_Top ) },\
}
/** @class CarStm
 * @extends HdStateMachine
 */
typedef struct tagCarStm {
    HdStateMachine base;
    PowerOn_Region1 PowerOn_TopPowerOn_Region1;                 
#define CarStm_CarTop_Dmy                       ( 1ULL <<  6 )
#define CarStm_CarTop                           ( CarStm_CarTop_Dmy | CarStm_PowerOn | CarStm_InitialPseudostate1 | CarStm_PowerOff )
#define CarStm_InitialPseudostate0              ( 1ULL <<  7 )
#define CarStm_EngineOn                         ( 1ULL <<  8 )
#define CarStm_EngineOff                        ( 1ULL <<  9 )
#define CarStm_InitialPseudostate1              ( 1ULL << 10 )
#define CarStm_PowerOff                         ( 1ULL << 11 )
#define CarStm_PowerOn_Dmy                      ( 1ULL << 12 )
#define CarStm_PowerOn                          ( CarStm_PowerOn_Dmy | CarStm_InitialPseudostate0 | CarStm_EngineOn | CarStm_EngineOff )
}CarStm;
#define CarStm_Init() {\
    .base = { HdStateMachine_Init( CarStm_CarTop, CarStm_CarTop ) },\
    .PowerOn_TopPowerOn_Region1 = PowerOn_Region1_Init(),\
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
