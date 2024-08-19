#ifndef __TransformConstraint_H__
#define __TransformConstraint_H__
#include "Constraint.h"
#include "ImgSprite.h"
typedef struct tagTransformConstraint TransformConstraint;
#endif//__TransformConstraint_H__
#if !defined( TransformConstraint_Init ) && ( defined( __TransformConstraint_INTERNAL__ )  )
#define __Constraint_INTERNAL__
#include "Constraint.h"
/** @memberof TransformConstraint
 * @brief TransformConstraint auto-generated constructor
 */
#define TransformConstraint_Init(_m_source, _m_influence, _m_next)\
    Constraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\

#define TransformConstraint_Ctor( _m_source, _m_influence, _m_next )    ( TransformConstraint ){ \
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
Constraint* TransformConstraint_Copy( TransformConstraint* pTransformConstraint, const TransformConstraint* pSource );
/** @class TransformConstraint
 * @extends Constraint
 */
struct tagTransformConstraint{
#define TransformConstraint_CLASS                                                               \
    Constraint_CLASS                                                                            \

    TransformConstraint_CLASS    
};
#endif//__TransformConstraint_INTERNAL__
