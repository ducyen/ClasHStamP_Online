#ifndef __WindscreenWiper_H__
#define __WindscreenWiper_H__
#include "ImgSprite.h"
typedef struct tagWindscreenWiper WindscreenWiper;
void WindscreenWiper_moveRight( WindscreenWiper* pWindscreenWiper );
void WindscreenWiper_moveLeft( WindscreenWiper* pWindscreenWiper );
#endif//__WindscreenWiper_H__
#if !defined( WindscreenWiper_Init ) && ( defined( __WindscreenWiper_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof WindscreenWiper
 * @brief WindscreenWiper auto-generated constructor
 */
#define WindscreenWiper_Init(_m_iniRect, _m_name, _m_imgPath, _m_stmPath, _m_constraints, _m_mouseListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_stmPath ), P( _m_constraints ), P( _m_mouseListeners ) )\
    .x = 0,\

#define WindscreenWiper_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_stmPath, _m_constraints, _m_mouseListeners )    ( WindscreenWiper ){ \
    WindscreenWiper_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_stmPath ), P( _m_constraints ), P( _m_mouseListeners ) ) \
}
ImgSprite* WindscreenWiper_Copy( WindscreenWiper* pWindscreenWiper, const WindscreenWiper* pSource );
/** @class WindscreenWiper
 * @extends ImgSprite
 */
#define WindscreenWiper_CLASS                                                                   \
    ImgSprite_CLASS                                                                             \
    int x;                                                                                                                              \

typedef struct tagWindscreenWiper{
    WindscreenWiper_CLASS    
}WindscreenWiper;
#endif//__WindscreenWiper_INTERNAL__
