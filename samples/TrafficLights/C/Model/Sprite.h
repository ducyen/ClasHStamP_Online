#ifndef __Sprite_H__
#define __Sprite_H__
typedef struct tagSprite Sprite;
void Sprite_draw0( Sprite* pSprite, SDL_Renderer* renderer );
void Sprite_update( Sprite* pSprite );
void Sprite_draw1( Sprite* pSprite, SDL_Renderer* renderer );
bool Sprite_load( Sprite* pSprite, SDL_Renderer* renderer );
void Sprite_free( Sprite* pSprite );
#endif//__Sprite_H__
#if !defined( Sprite_Init ) && ( defined( __Sprite_INTERNAL__ )  )
/** @memberof Sprite
 * @brief Sprite auto-generated constructor
 */
#define Sprite_Init(_m_iniRect, _m_imgPath)\
    .m_iniRect = _m_iniRect,\
    .m_imgPath = _m_imgPath,\
    .m_image = null,\
    .m_rect = { 0 },\
    .m_angle = 0,\
    .m_offset = { 0 },\
    .m_brightness = 1.,\

#define Sprite_Ctor( InitFunc, optionParams )    ( Sprite ){\
    InitFunc\
\
}
typedef struct tagSpriteVtbl{
    void ( * const pdraw0 )( Sprite*, SDL_Renderer* );
    void ( * const pupdate )( Sprite* );
    void ( * const pdraw1 )( Sprite*, SDL_Renderer* );
    bool ( * const pload )( Sprite*, SDL_Renderer* );
    void ( * const pfree )( Sprite* );
}SpriteVtbl;
Sprite* Sprite_Copy( Sprite* pSprite, const Sprite* pSource );
/** @class Sprite
 * @extends 
 */
#define Sprite_CLASS                                                                            \
    const SpriteVtbl* const vTbl;                                                               \
    size_t cbSize;                                                                              \
    RelativeRect m_iniRect;                                                                                           \
    char* m_imgPath;                                                                                                         \
    SDL_Texture* m_image;                                                                                               \
    SDL_Rect m_rect;                                                                                                         \
    double m_angle;                                                                                                           \
    SDL_Point m_offset;                                                                                                   \
    double m_brightness;                                                                                                 \

typedef struct tagSprite{
    Sprite_CLASS    
}Sprite;
#endif//__Sprite_INTERNAL__
