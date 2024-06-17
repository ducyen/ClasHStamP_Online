#ifndef __PhxSprite_H__
#define __PhxSprite_H__
#include "Sprite.h"
typedef struct tagPhxSprite PhxSprite;
#endif//__PhxSprite_H__
#if !defined( PhxSprite_Init ) && ( defined( __PhxSprite_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof PhxSprite
 * @brief PhxSprite auto-generated constructor
 */
#define PhxSprite_Init(_m_iniRect, _m_name, _m_imgPath)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .vTbl = &gPhxSpriteVtbl,\

#define PhxSprite_Ctor( _m_iniRect, _m_name, _m_imgPath )    ( PhxSprite ){ \
    PhxSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) ) \
}
extern const SpriteVtbl gPhxSpriteVtbl;
Sprite* PhxSprite_Copy( PhxSprite* pPhxSprite, const PhxSprite* pSource );
/** @class PhxSprite
 * @extends Sprite
 */
#define PhxSprite_CLASS                                                                         \
    Sprite_CLASS                                                                                \

typedef struct tagPhxSprite{
    PhxSprite_CLASS    
}PhxSprite;
#endif//__PhxSprite_INTERNAL__
