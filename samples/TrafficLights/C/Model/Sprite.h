#ifndef __Sprite_H__
#define __Sprite_H__
#include "Constraint.h"
typedef struct tagSprite Sprite;
void Sprite_addConstraint( Sprite* pSprite, Constraint* constraint );
void Sprite_translate( Sprite* pSprite, int dx, int dy );
void Sprite_rotate( Sprite* pSprite, double dAngle );
void Sprite_draw( Sprite* pSprite, SDL_Surface* screenSurface );
bool Sprite_load( Sprite* pSprite );
void Sprite_free( Sprite* pSprite );
#endif//__Sprite_H__
#if !defined( Sprite_Init ) && ( defined( __Sprite_INTERNAL__ )  )
#define __Constraint_INTERNAL__
#include "Constraint.h"
/** @memberof Sprite
 * @brief Sprite auto-generated constructor
 */
#define Sprite_Init(_m_iniRect, _m_imgPath, _m_x, _m_y, _m_angle)\
    .m_iniRect = _m_iniRect,\
    .m_imgPath = _m_imgPath,\
    .m_image = null,\
    .m_x = _m_x,\
    .m_y = _m_y,\
    .m_angle = _m_angle,\
    .m_constraints = P( { 0 } ),\
    .m_constraintCount = 0,\

#define Sprite_Ctor( InitFunc, optionParams )    ( Sprite ){\
    InitFunc\
\
}
Sprite* Sprite_Copy( Sprite* pSprite, const Sprite* pSource );
/** @class Sprite
 * @extends 
 */
#define Sprite_CLASS                                                                            \
    size_t cbSize;                                                                              \
    RelativeRect m_iniRect;                                                                                           \
    char* m_imgPath;                                                                                                         \
    SDL_Surface* m_image;                                                                                               \
    int m_x;                                                                                                                         \
    int m_y;                                                                                                                         \
    double m_angle;                                                                                                           \
    Constraint m_constraints[ 32 ];                             \
    int m_constraintCount;                                                                                             \

typedef struct tagSprite{
    Sprite_CLASS    
}Sprite;
#endif//__Sprite_INTERNAL__
