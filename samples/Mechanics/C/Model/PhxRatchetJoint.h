#ifndef __PhxRatchetJoint_H__
#define __PhxRatchetJoint_H__
#include "PhxJoint.h"
typedef struct tagPhxRatchetJoint PhxRatchetJoint;
#endif//__PhxRatchetJoint_H__
#if !defined( PhxRatchetJoint_Init ) && ( defined( __PhxRatchetJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxRatchetJoint
 * @brief PhxRatchetJoint auto-generated constructor
 */
#define PhxRatchetJoint_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) )\
    .vTbl = &gPhxRatchetJointVtbl,\

#define PhxRatchetJoint_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next )    ( PhxRatchetJoint ){ \
    PhxRatchetJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxRatchetJointVtbl;
PhxJoint* PhxRatchetJoint_Copy( PhxRatchetJoint* pPhxRatchetJoint, const PhxRatchetJoint* pSource );
/** @class PhxRatchetJoint
 * @extends PhxJoint
 */
#define PhxRatchetJoint_CLASS                                                                   \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxRatchetJoint{
    PhxRatchetJoint_CLASS    
}PhxRatchetJoint;
#endif//__PhxRatchetJoint_INTERNAL__
