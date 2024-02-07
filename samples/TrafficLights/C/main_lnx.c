#define __Main_INTERNAL__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h> 
#include <pthread.h> 
#include <termios.h> 
#include <fcntl.h>
#include <png.h>
typedef unsigned long   COLORREF;
typedef unsigned char   BYTE;
typedef unsigned int    UINT;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

typedef unsigned long  ULONG_PTR;
typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))

typedef struct IWICBitmap{
    int width, height;
    png_bytep *row_pointers;
}IWICBitmap;

static char* itoa(
    int   _Value,
    char* _Buffer,
    int   _Radix
) {
    return _Buffer;
}

static void abort_( const char *s, ... ){
    va_list args;
    va_start( args, s );
    vfprintf( stderr, s, args );
    fprintf( stderr, "\n" );
    va_end( args );
    exit( 1 );
}
#include <assert.h>

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "Model/ContextImpl.h"

int InputValue(char* pMsg) {
    char n;
    printf( "%s", pMsg );
    scanf( "%c", &n );
    char c = 0;
    while( c != '\n' ){
        scanf( "%c", &c );
    }
    return n - '0';
}

void DisplayMsg(char* pMsg) {
    printf( "%s\n", pMsg );
}

/**
 * Directions
 */
enum{
    EAST,
    WEST,
    NORTH,
    SOUTH
};
/**
 * Light types
 */
enum{
    RED,
    YELLOW,
    GREEN,
    LIGHT_TYPE_NUM
};
/**
 * Light positions
 */
static const struct tagLightPositions{
    int x, y;
} LIGHT_POSITIONS[][ LIGHT_TYPE_NUM ] = {
    /*  red         yellow      green */
    { { 42, 37 }, { 47, 37 }, { 52, 37 } },   /* east  */
    { { 22, 26 }, { 17, 26 }, { 12, 26 } },   /* west  */
    { { 36, 21 }, { 36, 16 }, { 36, 11 } },   /* north */
    { { 28, 42 }, { 28, 48 }, { 28, 53 } },   /* south */
};

#define FONT_CHAR_HEIGHT    ( 7 )
#define FONT_CHAR_WIDTH     ( 5 )
#define TEXT_ALIGN_LEFT     ( 0 )
#define TEXT_ALIGN_RIGHT    ( 1 )
#define TEXT_ALIGN_BTM      ( 2 )

/* Generic to compute font bit on/off for this font */
#define FONT_BIT(c, column, row) \
  ((font_data[(c)+(column)] & 1<<(7-(row))) != 0)


