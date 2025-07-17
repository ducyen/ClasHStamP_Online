#ifndef __ObjsBuilder_H__
#define __ObjsBuilder_H__
#include "Sprite.h"
typedef struct tagObjsBuilder ObjsBuilder;
extern Sprite* g_objects[];
enum {
#define Rectangle_k8s           ( g_objects[ _Rectangle_k8s ] )
    _Rectangle_k8s,
#define carBody                 ( g_objects[ _carBody ] )
    _carBody,
#define Text_1sh                ( g_objects[ _Text_1sh ] )
    _Text_1sh,
#define resetBtn                ( g_objects[ _resetBtn ] )
    _resetBtn,
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
#define gear                    ( g_objects[ _gear ] )
    _gear,
#define batteryOper             ( g_objects[ _batteryOper ] )
    _batteryOper,
#define display                 ( g_objects[ _display ] )
    _display,
#define airbag                  ( g_objects[ _airbag ] )
    _airbag,
#define seatbelt                ( g_objects[ _seatbelt ] )
    _seatbelt,
#define speedometer             ( g_objects[ _speedometer ] )
    _speedometer,
#define fanCtrl                 ( g_objects[ _fanCtrl ] )
    _fanCtrl,
#define radar                   ( g_objects[ _radar ] )
    _radar
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
