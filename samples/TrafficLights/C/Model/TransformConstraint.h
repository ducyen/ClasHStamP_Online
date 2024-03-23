#ifndef __TransformConstraint_H__
#define __TransformConstraint_H__
#include "Constraint.h"
#include "Sprite.h"
typedef struct tagTransformConstraint TransformConstraint;
#endif//__TransformConstraint_H__
#if !defined( TransformConstraint_Init ) && ( defined( __TransformConstraint_INTERNAL__ )  )
#define __Constraint_INTERNAL__
#include "Constraint.h"
#include "Sprite.h"
/** @memberof TransformConstraint
 * @brief TransformConstraint auto-generated constructor
 */
#define TransformConstraint_Init(_m_source, _m_target, _influence)\
    Constraint_Init(  )\
    .m_source = _m_source,\
    .m_target = _m_target,\
    .influence = _influence,\

#define TransformConstraint_Ctor( InitFunc, optionParams )    ( TransformConstraint ){\
    InitFunc\
\
}
Constraint* TransformConstraint_Copy( TransformConstraint* pTransformConstraint, const TransformConstraint* pSource );
/** @class TransformConstraint
 * @extends Constraint
 */
#define TransformConstraint_CLASS                                                               \
    Constraint_CLASS                                                                            \
    Sprite* m_source;                                           \
    Sprite* m_target;                                           \
    float influence;                                                                                                         \

typedef struct tagTransformConstraint{
    TransformConstraint_CLASS    
}TransformConstraint;
#endif//__TransformConstraint_INTERNAL__
