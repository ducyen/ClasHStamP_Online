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
#define Rectangle_4bm           ( getobj( _Rectangle_4bm ) )
    _Rectangle_4bm,
#define Oval_4dj                ( getobj( _Oval_4dj ) )
    _Oval_4dj,
#define Rectangle_4fh           ( getobj( _Rectangle_4fh ) )
    _Rectangle_4fh
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
