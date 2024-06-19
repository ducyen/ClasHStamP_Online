#ifndef __PhxSlideJoint_H__
#define __PhxSlideJoint_H__
#include "PhxJoint.h"
typedef struct tagPhxSlideJoint PhxSlideJoint;
#endif//__PhxSlideJoint_H__
#if !defined( PhxSlideJoint_Init ) && ( defined( __PhxSlideJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxSlideJoint
 * @brief PhxSlideJoint auto-generated constructor
 */
#define PhxSlideJoint_Init(_m_source, _m_influence, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gPhxSlideJointVtbl,\

#define PhxSlideJoint_Ctor( _m_source, _m_influence, _m_next )    ( PhxSlideJoint ){ \
    PhxSlideJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxSlideJointVtbl;
PhxJoint* PhxSlideJoint_Copy( PhxSlideJoint* pPhxSlideJoint, const PhxSlideJoint* pSource );
/** @class PhxSlideJoint
 * @extends PhxJoint
 */
#define PhxSlideJoint_CLASS                                                                     \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxSlideJoint{
    PhxSlideJoint_CLASS    
}PhxSlideJoint;
#endif//__PhxSlideJoint_INTERNAL__
