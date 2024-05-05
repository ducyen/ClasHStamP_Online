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
    uint64_t nPowerOnHistory;
#define PowerOn_Region1_PowerOn_Dmy             ( 1ULL <<  0 )
#define PowerOn_Region1_PowerOn                 ( PowerOn_Region1_PowerOn_Dmy | PowerOn_Region1_InitialPowerOnRegion1 | PowerOn_Region1_WipingCCW | PowerOn_Region1_WipingCW | PowerOn_Region1_WiperIdle )
#define PowerOn_Region1_InitialPowerOnRegion1   ( 1ULL <<  1 )
#define PowerOn_Region1_WipingCCW               ( 1ULL <<  2 )
#define PowerOn_Region1_WipingCW                ( 1ULL <<  3 )
#define PowerOn_Region1_WiperIdle               ( 1ULL <<  4 )
}PowerOn_Region1;
#define PowerOn_Region1_Init() {\
    .base = { HdStateMachine_Init( PowerOn_Region1_PowerOn, PowerOn_Region1_PowerOn ) },\
}
/** @class CarStm
 * @extends HdStateMachine
 */
typedef struct tagCarStm {
    HdStateMachine base;
    PowerOn_Region1 PowerOnPowerOn_Region1;                     
    uint64_t nPowerOnHistory;
#define CarStm_CarTop_Dmy                       ( 1ULL <<  5 )
#define CarStm_CarTop                           ( CarStm_CarTop_Dmy | CarStm_PowerOn | CarStm_InitialPseudostate0 | CarStm_PowerOff )
#define CarStm_InitialPowerOn                   ( 1ULL <<  6 )
#define CarStm_WiperOffWait                     ( 1ULL <<  7 )
#define CarStm_WiperOn                          ( 1ULL <<  8 )
#define CarStm_WiperOff                         ( 1ULL <<  9 )
#define CarStm_InitialPseudostate0              ( 1ULL << 10 )
#define CarStm_PowerOff                         ( 1ULL << 11 )
#define CarStm_PowerOn_Dmy                      ( 1ULL << 12 )
#define CarStm_PowerOn                          ( CarStm_PowerOn_Dmy | CarStm_InitialPowerOn | CarStm_WiperOffWait | CarStm_WiperOn | CarStm_WiperOff )
}CarStm;
#define CarStm_Init() {\
    .base = { HdStateMachine_Init( CarStm_CarTop, CarStm_CarTop ) },\
    .PowerOnPowerOn_Region1 = PowerOn_Region1_Init(),\
}
BOOL CarBody_EventProc( CarBody* pCarBody, CarBody_EVENT nEventId, void* pEventParams );
BOOL CarBody_Start( CarBody* pCarBody );
BOOL CarBody_Reset( CarBody* pCarBody, uint64_t nEntryPoint );
BOOL CarBody_IsIn( CarBody* pCarBody, uint64_t nState );
/** @memberof CarBody
 * @brief CarBody auto-generated constructor
 */
#define CarBody_Init(_m_iniRect, _m_name, _m_imgPath, _m_stmPath, _m_constraints, _m_mouseListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_stmPath ), P( _m_constraints ), P( _m_mouseListeners ) )\
    .x = 0,\
    .mainStm = CarStm_Init(),\

#define CarBody_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_stmPath, _m_constraints, _m_mouseListeners )    ( CarBody ){ \
    CarBody_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_stmPath ), P( _m_constraints ), P( _m_mouseListeners ) ) \
}
ImgSprite* CarBody_Copy( CarBody* pCarBody, const CarBody* pSource );
/** @class CarBody
 * @extends ImgSprite
 */
#define CarBody_CLASS                                                                           \
    ImgSprite_CLASS                                                                             \
    int x;                                                                                                                              \
    CarStm mainStm;                                             

typedef struct tagCarBody{
    CarBody_CLASS    
}CarBody;
#endif//__CarBody_INTERNAL__
