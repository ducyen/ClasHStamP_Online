#ifndef __AttachConstraint_H__
#define __AttachConstraint_H__
#include "TransformConstraint.h"
typedef struct tagAttachConstraint AttachConstraint;
#endif//__AttachConstraint_H__
#if !defined( AttachConstraint_Init ) && ( defined( __AttachConstraint_INTERNAL__ ) || defined( __ObjsBuilder_INTERNAL__ ) )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof AttachConstraint
 * @brief AttachConstraint auto-generated constructor
 */
#define AttachConstraint_Init(_m_source, _m_influence, _m_next)\
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gAttachConstraintVtbl,\

#define AttachConstraint_Ctor( InitFunc, optionParams )    ( AttachConstraint ){\
    InitFunc\
\
}
extern const ConstraintVtbl gAttachConstraintVtbl;
TransformConstraint* AttachConstraint_Copy( AttachConstraint* pAttachConstraint, const AttachConstraint* pSource );
/** @class AttachConstraint
 * @extends TransformConstraint
 */
#define AttachConstraint_CLASS                                                                  \
    TransformConstraint_CLASS                                                                   \

typedef struct tagAttachConstraint{
    AttachConstraint_CLASS    
}AttachConstraint;
#endif//__AttachConstraint_INTERNAL__
