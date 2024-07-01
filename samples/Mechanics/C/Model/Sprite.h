#ifndef __Sprite_H__
#define __Sprite_H__
typedef struct tagSprite Sprite;
void Sprite_draw0( Sprite* pSprite, SDL_Renderer* renderer );
void Sprite_update( Sprite* pSprite );
void Sprite_updateMouseState( Sprite* pSprite, int x, int y, int mouseEvent );
void Sprite_draw1( Sprite* pSprite, SDL_Renderer* renderer );
bool Sprite_load( Sprite* pSprite, SDL_Renderer* renderer );
void Sprite_free( Sprite* pSprite );
bool Sprite_isUpdated( Sprite* pSprite );
const SDL_Point* Sprite_getCenter( Sprite* pSprite );
#endif//__Sprite_H__
#if !defined( Sprite_Init ) && ( defined( __Sprite_INTERNAL__ )  )
/** @memberof Sprite
 * @brief Sprite auto-generated constructor
 */
#define Sprite_Init(_m_iniRect, _m_name, _m_imgPath)\
    .m_iniRect = _m_iniRect,\
    .m_name = _m_name,\
    .m_imgPath = _m_imgPath,\
    .m_image = null,\
    .m_rect = { 0 },\
    .m_updated = false,\
    .m_angle = 0,\
    .m_offset = { 0 },\
    .m_brightness = 1.,\
    .m_stmUpdated = false,\
    .m_stmTexture = null,\
    .m_stmWindow = null,\
    .m_stmShow = false,\

#define Sprite_Ctor( _m_iniRect, _m_name, _m_imgPath )    ( Sprite ){ \
    Sprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ) ) \
}
typedef struct tagSpriteVtbl{
    void ( * const pdraw0 )( Sprite*, SDL_Renderer* );
    void ( * const pupdate )( Sprite* );
    void ( * const pupdateMouseState )( Sprite*, int, int, int );
    void ( * const pdraw1 )( Sprite*, SDL_Renderer* );
    bool ( * const pload )( Sprite*, SDL_Renderer* );
    void ( * const pfree )( Sprite* );
    const SDL_Point* ( * const pgetCenter )( Sprite* );
}SpriteVtbl;
Sprite* Sprite_Copy( Sprite* pSprite, const Sprite* pSource );
/** @class Sprite
 * @extends 
 */
#define Sprite_CLASS                                                                            \
    const SpriteVtbl* const vTbl;                                                               \
    size_t cbSize;                                                                              \
    RelativeRect m_iniRect;                                                                                            \
    char* m_name;                                                                                                                \
    char* m_imgPath;                                                                                                          \
    SDL_Texture* m_image;                                                                                                \
    SDL_Rect m_rect;                                                                                                          \
    bool m_updated;                                                                                                            \
    double m_angle;                                                                                                            \
    SDL_Point m_offset;                                                                                                    \
    double m_brightness;                                                                                                  \
    bool* m_stmUpdated;                                                                                                    \
    SDL_Texture* m_stmTexture;                                                                                      \
    SDL_Window* m_stmWindow;                                                                                          \
    bool m_stmShow;                                                                                                            \

typedef struct tagSprite{
    Sprite_CLASS    
}Sprite;
#endif//__Sprite_INTERNAL__
