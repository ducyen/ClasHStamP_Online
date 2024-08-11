#ifndef __ContextImpl_H__
#define __ContextImpl_H__
#include "Context.h"
typedef struct tagContextImpl ContextImpl;
#endif//__ContextImpl_H__
#if !defined( ContextImpl_Init ) && ( defined( __ContextImpl_INTERNAL__ )  || defined( __AFriend_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __Context_INTERNAL__
#include "Context.h"
boolean ContextImpl_checkE1Params( EventParams* e );
/** @memberof ContextImpl
 * @brief ContextImpl auto-generated constructor
 */
#define ContextImpl_Init(_derivableAttribute, _publicAttribute, _privateAttribute, _internalAttribute, _readOnlyAttribute, _anAggregation, _aProtectedComposition)\
    Context_Init( P( _derivableAttribute ), P( _publicAttribute ), P( _privateAttribute ), P( _internalAttribute ), P( _readOnlyAttribute ), P( _anAggregation ), P( _aProtectedComposition ) )\
    .vTbl = &gContextImplVtbl,\

#define ContextImpl_Ctor( _derivableAttribute, _publicAttribute, _privateAttribute, _internalAttribute, _readOnlyAttribute, _anAggregation, _aProtectedComposition )    ( ContextImpl ){ \
    ContextImpl_Init( P( _derivableAttribute ), P( _publicAttribute ), P( _privateAttribute ), P( _internalAttribute ), P( _readOnlyAttribute ), P( _anAggregation ), P( _aProtectedComposition ) ) \
}
extern const BaseClassVtbl gContextImplVtbl;
Context* ContextImpl_Copy( ContextImpl* pContextImpl, const ContextImpl* pSource );
/** @class ContextImpl
 * @extends Context
 */
struct tagContextImpl{
#define ContextImpl_CLASS                                                                       \
    Context_CLASS                                                                               \

    ContextImpl_CLASS    
};
#endif//__ContextImpl_INTERNAL__
