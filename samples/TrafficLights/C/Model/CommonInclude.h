#ifndef __COMMON_INCLUDE_H__
#define __COMMON_INCLUDE_H__                                        /* 複数インクルード防止 */

#include <stddef.h>
#include <stdint.h>
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

#define FALSE   ( 0 )
#define TRUE    ( 1 )

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

#endif//__COMMON_INCLUDE_H__
