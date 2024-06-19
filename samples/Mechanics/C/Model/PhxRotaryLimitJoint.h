#ifndef __PhxRotaryLimitJoint_H__
#define __PhxRotaryLimitJoint_H__
#include "PhxJoint.h"
typedef struct tagPhxRotaryLimitJoint PhxRotaryLimitJoint;
#endif//__PhxRotaryLimitJoint_H__
#if !defined( PhxRotaryLimitJoint_Init ) && ( defined( __PhxRotaryLimitJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxRotaryLimitJoint
 * @brief PhxRotaryLimitJoint auto-generated constructor
 */
#define PhxRotaryLimitJoint_Init(_m_source, _m_influence, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gPhxRotaryLimitJointVtbl,\

#define PhxRotaryLimitJoint_Ctor( _m_source, _m_influence, _m_next )    ( PhxRotaryLimitJoint ){ \
    PhxRotaryLimitJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxRotaryLimitJointVtbl;
PhxJoint* PhxRotaryLimitJoint_Copy( PhxRotaryLimitJoint* pPhxRotaryLimitJoint, const PhxRotaryLimitJoint* pSource );
/** @class PhxRotaryLimitJoint
 * @extends PhxJoint
 */
#define PhxRotaryLimitJoint_CLASS                                                               \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxRotaryLimitJoint{
    PhxRotaryLimitJoint_CLASS    
}PhxRotaryLimitJoint;
#endif//__PhxRotaryLimitJoint_INTERNAL__
