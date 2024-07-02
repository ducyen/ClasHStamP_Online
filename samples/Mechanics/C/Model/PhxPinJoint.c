/* File generated by Đức's ClasHStamP */
#define __PhxPinJoint_INTERNAL__
#include "CommonInclude.h"
#include "PhxPinJoint.h"
#include "PhxSprite.h"                                          
/** @public @memberof PhxPinJoint */
static void PhxPinJoint_apply(
    PhxJoint* pPhxJoint,
    Sprite* target
){
    PhxPinJoint* pPhxPinJoint = ( PhxPinJoint* )pPhxJoint;
    cpSpace *space = ObjsBuilder_getPhxSpace();
    PhxSprite* pTarget = ( PhxSprite* )target;
    cpBody* pBodyTgt = PhxSprite_getBody( pTarget );
    cpBody* pBodySrc;
    if( pPhxPinJoint->m_source == null ){
        pBodySrc = cpSpaceGetStaticBody( space );
    }else{
        PhxSprite* pSource = ( PhxSprite* )( *pPhxPinJoint->m_source );
        pBodySrc = PhxSprite_getBody( pSource );
    }

    cpVect anchorSrc = cpvzero;
    if( pPhxPinJoint->m_anchorSrc != null){
        const SDL_Point* pCenter = Sprite_getCenter( *pPhxPinJoint->m_anchorSrc );
        cpVect center = cpv( pCenter->x, ObjsBuilder_getScreenHeight() - pCenter->y );
        anchorSrc = cpBodyWorldToLocal( pBodySrc, center );
    }

    cpVect anchorTgt = cpvzero;
    if( pPhxPinJoint->m_anchorTgt != null){
        const SDL_Point* pCenter = Sprite_getCenter( *pPhxPinJoint->m_anchorTgt );
        cpVect center = cpv( pCenter->x, ObjsBuilder_getScreenHeight() - pCenter->y );
        anchorTgt = cpBodyWorldToLocal( pBodyTgt, center );
    }
    if( pPhxPinJoint->m_cpJoint == null ){
        pPhxPinJoint->m_cpJoint = cpSpaceAddConstraint(
            space, 
            cpPinJointNew(
                pBodySrc, 
                pBodyTgt, 
                anchorSrc, 
                anchorTgt
            )
        );
        if( pPhxPinJoint->m_distance != null ){
            *pPhxPinJoint->m_distance = cpPinJointGetDist( pPhxPinJoint->m_cpJoint );
        }
    }else{
        cpPinJointSetAnchorA( pPhxPinJoint->m_cpJoint, anchorSrc );
        cpPinJointSetAnchorB( pPhxPinJoint->m_cpJoint, anchorTgt );
        if( pPhxPinJoint->m_distance != null ){
            cpPinJointSetDist( pPhxPinJoint->m_cpJoint, *pPhxPinJoint->m_distance );
        }
    }
} /* PhxPinJoint_apply */

PhxJoint* PhxPinJoint_Copy( PhxPinJoint* pPhxPinJoint, const PhxPinJoint* pSource ){
    PhxJoint_Copy( ( PhxJoint* )pPhxPinJoint, ( PhxJoint* )pSource );
    pPhxPinJoint->m_distance = pSource->m_distance;
    pPhxPinJoint->m_next0 = pSource->m_next0;
    return ( PhxJoint* )pPhxPinJoint;
}
const PhxJointVtbl gPhxPinJointVtbl = {
    .papply                      = PhxPinJoint_apply,
};
