#ifndef __PhxGearJoint_H__
#define __PhxGearJoint_H__
#include "PhxJoint.h"
typedef struct tagPhxGearJoint PhxGearJoint;
#endif//__PhxGearJoint_H__
#if !defined( PhxGearJoint_Init ) && ( defined( __PhxGearJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxGearJoint
 * @brief PhxGearJoint auto-generated constructor
 */
#define PhxGearJoint_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) )\
    .vTbl = &gPhxGearJointVtbl,\

#define PhxGearJoint_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next )    ( PhxGearJoint ){ \
    PhxGearJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxGearJointVtbl;
PhxJoint* PhxGearJoint_Copy( PhxGearJoint* pPhxGearJoint, const PhxGearJoint* pSource );
/** @class PhxGearJoint
 * @extends PhxJoint
 */
#define PhxGearJoint_CLASS                                                                      \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxGearJoint{
    PhxGearJoint_CLASS    
}PhxGearJoint;
#endif//__PhxGearJoint_INTERNAL__
