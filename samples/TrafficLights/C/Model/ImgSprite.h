#ifndef __ImgSprite_H__
#define __ImgSprite_H__
#include "Sprite.h"
typedef struct tagImgSprite ImgSprite;
#endif//__ImgSprite_H__
#if !defined( ImgSprite_Init ) && ( defined( __ImgSprite_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof ImgSprite
 * @brief ImgSprite auto-generated constructor
 */
#define ImgSprite_Init(_m_iniRect, _m_imgPath)\
    Sprite_Init( P( _m_iniRect ), P( _m_imgPath ) )\
    .vTbl = &gImgSpriteVtbl,\

#define ImgSprite_Ctor( InitFunc, optionParams )    ( ImgSprite ){\
    InitFunc\
\
}
extern const SpriteVtbl gImgSpriteVtbl;
Sprite* ImgSprite_Copy( ImgSprite* pImgSprite, const ImgSprite* pSource );
/** @class ImgSprite
 * @extends Sprite
 */
#define ImgSprite_CLASS                                                                         \
    Sprite_CLASS                                                                                \

typedef struct tagImgSprite{
    ImgSprite_CLASS    
}ImgSprite;
#endif//__ImgSprite_INTERNAL__
