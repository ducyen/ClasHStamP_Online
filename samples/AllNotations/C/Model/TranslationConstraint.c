/* File generated by Đức's ClasHStamP */
#define __TranslationConstraint_INTERNAL__
#include "CommonInclude.h"
#include "TranslationConstraint.h"
/** @public @memberof TranslationConstraint */
static void TranslationConstraint_apply(
    Constraint* pConstraint,
    Sprite* target
){
} /* TranslationConstraint_apply */

TransformConstraint* TranslationConstraint_Copy( TranslationConstraint* pTranslationConstraint, const TranslationConstraint* pSource ){
    TransformConstraint_Copy( ( TransformConstraint* )pTranslationConstraint, ( TransformConstraint* )pSource );
    return ( Constraint* )pTranslationConstraint;
}
const ConstraintVtbl gTranslationConstraintVtbl = {
    .papply                      = TranslationConstraint_apply,
};
