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
#define Button_Init(_m_iniRect, _m_imgPath, _m_constraints, _m_mouseListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ) )\

#define Button_Ctor( _m_iniRect, _m_imgPath, _m_constraints, _m_mouseListeners )    ( Button ){ \
    Button_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ) ) \
}
ImgSprite* Button_Copy( Button* pButton, const Button* pSource );
/** @class Button
 * @extends ImgSprite
 */
#define Button_CLASS                                                                            \
    ImgSprite_CLASS                                                                             \

typedef struct tagButton{
    Button_CLASS    
}Button;
#endif//__Button_INTERNAL__
