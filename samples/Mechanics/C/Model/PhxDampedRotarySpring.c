/* File generated by Đức's ClasHStamP */
#define __PhxDampedRotarySpring_INTERNAL__
#include "CommonInclude.h"
#include "PhxDampedRotarySpring.h"
/** @public @memberof PhxDampedRotarySpring */
static void PhxDampedRotarySpring_apply(
    PhxJoint* pPhxJoint,
    Sprite* target
){
    PhxDampedRotarySpring* pPhxDampedRotarySpring = ( PhxDampedRotarySpring* )pPhxJoint;
} /* PhxDampedRotarySpring_apply */

PhxJoint* PhxDampedRotarySpring_Copy( PhxDampedRotarySpring* pPhxDampedRotarySpring, const PhxDampedRotarySpring* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxDampedRotarySpring, ( PhxJoint* )pSource );
    return ( PhxJoint* )pPhxDampedRotarySpring;
}
const PhxJointVtbl gPhxDampedRotarySpringVtbl = {
    .papply                      = PhxDampedRotarySpring_apply,
};
