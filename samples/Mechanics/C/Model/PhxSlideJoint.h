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
#define PhxSlideJoint_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _min, _max, _m_next0)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next0 ) )\
    .vTbl = &gPhxSlideJointVtbl,\
    .min = _min,\
    .max = _max,\
    .m_next0 = _m_next0,\

#define PhxSlideJoint_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _min, _max, _m_next0 )    ( PhxSlideJoint ){ \
    PhxSlideJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _min ), P( _max ), P( _m_next0 ) ) \
}
extern const PhxJointVtbl gPhxSlideJointVtbl;
PhxJoint* PhxSlideJoint_Copy( PhxSlideJoint* pPhxSlideJoint, const PhxSlideJoint* pSource );
/** @class PhxSlideJoint
 * @extends PhxJoint
 */
#define PhxSlideJoint_CLASS                                                                     \
    PhxJoint_CLASS                                                                              \
    cpFloat min;                                                                                                                  \
    cpFloat max;                                                                                                                  \
    PhxJoint* m_next0;                                          \

typedef struct tagPhxSlideJoint{
    PhxSlideJoint_CLASS    
}PhxSlideJoint;
#endif//__PhxSlideJoint_INTERNAL__
