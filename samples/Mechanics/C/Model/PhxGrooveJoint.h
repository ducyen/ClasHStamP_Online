#ifndef __PhxGrooveJoint_H__
#define __PhxGrooveJoint_H__
#include "PhxJoint.h"
#include "Sprite.h"
typedef struct tagPhxGrooveJoint PhxGrooveJoint;
#endif//__PhxGrooveJoint_H__
#if !defined( PhxGrooveJoint_Init ) && ( defined( __PhxGrooveJoint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __PhxJoint_INTERNAL__
#include "PhxJoint.h"
#include "Sprite.h"
/** @memberof PhxGrooveJoint
 * @brief PhxGrooveJoint auto-generated constructor
 */
#define PhxGrooveJoint_Init(_m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_pivotTgt, _m_next0)\
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_next0 ) )\
    .vTbl = &gPhxGrooveJointVtbl,\
    .m_pivotTgt = _m_pivotTgt,\
    .m_next0 = _m_next0,\

#define PhxGrooveJoint_Ctor( _m_source, _m_influence, _m_anchorTgt, _m_anchorSrc, _m_pivotTgt, _m_next0 )    ( PhxGrooveJoint ){ \
    PhxGrooveJoint_Init( P( _m_source ), P( _m_influence ), P( _m_anchorTgt ), P( _m_anchorSrc ), P( _m_pivotTgt ), P( _m_next0 ) ) \
}
extern const PhxJointVtbl gPhxGrooveJointVtbl;
PhxJoint* PhxGrooveJoint_Copy( PhxGrooveJoint* pPhxGrooveJoint, const PhxGrooveJoint* pSource );
/** @class PhxGrooveJoint
 * @extends PhxJoint
 */
#define PhxGrooveJoint_CLASS                                                                    \
    PhxJoint_CLASS                                                                              \
    Sprite** m_pivotTgt;                                        \
    PhxJoint* m_next0;                                          \

typedef struct tagPhxGrooveJoint{
    PhxGrooveJoint_CLASS    
}PhxGrooveJoint;
#endif//__PhxGrooveJoint_INTERNAL__
