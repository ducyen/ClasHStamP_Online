#if defined( _MSC_VER )
#pragma warning(disable : 4996)
#define __Main_INTERNAL__
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>
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
    DWORD attribs = GetFileAttributes(path);
    if (attribs == INVALID_FILE_ATTRIBUTES) {
        return 0; // Path does not exist
    }
    return (attribs & FILE_ATTRIBUTE_DIRECTORY);
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
                if (!CreateDirectory(tmp, NULL)) {
                    return -1; // Failed to create directory
                }
            }
            *p = '/';
        }
    }
    //if (!directory_exists(tmp)) {
    //    return CreateDirectory(tmp, NULL) ? 0 : -1;
    //}
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
        if( g_arrPathToBitmap[ i ].m_pIBitmap ) {
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

int main(int argc, char **argv){
    if (argc >= 3) {
        g_sInputDir  = argv[ 1 ];
        g_sOutputDir = argv[ 2 ];
        printf( "arguments: %s %s\n", g_sInputDir, g_sOutputDir );
    }
    return ObjsBuilder_startSim();
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SPRITE_WIDTH = 100;
const int SPRITE_HEIGHT = 200;

double crossProduct(cpVect a, cpVect b) {
    return a.x * b.y - a.y * b.x;
}

bool isConvex(cpVect prev, cpVect current, cpVect next) {
    cpVect edge1 = cpvsub(current, prev);
    cpVect edge2 = cpvsub(next, current);
    double crossProductValue = crossProduct(edge1, edge2);
    return crossProductValue > 0;
}

bool isPointInTriangle(cpVect p, cpVect a, cpVect b, cpVect c) {
    double areaOrig = fabs(crossProduct(cpvsub(b, a), cpvsub(c, a)));
    double area1 = fabs(crossProduct(cpvsub(a, p), cpvsub(b, p)));
    double area2 = fabs(crossProduct(cpvsub(b, p), cpvsub(c, p)));
    double area3 = fabs(crossProduct(cpvsub(c, p), cpvsub(a, p)));
    return (area1 + area2 + area3 <= areaOrig);
}

bool isEar(cpVect *polygon, int vertexCount, int i) {
    int prevIndex = (i == 0) ? vertexCount - 1 : i - 1;
    int nextIndex = (i == vertexCount - 1) ? 0 : i + 1;

    cpVect prev = polygon[prevIndex];
    cpVect current = polygon[i];
    cpVect next = polygon[nextIndex];

    if (!isConvex(prev, current, next)) {
        return false;
    }

    for (int j = 0; j < vertexCount; j++) {
        if (j == prevIndex || j == i || j == nextIndex) {
            continue;
        }
        if (isPointInTriangle(polygon[j], prev, current, next)) {
            return false;
        }
    }
    return true;
}

bool isPolygonConvex(cpVect *vertices, int vertexCount) {
    for (int i = 0; i < vertexCount; i++) {
        int prevIndex = (i == 0) ? vertexCount - 1 : i - 1;
        int nextIndex = (i == vertexCount - 1) ? 0 : i + 1;

        if (!isConvex(vertices[prevIndex], vertices[i], vertices[nextIndex])) {
            return false;
        }
    }
    return true;
}

cpPolygon* decomposeConcavePolygon(cpVect *vertices, int vertexCount) {
    if (isPolygonConvex(vertices, vertexCount)) {
        cpPolygon *polygon = malloc(sizeof(cpPolygon));
        polygon->vertices = malloc(vertexCount * sizeof(cpVect));
        memcpy(polygon->vertices, vertices, vertexCount * sizeof(cpVect));
        polygon->vertexCount = vertexCount;
        polygon->next = NULL;
        return polygon;
    }

    cpPolygon *result = NULL;
    cpPolygon *last = NULL;
    cpVect *polygon = malloc(vertexCount * sizeof(cpVect));
    memcpy(polygon, vertices, vertexCount * sizeof(cpVect));

    while (vertexCount > 3) {
        bool earFound = false;
        for (int i = 0; i < vertexCount; i++) {
            if (isEar(polygon, vertexCount, i)) {
                cpPolygon *ear = malloc(sizeof(cpPolygon));
                ear->vertices = malloc(3 * sizeof(cpVect));
                ear->vertexCount = 3;
                ear->vertices[0] = polygon[(i == 0) ? vertexCount - 1 : i - 1];
                ear->vertices[1] = polygon[i];
                ear->vertices[2] = polygon[(i == vertexCount - 1) ? 0 : i + 1];
                ear->next = NULL;

                if (last == NULL) {
                    result = ear;
                } else {
                    last->next = ear;
                }
                last = ear;

                for (int j = i; j < vertexCount - 1; j++) {
                    polygon[j] = polygon[j + 1];
                }
                vertexCount--;
                earFound = true;
                break;
            }
        }
        if (!earFound) {
            free(polygon);
            while (result != NULL) {
                cpPolygon *temp = result;
                result = result->next;
                free(temp->vertices);
                free(temp);
            }
            return NULL;
        }
    }

    cpPolygon *finalPolygon = malloc(sizeof(cpPolygon));
    finalPolygon->vertices = malloc(vertexCount * sizeof(cpVect));
    memcpy(finalPolygon->vertices, polygon, vertexCount * sizeof(cpVect));
    finalPolygon->vertexCount = vertexCount;
    finalPolygon->next = NULL;

    if (last == NULL) {
        result = finalPolygon;
    } else {
        last->next = finalPolygon;
    }

    free(polygon);
    return result;
}

void DrawPolygonToTexture(SDL_Renderer *renderer, SDL_Texture *texture, cpVect *vertices, int vertexCount, int textureWidth, int textureHeight) {
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vertexCount; i++) {
        cpVect v1 = vertices[i];
        cpVect v2 = vertices[(i + 1) % vertexCount];

        int x1 = (int)(v1.x + textureWidth / 2);
        int y1 = (int)(textureHeight / 2 - v1.y);
        int x2 = (int)(v2.x + textureWidth / 2);
        int y2 = (int)(textureHeight / 2 - v2.y);

        lineRGBA(renderer, x1, y1, x2, y2, 255, 255, 255, 255);
    }

    SDL_SetRenderTarget(renderer, NULL);
}

void DrawSprite(SDL_Renderer *renderer, SDL_Texture *texture, cpBody *body) {
    cpVect pos = cpBodyGetPosition(body);
    cpFloat angle = cpBodyGetAngle(body);
    float degrees = -angle * (180.0 / M_PI);

    SDL_Rect dstrect;
    dstrect.x = (int)pos.x - SPRITE_WIDTH / 2;
    dstrect.y = (int)(SCREEN_HEIGHT - pos.y - SPRITE_HEIGHT / 2);
    dstrect.w = SPRITE_WIDTH;
    dstrect.h = SPRITE_HEIGHT;

    SDL_Point center = { SPRITE_WIDTH / 2, SPRITE_HEIGHT / 2 };

    SDL_RenderCopyEx(renderer, texture, NULL, &dstrect, degrees, &center, SDL_FLIP_NONE);
}

bool InitializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Chipmunk2D with SDL2 - Polygon Shape", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        return false;
    }

    return true;
}

void Cleanup(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void printPolygons(cpPolygon *polygons) {
    cpPolygon *current = polygons;
    while (current != NULL) {
        printf("Polygon:\n");
        for (int i = 0; i < current->vertexCount; i++) {
            printf("  (%f, %f)\n", current->vertices[i].x, current->vertices[i].y);
        }
        current = current->next;
    }
}

void freePolygons(cpPolygon *polygons) {
    while (polygons != NULL) {
        cpPolygon *temp = polygons;
        polygons = polygons->next;
        free(temp->vertices);
        cpShapeFree(temp->shape);
        free(temp);
    }
}
#endif
