/* File generated by Đức's ClasHStamP */
#define __PhxGrooveJoint_INTERNAL__
#include "CommonInclude.h"
#include "PhxGrooveJoint.h"
/** @public @memberof PhxGrooveJoint */
static void PhxGrooveJoint_apply(
    PhxJoint* pPhxJoint,
    Sprite* target
){
    PhxGrooveJoint* pPhxGrooveJoint = ( PhxGrooveJoint* )pPhxJoint;
} /* PhxGrooveJoint_apply */

PhxJoint* PhxGrooveJoint_Copy( PhxGrooveJoint* pPhxGrooveJoint, const PhxGrooveJoint* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxGrooveJoint, ( PhxJoint* )pSource );
    return ( PhxJoint* )pPhxGrooveJoint;
}
const PhxJointVtbl gPhxGrooveJointVtbl = {
    .papply                      = PhxGrooveJoint_apply,
};
