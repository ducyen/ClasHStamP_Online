#ifndef __MotorRotor_H__
#define __MotorRotor_H__
#include "ImgSprite.h"
typedef struct tagMotorRotor MotorRotor;
void MotorRotor_rotateCW( MotorRotor* pMotorRotor );
void MotorRotor_rotateCCW( MotorRotor* pMotorRotor );
bool MotorRotor_isRotMax( MotorRotor* pMotorRotor );
bool MotorRotor_isRotMin( MotorRotor* pMotorRotor );
#endif//__MotorRotor_H__
#if !defined( MotorRotor_Init ) && ( defined( __MotorRotor_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __ImgSprite_INTERNAL__
#include "ImgSprite.h"
/** @memberof MotorRotor
 * @brief MotorRotor auto-generated constructor
 */
#define MotorRotor_Init(_m_iniRect, _m_name, _m_imgPath, _m_constraints, _m_mouseListeners, _m_onDrawListeners)\
    ImgSprite_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) )\
    .rotation = 0,\

#define MotorRotor_Ctor( _m_iniRect, _m_name, _m_imgPath, _m_constraints, _m_mouseListeners, _m_onDrawListeners )    ( MotorRotor ){ \
    MotorRotor_Init( P( _m_iniRect ), P( _m_name ), P( _m_imgPath ), P( _m_constraints ), P( _m_mouseListeners ), P( _m_onDrawListeners ) ) \
}
ImgSprite* MotorRotor_Copy( MotorRotor* pMotorRotor, const MotorRotor* pSource );
/** @class MotorRotor
 * @extends ImgSprite
 */
#define MotorRotor_CLASS                                                                        \
    ImgSprite_CLASS                                                                             \
    double rotation;                                                                                                          \

typedef struct tagMotorRotor{
    MotorRotor_CLASS    
}MotorRotor;
#endif//__MotorRotor_INTERNAL__
