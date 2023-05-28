#pragma once
#include <string>

#define Bit(n) (1<<n)
enum class EventType:uint32_t
{
    KEY_PRESS=Bit(0),
    KEY_RELEASE=Bit(1),
    MOUSE_BUTTON_PRESS=Bit(2),
    MOUSE_BUTTON_RELEASE=Bit(3),
    KEY_REPEAT=Bit(4),
    WINDOW_FILE_DROP=Bit(5),
    WINDOW_RESIZE=Bit(6)
};
std::string EventType2String(EventType eventType);
class Event
{
protected:
    EventType m_Type;
public:
    Event(EventType type)
        :m_Type(type),m_IsHandled(false){}
    virtual ~Event(){}
    virtual const std::string ToString()const=0;
    inline bool IsOnCategory(EventType type)const{return static_cast<uint32_t>(m_Type)&static_cast<uint32_t>(type);}
    inline const EventType GetType()const{return m_Type;}
    mutable bool m_IsHandled;
};