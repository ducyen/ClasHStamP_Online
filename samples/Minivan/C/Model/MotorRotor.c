/* File generated by Đức's ClasHStamP */
#define __MotorRotor_INTERNAL__
#include "CommonInclude.h"
#include "MotorRotor.h"
#include "ObjsBuilder.h"                                        
/** @public @memberof MotorRotor */
void MotorRotor_rotateCW(
    MotorRotor* pMotorRotor
){
    pMotorRotor->rotation += 5.;
    ImgSprite_setRotation( pMotorRotor, -pMotorRotor->rotation );
} /* MotorRotor_rotateCW */

/** @public @memberof MotorRotor */
void MotorRotor_rotateCCW(
    MotorRotor* pMotorRotor
){
    pMotorRotor->rotation -= 5.;
    ImgSprite_setRotation( pMotorRotor, -pMotorRotor->rotation );
} /* MotorRotor_rotateCCW */

/** @public @memberof MotorRotor */
bool MotorRotor_isRotMax(
    MotorRotor* pMotorRotor
){
    return pMotorRotor->rotation > 120.;
} /* MotorRotor_isRotMax */

/** @public @memberof MotorRotor */
bool MotorRotor_isRotMin(
    MotorRotor* pMotorRotor
){
    return pMotorRotor->rotation <= 0.;
} /* MotorRotor_isRotMin */

ImgSprite* MotorRotor_Copy( MotorRotor* pMotorRotor, const MotorRotor* pSource ){
    ImgSprite_Copy( ( ImgSprite* )pMotorRotor, ( ImgSprite* )pSource );
    pMotorRotor->rotation = pSource->rotation;
    return ( Sprite* )pMotorRotor;
}