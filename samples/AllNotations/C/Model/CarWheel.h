#ifndef __CarWheel_H__
#define __CarWheel_H__
#include "ImgSprite.h"
typedef struct tagCarWheel CarWheel;
void CarWheel_rotateCW( CarWheel* pCarWheel );
void CarWheel_rotateCCW( CarWheel* pCarWheel );
#endif//__CarWheel_H__
#if !defined( CarWheel_Init ) && ( defined( __CarWheel_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof CarWheel
 * @brief CarWheel auto-generated constructor
 */
#define CarWheel_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .rotation = 0,\

#define CarWheel_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( CarWheel ){ \
    CarWheel_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* CarWheel_Copy( CarWheel* pCarWheel, const CarWheel* pSource );
/** @class CarWheel
 * @extends ImgSprite
 */
struct tagCarWheel{
#define CarWheel_CLASS                                                                          \
    ImgSprite_CLASS                                                                             \
    double rotation;                                                                                                          \

    CarWheel_CLASS    
};
#endif//__CarWheel_INTERNAL__