static const unsigned char font_data[][5] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00 },   //  00
	{ 0x3E, 0x5B, 0x4F, 0x5B, 0x3E },   //  01
	{ 0x3E, 0x6B, 0x4F, 0x6B, 0x3E },   //  02
	{ 0x1C, 0x3E, 0x7C, 0x3E, 0x1C },   //  03
	{ 0x18, 0x3C, 0x7E, 0x3C, 0x18 },   //  04
	{ 0x1C, 0x57, 0x7D, 0x57, 0x1C },   //  05
	{ 0x1C, 0x5E, 0x7F, 0x5E, 0x1C },   //  06
	{ 0x00, 0x18, 0x3C, 0x18, 0x00 },   //  07
	{ 0xFF, 0xE7, 0xC3, 0xE7, 0xFF },   //  08
	{ 0x00, 0x18, 0x24, 0x18, 0x00 },   //  09
	{ 0xFF, 0xE7, 0xDB, 0xE7, 0xFF },   //  0A
	{ 0x30, 0x48, 0x3A, 0x06, 0x0E },   //  0B
	{ 0x26, 0x29, 0x79, 0x29, 0x26 },   //  0C
	{ 0x40, 0x7F, 0x05, 0x05, 0x07 },   //  0D
	{ 0x40, 0x7F, 0x05, 0x25, 0x3F },   //  0E
	{ 0x5A, 0x3C, 0xE7, 0x3C, 0x5A },   //  0F
	{ 0x7F, 0x3E, 0x1C, 0x1C, 0x08 },   //  10
	{ 0x08, 0x1C, 0x1C, 0x3E, 0x7F },   //  11
	{ 0x14, 0x22, 0x7F, 0x22, 0x14 },   //  12
	{ 0x5F, 0x5F, 0x00, 0x5F, 0x5F },   //  13
	{ 0x06, 0x09, 0x7F, 0x01, 0x7F },   //  14
	{ 0x00, 0x66, 0x89, 0x95, 0x6A },   //  15
	{ 0x60, 0x60, 0x60, 0x60, 0x60 },   //  16
	{ 0x94, 0xA2, 0xFF, 0xA2, 0x94 },   //  17
	{ 0x08, 0x04, 0x7E, 0x04, 0x08 },   //  18
	{ 0x10, 0x20, 0x7E, 0x20, 0x10 },   //  19
	{ 0x08, 0x08, 0x2A, 0x1C, 0x08 },   //  1A
	{ 0x08, 0x1C, 0x2A, 0x08, 0x08 },   //  1B
	{ 0x1E, 0x10, 0x10, 0x10, 0x10 },   //  1C
	{ 0x0C, 0x1E, 0x0C, 0x1E, 0x0C },   //  1D
	{ 0x30, 0x38, 0x3E, 0x38, 0x30 },   //  1E
	{ 0x06, 0x0E, 0x3E, 0x0E, 0x06 },   //  1F
	{ 0x00, 0x00, 0x00, 0x00, 0x00 },   //  20
	{ 0x00, 0x00, 0x5F, 0x00, 0x00 },   //  21
	{ 0x00, 0x07, 0x00, 0x07, 0x00 },   //  22
	{ 0x14, 0x7F, 0x14, 0x7F, 0x14 },   //  23
	{ 0x24, 0x2A, 0x7F, 0x2A, 0x12 },   //  24
	{ 0x23, 0x13, 0x08, 0x64, 0x62 },   //  25
	{ 0x36, 0x49, 0x56, 0x20, 0x50 },   //  26
	{ 0x00, 0x08, 0x07, 0x03, 0x00 },   //  27
	{ 0x00, 0x1C, 0x22, 0x41, 0x00 },   //  28
	{ 0x00, 0x41, 0x22, 0x1C, 0x00 },   //  29
	{ 0x2A, 0x1C, 0x7F, 0x1C, 0x2A },   //  2A
	{ 0x08, 0x08, 0x3E, 0x08, 0x08 },   //  2B
	{ 0x00, 0x80, 0x70, 0x30, 0x00 },   //  2C
	{ 0x08, 0x08, 0x08, 0x08, 0x08 },   //  2D
	{ 0x00, 0x00, 0x60, 0x60, 0x00 },   //  2E
	{ 0x20, 0x10, 0x08, 0x04, 0x02 },   //  2F
	{ 0x3E, 0x51, 0x49, 0x45, 0x3E },   //  30
	{ 0x00, 0x42, 0x7F, 0x40, 0x00 },   //  31
	{ 0x72, 0x49, 0x49, 0x49, 0x46 },   //  32
	{ 0x21, 0x41, 0x49, 0x4D, 0x33 },   //  33
	{ 0x18, 0x14, 0x12, 0x7F, 0x10 },   //  34
	{ 0x27, 0x45, 0x45, 0x45, 0x39 },   //  35
	{ 0x3C, 0x4A, 0x49, 0x49, 0x31 },   //  36
	{ 0x41, 0x21, 0x11, 0x09, 0x07 },   //  37
	{ 0x36, 0x49, 0x49, 0x49, 0x36 },   //  38
	{ 0x46, 0x49, 0x49, 0x29, 0x1E },   //  39
	{ 0x00, 0x00, 0x14, 0x00, 0x00 },   //  3A
	{ 0x00, 0x40, 0x34, 0x00, 0x00 },   //  3B
	{ 0x00, 0x08, 0x14, 0x22, 0x41 },   //  3C
	{ 0x14, 0x14, 0x14, 0x14, 0x14 },   //  3D
	{ 0x00, 0x41, 0x22, 0x14, 0x08 },   //  3E
	{ 0x02, 0x01, 0x59, 0x09, 0x06 },   //  3F
	{ 0x3E, 0x41, 0x5D, 0x59, 0x4E },   //  40
	{ 0x7C, 0x12, 0x11, 0x12, 0x7C },   //  41
	{ 0x7F, 0x49, 0x49, 0x49, 0x36 },   //  42
	{ 0x3E, 0x41, 0x41, 0x41, 0x22 },   //  43
	{ 0x7F, 0x41, 0x41, 0x41, 0x3E },   //  44
	{ 0x7F, 0x49, 0x49, 0x49, 0x41 },   //  45
	{ 0x7F, 0x09, 0x09, 0x09, 0x01 },   //  46
	{ 0x3E, 0x41, 0x41, 0x51, 0x73 },   //  47
	{ 0x7F, 0x08, 0x08, 0x08, 0x7F },   //  48
	{ 0x00, 0x41, 0x7F, 0x41, 0x00 },   //  49
	{ 0x20, 0x40, 0x41, 0x3F, 0x01 },   //  4A
	{ 0x7F, 0x08, 0x14, 0x22, 0x41 },   //  4B
	{ 0x7F, 0x40, 0x40, 0x40, 0x40 },   //  4C
	{ 0x7F, 0x02, 0x1C, 0x02, 0x7F },   //  4D
	{ 0x7F, 0x04, 0x08, 0x10, 0x7F },   //  4E
	{ 0x3E, 0x41, 0x41, 0x41, 0x3E },   //  4F
	{ 0x7F, 0x09, 0x09, 0x09, 0x06 },   //  50
	{ 0x3E, 0x41, 0x51, 0x21, 0x5E },   //  51
	{ 0x7F, 0x09, 0x19, 0x29, 0x46 },   //  52
	{ 0x26, 0x49, 0x49, 0x49, 0x32 },   //  53
	{ 0x03, 0x01, 0x7F, 0x01, 0x03 },   //  54
	{ 0x3F, 0x40, 0x40, 0x40, 0x3F },   //  55
	{ 0x1F, 0x20, 0x40, 0x20, 0x1F },   //  56
	{ 0x3F, 0x40, 0x38, 0x40, 0x3F },   //  57
	{ 0x63, 0x14, 0x08, 0x14, 0x63 },   //  58
	{ 0x03, 0x04, 0x78, 0x04, 0x03 },   //  59
	{ 0x61, 0x59, 0x49, 0x4D, 0x43 },   //  5A
	{ 0x00, 0x7F, 0x41, 0x41, 0x41 },   //  5B
	{ 0x02, 0x04, 0x08, 0x10, 0x20 },   //  5C
	{ 0x00, 0x41, 0x41, 0x41, 0x7F },   //  5D
	{ 0x04, 0x02, 0x01, 0x02, 0x04 },   //  5E
	{ 0x40, 0x40, 0x40, 0x40, 0x40 },   //  5F
	{ 0x00, 0x03, 0x07, 0x08, 0x00 },   //  60
	{ 0x20, 0x54, 0x54, 0x78, 0x40 },   //  61
	{ 0x7F, 0x28, 0x44, 0x44, 0x38 },   //  62
	{ 0x38, 0x44, 0x44, 0x44, 0x28 },   //  63
	{ 0x38, 0x44, 0x44, 0x28, 0x7F },   //  64
	{ 0x38, 0x54, 0x54, 0x54, 0x18 },   //  65
	{ 0x00, 0x08, 0x7E, 0x09, 0x02 },   //  66
	{ 0x18, 0xA4, 0xA4, 0x9C, 0x78 },   //  67
	{ 0x7F, 0x08, 0x04, 0x04, 0x78 },   //  68
	{ 0x00, 0x44, 0x7D, 0x40, 0x00 },   //  69
	{ 0x20, 0x40, 0x40, 0x3D, 0x00 },   //  6A
	{ 0x7F, 0x10, 0x28, 0x44, 0x00 },   //  6B
	{ 0x00, 0x41, 0x7F, 0x40, 0x00 },   //  6C
	{ 0x7C, 0x04, 0x78, 0x04, 0x78 },   //  6D
	{ 0x7C, 0x08, 0x04, 0x04, 0x78 },   //  6E
	{ 0x38, 0x44, 0x44, 0x44, 0x38 },   //  6F
	{ 0xFC, 0x18, 0x24, 0x24, 0x18 },   //  70
	{ 0x18, 0x24, 0x24, 0x18, 0xFC },   //  71
	{ 0x7C, 0x08, 0x04, 0x04, 0x08 },   //  72
	{ 0x48, 0x54, 0x54, 0x54, 0x24 },   //  73
	{ 0x04, 0x04, 0x3F, 0x44, 0x24 },   //  74
	{ 0x3C, 0x40, 0x40, 0x20, 0x7C },   //  75
	{ 0x1C, 0x20, 0x40, 0x20, 0x1C },   //  76
	{ 0x3C, 0x40, 0x30, 0x40, 0x3C },   //  77
	{ 0x44, 0x28, 0x10, 0x28, 0x44 },   //  78
	{ 0x4C, 0x90, 0x90, 0x90, 0x7C },   //  79
	{ 0x44, 0x64, 0x54, 0x4C, 0x44 },   //  7A
	{ 0x00, 0x08, 0x36, 0x41, 0x00 },   //  7B
	{ 0x00, 0x00, 0x77, 0x00, 0x00 },   //  7C
	{ 0x00, 0x41, 0x36, 0x08, 0x00 },   //  7D
	{ 0x02, 0x01, 0x02, 0x04, 0x02 },   //  7E
	{ 0x3C, 0x26, 0x23, 0x26, 0x3C },   //  7F
	{ 0x1E, 0xA1, 0xA1, 0x61, 0x12 },   //  80
	{ 0x3A, 0x40, 0x40, 0x20, 0x7A },   //  81
	{ 0x38, 0x54, 0x54, 0x55, 0x59 },   //  82
	{ 0x21, 0x55, 0x55, 0x79, 0x41 },   //  83
	{ 0x21, 0x54, 0x54, 0x78, 0x41 },   //  84
	{ 0x21, 0x55, 0x54, 0x78, 0x40 },   //  85
	{ 0x20, 0x54, 0x55, 0x79, 0x40 },   //  86
	{ 0x0C, 0x1E, 0x52, 0x72, 0x12 },   //  87
	{ 0x39, 0x55, 0x55, 0x55, 0x59 },   //  88
	{ 0x39, 0x54, 0x54, 0x54, 0x59 },   //  89
	{ 0x39, 0x55, 0x54, 0x54, 0x58 },   //  8A
	{ 0x00, 0x00, 0x45, 0x7C, 0x41 },   //  8B
	{ 0x00, 0x02, 0x45, 0x7D, 0x42 },   //  8C
	{ 0x00, 0x01, 0x45, 0x7C, 0x40 },   //  8D
	{ 0xF0, 0x29, 0x24, 0x29, 0xF0 },   //  8E
	{ 0xF0, 0x28, 0x25, 0x28, 0xF0 },   //  8F
	{ 0x7C, 0x54, 0x55, 0x45, 0x00 },   //  90
	{ 0x20, 0x54, 0x54, 0x7C, 0x54 },   //  91
	{ 0x7C, 0x0A, 0x09, 0x7F, 0x49 },   //  92
	{ 0x32, 0x49, 0x49, 0x49, 0x32 },   //  93
	{ 0x32, 0x48, 0x48, 0x48, 0x32 },   //  94
	{ 0x32, 0x4A, 0x48, 0x48, 0x30 },   //  95
	{ 0x3A, 0x41, 0x41, 0x21, 0x7A },   //  96
	{ 0x3A, 0x42, 0x40, 0x20, 0x78 },   //  97
	{ 0x00, 0x9D, 0xA0, 0xA0, 0x7D },   //  98
	{ 0x39, 0x44, 0x44, 0x44, 0x39 },   //  99
	{ 0x3D, 0x40, 0x40, 0x40, 0x3D },   //  9A
	{ 0x3C, 0x24, 0xFF, 0x24, 0x24 },   //  9B
	{ 0x48, 0x7E, 0x49, 0x43, 0x66 },   //  9C
	{ 0x2B, 0x2F, 0xFC, 0x2F, 0x2B },   //  9D
	{ 0xFF, 0x09, 0x29, 0xF6, 0x20 },   //  9E
	{ 0xC0, 0x88, 0x7E, 0x09, 0x03 },   //  9F
	{ 0x20, 0x54, 0x54, 0x79, 0x41 },   //  A0
	{ 0x00, 0x00, 0x44, 0x7D, 0x41 },   //  A1
	{ 0x30, 0x48, 0x48, 0x4A, 0x32 },   //  A2
	{ 0x38, 0x40, 0x40, 0x22, 0x7A },   //  A3
	{ 0x00, 0x7A, 0x0A, 0x0A, 0x72 },   //  A4
	{ 0x7D, 0x0D, 0x19, 0x31, 0x7D },   //  A5
	{ 0x26, 0x29, 0x29, 0x2F, 0x28 },   //  A6
	{ 0x26, 0x29, 0x29, 0x29, 0x26 },   //  A7
	{ 0x30, 0x48, 0x4D, 0x40, 0x20 },   //  A8
	{ 0x38, 0x08, 0x08, 0x08, 0x08 },   //  A9
	{ 0x08, 0x08, 0x08, 0x08, 0x38 },   //  AA
	{ 0x2F, 0x10, 0xC8, 0xAC, 0xBA },   //  AB
	{ 0x2F, 0x10, 0x28, 0x34, 0xFA },   //  AC
	{ 0x00, 0x00, 0x7B, 0x00, 0x00 },   //  AD
	{ 0x08, 0x14, 0x2A, 0x14, 0x22 },   //  AE
	{ 0x22, 0x14, 0x2A, 0x14, 0x08 },   //  AF
	{ 0xAA, 0x00, 0x55, 0x00, 0xAA },   //  B0
	{ 0xAA, 0x55, 0xAA, 0x55, 0xAA },   //  B1
	{ 0x00, 0x00, 0x00, 0xFF, 0x00 },   //  B2
	{ 0x10, 0x10, 0x10, 0xFF, 0x00 },   //  B3
	{ 0x14, 0x14, 0x14, 0xFF, 0x00 },   //  B4
	{ 0x10, 0x10, 0xFF, 0x00, 0xFF },   //  B5
	{ 0x10, 0x10, 0xF0, 0x10, 0xF0 },   //  B6
	{ 0x14, 0x14, 0x14, 0xFC, 0x00 },   //  B7
	{ 0x14, 0x14, 0xF7, 0x00, 0xFF },   //  B8
	{ 0x00, 0x00, 0xFF, 0x00, 0xFF },   //  B9
	{ 0x14, 0x14, 0xF4, 0x04, 0xFC },   //  BA
	{ 0x14, 0x14, 0x17, 0x10, 0x1F },   //  BB
	{ 0x10, 0x10, 0x1F, 0x10, 0x1F },   //  BC
	{ 0x14, 0x14, 0x14, 0x1F, 0x00 },   //  BD
	{ 0x10, 0x10, 0x10, 0xF0, 0x00 },   //  BE
	{ 0x00, 0x00, 0x00, 0x1F, 0x10 },   //  BF
	{ 0x10, 0x10, 0x10, 0x1F, 0x10 },   //  C0
	{ 0x10, 0x10, 0x10, 0xF0, 0x10 },   //  C1
	{ 0x00, 0x00, 0x00, 0xFF, 0x10 },   //  C2
	{ 0x10, 0x10, 0x10, 0x10, 0x10 },   //  C3
	{ 0x10, 0x10, 0x10, 0xFF, 0x10 },   //  C4
	{ 0x00, 0x00, 0x00, 0xFF, 0x14 },   //  C5
	{ 0x00, 0x00, 0xFF, 0x00, 0xFF },   //  C6
	{ 0x00, 0x00, 0x1F, 0x10, 0x17 },   //  C7
	{ 0x00, 0x00, 0xFC, 0x04, 0xF4 },   //  C8
	{ 0x14, 0x14, 0x17, 0x10, 0x17 },   //  C9
	{ 0x14, 0x14, 0xF4, 0x04, 0xF4 },   //  CA
	{ 0x00, 0x00, 0xFF, 0x00, 0xF7 },   //  CB
	{ 0x14, 0x14, 0x14, 0x14, 0x14 },   //  CC
	{ 0x14, 0x14, 0xF7, 0x00, 0xF7 },   //  CD
	{ 0x14, 0x14, 0x14, 0x17, 0x14 },   //  CE
	{ 0x10, 0x10, 0x1F, 0x10, 0x1F },   //  CF
	{ 0x14, 0x14, 0x14, 0xF4, 0x14 },   //  D0
	{ 0x10, 0x10, 0xF0, 0x10, 0xF0 },   //  D1
	{ 0x00, 0x00, 0x1F, 0x10, 0x1F },   //  D2
	{ 0x00, 0x00, 0x00, 0x1F, 0x14 },   //  D3
	{ 0x00, 0x00, 0x00, 0xFC, 0x14 },   //  D4
	{ 0x00, 0x00, 0xF0, 0x10, 0xF0 },   //  D5
	{ 0x10, 0x10, 0xFF, 0x10, 0xFF },   //  D6
	{ 0x14, 0x14, 0x14, 0xFF, 0x14 },   //  D7
	{ 0x10, 0x10, 0x10, 0x1F, 0x00 },   //  D8
	{ 0x00, 0x00, 0x00, 0xF0, 0x10 },   //  D9
	{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF },   //  DA
	{ 0xF0, 0xF0, 0xF0, 0xF0, 0xF0 },   //  DB
	{ 0xFF, 0xFF, 0xFF, 0x00, 0x00 },   //  DC
	{ 0x00, 0x00, 0x00, 0xFF, 0xFF },   //  DD
	{ 0x0F, 0x0F, 0x0F, 0x0F, 0x0F },   //  DE
	{ 0x38, 0x44, 0x44, 0x38, 0x44 },   //  DF
	{ 0x7C, 0x2A, 0x2A, 0x3E, 0x14 },   //  E0
	{ 0x7E, 0x02, 0x02, 0x06, 0x06 },   //  E1
	{ 0x02, 0x7E, 0x02, 0x7E, 0x02 },   //  E2
	{ 0x63, 0x55, 0x49, 0x41, 0x63 },   //  E3
	{ 0x38, 0x44, 0x44, 0x3C, 0x04 },   //  E4
	{ 0x40, 0x7E, 0x20, 0x1E, 0x20 },   //  E5
	{ 0x06, 0x02, 0x7E, 0x02, 0x02 },   //  E6
	{ 0x99, 0xA5, 0xE7, 0xA5, 0x99 },   //  E7
	{ 0x1C, 0x2A, 0x49, 0x2A, 0x1C },   //  E8
	{ 0x4C, 0x72, 0x01, 0x72, 0x4C },   //  E9
	{ 0x30, 0x4A, 0x4D, 0x4D, 0x30 },   //  EA
	{ 0x30, 0x48, 0x78, 0x48, 0x30 },   //  EB
	{ 0xBC, 0x62, 0x5A, 0x46, 0x3D },   //  EC
	{ 0x3E, 0x49, 0x49, 0x49, 0x00 },   //  ED
	{ 0x7E, 0x01, 0x01, 0x01, 0x7E },   //  EE
	{ 0x2A, 0x2A, 0x2A, 0x2A, 0x2A },   //  EF
	{ 0x44, 0x44, 0x5F, 0x44, 0x44 },   //  F0
	{ 0x40, 0x51, 0x4A, 0x44, 0x40 },   //  F1
	{ 0x40, 0x44, 0x4A, 0x51, 0x40 },   //  F2
	{ 0x00, 0x00, 0xFF, 0x01, 0x03 },   //  F3
	{ 0xE0, 0x80, 0xFF, 0x00, 0x00 },   //  F4
	{ 0x08, 0x08, 0x6B, 0x6B, 0x08 },   //  F5
	{ 0x36, 0x12, 0x36, 0x24, 0x36 },   //  F6
	{ 0x06, 0x0F, 0x09, 0x0F, 0x06 },   //  F7
	{ 0x00, 0x00, 0x18, 0x18, 0x00 },   //  F8
	{ 0x00, 0x00, 0x10, 0x10, 0x00 },   //  F9
	{ 0x30, 0x40, 0xFF, 0x01, 0x01 },   //  FA
	{ 0x00, 0x1F, 0x01, 0x01, 0x1E },   //  FB
	{ 0x00, 0x19, 0x1D, 0x17, 0x12 },   //  FC
	{ 0x00, 0x3C, 0x3C, 0x3C, 0x3C },   //  FD
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }    //  FE
};

