#ifndef __Constraint_H__
#define __Constraint_H__
#include "Sprite.h"
typedef struct tagConstraint Constraint;
void Constraint_apply( Constraint* pConstraint, Sprite* target );
Constraint* Constraint_getNext( Constraint* pConstraint );
#endif//__Constraint_H__
#if !defined( Constraint_Init ) && ( defined( __Constraint_INTERNAL__ )  )
#include "Sprite.h"
/** @memberof Constraint
 * @brief Constraint auto-generated constructor
 */
#define Constraint_Init(_m_source, _m_influence, _m_next)\
    .m_source = _m_source,\
    .m_influence = _m_influence,\
    .m_next = _m_next,\

#define Constraint_Ctor( _m_source, _m_influence, _m_next )    ( Constraint ){ \
    Constraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) ) \
}
typedef struct tagConstraintVtbl{
    void ( * const papply )( Constraint*, Sprite* );
}ConstraintVtbl;
Constraint* Constraint_Copy( Constraint* pConstraint, const Constraint* pSource );
/** @class Constraint
 * @extends 
 */
#define Constraint_CLASS                                                                        \
    const ConstraintVtbl* const vTbl;                                                           \
    size_t cbSize;                                                                              \
    Sprite** m_source;                                          \
    float m_influence;                                                                                                      \
    Constraint* m_next;                                         \

typedef struct tagConstraint{
    Constraint_CLASS    
}Constraint;
#endif//__Constraint_INTERNAL__
