/* File generated by Đức's ClasHStamP */
#define __PhxPinJoint_INTERNAL__
#include "CommonInclude.h"
#include "PhxPinJoint.h"
/** @public @memberof PhxPinJoint */
static void PhxPinJoint_apply(
    PhxPinJoint* pPhxPinJoint,
    Sprite* target
){
} /* PhxPinJoint_apply */

PhxJoint* PhxPinJoint_Copy( PhxPinJoint* pPhxPinJoint, const PhxPinJoint* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxPinJoint, ( PhxJoint* )pSource );
    return ( PhxJoint* )pPhxPinJoint;
}
const PhxJointVtbl gPhxPinJointVtbl = {
    .papply                      = PhxPinJoint_apply,
};