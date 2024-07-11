#ifndef __EventListener_H__
#define __EventListener_H__
#include "Sprite.h"
typedef struct tagEventListener EventListener;
void EventListener_actionPerformed( EventListener* pEventListener, Sprite* target, void* pEventParams );
int EventListener_getType( EventListener* pEventListener );
EventListener* EventListener_getNext( EventListener* pEventListener );
#endif//__EventListener_H__
#if !defined( EventListener_Init ) && ( defined( __EventListener_INTERNAL__ ) || defined( __ObjsBuilder_INTERNAL__ ) )
#include "Sprite.h"
/** @memberof EventListener
 * @brief EventListener auto-generated constructor
 */
#define EventListener_Init(_m_type, _m_action, _m_source, _m_event, _m_next)\
    .m_type = _m_type,\
    .m_action = _m_action,\
    .m_source = _m_source,\
    .m_event = _m_event,\
    .m_next = _m_next,\

#define EventListener_Ctor( _m_type, _m_action, _m_source, _m_event, _m_next )    ( EventListener ){ \
    EventListener_Init( P( _m_type ), P( _m_action ), P( _m_source ), P( _m_event ), P( _m_next ) ) \
}
EventListener* EventListener_Copy( EventListener* pEventListener, const EventListener* pSource );
/** @class EventListener
 * @extends 
 */
#define EventListener_CLASS                                                                     \
    size_t cbSize;                                                                              \
    int m_type;                                                                                                                    \
    MouseAction m_action;                                                                                                \
    Sprite** m_source;                                          \
    int m_event;                                                                                                                  \
    EventListener* m_next;                                      \

typedef struct tagEventListener{
    EventListener_CLASS    
}EventListener;
#endif//__EventListener_INTERNAL__
