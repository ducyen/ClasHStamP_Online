#ifndef __PhxRotaryLimitJoint_H__
#define __PhxRotaryLimitJoint_H__
#include "PhxJoint.h"
#include "Sprite.h"
typedef struct tagPhxRotaryLimitJoint PhxRotaryLimitJoint;
#endif//__PhxRotaryLimitJoint_H__
#if !defined( PhxRotaryLimitJoint_Init ) && ( defined( __PhxRotaryLimitJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof PhxRotaryLimitJoint
 * @brief PhxRotaryLimitJoint auto-generated constructor
 */
#define PhxRotaryLimitJoint_Init(_m_source, _m_influence, _min, _max, _m_next0)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( null ), P( null ), P( _m_next0 ) )\
    .vTbl = &gPhxRotaryLimitJointVtbl,\
    .min = _min,\
    .max = _max,\
    .m_next0 = _m_next0,\

#define PhxRotaryLimitJoint_Ctor( _m_source, _m_influence, _min, _max, _m_next0 )    ( PhxRotaryLimitJoint ){ \
    PhxRotaryLimitJoint_Init( P( _m_source ), P( _m_influence ), P( _min ), P( _max ), P( _m_next0 ) ) \
}
extern const PhxJointVtbl gPhxRotaryLimitJointVtbl;
PhxJoint* PhxRotaryLimitJoint_Copy( PhxRotaryLimitJoint* pPhxRotaryLimitJoint, const PhxRotaryLimitJoint* pSource );
/** @class PhxRotaryLimitJoint
 * @extends PhxJoint
 */
struct tagPhxRotaryLimitJoint{
#define PhxRotaryLimitJoint_CLASS                                                               \
    PhxJoint_CLASS                                                                              \
    cpFloat min;                                                                                                                  \
    cpFloat max;                                                                                                                  \
    PhxJoint* m_next0;                                          \

    PhxRotaryLimitJoint_CLASS    
};
#endif//__PhxRotaryLimitJoint_INTERNAL__
