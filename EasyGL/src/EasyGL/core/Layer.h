#pragma once
#include "Event.h"

class Application;

class Layer
{
public:
    Layer(){}
    virtual ~Layer(){}
    virtual void OnRender(){}
    virtual void OnUpdate(){}
    virtual void OnImguiRender(){}
    virtual void OnEvent(const Event& event){}
    virtual void OnAttach(){}
    virtual void OnDetach(){}
};