#ifndef __PhxSimpleMotor_H__
#define __PhxSimpleMotor_H__
#include "PhxJoint.h"
#include "Sprite.h"
typedef struct tagPhxSimpleMotor PhxSimpleMotor;
#endif//__PhxSimpleMotor_H__
#if !defined( PhxSimpleMotor_Init ) && ( defined( __PhxSimpleMotor_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
#define __Sprite_INTERNAL__
#include "Sprite.h"
/** @memberof PhxSimpleMotor
 * @brief PhxSimpleMotor auto-generated constructor
 */
#define PhxSimpleMotor_Init(_m_source, _m_influence, _m_rate, _m_next0)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( null ), P( null ), P( _m_next0 ) )\
    .vTbl = &gPhxSimpleMotorVtbl,\
    .m_rate = _m_rate,\
    .m_next0 = _m_next0,\

#define PhxSimpleMotor_Ctor( _m_source, _m_influence, _m_rate, _m_next0 )    ( PhxSimpleMotor ){ \
    PhxSimpleMotor_Init( P( _m_source ), P( _m_influence ), P( _m_rate ), P( _m_next0 ) ) \
}
extern const PhxJointVtbl gPhxSimpleMotorVtbl;
PhxJoint* PhxSimpleMotor_Copy( PhxSimpleMotor* pPhxSimpleMotor, const PhxSimpleMotor* pSource );
/** @class PhxSimpleMotor
 * @extends PhxJoint
 */
struct tagPhxSimpleMotor{
#define PhxSimpleMotor_CLASS                                                                    \
    PhxJoint_CLASS                                                                              \
    cpFloat m_rate;                                                                                                            \
    PhxJoint* m_next0;                                          \

    PhxSimpleMotor_CLASS    
};
#endif//__PhxSimpleMotor_INTERNAL__
