#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define westRedLight            ( g_objects[ _westRedLight ] )
    _westRedLight,
#define eastRedLight            ( g_objects[ _eastRedLight ] )
    _eastRedLight,
#define westYellowLight         ( g_objects[ _westYellowLight ] )
    _westYellowLight,
#define westGreenLight          ( g_objects[ _westGreenLight ] )
    _westGreenLight,
#define eastYellowLight         ( g_objects[ _eastYellowLight ] )
    _eastYellowLight,
#define eastGreenLight          ( g_objects[ _eastGreenLight ] )
    _eastGreenLight,
#define northRedLight           ( g_objects[ _northRedLight ] )
    _northRedLight,
#define northYellowLight        ( g_objects[ _northYellowLight ] )
    _northYellowLight,
#define northGreenLight         ( g_objects[ _northGreenLight ] )
    _northGreenLight,
#define southRedLight           ( g_objects[ _southRedLight ] )
    _southRedLight,
#define southYellowLight        ( g_objects[ _southYellowLight ] )
    _southYellowLight,
#define southGreenLight         ( g_objects[ _southGreenLight ] )
    _southGreenLight,
#define Rectangle_4fh           ( g_objects[ _Rectangle_4fh ] )
    _Rectangle_4fh,
#define Rectangle_phs           ( g_objects[ _Rectangle_phs ] )
    _Rectangle_phs,
#define Rectangle_ps7           ( g_objects[ _Rectangle_ps7 ] )
    _Rectangle_ps7,
#define Rectangle_q2m           ( g_objects[ _Rectangle_q2m ] )
    _Rectangle_q2m,
#define Oval_rex                ( g_objects[ _Oval_rex ] )
    _Oval_rex,
#define Oval_rlz                ( g_objects[ _Oval_rlz ] )
    _Oval_rlz,
#define Oval_rwe                ( g_objects[ _Oval_rwe ] )
    _Oval_rwe,
#define Rectangle_sbx           ( g_objects[ _Rectangle_sbx ] )
    _Rectangle_sbx,
#define Oval_swa                ( g_objects[ _Oval_swa ] )
    _Oval_swa,
#define Oval_swb                ( g_objects[ _Oval_swb ] )
    _Oval_swb,
#define Oval_swc                ( g_objects[ _Oval_swc ] )
    _Oval_swc,
#define Rectangle_swd           ( g_objects[ _Rectangle_swd ] )
    _Rectangle_swd,
#define Oval_tjf                ( g_objects[ _Oval_tjf ] )
    _Oval_tjf,
#define Oval_tjg                ( g_objects[ _Oval_tjg ] )
    _Oval_tjg,
#define Oval_tjh                ( g_objects[ _Oval_tjh ] )
    _Oval_tjh,
#define Rectangle_tji           ( g_objects[ _Rectangle_tji ] )
    _Rectangle_tji,
#define Oval_u0q                ( g_objects[ _Oval_u0q ] )
    _Oval_u0q,
#define Oval_u0r                ( g_objects[ _Oval_u0r ] )
    _Oval_u0r,
#define Oval_u0s                ( g_objects[ _Oval_u0s ] )
    _Oval_u0s,
#define Rectangle_u0t           ( g_objects[ _Rectangle_u0t ] )
    _Rectangle_u0t,
#define carBody                 ( g_objects[ _carBody ] )
    _carBody,
#define rearWheels              ( g_objects[ _rearWheels ] )
    _rearWheels,
#define frontWheels             ( g_objects[ _frontWheels ] )
    _frontWheels
};
int ObjsBuilder_startSim( void   );
#endif//__ObjsBuilder_H__
#if !defined( ObjsBuilder_Init ) && ( defined( __ObjsBuilder_INTERNAL__ )  )
/** @memberof ObjsBuilder
 * @brief ObjsBuilder auto-generated constructor
 */
#define ObjsBuilder_Init()\

#define ObjsBuilder_Ctor(  )    ( ObjsBuilder ){ \
    ObjsBuilder_Init(  ) \
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
