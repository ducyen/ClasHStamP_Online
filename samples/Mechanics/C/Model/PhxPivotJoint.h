#ifndef __PhxPivotJoint_H__
#define __PhxPivotJoint_H__
#include "PhxJoint.h"
#include "Sprite.h"
typedef struct tagPhxPivotJoint PhxPivotJoint;
#endif//__PhxPivotJoint_H__
#if !defined( PhxPivotJoint_Init ) && ( defined( __PhxPivotJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
#include "Sprite.h"
/** @memberof PhxPivotJoint
 * @brief PhxPivotJoint auto-generated constructor
 */
#define PhxPivotJoint_Init(_m_source, _m_influence, _m_anchorTgt, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( null ), P( _m_next ) )\
    .vTbl = &gPhxPivotJointVtbl,\

#define PhxPivotJoint_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_next )    ( PhxPivotJoint ){ \
    PhxPivotJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxPivotJointVtbl;
PhxJoint* PhxPivotJoint_Copy( PhxPivotJoint* pPhxPivotJoint, const PhxPivotJoint* pSource );
/** @class PhxPivotJoint
 * @extends PhxJoint
 */
#define PhxPivotJoint_CLASS                                                                     \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxPivotJoint{
    PhxPivotJoint_CLASS    
}PhxPivotJoint;
#endif//__PhxPivotJoint_INTERNAL__
