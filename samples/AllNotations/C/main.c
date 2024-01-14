#pragma warning(disable : 4996)
#define __Main_INTERNAL__
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#if defined( _MSC_VER )
#include <windows.h>
#include <wincodec.h>
#endif
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

#if defined( _MSC_VER )
#define CALL(ptr, method, ...) ((ptr)->lpVtbl->method((ptr), __VA_ARGS__))

void SavePngImage( char* sPath );

/**
 * Convert char to wide char
 */
WCHAR* ConvertCharToWChar(const char* charString, UINT codePage) {
    int requiredSize = MultiByteToWideChar(codePage, 0, charString, -1, NULL, 0);
    if (requiredSize == 0) {
        fprintf(stderr, "MultiByteToWideChar failed.\n");
        return NULL;
    }

    WCHAR* wideString = (WCHAR*)malloc(requiredSize * sizeof(WCHAR));
    if (wideString == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    if (MultiByteToWideChar(codePage, 0, charString, -1, wideString, requiredSize) == 0) {
        free(wideString);
        fprintf(stderr, "MultiByteToWideChar failed.\n");
        return NULL;
    }

    return wideString;
}

IWICImagingFactory* m_pIWICFactory = NULL;
/**
 * Load image from png file
 */
IWICBitmap* LoadPngImage( char* sPath ){
    WCHAR* wideString = ConvertCharToWChar(sPath, CP_UTF8);  // Using UTF-8 code page
    WCHAR strInputFile[ 256 ];
    swprintf( strInputFile, sizeof( strInputFile ) / sizeof( strInputFile[ 0 ] ), L"../Image/Design/%s.png", wideString );
    HRESULT hr = S_OK;

    IWICBitmapDecoder *pIDecoder = NULL;
    IWICBitmapFrameDecode *pIDecoderFrame = NULL;

    hr = CALL( m_pIWICFactory, CreateDecoderFromFilename,
        strInputFile,                   // Image to be decoded
        NULL,                           // Do not prefer a particular vendor
        GENERIC_READ,                   // Desired read access to the file
        WICDecodeMetadataCacheOnDemand, // Cache metadata when needed
        &pIDecoder                      // Pointer to the decoder
    );

    // Retrieve the first bitmap frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( pIDecoder, GetFrame, 0, &pIDecoderFrame );
    }

    IWICBitmap *pIBitmap = NULL;

    // Create the bitmap from the image frame.
    if( SUCCEEDED( hr ) ){
        hr = CALL( m_pIWICFactory, CreateBitmapFromSource,
            pIDecoderFrame,          // Create a bitmap from the image frame
            WICBitmapCacheOnDemand,  // Cache bitmap pixels on first access
            &pIBitmap );              // Pointer to the bitmap
    }
    if( pIDecoder ) CALL( pIDecoder, Release );
    if( pIDecoderFrame ) CALL( pIDecoderFrame, Release );

    return pIBitmap;
}

/**
 * find bitmap from path
 */
static int g_nPathToBitmapCnt = 0;
static struct{
    char m_sPath[ 256 ];
    IWICBitmap* m_pIBitmap;
} g_arrPathToBitmap[ 10 ];

void LoadAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        g_arrPathToBitmap[ i ].m_pIBitmap = LoadPngImage( g_arrPathToBitmap[ i ].m_sPath );
    }
}

void ReleaseAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        if( g_arrPathToBitmap[ i ].m_pIBitmap ) CALL( g_arrPathToBitmap[ i ].m_pIBitmap, Release );
    }
}

