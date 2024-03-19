#ifndef __Constraint_H__
#define __Constraint_H__
typedef struct tagConstraint Constraint;
void Constraint_apply( Constraint* pConstraint );
#endif//__Constraint_H__
#if !defined( Constraint_Init ) && ( defined( __Constraint_INTERNAL__ )  )
/** @memberof Constraint
 * @brief Constraint auto-generated constructor
 */
#define Constraint_Init()\

#define Constraint_Ctor( InitFunc, optionParams )    ( Constraint ){\
    InitFunc\
\
}
typedef struct tagConstraintVtbl{
    void ( * const papply )( Constraint* );
}ConstraintVtbl;
Constraint* Constraint_Copy( Constraint* pConstraint, const Constraint* pSource );
/** @class Constraint
 * @extends 
 */
#define Constraint_CLASS                                                                        \
    const ConstraintVtbl* const vTbl;                                                           \
    size_t cbSize;                                                                              \

typedef struct tagConstraint{
    Constraint_CLASS    
}Constraint;
#endif//__Constraint_INTERNAL__
