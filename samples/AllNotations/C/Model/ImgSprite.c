/* File generated by Đức's ClasHStamP */
#define __ImgSprite_INTERNAL__
#include "CommonInclude.h"
#include "ImgSprite.h"
/** @public @memberof ImgSprite */
void ImgSprite_setOffset(
    ImgSprite* pImgSprite,
    int x,
    int y
){
    pImgSprite->m_offset.x = x;
    pImgSprite->m_offset.y = y;
    pImgSprite->m_center.x = pImgSprite->m_rect.x + pImgSprite->m_rect.w / 2 + pImgSprite->m_offset.x;
    pImgSprite->m_center.y = pImgSprite->m_rect.y + pImgSprite->m_rect.h / 2 + pImgSprite->m_offset.y;
    pImgSprite->m_updated = true;
} /* ImgSprite_setOffset */

/** @public @memberof ImgSprite */
const SDL_Point* ImgSprite_getOffset(
    ImgSprite* pImgSprite
){
    return &pImgSprite->m_offset;
} /* ImgSprite_getOffset */

/** @public @memberof ImgSprite */
const SDL_Rect* ImgSprite_getBoundary(
    ImgSprite* pImgSprite
){
    return &pImgSprite->m_rect;
} /* ImgSprite_getBoundary */

/** @public @memberof ImgSprite */
const SDL_Point* ImgSprite_getCenter(
    ImgSprite* pImgSprite
){
    return &pImgSprite->m_center;
} /* ImgSprite_getCenter */

/** @public @memberof ImgSprite */
void ImgSprite_setRotation(
    ImgSprite* pImgSprite,
    double value
){
    pImgSprite->m_angle = value;
    pImgSprite->m_updated = true;
} /* ImgSprite_setRotation */

/** @public @memberof ImgSprite */
double ImgSprite_getRotation(
    ImgSprite* pImgSprite
){
    return pImgSprite->m_angle;
} /* ImgSprite_getRotation */

/** @public @memberof ImgSprite */
void ImgSprite_setBrightness(
    ImgSprite* pImgSprite,
    double value
){
    pImgSprite->m_brightness = value;
    pImgSprite->m_updated = true;
} /* ImgSprite_setBrightness */

/** @public @memberof ImgSprite */
static void ImgSprite_draw0(
    ImgSprite* pImgSprite,
    SDL_Renderer* renderer
){
    ImgSprite* sprite = pImgSprite;
    EventListener* pCurListener = sprite->m_onDrawListeners;
    while( pCurListener != null ){
        if( EventListener_getType( pCurListener ) == 0 ){
            EventListener_actionPerformed( pCurListener, sprite, null );
        }
        pCurListener = EventListener_getNext( pCurListener );
    }
} /* ImgSprite_draw0 */

/** @public @memberof ImgSprite */
static void ImgSprite_update(
    ImgSprite* pImgSprite
){
    Constraint* pCurConstraint = pImgSprite->m_constraints;
    while( pCurConstraint != null ){
        Constraint_apply( pCurConstraint, pImgSprite );
        pCurConstraint = Constraint_getNext( pCurConstraint );
    }
    pImgSprite->m_updated = false;
} /* ImgSprite_update */

/** @public @memberof ImgSprite */
static void ImgSprite_updateMouseState(
    ImgSprite* pImgSprite,
    int x,
    int y,
    int mouseEvent
){
#if 0
    extern SDL_Renderer* g_renderer;
    SDL_Renderer* renderer = g_renderer;
    ImgSprite* sprite = pImgSprite;
    int mouseX = x;
    int mouseY = y;
    SDL_Rect rect = sprite->m_rect;
    rect.x += sprite->m_offset.x;
    rect.y += sprite->m_offset.y;

    if (mouseX >= rect.x && mouseX < rect.x + rect.w &&
        mouseY >= rect.y && mouseY < rect.y + rect.h) {
        // Map mouse coordinates to texture coordinates
        int texX = mouseX - rect.x;
        int texY = mouseY - rect.y;

        // Set the render target to the buffer texture
        SDL_SetRenderTarget(renderer, sprite->m_buffer);
        // Clear first
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00); // White
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, sprite->m_image, NULL, NULL, sprite->m_angle, NULL, SDL_FLIP_NONE);

        Uint32 pixel = { 0 };
        int result = SDL_RenderReadPixels(renderer, &(SDL_Rect){texX, texY, 1, 1}, SDL_PIXELFORMAT_RGBA8888, &pixel, 4);
        SDL_SetRenderTarget(renderer, NULL);

        if (result == 0) {
            Uint8 alpha = pixel >> 24;  // Extract the alpha value
            if (alpha > 0) {
                printf("Hehe\n");
            }
        } else {
            printf("SDL_RenderReadPixels error: %s\n", SDL_GetError());
        }
    }
#else
    ImgSprite* sprite = pImgSprite;
    int mouseX = x;
    int mouseY = y;
    SDL_Rect rect = sprite->m_rect;
    rect.x += sprite->m_offset.x;
    rect.y += sprite->m_offset.y;

    if (mouseX >= rect.x && mouseX < rect.x + rect.w &&
        mouseY >= rect.y && mouseY < rect.y + rect.h
    ) {
        EventListener* pCurListener = pImgSprite->m_mouseListeners;
        while( pCurListener != null ){
            if( EventListener_getType( pCurListener ) == mouseEvent ){
                EventListener_actionPerformed( pCurListener, pImgSprite, null );
            }
            pCurListener = EventListener_getNext( pCurListener );
        }
    }
