#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define arm_main                ( g_objects[ _arm_main ] )
    _arm_main,
#define arm_right               ( g_objects[ _arm_right ] )
    _arm_right,
#define arm_left                ( g_objects[ _arm_left ] )
    _arm_left,
#define leftButton              ( g_objects[ _leftButton ] )
    _leftButton,
#define prize0                  ( g_objects[ _prize0 ] )
    _prize0,
#define prize1                  ( g_objects[ _prize1 ] )
    _prize1,
#define prize2                  ( g_objects[ _prize2 ] )
    _prize2,
#define arm_main_hanger         ( g_objects[ _arm_main_hanger ] )
    _arm_main_hanger,
#define gate_position           ( g_objects[ _gate_position ] )
    _gate_position,
#define clawMachine             ( g_objects[ _clawMachine ] )
    _clawMachine,
#define rightButton             ( g_objects[ _rightButton ] )
    _rightButton,
#define home_position           ( g_objects[ _home_position ] )
    _home_position,
#define clawButton              ( g_objects[ _clawButton ] )
    _clawButton,
#define prize3                  ( g_objects[ _prize3 ] )
    _prize3,
#define prize4                  ( g_objects[ _prize4 ] )
    _prize4,
#define arm_pivot_position      ( g_objects[ _arm_pivot_position ] )
    _arm_pivot_position
};
cpBool ObjsBuilder_collisionBegin( cpArbiter* arb, cpSpace* space, cpDataPointer userData );
int ObjsBuilder_startSim( void   );
void ObjsBuilder_showEntry( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDoing( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showExit( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDiagram( void* pObj, void* pStm_, char* pMsg, char r, char g, char b );
cpSpace* ObjsBuilder_getPhxSpace( void   );
int ObjsBuilder_getScreenWidth( void   );
int ObjsBuilder_getScreenHeight( void   );
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
