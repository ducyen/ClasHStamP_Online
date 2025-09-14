#ifndef __RotationConstraint_H__
#define __RotationConstraint_H__
#include "TransformConstraint.h"
typedef struct tagRotationConstraint RotationConstraint;
#endif//__RotationConstraint_H__
#if !defined( RotationConstraint_Init ) && ( defined( __RotationConstraint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"

/** @memberof RotationConstraint
 * @brief RotationConstraint auto-generated constructor
 */
#define RotationConstraint_Init(_m_source, _m_influence, _m_next)\
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gRotationConstraintVtbl,\

#define RotationConstraint_Ctor( _m_source, _m_influence, _m_next )    ( RotationConstraint ){ \
    RotationConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const ConstraintVtbl gRotationConstraintVtbl;
TransformConstraint* RotationConstraint_Copy( RotationConstraint* pRotationConstraint, const RotationConstraint* pSource );
/** @class RotationConstraint
 * @extends TransformConstraint
 */
struct tagRotationConstraint{
#define RotationConstraint_CLASS                                                                \
    TransformConstraint_CLASS                                                                   \

    RotationConstraint_CLASS    
};
#endif//__RotationConstraint_INTERNAL__
