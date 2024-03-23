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
#include <sys/stat.h>

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

static char* g_sInputDir = "../Image/Design";
const char* getInputDir( void ) { return g_sInputDir; }
static char* g_sOutputDir = "../TransImg/Design";
const char* getOutputDir( void ) { return g_sOutputDir; }

int InputValue(char* pMsg);
void DisplayMsg(char* pMsg);

#include "CommonInclude.h"
#include "ObjsBuilder.h";

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

#define FONT_CHAR_HEIGHT    ( 7 )
#define FONT_CHAR_WIDTH     ( 5 )
#define TEXT_ALIGN_LEFT     ( 0 )
#define TEXT_ALIGN_RIGHT    ( 1 )
#define TEXT_ALIGN_BTM      ( 2 )

#define IWICBitmap          SDL_Surface

// Function to place a character from the font into an RGBA bitmap
void placeCharacterInBitmap(BYTE *pv, unsigned char ch, int scale, int x, int y, int cbStride, COLORREF color ) {
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

    IWICBitmap *pIBitmap = IMG_Load( sPath );

    return pIBitmap;
}

/**
 * action counter
 */
static int g_nActionCounter = 0;
void ResetActionCounter( void ){
    g_nActionCounter = 0;
}

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
            SDL_FreeSurface( g_arrPathToBitmap[ i ].m_pIBitmap );
        }
    }
    g_nPathToBitmapCnt = 0;
}

void SaveAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        IWICBitmap *pIBitmap = FindBitmapFromPath( g_arrPathToBitmap[ i ].m_sPath );
        char sRelPath[ 256 ];
        sprintf( sRelPath, "%s/%s.png", g_sOutputDir, g_arrPathToBitmap[ i ].m_sPath );
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
    sprintf( sFullPath, "%s/%s.png", g_sInputDir, sPath );
    IWICBitmap* pIBitmap = LoadPngImage( sFullPath );
    g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_pIBitmap = pIBitmap;
    g_nPathToBitmapCnt++;
    assert( g_nPathToBitmapCnt < sizeof( g_arrPathToBitmap ) / sizeof( g_arrPathToBitmap[ 0 ] ) );
    return pIBitmap;
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
    UINT uiWidth = pIBitmap->w;
    UINT uiHeight = pIBitmap->h;

    uiHeight -= 20;
    //uiWidth  -= ( nLeftMgn + nRightMgn );
    nTop = ( float )( nTop - nDgrTop ) * uiHeight / nDgrHeight;
    nLeft = ( float )( nLeft - nDgrLeft ) * uiWidth / nDgrWidth;
    nHeight = ( float )nHeight * uiHeight / nDgrHeight;
    nWidth = ( float )nWidth * uiWidth / nDgrWidth;
    UINT nDotSize = 3;

    SDL_FillRect( pIBitmap, &( SDL_Rect ){ nLeft                , nTop                 , nWidth  , nDotSize }, SDL_MapRGB(pIBitmap->format, GetRValue( color ), GetGValue( color ), GetBValue( color )) );
    SDL_FillRect( pIBitmap, &( SDL_Rect ){ nLeft+nWidth-nDotSize, nTop                 , nDotSize, nHeight  }, SDL_MapRGB(pIBitmap->format, GetRValue( color ), GetGValue( color ), GetBValue( color )) );
    SDL_FillRect( pIBitmap, &( SDL_Rect ){ nLeft                , nTop+nHeight-nDotSize, nWidth  , nDotSize }, SDL_MapRGB(pIBitmap->format, GetRValue( color ), GetGValue( color ), GetBValue( color )) );
    SDL_FillRect( pIBitmap, &( SDL_Rect ){ nLeft                , nTop                 , nDotSize, nHeight }, SDL_MapRGB(pIBitmap->format, GetRValue( color ), GetGValue( color ), GetBValue( color )) );

}

/**
 * Save png image to file
 */
void SavePngImage( char* sPath, IWICBitmap *pIBitmap ){
    IMG_SavePNG(pIBitmap, sPath);
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

void startTimer( int tmout ){
}

void TurnOnPrimaryRed( void ){
    Sprite_setBrightness( westRedLight, 1 );
    Sprite_setBrightness( eastRedLight, 1 );
}
void TurnOffPrimaryRed( void ){
    Sprite_setBrightness( westRedLight, 0.25 );
    Sprite_setBrightness( eastRedLight, 0.25 );
}
void TurnOnPrimaryYellow( void ){
    Sprite_setBrightness( westYellowLight, 1 );
    Sprite_setBrightness( eastYellowLight, 1 );
}
void TurnOffPrimaryYellow( void ){
    Sprite_setBrightness( westYellowLight, 0.25 );
    Sprite_setBrightness( eastYellowLight, 0.25 );
}
void TurnOnPrimaryGreen( void ){
    Sprite_setBrightness( westGreenLight, 1 );
    Sprite_setBrightness( eastGreenLight, 1 );
}
void TurnOffPrimaryGreen( void ){
    Sprite_setBrightness( westGreenLight, 0.25 );
    Sprite_setBrightness( eastGreenLight, 0.25 );
}
void TurnOnSecondaryRed( void ){
    Sprite_setBrightness( northRedLight, 1 );
    Sprite_setBrightness( southRedLight, 1 );
}
void TurnOffSecondaryRed( void ){
    Sprite_setBrightness( northRedLight, 0.25 );
    Sprite_setBrightness( southRedLight, 0.25 );
}
void TurnOnSecondaryYellow( void ){
    Sprite_setBrightness( northYellowLight, 1 );
    Sprite_setBrightness( southYellowLight, 1 );
}
void TurnOffSecondaryYellow( void ){
    Sprite_setBrightness( northYellowLight, 0.25 );
    Sprite_setBrightness( southYellowLight, 0.25 );
}
void TurnOnSecondaryGreen( void ){
    Sprite_setBrightness( northGreenLight, 1 );
    Sprite_setBrightness( southGreenLight, 1 );
}
void TurnOffSecondaryGreen( void ){
    Sprite_setBrightness( northGreenLight, 0.25 );
    Sprite_setBrightness( southGreenLight, 0.25 );
}

int main(int argc, char **argv){
    if (argc >= 3) {
        g_sInputDir  = argv[ 1 ];
        g_sOutputDir = argv[ 2 ];
        printf( "arguments: %s %s\n", g_sInputDir, g_sOutputDir );
    }
    return ObjsBuilder_startSim();
}