// Function to place a character from the font into an RGBA bitmap
void placeCharacterInBitmap(BYTE *pv, unsigned char ch, int scale, int x, int y, int cbStride, COLORREF color ) {
    int fontIndex, i, j;
    fontIndex = ch;

    // Place the character into the bitmap
    for (i = 0; i < FONT_CHAR_WIDTH; ++i) {
        for (j = 0; j < FONT_CHAR_HEIGHT; ++j) {
            if ((font_data[fontIndex][i] >> j) & 1) {
                for( int u = 0; u < scale; u++ ){
                    for( int v = 0; v < scale; v++ ){
                        // Set the pixel to white (RGBA: 255, 255, 255, 255)
                        UINT destIndex = ( y + j*scale + v ) * cbStride + ( x + i*scale + u ) * 4;

                        // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                        pv[ destIndex ] = GetBValue( color );       // Blue
                        pv[ destIndex + 1 ] = GetGValue( color );   // Green
                        pv[ destIndex + 2 ] = GetRValue( color );   // Red
                        pv[ destIndex + 3 ] = 255; // Alpha
                    }
                }
            }
        }
    }
}

// Function to set pixel
static void setPixel( png_bytep *pv, int x, int y, int cbStride, COLORREF color ){
    UINT destIndex = x * 4;
    pv[ y ][ destIndex ] = GetBValue( color );       // Blue
    pv[ y ][ destIndex + 1 ] = GetGValue( color );   // Green
    pv[ y ][ destIndex + 2 ] = GetRValue( color );   // Red
    pv[ y ][ destIndex + 3 ] = 255; // Alpha
}

