#ifndef __COMMON_INCLUDE_H__
#define __COMMON_INCLUDE_H__                                        /* 複数インクルード防止 */

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_rotozoom.h> // Include the SDL2_gfx library header
#include <SDL2_gfxPrimitives.h>
#include <SDL_ttf.h>

#include <chipmunk/chipmunk.h>

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#if defined( _MSC_VER )
#include <windows.h>
#else
#include <unistd.h>
#include <stdio.h>
#endif

#if !defined( _MSC_VER )
typedef int             boolean;
#endif
typedef int             bool;

#define false   ( 0 )
#define true    ( 1 )

typedef unsigned long   UINT32;
typedef unsigned short  UINT16;
typedef unsigned char   UINT8;
typedef int             BOOL;
typedef int             Bool;
typedef char            TCHAR;

#define _T(x)           x

#ifndef FALSE
#define FALSE   ( 0 )
#endif
#ifndef TRUE
#define TRUE    ( 1 )
#endif

#ifndef S_OK
#define S_OK    ( 0 )
#endif
#ifndef S_FALSE
#define S_FALSE ( 1 )
#endif

#define STATE_UNDEF                 ( 0x0000000000000000ULL )
#define IS_IN( leaf, composite )    ( composite >= leaf && ( composite & leaf ) > 0 )
#define UNREF( x )                  ( ( x ) = ( x ) )
#define MAX_STATE_NUM               ( 63 )

#define null                        ( ( void* )0 )
#ifndef NULL
#define NULL                        ( ( void* )0 )
#endif

#define P( ... )                    __VA_ARGS__

typedef struct tagString{ char buf[255]; }* String;
#define MakeString( charBuf )       ( ( String )&( struct tagString ){ charBuf } )
#define GetCharBuf( pStr )          ( ( pStr )->buf )

#ifndef LOBYTE
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#endif

#ifndef _MSC_VER
typedef unsigned long   COLORREF;
#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))
typedef unsigned char   BYTE;
typedef unsigned int    UINT;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

typedef unsigned long  ULONG_PTR;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;

#endif

typedef int ( *MouseAction )( void*, int, void* );

typedef struct tagEventParams{
    int cbSize;
}EventParams;

typedef struct tagRelativeRect{
    double x, y, w, h;
}RelativeRect;

typedef enum{
    MDD_ON_CLICK = SDL_USEREVENT,
    MDD_ON_VALUE_CHANGED,
    MDD_EVENT_TYPE_MAX
}MDD_EventType;

typedef struct Polygon {
    cpVect *vertices;
    int vertexCount;
    cpShape* shape;
    struct Polygon *next;
} Polygon;

const char* getInputDir( void );
const char* getOutputDir( void );

void ReleaseAllImages( void );
void SaveAllImages( void );
void ResetActionCounter( void );
void ObjsBuilder_showEntry( void*, void*, char* );
void ObjsBuilder_showExit( void*, void*, char* );
void ObjsBuilder_showDoing( void*, void*, char* );
cpSpace* ObjsBuilder_getPhxSpace( void   );
int ObjsBuilder_getScreenWidth( void   );
int ObjsBuilder_getScreenHeight( void   );
Polygon* decomposeConcavePolygon(cpVect *vertices, int vertexCount);
void freePolygons(Polygon *polygons);

#endif//__COMMON_INCLUDE_H__
