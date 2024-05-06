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
#define rightWiperMotor         ( g_objects[ _rightWiperMotor ] )
    _rightWiperMotor,
#define leftWiperMotor          ( g_objects[ _leftWiperMotor ] )
    _leftWiperMotor,
#define wiperLever              ( g_objects[ _wiperLever ] )
    _wiperLever,
#define powerButton             ( g_objects[ _powerButton ] )
    _powerButton,
#define carBody                 ( g_objects[ _carBody ] )
    _carBody,
#define Text_427                ( g_objects[ _Text_427 ] )
    _Text_427,
#define pushButton              ( g_objects[ _pushButton ] )
    _pushButton,
#define selectButton            ( g_objects[ _selectButton ] )
    _selectButton,
#define toggleButton            ( g_objects[ _toggleButton ] )
    _toggleButton,
#define slideButton             ( g_objects[ _slideButton ] )
    _slideButton
};
int ObjsBuilder_startSim( void   );
void ObjsBuilder_showEntry( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDoing( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showExit( void* pObj, void* pStm_, char* pMsg );
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
