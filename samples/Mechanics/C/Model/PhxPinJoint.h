#ifndef __PhxPinJoint_H__
#define __PhxPinJoint_H__
#include "PhxJoint.h"
typedef struct tagPhxPinJoint PhxPinJoint;
#endif//__PhxPinJoint_H__
#if !defined( PhxPinJoint_Init ) && ( defined( __PhxPinJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxPinJoint
 * @brief PhxPinJoint auto-generated constructor
 */
#define PhxPinJoint_Init(_m_source, _m_influence, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gPhxPinJointVtbl,\

#define PhxPinJoint_Ctor( _m_source, _m_influence, _m_next )    ( PhxPinJoint ){ \
    PhxPinJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxPinJointVtbl;
PhxJoint* PhxPinJoint_Copy( PhxPinJoint* pPhxPinJoint, const PhxPinJoint* pSource );
/** @class PhxPinJoint
 * @extends PhxJoint
 */
#define PhxPinJoint_CLASS                                                                       \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxPinJoint{
    PhxPinJoint_CLASS    
}PhxPinJoint;
#endif//__PhxPinJoint_INTERNAL__