// Function to set pixel
static COLORREF getPixel( png_bytep *pv, int x, int y, int cbStride ){
    UINT destIndex = x * 4;
    return RGB( pv[ y ][ destIndex + 2 ], pv[ y ][ destIndex + 1 ], pv[ y ][ destIndex ] );
}

// Function to fill color
void fillColor( png_bytep *pv, int x, int y, int cbStride, int cHeight, COLORREF oldColor, COLORREF color ){
    if( 0 <= x && x * 4 < cbStride && 0 <= y && y < cHeight ){
        COLORREF curColor = getPixel( pv, x, y, cbStride );
        if( curColor == oldColor ){
            setPixel( pv, x, y, cbStride, color );
            fillColor( pv, x+1, y, cbStride, cHeight, oldColor, color );
            fillColor( pv, x-1, y, cbStride, cHeight, oldColor, color );
            fillColor( pv, x, y+1, cbStride, cHeight, oldColor, color );
            fillColor( pv, x, y-1, cbStride, cHeight, oldColor, color );
        }
    }
}

void SavePngImage( char*, IWICBitmap* );
IWICBitmap* FindBitmapFromPath( char* );

int directory_exists(const char *path) {
    struct stat statbuf;
    if( stat( path, &statbuf ) != 0 ){
        return 0;
    }
    return S_ISDIR( statbuf.st_mode );
}

