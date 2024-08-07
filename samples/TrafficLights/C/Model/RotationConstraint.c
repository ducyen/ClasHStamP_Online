/* File generated by Đức's ClasHStamP */
#define __RotationConstraint_INTERNAL__
#include "CommonInclude.h"
#include "RotationConstraint.h"
/** @public @memberof RotationConstraint */
static void RotationConstraint_apply(
    RotationConstraint* pRotationConstraint,
    Sprite* target
){
    if( pRotationConstraint->m_influence == 0 ){
        return;
    }

    ImgSprite* pSource = ( ImgSprite* )*pRotationConstraint->m_source;
    ImgSprite* pTarget = ( ImgSprite* )target;
    double sourceRot = ImgSprite_getRotation( pSource );
    double targetRot = ImgSprite_getRotation( pTarget );
    ImgSprite_setRotation( pSource, sourceRot + targetRot );

} /* RotationConstraint_apply */

TransformConstraint* RotationConstraint_Copy( RotationConstraint* pRotationConstraint, const RotationConstraint* pSource ){
    TransformConstraint_Copy( ( TransformConstraint* )pRotationConstraint, ( TransformConstraint* )pSource );
    return ( Constraint* )pRotationConstraint;
}
const ConstraintVtbl gRotationConstraintVtbl = {
    .papply                      = RotationConstraint_apply,
};
