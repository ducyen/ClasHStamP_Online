#ifndef __MouseListener_H__
#define __MouseListener_H__
#include "EventListener.h"
typedef struct tagMouseListener MouseListener;
#endif//__MouseListener_H__
#if !defined( MouseListener_Init ) && ( defined( __MouseListener_INTERNAL__ )  || defined( __ObjsBuilder_INTERNAL__ )  )
#define __EventListener_INTERNAL__
#include "EventListener.h"
/** @memberof MouseListener
 * @brief MouseListener auto-generated constructor
 */
#define MouseListener_Init(_m_action, _m_source, _m_event, _m_next)\
    EventListener_Init( P( _m_action ), P( _m_source ), P( _m_event ), P( _m_next ) )\
    .vTbl = &gMouseListenerVtbl,\

#define MouseListener_Ctor( _m_action, _m_source, _m_event, _m_next )    ( MouseListener ){ \
    MouseListener_Init( P( _m_action ), P( _m_source ), P( _m_event ), P( _m_next ) ) \
}
extern const EventListenerVtbl gMouseListenerVtbl;
EventListener* MouseListener_Copy( MouseListener* pMouseListener, const MouseListener* pSource );
/** @class MouseListener
 * @extends EventListener
 */
#define MouseListener_CLASS                                                                     \
    EventListener_CLASS                                                                         \

typedef struct tagMouseListener{
    MouseListener_CLASS    
}MouseListener;
#endif//__MouseListener_INTERNAL__
