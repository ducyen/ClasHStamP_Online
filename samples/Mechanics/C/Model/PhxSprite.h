#ifndef __PhxSprite_H__
#define __PhxSprite_H__
#include "Sprite.h"
#include "PhxJoint.h"
typedef struct tagPhxSprite PhxSprite;
cpBody* PhxSprite_getBody( PhxSprite* pPhxSprite );
#endif//__PhxSprite_H__
#if !defined( PhxSprite_Init ) && ( defined( __PhxSprite_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Sprite_INTERNAL__
#include "Sprite.h"
#include "PhxJoint.h"
/** @memberof PhxSprite
 * @brief PhxSprite auto-generated constructor
 */
#define PhxSprite_Init(_m_iniRect, _m_name, _m_imgPath, _m_verts, _m_vertsCnt, _m_center, _m_mass, _m_group, _m_joints)\
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) )\
    .vTbl = &gPhxSpriteVtbl,\
    .m_verts = _m_verts,\
    .m_vertsCnt = _m_vertsCnt,\
    .m_center = _m_center,\
    .m_mass = _m_mass,\
    .m_group = _m_group,\
    .m_joints = _m_joints,\
    .m_body = null,\
    .m_shape = null,\
    .m_decomposedPolygons = null,\
    .m_sdlCenter = { 0 },\

#define PhxSprite_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_verts, _m_vertsCnt, _m_center, _m_mass, _m_group, _m_joints )    ( PhxSprite ){ \
    PhxSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_verts ), P( _m_vertsCnt ), P( _m_center ), P( _m_mass ), P( _m_group ), P( _m_joints ) ) \
}
extern const SpriteVtbl gPhxSpriteVtbl;
Sprite* PhxSprite_Copy( PhxSprite* pPhxSprite, const PhxSprite* pSource );
/** @class PhxSprite
 * @extends Sprite
 */
#define PhxSprite_CLASS                                                                         \
    Sprite_CLASS                                                                                \
    cpVect* m_verts;                                                                                                          \
    int m_vertsCnt;                                                                                                            \
    cpVect m_center;                                                                                                          \
    float m_mass;                                                                                                                \
    int m_group;                                                                                                                  \
    PhxJoint* m_joints;                                         \
    cpBody* m_body;                                                                                                            \
    cpShape* m_shape;                                                                                                        \
    cpPolygon* m_decomposedPolygons;                                                                          \
    SDL_Point m_sdlCenter;                                                                                              \

typedef struct tagPhxSprite{
    PhxSprite_CLASS    
}PhxSprite;
#endif//__PhxSprite_INTERNAL__
