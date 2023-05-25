#pragma once
#include <GL/glew.h>
#include "Window.h"
#include <string>
#include <memory>
#include "Event.h"
#include <vector>
#include "Layer.h"
#include "LayerStack.h"

class Application
{
private:
    static const char* glsl_version ;
    void Init();
protected:
    size_t m_Width;
    size_t m_Height;
    std::string m_Title;
    std::unique_ptr<Window> m_Window;
    LayerStack m_LayerStack;

public:
    Application();
    Application(size_t width,size_t height,const std::string& title);
    
    virtual ~Application(){}
    void Run();
    void OnRender();
    virtual void OnBegin(){}
    void OnUpdate();
    void OnImguiRender();
    static void OnEvent(const Event& event,void* args);
    inline void PushLayer(const std::shared_ptr<Layer> layer){m_LayerStack.Push(layer);}
    inline void PopLayer(const std::shared_ptr<Layer> layer){m_LayerStack.Pop(layer);}
};