int make_dir(const char *path) {
    char tmp[256];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", path);
    len = strlen(tmp);
    if(tmp[len - 1] == '/')
        tmp[len - 1] = 0;
    for(p = tmp + 1; *p; p++) {
        if(*p == '/') {
            *p = 0;
            if (!directory_exists(tmp)) {
                mode_t mode = 0755;
                if (mkdir(tmp, mode) == -1) {
                    return -1; // Failed to create directory
                }
            }
            *p = '/';
        }
    }
    return 0; // Directory already exists
}

/**
 * Load image from png file
 */
IWICBitmap* LoadPngImage( char* sPath ){
    IWICBitmap* pNewBitmap = malloc( sizeof( IWICBitmap ) );

    char* file_name = sPath;
    png_byte header[ 8 ];
    FILE *fp = fopen( file_name, "rb" );
    printf( "[read_png_file] Loading %s\n", file_name );
    if( !fp )
        abort_( "[read_png_file] File %s could not be opened for reading", file_name );
    fread( header, 1, 8, fp );
    if( png_sig_cmp( header, 0, 8 ) )
        abort_( "[read_png_file] File %s is not recognized as a PNG file", file_name );

    png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
    if( !png_ptr )
        abort_( "[read_png_file] png_create_read_struct failed" );

    png_infop info_ptr = png_create_info_struct( png_ptr );
    if( !info_ptr )
        abort_( "[read_png_file] png_create_info_struct failed" );

    if( setjmp( png_jmpbuf( png_ptr ) ) )
        abort_( "[read_png_file] Error during init_io" );

    png_init_io( png_ptr, fp );
    png_set_sig_bytes( png_ptr, 8 );
    png_read_info( png_ptr, info_ptr );

    int width = png_get_image_width( png_ptr, info_ptr );
    int height = png_get_image_height( png_ptr, info_ptr );

    if( png_get_color_type( png_ptr, info_ptr ) != PNG_COLOR_TYPE_RGBA ){
        abort_( "Unsupported color type" );
    }

    png_bytep *row_pointers = calloc( height, sizeof( png_bytep ) );
    for( int y = 0; y < height; y++ ){
        row_pointers[ y ] = ( png_bytep )malloc( 4 * width );
        png_read_row( png_ptr, row_pointers[ y ], NULL );
    }
    pNewBitmap->width = width;
    pNewBitmap->height = height;
    pNewBitmap->row_pointers = row_pointers;

    fclose( fp );
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    return pNewBitmap;
}

