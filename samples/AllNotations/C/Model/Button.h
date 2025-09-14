#ifndef __Button_H__
#define __Button_H__
#include "ImgSprite.h"
typedef struct tagButton Button;
#endif//__Button_H__
#if !defined( Button_Init ) && ( defined( __Button_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"

/** @memberof Button
 * @brief Button auto-generated constructor
 */
#define Button_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\

#define Button_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_angle, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( Button ){ \
    Button_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_angle ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* Button_Copy( Button* pButton, const Button* pSource );
/** @class Button
 * @extends ImgSprite
 */
struct tagButton{
#define Button_CLASS                                                                            \
    ImgSprite_CLASS                                                                             \

    Button_CLASS    
};
#endif//__Button_INTERNAL__
