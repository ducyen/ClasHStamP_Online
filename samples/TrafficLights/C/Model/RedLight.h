#ifndef __RedLight_H__
#define __RedLight_H__
#include "ImgSprite.h"
typedef struct tagRedLight RedLight;
#endif//__RedLight_H__
#if !defined( RedLight_Init ) && ( defined( __RedLight_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof RedLight
 * @brief RedLight auto-generated constructor
 */
#define RedLight_Init(_m_iniRect, _m_imgPath, _m_constraints)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ) )\

#define RedLight_Ctor( InitFunc, optionParams )    ( RedLight ){\
    InitFunc\
\
}
ImgSprite* RedLight_Copy( RedLight* pRedLight, const RedLight* pSource );
/** @class RedLight
 * @extends ImgSprite
 */
#define RedLight_CLASS                                                                          \
    ImgSprite_CLASS                                                                             \

typedef struct tagRedLight{
    RedLight_CLASS    
}RedLight;
#endif//__RedLight_INTERNAL__
