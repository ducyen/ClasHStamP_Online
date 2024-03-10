#ifndef __Barrier_H__
#define __Barrier_H__
#include "Sprite.h"
typedef struct tagBarrier Barrier;
#endif//__Barrier_H__
#if !defined( Barrier_Init ) && ( defined( __Barrier_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof Barrier
 * @brief Barrier auto-generated constructor
 */
#define Barrier_Init(_m_iniRect, _m_imgPath, _m_x, _m_y, _m_angle)\
    Sprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_x ), P( _m_y ), P( _m_angle ) )\

#define Barrier_Ctor( InitFunc, optionParams )    ( Barrier ){\
    InitFunc\
\
}
Sprite* Barrier_Copy( Barrier* pBarrier, const Barrier* pSource );
/** @class Barrier
 * @extends Sprite
 */
#define Barrier_CLASS                                                                           \
    Sprite_CLASS                                                                                \

typedef struct tagBarrier{
    Barrier_CLASS    
}Barrier;
#endif//__Barrier_INTERNAL__
