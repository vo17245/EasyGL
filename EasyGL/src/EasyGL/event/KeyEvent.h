#pragma once
#include "Event.h"
#include "KeyCode.h"

class KeyEvent:public Event
{
protected:
    KeyCode m_KeyCode;
public:
    KeyEvent(EventType type,const KeyCode& code)
        :Event(type),m_KeyCode(code){}
    virtual ~KeyEvent(){}
    virtual const std::string ToString()const;
    inline const KeyCode GetKeyCode()const{return m_KeyCode;}
};

class KeyPressEvent:public KeyEvent
{
public:
    KeyPressEvent(KeyCode code)
        :KeyEvent(EventType::KEY_PRESS,code){}
    ~KeyPressEvent(){}
};

class KeyReleaseEvent:public KeyEvent
{
public:
    KeyReleaseEvent(KeyCode code)
        :KeyEvent(EventType::KEY_RELEASE,code){}
    ~KeyReleaseEvent(){}
};

class KeyRepeatEvent:public KeyEvent
{
public:
    KeyRepeatEvent(KeyCode code)
        :KeyEvent(EventType::KEY_REPEAT,code){}
    ~KeyRepeatEvent(){}
};
