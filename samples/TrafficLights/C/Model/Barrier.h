#ifndef __Barrier_H__
#define __Barrier_H__
#include "ImgSprite.h"
typedef struct tagBarrier Barrier;
#endif//__Barrier_H__
#if !defined( Barrier_Init ) && ( defined( __Barrier_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof Barrier
 * @brief Barrier auto-generated constructor
 */
#define Barrier_Init(_m_iniRect, _m_imgPath, _m_constraints)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_imgPath ), P( _m_constraints ) )\

#define Barrier_Ctor( InitFunc, optionParams )    ( Barrier ){\
    InitFunc\
\
}
ImgSprite* Barrier_Copy( Barrier* pBarrier, const Barrier* pSource );
/** @class Barrier
 * @extends ImgSprite
 */
#define Barrier_CLASS                                                                           \
    ImgSprite_CLASS                                                                             \

typedef struct tagBarrier{
    Barrier_CLASS    
}Barrier;
#endif//__Barrier_INTERNAL__
