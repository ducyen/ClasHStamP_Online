#ifndef __TranslationConstraint_H__
#define __TranslationConstraint_H__
#include "TransformConstraint.h"
typedef struct tagTranslationConstraint TranslationConstraint;
#endif//__TranslationConstraint_H__
#if !defined( TranslationConstraint_Init ) && ( defined( __TranslationConstraint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof TranslationConstraint
 * @brief TranslationConstraint auto-generated constructor
 */
#define TranslationConstraint_Init(_m_source, _m_influence, _m_next)\
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gTranslationConstraintVtbl,\

#define TranslationConstraint_Ctor( _m_source, _m_influence, _m_next )    ( TranslationConstraint ){ \
    TranslationConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
extern const ConstraintVtbl gTranslationConstraintVtbl;
TransformConstraint* TranslationConstraint_Copy( TranslationConstraint* pTranslationConstraint, const TranslationConstraint* pSource );
/** @class TranslationConstraint
 * @extends TransformConstraint
 */
struct tagTranslationConstraint{
#define TranslationConstraint_CLASS                                                             \
    TransformConstraint_CLASS                                                                   \

    TranslationConstraint_CLASS    
};
#endif//__TranslationConstraint_INTERNAL__
