#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define carBody                 ( g_objects[ _carBody ] )
    _carBody,
#define Text_1sh                ( g_objects[ _Text_1sh ] )
    _Text_1sh,
#define selectBtn               ( g_objects[ _selectBtn ] )
    _selectBtn,
#define resetBtn                ( g_objects[ _resetBtn ] )
    _resetBtn,
#define toggleBtn               ( g_objects[ _toggleBtn ] )
    _toggleBtn,
#define slider                  ( g_objects[ _slider ] )
    _slider,
#define Text_30d                ( g_objects[ _Text_30d ] )
    _Text_30d,
#define Text_389                ( g_objects[ _Text_389 ] )
    _Text_389,
#define Text_3ht                ( g_objects[ _Text_3ht ] )
    _Text_3ht,
#define Text_3re                ( g_objects[ _Text_3re ] )
    _Text_3re,
#define Text_4by                ( g_objects[ _Text_4by ] )
    _Text_4by,
#define pushBtn0                ( g_objects[ _pushBtn0 ] )
    _pushBtn0,
#define Text_76n                ( g_objects[ _Text_76n ] )
    _Text_76n,
#define pushBtn1                ( g_objects[ _pushBtn1 ] )
    _pushBtn1,
#define Text_7ik                ( g_objects[ _Text_7ik ] )
    _Text_7ik,
#define pushBtn2                ( g_objects[ _pushBtn2 ] )
    _pushBtn2,
#define Text_9uo                ( g_objects[ _Text_9uo ] )
    _Text_9uo,
#define pushBtn3                ( g_objects[ _pushBtn3 ] )
    _pushBtn3,
#define Text_c7m                ( g_objects[ _Text_c7m ] )
    _Text_c7m,
#define pushBtn4                ( g_objects[ _pushBtn4 ] )
    _pushBtn4,
#define Text_euz                ( g_objects[ _Text_euz ] )
    _Text_euz,
#define pushBtn5                ( g_objects[ _pushBtn5 ] )
    _pushBtn5,
#define Text_hkt                ( g_objects[ _Text_hkt ] )
    _Text_hkt,
#define batteryLife             ( g_objects[ _batteryLife ] )
    _batteryLife,
#define Text_40e                ( g_objects[ _Text_40e ] )
    _Text_40e,
#define Text_41a                ( g_objects[ _Text_41a ] )
    _Text_41a
};
int ObjsBuilder_startSim( void   );
void ObjsBuilder_showEntry( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDoing( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showExit( void* pObj, void* pStm_, char* pMsg );
void ObjsBuilder_showDiagram( void* pObj, void* pStm_, char* pMsg, char r, char g, char b, int sizeAdj );
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
struct tagObjsBuilder{
#define ObjsBuilder_CLASS                                                                       \
    size_t cbSize;                                                                              \

    ObjsBuilder_CLASS    
};
#endif//__ObjsBuilder_INTERNAL__
