#ifndef __ImgSprite_H__
#define __ImgSprite_H__
#include "Sprite.h"
#include "Constraint.h"
#include "EventListener.h"
typedef struct tagImgSprite ImgSprite;
void ImgSprite_setOffset( ImgSprite* pImgSprite, int x, int y );
const SDL_Point* ImgSprite_getOffset( ImgSprite* pImgSprite );
const SDL_Rect* ImgSprite_getBoundary( ImgSprite* pImgSprite );
const SDL_Point* ImgSprite_getCenter( ImgSprite* pImgSprite );
void ImgSprite_setRotation( ImgSprite* pImgSprite, double value );
double ImgSprite_getRotation( ImgSprite* pImgSprite );
void ImgSprite_setBrightness( ImgSprite* pImgSprite, double value );
#endif//__ImgSprite_H__
#if !defined( ImgSprite_Init ) && ( defined( __ImgSprite_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#include "Constraint.h"
#include "EventListener.h"
/** @memberof ImgSprite
 * @brief ImgSprite auto-generated constructor
 */
#define ImgSprite_Init(_m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .vTbl = &gImgSpriteVtbl,\
    .m_buffer = null,\
    .m_center = _m_center,\
    .m_constraints = _m_constraints,\
    .m_mouseListeners = _m_mouseListeners,\
    .m_onDrawListeners = _m_onDrawListeners,\

#define ImgSprite_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_center, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( ImgSprite ){ \
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_center ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
extern const SpriteVtbl gImgSpriteVtbl;
Sprite* ImgSprite_Copy( ImgSprite* pImgSprite, const ImgSprite* pSource );
/** @class ImgSprite
 * @extends Sprite
 */
struct tagImgSprite{
#define ImgSprite_CLASS                                                                         \
    Sprite_CLASS                                                                                \
    SDL_Texture* m_buffer;                                                                                              \
    SDL_Point m_center;                                                                                                    \
    Constraint* m_constraints;                                  \
    EventListener* m_mouseListeners;                            \
    EventListener* m_onDrawListeners;                           \

    ImgSprite_CLASS    
};
#endif//__ImgSprite_INTERNAL__
