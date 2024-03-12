#ifndef __COMMON_INCLUDE_H__
#define __COMMON_INCLUDE_H__                                        /* 複数インクルード防止 */

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_rotozoom.h> // Include the SDL2_gfx library header

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#if defined( _MSC_VER )
#include <windows.h>
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

typedef struct tagEventParams{
    int cbSize;
}EventParams;

typedef struct tagRelativeRect{
    double x, y, w, h;
}RelativeRect;

const char* getInputDir( void );
const char* getOutputDir( void );

#endif//__COMMON_INCLUDE_H__
