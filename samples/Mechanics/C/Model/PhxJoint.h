#ifndef __PhxJoint_H__
#define __PhxJoint_H__
#include "Sprite.h"
typedef struct tagPhxJoint PhxJoint;
void PhxJoint_apply( PhxJoint* pPhxJoint, Sprite* target );
PhxJoint* PhxJoint_getNext( PhxJoint* pPhxJoint );
#endif//__PhxJoint_H__
#if !defined( PhxJoint_Init ) && ( defined( __PhxJoint_INTERNAL__ )  )
#include "Sprite.h"
/** @memberof PhxJoint
 * @brief PhxJoint auto-generated constructor
 */
#define PhxJoint_Init(_m_source, _m_influence, _m_next)\
    .m_source = _m_source,\
    .m_influence = _m_influence,\
    .m_next = _m_next,\

#define PhxJoint_Ctor( _m_source, _m_influence, _m_next )    ( PhxJoint ){ \
    PhxJoint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
typedef struct tagPhxJointVtbl{
    void ( * const papply )( PhxJoint*, Sprite* );
}PhxJointVtbl;
PhxJoint* PhxJoint_Copy( PhxJoint* pPhxJoint, const PhxJoint* pSource );
/** @class PhxJoint
 * @extends 
 */
#define PhxJoint_CLASS                                                                          \
    const PhxJointVtbl* const vTbl;                                                             \
    size_t cbSize;                                                                              \
    Sprite** m_source;                                          \
    float m_influence;                                                                                                      \
    PhxJoint* m_next;                                           \

typedef struct tagPhxJoint{
    PhxJoint_CLASS    
}PhxJoint;
#endif//__PhxJoint_INTERNAL__