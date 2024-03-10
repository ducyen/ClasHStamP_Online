#ifndef __TranslationConstraint_H__
#define __TranslationConstraint_H__
#include "TransformConstraint.h"
typedef struct tagTranslationConstraint TranslationConstraint;
#endif//__TranslationConstraint_H__
#if !defined( TranslationConstraint_Init ) && ( defined( __TranslationConstraint_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof TranslationConstraint
 * @brief TranslationConstraint auto-generated constructor
 */
#define TranslationConstraint_Init(_m_source, _m_target, _influence)\
    TransformConstraint_Init( P( _m_source ), P( _m_target ), P( _influence ) )\
    .vTbl = &gTranslationConstraintVtbl,\

#define TranslationConstraint_Ctor( InitFunc, optionParams )    ( TranslationConstraint ){\
    InitFunc\
\
}
extern const ConstraintVtbl gTranslationConstraintVtbl;
TransformConstraint* TranslationConstraint_Copy( TranslationConstraint* pTranslationConstraint, const TranslationConstraint* pSource );
/** @class TranslationConstraint
 * @extends TransformConstraint
 */
#define TranslationConstraint_CLASS                                                             \
    TransformConstraint_CLASS                                                                   \

typedef struct tagTranslationConstraint{
    TranslationConstraint_CLASS    
}TranslationConstraint;
#endif//__TranslationConstraint_INTERNAL__