/**
 * action counter
 */
static int g_nActionCounter = 0;
/**
 * find bitmap from path
 */
static int g_nPathToBitmapCnt = 0;

static struct{
    char m_sPath[ 256 ];
    IWICBitmap* m_pIBitmap;
} g_arrPathToBitmap[ 10 ];

void ReleaseAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        if( g_arrPathToBitmap[ i ].m_pIBitmap ){
            for( int y = 0; y < sizeof( g_arrPathToBitmap[ i ].m_pIBitmap->row_pointers ) / sizeof( g_arrPathToBitmap[ i ].m_pIBitmap->row_pointers[ 0 ] ); y++ ){
                free( g_arrPathToBitmap[ i ].m_pIBitmap->row_pointers[ y ] );
            }
            free( g_arrPathToBitmap[ i ].m_pIBitmap->row_pointers );
            free( g_arrPathToBitmap[ i ].m_pIBitmap );
        }
    }
    g_nPathToBitmapCnt = 0;
}

void SaveAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        IWICBitmap *pIBitmap = FindBitmapFromPath( g_arrPathToBitmap[ i ].m_sPath );
        char sRelPath[ 256 ];
        sprintf( sRelPath, "../TransImg/Design/%s.png", g_arrPathToBitmap[ i ].m_sPath );
        make_dir( sRelPath );
        SavePngImage( sRelPath, pIBitmap );
    }
}

IWICBitmap* FindBitmapFromPath( char* sPath ){
    // Find if existed or not
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        if( strcmp( sPath, g_arrPathToBitmap[ i ].m_sPath ) == 0 ){
            return g_arrPathToBitmap[ i ].m_pIBitmap;
        }
    }
    // If not exsited, add new
    strcpy( g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_sPath, sPath );
    char sFullPath[ 255 ];
    sprintf( sFullPath, "../Image/Design/%s.png", sPath );
    IWICBitmap* pIBitmap = LoadPngImage( sFullPath );
    g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_pIBitmap = pIBitmap;
    g_nPathToBitmapCnt++;
    assert( g_nPathToBitmapCnt < sizeof( g_arrPathToBitmap ) / sizeof( g_arrPathToBitmap[ 0 ] ) );
    return pIBitmap;
}

/**
 * Flood fill on a png file
 */
int MyFloodFill( IWICBitmap *pIBitmap, int x, int y, COLORREF color ){

    int width = pIBitmap->width;
    int height = pIBitmap->height;

    UINT uiWidth = width;
    UINT uiHeight = height;

    // Pixel manipulation using the image data pointer pv.
    UINT cbStride = 4 * width;

    png_bytep *pv = pIBitmap->row_pointers;
    COLORREF oldColor = getPixel( pv, x, y, cbStride );
    if( oldColor != color ){
        fillColor( pv, x, y, cbStride, uiHeight, oldColor, color );
    }

    return 0;

}

/**
 * Draw rectangle on a png file
 */
