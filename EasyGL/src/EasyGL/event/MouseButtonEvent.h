#pragma once
#include "Event.h"
#include "MouseButton.h"

class MouseButtonEvent:public Event
{
protected:
    MouseButton m_Button; 
public:
    MouseButtonEvent(const EventType& type,const MouseButton& button)
        :Event(type),m_Button(button){}
    virtual ~MouseButtonEvent(){}
    virtual const std::string ToString()const;
};

class MouseButtonPressEvent:public MouseButtonEvent
{
public:
    MouseButtonPressEvent(const MouseButton& button)
        :MouseButtonEvent(EventType::MOUSE_BUTTON_PRESS,button){}
    ~MouseButtonPressEvent(){}
    
};

class MouseButtonReleaseEvent:public MouseButtonEvent
{
public:
    MouseButtonReleaseEvent(const MouseButton& button)
        :MouseButtonEvent(EventType::MOUSE_BUTTON_RELEASE,button){}
    ~MouseButtonReleaseEvent(){}
    
};