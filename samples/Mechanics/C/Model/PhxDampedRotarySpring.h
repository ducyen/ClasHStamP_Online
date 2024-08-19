#ifndef __PhxDampedRotarySpring_H__
#define __PhxDampedRotarySpring_H__
#include "PhxJoint.h"
typedef struct tagPhxDampedRotarySpring PhxDampedRotarySpring;
#endif//__PhxDampedRotarySpring_H__
#if !defined( PhxDampedRotarySpring_Init ) && ( defined( __PhxDampedRotarySpring_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxDampedRotarySpring
 * @brief PhxDampedRotarySpring auto-generated constructor
 */
#define PhxDampedRotarySpring_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) )\
    .vTbl = &gPhxDampedRotarySpringVtbl,\

#define PhxDampedRotarySpring_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next )    ( PhxDampedRotarySpring ){ \
    PhxDampedRotarySpring_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxDampedRotarySpringVtbl;
PhxJoint* PhxDampedRotarySpring_Copy( PhxDampedRotarySpring* pPhxDampedRotarySpring, const PhxDampedRotarySpring* pSource );
/** @class PhxDampedRotarySpring
 * @extends PhxJoint
 */
struct tagPhxDampedRotarySpring{
#define PhxDampedRotarySpring_CLASS                                                             \
    PhxJoint_CLASS                                                                              \

    PhxDampedRotarySpring_CLASS    
};
#endif//__PhxDampedRotarySpring_INTERNAL__
