#ifndef __AttachmentConstraint_H__
#define __AttachmentConstraint_H__
#include "TransformConstraint.h"
typedef struct tagAttachmentConstraint AttachmentConstraint;
#endif//__AttachmentConstraint_H__
#if !defined( AttachmentConstraint_Init ) && ( defined( __AttachmentConstraint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof AttachmentConstraint
 * @brief AttachmentConstraint auto-generated constructor
 */
#define AttachmentConstraint_Init(_m_source, _m_influence, _m_next)\
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gAttachmentConstraintVtbl,\

#define AttachmentConstraint_Ctor( _m_source, _m_influence, _m_next )    ( AttachmentConstraint ){ \
    AttachmentConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const ConstraintVtbl gAttachmentConstraintVtbl;
TransformConstraint* AttachmentConstraint_Copy( AttachmentConstraint* pAttachmentConstraint, const AttachmentConstraint* pSource );
/** @class AttachmentConstraint
 * @extends TransformConstraint
 */
struct tagAttachmentConstraint{
#define AttachmentConstraint_CLASS                                                              \
    TransformConstraint_CLASS                                                                   \

    AttachmentConstraint_CLASS    
};
#endif//__AttachmentConstraint_INTERNAL__
