#ifndef __ClampConstraint_H__
#define __ClampConstraint_H__
#include "TransformConstraint.h"
typedef struct tagClampConstraint ClampConstraint;
#endif//__ClampConstraint_H__
#if !defined( ClampConstraint_Init ) && ( defined( __ClampConstraint_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof ClampConstraint
 * @brief ClampConstraint auto-generated constructor
 */
#define ClampConstraint_Init(_m_source, _m_target, _influence)\
    TransformConstraint_Init( P( _m_source ), P( _m_target ), P( _influence ) )\
    .vTbl = &gClampConstraintVtbl,\

#define ClampConstraint_Ctor( InitFunc, optionParams )    ( ClampConstraint ){\
    InitFunc\
\
}
extern const ConstraintVtbl gClampConstraintVtbl;
TransformConstraint* ClampConstraint_Copy( ClampConstraint* pClampConstraint, const ClampConstraint* pSource );
/** @class ClampConstraint
 * @extends TransformConstraint
 */
#define ClampConstraint_CLASS                                                                   \
    TransformConstraint_CLASS                                                                   \

typedef struct tagClampConstraint{
    ClampConstraint_CLASS    
}ClampConstraint;
#endif//__ClampConstraint_INTERNAL__