int DrawRectangle( char* sPath, 
    int nLeft, int nTop, int nWidth, int nHeight, 
    int nDgrLeft, int nDgrTop, int nDgrWidth, int nDgrHeight,
    COLORREF color,
    unsigned char* sText,
    int nMargin, int nAlign
){
    IWICBitmap *pIBitmap = FindBitmapFromPath( sPath );

    int width = pIBitmap->width;
    int height = pIBitmap->height;

    UINT uiWidth = width;
    UINT uiHeight = height;

    // Pixel manipulation using the image data pointer pv.
    UINT cbStride = 4 * width;
    uiHeight -= ( 40 - 14 );
    //uiWidth  -= ( nLeftMgn + nRightMgn );
    nTop = ( float )( nTop - nDgrTop ) * uiHeight / nDgrHeight;
    nLeft = ( float )( nLeft - nDgrLeft ) * uiWidth / nDgrWidth;
    nHeight = ( float )nHeight * uiHeight / nDgrHeight;
    nWidth = ( float )nWidth * uiWidth / nDgrWidth;
    UINT nDotSize = 3;
    // Draw the rectangle on the destination bitmap
    for( UINT y = nTop; y < nTop + nHeight; y++ ){
        png_bytep pv = pIBitmap->row_pointers[ y ];

        for( UINT x = nLeft; x < nLeft + nWidth; x++ ){
            if( y >= nTop + nDotSize && y < nTop + nHeight - nDotSize && x >= nLeft + nDotSize && x < nLeft + nWidth - nDotSize ){
                ; // Do nothing
            } else{
                UINT destIndex = x * 4;

                // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                pv[ destIndex ] = GetBValue( color );      // Blue
                pv[ destIndex + 1 ] = GetGValue( color ); // Green
                pv[ destIndex + 2 ] = GetRValue( color );   // Red
                pv[ destIndex + 3 ] = 255; // Alpha
            }
        }
    }
    return 0;
}

/**
 * Save png image to file
 */
void SavePngImage( char* sPath, IWICBitmap *pIBitmap ){
    char* output_file_name = sPath;
    FILE *output_file = fopen( output_file_name, "wb" );
    if( !output_file )
        abort_( "Cannot open output file for writing" );

    png_structp output_png_ptr =
        png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
    if( !output_png_ptr )
        abort_( "png_create_write_struct failed" );

    png_infop output_info_ptr = png_create_info_struct( output_png_ptr );
    if( !output_info_ptr )
        abort_( "png_create_info_struct failed" );

    int width = pIBitmap->width;
    int height = pIBitmap->height;

    if( setjmp( png_jmpbuf( output_png_ptr ) ) )
        abort_( "Error during init_io" );

    png_init_io( output_png_ptr, output_file );

    png_set_IHDR( output_png_ptr, output_info_ptr, width, height, 8,
        PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT );
    png_write_info( output_png_ptr, output_info_ptr );

    for( int y = 0; y < height; y++ ){
        png_bytep row = pIBitmap->row_pointers[y];
        png_write_row( output_png_ptr, row );
    }

    png_write_end( output_png_ptr, NULL );
    fclose( output_file );
    png_destroy_write_struct( &output_png_ptr, &output_info_ptr );
}

void ShowEntry( char* pMsg ){

    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    char sCounter[ 10 ];
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, RGB( 0, 255, 0 ), itoa( g_nActionCounter++, sCounter, 10 ), 5, TEXT_ALIGN_LEFT );
}

void ShowDoing( char* pMsg ){

    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, RGB( 0, 0, 255 ), "", 5, TEXT_ALIGN_BTM );
}

void ShowExit( char* pMsg ){
    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    char sCounter[ 10 ];
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, RGB( 255, 0, 0 ), itoa( g_nActionCounter++, sCounter, 10 ), 5, TEXT_ALIGN_RIGHT );
}



#define INTERVAL_SEC 2

// Node for the message queue 
typedef struct node { 
    char data; 
    struct node* next; 
} Node;

// Queue structure 
typedef struct { 
    Node* front; 
    Node* rear;
    pthread_mutex_t lock; 
    pthread_cond_t cond;
} Queue;

// Initialize the queue 
void initQueue(Queue* q) { 
    q->front = q->rear = NULL;
    pthread_mutex_init(&q->lock, NULL); 
    pthread_cond_init(&q->cond, NULL);
}

// Enqueue a message 
void enqueue( Queue* q, char data ){
    Node* temp = ( Node* )malloc( sizeof( Node ) );
    temp->data = data;
    temp->next = NULL;

    pthread_mutex_lock( &q->lock );
    if( q->rear == NULL ){
        q->front = q->rear = temp;
    } else{
        q->rear->next = temp;
        q->rear = temp;
    }
    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->lock);
}

// Dequeue a message 
char dequeue( Queue* q ){
    pthread_mutex_lock( &q->lock );
    if( q->front == NULL ){
        pthread_cond_wait(&q->cond, &q->lock);
    }

    Node* temp = q->front;
    char data = temp->data;
    q->front = q->front->next;

    if( q->front == NULL ){
        q->rear = NULL;
    }

    free( temp );
    pthread_mutex_unlock( &q->lock );
    return data;
}

