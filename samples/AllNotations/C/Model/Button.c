/* File generated by Đức's ClasHStamP */
#define __Button_INTERNAL__
#include "CommonInclude.h"
#include "Button.h"
#include "ObjsBuilder.h"                                        
ImgSprite* Button_Copy( Button* pButton, const Button* pSource ){
    ImgSprite_Copy( ( ImgSprite* )pButton, ( ImgSprite* )pSource );
    return ( Sprite* )pButton;
}
