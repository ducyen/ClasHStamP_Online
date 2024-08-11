#ifndef __Lever_H__
#define __Lever_H__
#include "ImgSprite.h"
typedef struct tagLever Lever;
#endif//__Lever_H__
#if !defined( Lever_Init ) && ( defined( __Lever_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof Lever
 * @brief Lever auto-generated constructor
 */
#define Lever_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\

#define Lever_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( Lever ){ \
    Lever_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* Lever_Copy( Lever* pLever, const Lever* pSource );
/** @class Lever
 * @extends ImgSprite
 */
struct tagLever{
#define Lever_CLASS                                                                             \
    ImgSprite_CLASS                                                                             \

    Lever_CLASS    
};
#endif//__Lever_INTERNAL__