// Check for keyboard hit 
int kbhit(void) {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if( ch != EOF ){
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

// Keyboard Thread 
void* keyboard_thread( void* arg ){
    Queue* q = ( Queue* )arg;
    printf( "Keyboard thread started. Press 'q' to exit.\n" );

    while( 1 ){
        if( kbhit() ){
            char c = getchar();
            enqueue( q, c );
            if( c == 'q' ){
                break;
            }
        }
        usleep( 100000 ); // Sleep for 100 milliseconds
    }
    return NULL;
}

static struct timer_data{
    Queue* q;
    int value;
};
static pthread_t thread1, thread2;
static Queue q;

// Timer Thread 
void* timer_thread( void* arg ){
    struct timer_data* pmsg = arg;
    Queue* q = pmsg->q;

    sleep( pmsg->value );
    enqueue( q, -64 );

    return NULL;
}

static IWICBitmap* g_pIBmpSim;

void startTimer( int tmout ){
    struct timer_data* pmsg = malloc( sizeof( struct timer_data ) );
    pmsg->q = &q;
    pmsg->value = tmout;
    if( pthread_create( &thread2, NULL, timer_thread, ( void* )pmsg ) != 0 ){
        perror( "pthread_create for timer thread" );
    }
}

void TurnOnPrimaryRed( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ RED ].x, LIGHT_POSITIONS[ EAST ][ RED ].y, RGB( 255, 0, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ RED ].x, LIGHT_POSITIONS[ WEST ][ RED ].y, RGB( 255, 0, 0 ) );
}
void TurnOffPrimaryRed( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ RED ].x, LIGHT_POSITIONS[ EAST ][ RED ].y, RGB( 64, 0, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ RED ].x, LIGHT_POSITIONS[ WEST ][ RED ].y, RGB( 64, 0, 0 ) );
}
void TurnOnPrimaryYellow( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ YELLOW ].x, LIGHT_POSITIONS[ EAST ][ YELLOW ].y, RGB( 255, 255, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ YELLOW ].x, LIGHT_POSITIONS[ WEST ][ YELLOW ].y, RGB( 255, 255, 0 ) );
}
void TurnOffPrimaryYellow( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ YELLOW ].x, LIGHT_POSITIONS[ EAST ][ YELLOW ].y, RGB( 64, 64, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ YELLOW ].x, LIGHT_POSITIONS[ WEST ][ YELLOW ].y, RGB( 64, 64, 0 ) );
}
void TurnOnPrimaryGreen( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ GREEN ].x, LIGHT_POSITIONS[ EAST ][ GREEN ].y, RGB( 0, 255, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ GREEN ].x, LIGHT_POSITIONS[ WEST ][ GREEN ].y, RGB( 0, 255, 0 ) );
}
void TurnOffPrimaryGreen( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ EAST ][ GREEN ].x, LIGHT_POSITIONS[ EAST ][ GREEN ].y, RGB( 0, 64, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ WEST ][ GREEN ].x, LIGHT_POSITIONS[ WEST ][ GREEN ].y, RGB( 0, 64, 0 ) );
}

void TurnOnSecondaryRed( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ RED ].x, LIGHT_POSITIONS[ NORTH ][ RED ].y, RGB( 255, 0, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ RED ].x, LIGHT_POSITIONS[ SOUTH ][ RED ].y, RGB( 255, 0, 0 ) );
}
void TurnOffSecondaryRed( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ RED ].x, LIGHT_POSITIONS[ NORTH ][ RED ].y, RGB( 64, 0, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ RED ].x, LIGHT_POSITIONS[ SOUTH ][ RED ].y, RGB( 64, 0, 0 ) );
}
void TurnOnSecondaryYellow( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ YELLOW ].x, LIGHT_POSITIONS[ NORTH ][ YELLOW ].y, RGB( 255, 255, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ YELLOW ].x, LIGHT_POSITIONS[ SOUTH ][ YELLOW ].y, RGB( 255, 255, 0 ) );
}
void TurnOffSecondaryYellow( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ YELLOW ].x, LIGHT_POSITIONS[ NORTH ][ YELLOW ].y, RGB( 64, 64, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ YELLOW ].x, LIGHT_POSITIONS[ SOUTH ][ YELLOW ].y, RGB( 64, 64, 0 ) );
}
void TurnOnSecondaryGreen( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ GREEN ].x, LIGHT_POSITIONS[ NORTH ][ GREEN ].y, RGB( 0, 255, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ GREEN ].x, LIGHT_POSITIONS[ SOUTH ][ GREEN ].y, RGB( 0, 255, 0 ) );
}
void TurnOffSecondaryGreen( void ){
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ NORTH ][ GREEN ].x, LIGHT_POSITIONS[ NORTH ][ GREEN ].y, RGB( 0, 64, 0 ) );
    MyFloodFill( g_pIBmpSim, LIGHT_POSITIONS[ SOUTH ][ GREEN ].x, LIGHT_POSITIONS[ SOUTH ][ GREEN ].y, RGB( 0, 64, 0 ) );
}

int main(){
    initQueue( &q );

    g_pIBmpSim = LoadPngImage( "../Image/Visualized_2x_TrafficLights.png" );

    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( 
        4, "", 1, 2, 3, { 0 },
        Composition_Ctor( Composition_Init( 3 ), )
    ), );

    ContextImpl_Start( &context );

    // Create threads
    if( pthread_create( &thread1, NULL, keyboard_thread, ( void* )&q ) != 0 ){
        perror( "pthread_create for keyboard thread" );
        return EXIT_FAILURE;
    }

    while( 1 ){
        char msg = dequeue( &q );
        printf("Main thread received: %c\n", msg);
        if( msg == 'q' ){
            printf( "Exiting program.\n" );
            break;
        } else if( msg == -64 ){
            printf( "Timer event trigerred\n" );
            g_nActionCounter = 0;
            ContextImpl_EventProc( &context, ContextImpl_TMOUT, NULL);
            SaveAllImages();
            ReleaseAllImages();
            SavePngImage( "../TransImg/Visualized_2x_TrafficLights.png", g_pIBmpSim );
        } else{

        }
    }
    
    // Join Threads
    if( thread1 ) pthread_join( thread1, NULL );
    if( thread2 ) pthread_join( thread2, NULL );

    // Cleanup
    pthread_mutex_destroy(&q.lock);
    pthread_cond_destroy(&q.cond);

    ReleaseAllImages();
    if( g_pIBmpSim ){
        for( int y = 0; y < sizeof( g_pIBmpSim->row_pointers ) / sizeof( g_pIBmpSim->row_pointers[ 0 ] ); y++ ){
            free( g_pIBmpSim->row_pointers[ y ] );
        }
        free( g_pIBmpSim->row_pointers );
        free( g_pIBmpSim );
    }

    return EXIT_SUCCESS;
}
