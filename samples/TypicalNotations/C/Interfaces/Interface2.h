#ifndef __Interface2_H__
#define __Interface2_H__
typedef struct tagInterface2 Interface2;
void Interface2_methodWithParams( Interface2* pInterface2, String parm1, float parm2 );
#endif//__Interface2_H__
#if !defined( Interface2_Init ) && ( defined( __Interface2_INTERNAL__ )  )
/** @memberof Interface2
 * @brief Interface2 auto-generated constructor
 */
#define Interface2_Init()\

#define Interface2_Ctor(  )    ( Interface2 ){ \
    Interface2_Init(  ) \
}
Interface2* Interface2_Copy( Interface2* pInterface2, const Interface2* pSource );
/** @class Interface2
 * @extends 
 */
struct tagInterface2{
#define Interface2_CLASS                                                                        \
    size_t cbSize;                                                                              \

    Interface2_CLASS    
};
#endif//__Interface2_INTERNAL__
