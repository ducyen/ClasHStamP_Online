#ifndef __PhxSimpleMotor_H__
#define __PhxSimpleMotor_H__
#include "PhxJoint.h"
typedef struct tagPhxSimpleMotor PhxSimpleMotor;
#endif//__PhxSimpleMotor_H__
#if !defined( PhxSimpleMotor_Init ) && ( defined( __PhxSimpleMotor_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
/** @memberof PhxSimpleMotor
 * @brief PhxSimpleMotor auto-generated constructor
 */
#define PhxSimpleMotor_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) )\
    .vTbl = &gPhxSimpleMotorVtbl,\

#define PhxSimpleMotor_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_next )    ( PhxSimpleMotor ){ \
    PhxSimpleMotor_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next ) ) \
}
extern const PhxJointVtbl gPhxSimpleMotorVtbl;
PhxJoint* PhxSimpleMotor_Copy( PhxSimpleMotor* pPhxSimpleMotor, const PhxSimpleMotor* pSource );
/** @class PhxSimpleMotor
 * @extends PhxJoint
 */
#define PhxSimpleMotor_CLASS                                                                    \
    PhxJoint_CLASS                                                                              \

typedef struct tagPhxSimpleMotor{
    PhxSimpleMotor_CLASS    
}PhxSimpleMotor;
#endif//__PhxSimpleMotor_INTERNAL__
