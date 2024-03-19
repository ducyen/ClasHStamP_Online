#ifndef __YellowLight_H__
#define __YellowLight_H__
#include "ImgSprite.h"
typedef struct tagYellowLight YellowLight;
#endif//__YellowLight_H__
#if !defined( YellowLight_Init ) && ( defined( __YellowLight_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof YellowLight
 * @brief YellowLight auto-generated constructor
 */
#define YellowLight_Init(_m_iniRect, _m_imgPath)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ) )\

#define YellowLight_Ctor( InitFunc, optionParams )    ( YellowLight ){\
    InitFunc\
\
}
ImgSprite* YellowLight_Copy( YellowLight* pYellowLight, const YellowLight* pSource );
/** @class YellowLight
 * @extends ImgSprite
 */
#define YellowLight_CLASS                                                                       \
    ImgSprite_CLASS                                                                             \

typedef struct tagYellowLight{
    YellowLight_CLASS    
}YellowLight;
#endif//__YellowLight_INTERNAL__
