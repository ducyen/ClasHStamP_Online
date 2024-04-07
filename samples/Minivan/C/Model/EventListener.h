#ifndef __EventListener_H__
#define __EventListener_H__
#include "Sprite.h"
typedef struct tagEventListener EventListener;
void EventListener_actionPerformed( EventListener* pEventListener, Sprite* target );
EventListener* EventListener_getNext( EventListener* pEventListener );
#endif//__EventListener_H__
#if !defined( EventListener_Init ) && ( defined( __EventListener_INTERNAL__ )  )
/** @memberof EventListener
 * @brief EventListener auto-generated constructor
 */
#define EventListener_Init(_m_action, _m_next)\
    .m_action = _m_action,\
    .m_mouseEvent = null,\
    .m_next = _m_next,\

#define EventListener_Ctor( _m_action, _m_next )    ( EventListener ){ \
    EventListener_Init( P( _m_action ), P( _m_next ) ) \
}
typedef struct tagEventListenerVtbl{
    void ( * const pactionPerformed )( EventListener*, Sprite* );
}EventListenerVtbl;
EventListener* EventListener_Copy( EventListener* pEventListener, const EventListener* pSource );
/** @class EventListener
 * @extends 
 */
#define EventListener_CLASS                                                                     \
    const EventListenerVtbl* const vTbl;                                                        \
    size_t cbSize;                                                                              \
    MouseAction m_action;                                                                                               \
    int m_mouseEvent;                                                                                                       \
    EventListener* m_next;                                      \

typedef struct tagEventListener{
    EventListener_CLASS    
}EventListener;
#endif//__EventListener_INTERNAL__