#endif
} /* ImgSprite_updateMouseState */

/** @public @memberof ImgSprite */
static void ImgSprite_draw1(
    ImgSprite* pImgSprite,
    SDL_Renderer* renderer
){
    int width, height;
#if 0
    // Set the new texture as the render target
    SDL_SetRenderTarget(renderer, pImgSprite->m_buffer);

    // Clear first
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0x00); // White
    SDL_RenderClear( renderer );

    // Copy the original texture to the new texture
    SDL_RenderCopyEx(renderer, pImgSprite->m_image, NULL, NULL, pImgSprite->m_angle, NULL, SDL_FLIP_NONE);

    // Reset the render target to the default
    SDL_SetRenderTarget(renderer, NULL);
#endif

    // Set texture color modulation (brightness)
    SDL_SetTextureColorMod(
        pImgSprite->m_image, 
        pImgSprite->m_brightness * 255, 
        pImgSprite->m_brightness * 255, 
        pImgSprite->m_brightness * 255
    );

    // Execute transformation
    SDL_Rect rect = pImgSprite->m_rect;
    rect.x = pImgSprite->m_rect.x + pImgSprite->m_offset.x;
    rect.y = pImgSprite->m_rect.y + pImgSprite->m_offset.y;

    // Render the texture
#if 0
    SDL_RenderCopyEx(renderer, pImgSprite->m_buffer, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
#else
    SDL_RenderCopyEx(renderer, pImgSprite->m_image, NULL, &rect, pImgSprite->m_angle, NULL, SDL_FLIP_NONE);
#endif

    // Reset transformation
    pImgSprite->m_angle = 0;
    pImgSprite->m_offset.x = 0;
    pImgSprite->m_offset.y = 0;

    // Event dispatch
    ImgSprite* sprite = pImgSprite;
    EventListener* pCurListener = sprite->m_onDrawListeners;
    while( pCurListener != null ){
        if( EventListener_getType( pCurListener ) == 1 ){
            EventListener_actionPerformed( pCurListener, sprite, null );
        }
        pCurListener = EventListener_getNext( pCurListener );
    }
} /* ImgSprite_draw1 */

/** @public @memberof ImgSprite */
static bool ImgSprite_load(
    ImgSprite* pImgSprite,
    SDL_Renderer* renderer
){
    char sRelPath[ 256 ];
    sprintf( sRelPath, "%s/../%s", getInputDir(), pImgSprite->m_imgPath );
    pImgSprite->m_image = IMG_LoadTexture(renderer, sRelPath);
    if (!pImgSprite->m_image) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return false;
    }

    // Query the original texture to get its width, height, and format
    Uint32 format;
    int width, height;
    SDL_QueryTexture(pImgSprite->m_image, &format, NULL, &width, &height);

    // Create a new texture with the same format and dimensions
    pImgSprite->m_buffer = SDL_CreateTexture(renderer, format, SDL_TEXTUREACCESS_TARGET, width, height);
    if (!pImgSprite->m_buffer) {
        printf("Failed to create new texture: %s\n", SDL_GetError());
        return NULL;
    }

    // Set the blend mode for the new texture to enable alpha blending
    SDL_SetTextureBlendMode(pImgSprite->m_buffer, SDL_BLENDMODE_BLEND);

    // Get the size of the renderer
    if (SDL_GetRendererOutputSize(renderer, &width, &height) != 0) {
        printf("Error getting renderer size: %s\n", SDL_GetError());
    }

    pImgSprite->m_rect = (SDL_Rect){
        pImgSprite->m_iniRect.x * width, 
        pImgSprite->m_iniRect.y * height, 
        pImgSprite->m_iniRect.w * width, 
        pImgSprite->m_iniRect.h * height
    };

    ImgSprite_setOffset( pImgSprite, 0, 0 );

    return true;
} /* ImgSprite_load */

/** @public @memberof ImgSprite */
static void ImgSprite_free(
    ImgSprite* pImgSprite
){
    if (pImgSprite->m_image) {
        SDL_DestroyTexture(pImgSprite->m_image);
    }
    if (pImgSprite->m_buffer) {
        SDL_DestroyTexture(pImgSprite->m_buffer);
    }
} /* ImgSprite_free */

Sprite* ImgSprite_Copy( ImgSprite* pImgSprite, const ImgSprite* pSource ){
    Sprite_Copy( ( Sprite* )pImgSprite, ( Sprite* )pSource );
    pImgSprite->m_buffer = pSource->m_buffer;
    pImgSprite->m_center = pSource->m_center;
    pImgSprite->m_constraints = pSource->m_constraints;
    pImgSprite->m_mouseListeners = pSource->m_mouseListeners;
    pImgSprite->m_onDrawListeners = pSource->m_onDrawListeners;
    return ( Sprite* )pImgSprite;
}
const SpriteVtbl gImgSpriteVtbl = {
    .pdraw0                      = ImgSprite_draw0,
    .pupdate                     = ImgSprite_update,
    .pupdateMouseState           = ImgSprite_updateMouseState,
    .pdraw1                      = ImgSprite_draw1,
    .pload                       = ImgSprite_load,
    .pfree                       = ImgSprite_free,
};