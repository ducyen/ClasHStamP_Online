#ifndef __ImgSprite_H__
#define __ImgSprite_H__
#include "Sprite.h"
#include "Constraint.h"
typedef struct tagImgSprite ImgSprite;
void ImgSprite_setOffset( ImgSprite* pImgSprite, int x, int y );
SDL_Point* ImgSprite_getOffset( ImgSprite* pImgSprite );
void ImgSprite_setRotation( ImgSprite* pImgSprite, double value );
double ImgSprite_getRotation( ImgSprite* pImgSprite );
void ImgSprite_setBrightness( ImgSprite* pImgSprite, double value );
#endif//__ImgSprite_H__
#if !defined( ImgSprite_Init ) && ( defined( __ImgSprite_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#include "Constraint.h"
/** @memberof ImgSprite
 * @brief ImgSprite auto-generated constructor
 */
#define ImgSprite_Init(_m_iniRect, _m_imgPath, _m_constraints)\
    Sprite_Init( P( _m_iniRect ), P( _m_imgPath ) )\
    .vTbl = &gImgSpriteVtbl,\
    .m_buffer = null,\
    .m_constraints = _m_constraints,\

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
    SDL_Texture* m_buffer;                                                                                             \
    Constraint* m_constraints;                                  \

typedef struct tagImgSprite{
    ImgSprite_CLASS    
}ImgSprite;
#endif//__ImgSprite_INTERNAL__
