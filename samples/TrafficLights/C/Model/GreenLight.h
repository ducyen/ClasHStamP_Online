#ifndef __GreenLight_H__
#define __GreenLight_H__
#include "ImgSprite.h"
typedef struct tagGreenLight GreenLight;
#endif//__GreenLight_H__
#if !defined( GreenLight_Init ) && ( defined( __GreenLight_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof GreenLight
 * @brief GreenLight auto-generated constructor
 */
#define GreenLight_Init(_m_iniRect, _m_imgPath, _m_constraints)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ) )\

#define GreenLight_Ctor( _m_iniRect, _m_imgPath, _m_constraints )    ( GreenLight ){ \
    GreenLight_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ) ) \
}
ImgSprite* GreenLight_Copy( GreenLight* pGreenLight, const GreenLight* pSource );
/** @class GreenLight
 * @extends ImgSprite
 */
#define GreenLight_CLASS                                                                        \
    ImgSprite_CLASS                                                                             \

typedef struct tagGreenLight{
    GreenLight_CLASS    
}GreenLight;
#endif//__GreenLight_INTERNAL__
