/* File generated by Đức's ClasHStamP */
#define __Barrier_INTERNAL__
#include "CommonInclude.h"
#include "Barrier.h"
Sprite* Barrier_Copy( Barrier* pBarrier, const Barrier* pSource ){
    Sprite_Copy( ( Sprite* )pBarrier, ( Sprite* )pSource );
    return ( Sprite* )pBarrier;
}