void SaveAllImages( void ){
    for( int i = 0; i < g_nPathToBitmapCnt; i++ ){
        SavePngImage( g_arrPathToBitmap[ i ].m_sPath );
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
    IWICBitmap* pIBitmap = LoadPngImage( sPath );
    g_arrPathToBitmap[ g_nPathToBitmapCnt ].m_pIBitmap = pIBitmap;
    g_nPathToBitmapCnt++;
    assert( g_nPathToBitmapCnt < sizeof( g_arrPathToBitmap ) / sizeof( g_arrPathToBitmap[ 0 ] ) );
    return pIBitmap;
}


/**
 * Draw rectangle on a png file
 */
int DrawRectangle( char* sPath, int nLeft, int nTop, int nWidth, int nHeight, int nDgrLeft, int nDgrTop, int nDgrWidth, int nDgrHeight, uint8_t byRed, uint8_t byGreen, uint8_t byBlue )
{
    HRESULT hr = S_OK;
    IWICBitmap *pIBitmap = FindBitmapFromPath( sPath );
    IWICBitmapLock *pILock = NULL;

    if( SUCCEEDED( hr ) ){
        UINT uiWidth = 10;
        UINT uiHeight = 10;

        hr = CALL( pIBitmap, GetSize, &uiWidth, &uiHeight );
        if( FAILED( hr ) ) return hr;

        WICRect rcLock = { 0, 0, uiWidth, uiHeight };

        // Obtain a bitmap lock for exclusive write.
        // The lock is for a 10x10 rectangle starting at the top left of the
        // bitmap.
        hr = CALL( pIBitmap, Lock, &rcLock, WICBitmapLockWrite, &pILock );

        if( SUCCEEDED( hr ) ){
            UINT cbBufferSize = 0;
            BYTE *pv = NULL;

            // Retrieve a pointer to the pixel data.
            if( SUCCEEDED( hr ) ){
                hr = CALL( pILock, GetDataPointer, &cbBufferSize, &pv );
            }

            // Pixel manipulation using the image data pointer pv.
            UINT cbStride;
            hr = CALL( pILock, GetStride, &cbStride );
            uiHeight -= ( 40 - 14 );
            //uiWidth  -= ( nLeftMgn + nRightMgn );
            nTop = ( float )( nTop - nDgrTop ) * uiHeight / nDgrHeight;
            nLeft = ( float )( nLeft - nDgrLeft ) * uiWidth / nDgrWidth;
            nHeight = ( float )nHeight * uiHeight / nDgrHeight;
            nWidth = ( float )nWidth * uiWidth / nDgrWidth;
            UINT nDotSize = 3;
            // Draw the rectangle on the destination bitmap
            for( UINT y = nTop; y < nTop + nHeight; y++ ){
                for( UINT x = nLeft; x < nLeft + nWidth; x++ ){
                    if( y >= nTop + nDotSize && y < nTop + nHeight - nDotSize && x >= nLeft + nDotSize && x < nLeft + nWidth - nDotSize ){
                        ; // Do nothing
                    } else{
                        UINT srcIndex = y * cbStride + x * 4;
                        UINT destIndex = y * cbStride + x * 4;

                        // For simplicity, we'll just set the pixel to red (assuming 32bpp BGRA format)
                        pv[ destIndex ] = byBlue;       // Blue
                        pv[ destIndex + 1 ] = byGreen;   // Green
                        pv[ destIndex + 2 ] = byRed; // Red
                        pv[ destIndex + 3 ] = 255; // Alpha
                    }
                }
            }

            // Release the bitmap lock.
            CALL( pILock, Release );

        }
    }
    SavePngImage( sPath );
}

/**
 * Save png image to file
 */
void SavePngImage( char* sPath ){
    WCHAR* wideString = ConvertCharToWChar(sPath, CP_UTF8);  // Using UTF-8 code page
    WCHAR strOutputFile[ 256 ];
    swprintf( strOutputFile, sizeof( strOutputFile ) / sizeof( strOutputFile[ 0 ] ), L"../TransImg/Design/%s.png", wideString );
    HRESULT hr = S_OK;
    IWICBitmap *pIBitmap = FindBitmapFromPath( sPath );

    if( SUCCEEDED( hr ) ){
        IWICStream* pStream = NULL;
        IWICBitmapEncoder* pEncoder = NULL;
        IWICBitmapFrameEncode* pFrameEncode = NULL;

        hr = CALL( m_pIWICFactory, CreateStream, &pStream );

        if( SUCCEEDED( hr ) ){
            hr = CALL( pStream, InitializeFromFilename, strOutputFile, GENERIC_WRITE );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( m_pIWICFactory, CreateEncoder, &GUID_ContainerFormatPng, NULL, &pEncoder );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Initialize, pStream, WICBitmapEncoderNoCache );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, CreateNewFrame, &pFrameEncode, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Initialize, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, WriteSource, pIBitmap, NULL );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pFrameEncode, Commit );
        }

        if( SUCCEEDED( hr ) ){
            hr = CALL( pEncoder, Commit );
        }
        if( pFrameEncode ) CALL( pFrameEncode, Release );
        if( pEncoder ) CALL( pEncoder, Release );
        if( pStream ) CALL( pStream, Release );
    }

    free(wideString);
}

// Linker pragmas
#pragma comment(lib, "windowscodecs.lib")

#endif

void ShowEntry( char* pMsg ){

    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, 0, 255, 0 );
    Sleep( 500 );
}

void ShowExit( char* pMsg ){
    char s[ 256 ];
    int l, t, w, h, dgrX, dgrY, dgrW, dgrH;
    sscanf( pMsg, "%s%d%d%d%d%d%d%d%d", s, &l, &t, &w, &h, &dgrX, &dgrY, &dgrW, &dgrH );
    
    DrawRectangle( s, l, t, w, h, dgrX, dgrY, dgrW, dgrH, 255, 0, 0 );
    Sleep( 500 );
}

int main( void ){
    HRESULT hr = CoInitialize( NULL );
    if( FAILED( hr ) ){
        printf( "Failed to initialize COM: %08X\n", hr );
        return 1;
    }

    // Create WIC factory
    hr = CoCreateInstance(
        &CLSID_WICImagingFactory,
        NULL,
        CLSCTX_INPROC_SERVER,
        &IID_IWICImagingFactory,
        &m_pIWICFactory
    );


    ContextImpl context = ContextImpl_Ctor( ContextImpl_Init( 
        4, "", 1, 2, 3, { 0 },
        Composition_Ctor( Composition_Init( 3 ), )
    ), );
    char n;
    do {
        ContextImpl_Start( &context );

        do {
            LoadAllImages();
            n = InputValue( "Enter event number('q': quit, 'r':restart): E" );
            EventParams* pParams = NULL;
            E1Params e1Params = { .x = Two };
            if (n == ContextImpl_E1) {
                pParams = &e1Params;
            }
            ContextImpl_EventProc( &context, (ContextImpl_EVENT)n, pParams);
        } while (n+'0' != 'q' && n+'0' != 'r');
    }while (n+'0' != 'q');



    ReleaseAllImages();
    if( m_pIWICFactory ) CALL( m_pIWICFactory, Release );
    CoUninitialize();

    return 0;
}