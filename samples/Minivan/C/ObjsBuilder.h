#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define rightWiperArm           ( g_objects[ _rightWiperArm ] )
    _rightWiperArm,
#define leftWiperArm            ( g_objects[ _leftWiperArm ] )
    _leftWiperArm,
#define rightWiperAxis          ( g_objects[ _rightWiperAxis ] )
    _rightWiperAxis,
#define leftWiperAxis           ( g_objects[ _leftWiperAxis ] )
    _leftWiperAxis,
#define wiperLever              ( g_objects[ _wiperLever ] )
    _wiperLever,
#define powerButton             ( g_objects[ _powerButton ] )
    _powerButton
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
