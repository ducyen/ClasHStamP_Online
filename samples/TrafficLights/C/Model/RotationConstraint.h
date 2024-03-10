#ifndef __RotationConstraint_H__
#define __RotationConstraint_H__
#include "TransformConstraint.h"
typedef struct tagRotationConstraint RotationConstraint;
#endif//__RotationConstraint_H__
#if !defined( RotationConstraint_Init ) && ( defined( __RotationConstraint_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof RotationConstraint
 * @brief RotationConstraint auto-generated constructor
 */
#define RotationConstraint_Init(_m_source, _m_target, _influence)\
    TransformConstraint_Init( P( _m_source ), P( _m_target ), P( _influence ) )\
    .vTbl = &gRotationConstraintVtbl,\

#define RotationConstraint_Ctor( InitFunc, optionParams )    ( RotationConstraint ){\
    InitFunc\
\
}
extern const ConstraintVtbl gRotationConstraintVtbl;
TransformConstraint* RotationConstraint_Copy( RotationConstraint* pRotationConstraint, const RotationConstraint* pSource );
/** @class RotationConstraint
 * @extends TransformConstraint
 */
#define RotationConstraint_CLASS                                                                \
    TransformConstraint_CLASS                                                                   \

typedef struct tagRotationConstraint{
    RotationConstraint_CLASS    
}RotationConstraint;
#endif//__RotationConstraint_INTERNAL__
