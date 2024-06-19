#ifndef __PhxDampedSpring_H__
#define __PhxDampedSpring_H__
#include "PhxJoint.h"
typedef struct tagPhxDampedSpring PhxDampedSpring;
#endif//__PhxDampedSpring_H__
#if !defined( PhxDampedSpring_Init ) && ( defined( __PhxDampedSpring_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxDampedSpring
 * @brief PhxDampedSpring auto-generated constructor
 */
#define PhxDampedSpring_Init(_m_source, _m_influence, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gPhxDampedSpringVtbl,\

#define PhxDampedSpring_Ctor( _m_source, _m_influence, _m_next )    ( PhxDampedSpring ){ \
    PhxDampedSpring_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxDampedSpringVtbl;
PhxJoint* PhxDampedSpring_Copy( PhxDampedSpring* pPhxDampedSpring, const PhxDampedSpring* pSource );
/** @class PhxDampedSpring
 * @extends PhxJoint
 */
#define PhxDampedSpring_CLASS                                                                   \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxDampedSpring{
    PhxDampedSpring_CLASS    
}PhxDampedSpring;
#endif//__PhxDampedSpring_INTERNAL__
