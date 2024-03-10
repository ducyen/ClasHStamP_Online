#ifndef __RedLight_H__
#define __RedLight_H__
#include "Sprite.h"
typedef struct tagRedLight RedLight;
#endif//__RedLight_H__
#if !defined( RedLight_Init ) && ( defined( __RedLight_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof RedLight
 * @brief RedLight auto-generated constructor
 */
#define RedLight_Init(_m_iniRect, _m_imgPath)\
    Sprite_Init( P( _m_iniRect ), P( _m_imgPath ) )\

#define RedLight_Ctor( InitFunc, optionParams )    ( RedLight ){\
    InitFunc\
\
}
Sprite* RedLight_Copy( RedLight* pRedLight, const RedLight* pSource );
/** @class RedLight
 * @extends Sprite
 */
#define RedLight_CLASS                                                                          \
    Sprite_CLASS                                                                                \

typedef struct tagRedLight{
    RedLight_CLASS    
}RedLight;
#endif//__RedLight_INTERNAL__
