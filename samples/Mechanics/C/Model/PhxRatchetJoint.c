/* File generated by Đức's ClasHStamP */
#define __PhxRatchetJoint_INTERNAL__
#include "CommonInclude.h"
#include "PhxRatchetJoint.h"
/** @public @memberof PhxRatchetJoint */
static void PhxRatchetJoint_apply(
    PhxJoint* pPhxJoint,
    Sprite* target
){
    PhxRatchetJoint* pPhxRatchetJoint = ( PhxRatchetJoint* )pPhxJoint;
} /* PhxRatchetJoint_apply */

PhxJoint* PhxRatchetJoint_Copy( PhxRatchetJoint* pPhxRatchetJoint, const PhxRatchetJoint* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxRatchetJoint, ( PhxJoint* )pSource );
    return ( PhxJoint* )pPhxRatchetJoint;
}
const PhxJointVtbl gPhxRatchetJointVtbl = {
    .papply                      = PhxRatchetJoint_apply,
};
