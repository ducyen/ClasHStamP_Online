#ifndef __Primitive_H__
#define __Primitive_H__
#include "Sprite.h"
typedef struct tagPrimitive Primitive;
#endif//__Primitive_H__
#if !defined( Primitive_Init ) && ( defined( __Primitive_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof Primitive
 * @brief Primitive auto-generated constructor
 */
#define Primitive_Init(_m_iniRect, _m_imgPath)\
    Sprite_Init( P( _m_iniRect ), P( _m_imgPath ) )\
    .vTbl = &gPrimitiveVtbl,\

#define Primitive_Ctor( _m_iniRect, _m_imgPath )    ( Primitive ){ \
    Primitive_Init( P( _m_iniRect ), P( _m_imgPath ) ) \
}
extern const SpriteVtbl gPrimitiveVtbl;
Sprite* Primitive_Copy( Primitive* pPrimitive, const Primitive* pSource );
/** @class Primitive
 * @extends Sprite
 */
#define Primitive_CLASS                                                                         \
    Sprite_CLASS                                                                                \

typedef struct tagPrimitive{
    Primitive_CLASS    
}Primitive;
#endif//__Primitive_INTERNAL__
