#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
enum {
#define westRedLight            ( getobj( _westRedLight ) )
    _westRedLight,
#define eastRedLight            ( getobj( _eastRedLight ) )
    _eastRedLight,
#define westYellowLight         ( getobj( _westYellowLight ) )
    _westYellowLight,
#define westGreenLight          ( getobj( _westGreenLight ) )
    _westGreenLight,
#define eastYellowLight         ( getobj( _eastYellowLight ) )
    _eastYellowLight,
#define eastGreenLight          ( getobj( _eastGreenLight ) )
    _eastGreenLight,
#define northRedLight           ( getobj( _northRedLight ) )
    _northRedLight,
#define northYellowLight        ( getobj( _northYellowLight ) )
    _northYellowLight,
#define northGreenLight         ( getobj( _northGreenLight ) )
    _northGreenLight,
#define southRedLight           ( getobj( _southRedLight ) )
    _southRedLight,
#define southYellowLight        ( getobj( _southYellowLight ) )
    _southYellowLight,
#define southGreenLight         ( getobj( _southGreenLight ) )
    _southGreenLight,
#define Rectangle_4fh           ( getobj( _Rectangle_4fh ) )
    _Rectangle_4fh,
#define Rectangle_phs           ( getobj( _Rectangle_phs ) )
    _Rectangle_phs,
#define Rectangle_ps7           ( getobj( _Rectangle_ps7 ) )
    _Rectangle_ps7,
#define Rectangle_q2m           ( getobj( _Rectangle_q2m ) )
    _Rectangle_q2m,
#define Oval_rex                ( getobj( _Oval_rex ) )
    _Oval_rex,
#define Oval_rlz                ( getobj( _Oval_rlz ) )
    _Oval_rlz,
#define Oval_rwe                ( getobj( _Oval_rwe ) )
    _Oval_rwe,
#define Rectangle_sbx           ( getobj( _Rectangle_sbx ) )
    _Rectangle_sbx,
#define Oval_swa                ( getobj( _Oval_swa ) )
    _Oval_swa,
#define Oval_swb                ( getobj( _Oval_swb ) )
    _Oval_swb,
#define Oval_swc                ( getobj( _Oval_swc ) )
    _Oval_swc,
#define Rectangle_swd           ( getobj( _Rectangle_swd ) )
    _Rectangle_swd,
#define Oval_tjf                ( getobj( _Oval_tjf ) )
    _Oval_tjf,
#define Oval_tjg                ( getobj( _Oval_tjg ) )
    _Oval_tjg,
#define Oval_tjh                ( getobj( _Oval_tjh ) )
    _Oval_tjh,
#define Rectangle_tji           ( getobj( _Rectangle_tji ) )
    _Rectangle_tji,
#define Oval_u0q                ( getobj( _Oval_u0q ) )
    _Oval_u0q,
#define Oval_u0r                ( getobj( _Oval_u0r ) )
    _Oval_u0r,
#define Oval_u0s                ( getobj( _Oval_u0s ) )
    _Oval_u0s,
#define Rectangle_u0t           ( getobj( _Rectangle_u0t ) )
    _Rectangle_u0t
};
Sprite* getobj( int id );
int ObjsBuilder_startSim( void   );
#endif//__ObjsBuilder_H__
#if !defined( ObjsBuilder_Init ) && ( defined( __ObjsBuilder_INTERNAL__ )  )
/** @memberof ObjsBuilder
 * @brief ObjsBuilder auto-generated constructor
 */
#define ObjsBuilder_Init()\

#define ObjsBuilder_Ctor( InitFunc, optionParams )    ( ObjsBuilder ){\
    InitFunc\
\
}
ObjsBuilder* ObjsBuilder_Copy( ObjsBuilder* pObjsBuilder, const ObjsBuilder* pSource );
/** @class ObjsBuilder
 * @extends 
 */
#define ObjsBuilder_CLASS                                                                       \
    size_t cbSize;                                                                              \

typedef struct tagObjsBuilder{
    ObjsBuilder_CLASS    
}ObjsBuilder;
#endif//__ObjsBuilder_INTERNAL__
