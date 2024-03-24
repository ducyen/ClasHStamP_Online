#ifndef __TrackToConstraint_H__
#define __TrackToConstraint_H__
#include "TransformConstraint.h"
typedef struct tagTrackToConstraint TrackToConstraint;
#endif//__TrackToConstraint_H__
#if !defined( TrackToConstraint_Init ) && ( defined( __TrackToConstraint_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __TransformConstraint_INTERNAL__
#include "TransformConstraint.h"
/** @memberof TrackToConstraint
 * @brief TrackToConstraint auto-generated constructor
 */
#define TrackToConstraint_Init(_m_source, _m_influence, _m_next)\
    TransformConstraint_Init( P( _m_source ), P( _m_influence ), P( _m_next ) )\
    .vTbl = &gTrackToConstraintVtbl,\

#define TrackToConstraint_Ctor( InitFunc, optionParams )    ( TrackToConstraint ){\
    InitFunc\
\
}
extern const ConstraintVtbl gTrackToConstraintVtbl;
TransformConstraint* TrackToConstraint_Copy( TrackToConstraint* pTrackToConstraint, const TrackToConstraint* pSource );
/** @class TrackToConstraint
 * @extends TransformConstraint
 */
#define TrackToConstraint_CLASS                                                                 \
    TransformConstraint_CLASS                                                                   \

typedef struct tagTrackToConstraint{
    TrackToConstraint_CLASS    
}TrackToConstraint;
#endif//__TrackToConstraint_INTERNAL__
