#pragma once
#include <GL/glew.h>
#include "Window.h"
#include <string>
#include <memory>
#include "Event.h"

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

public:
    Application();
    Application(size_t width,size_t height,const std::string& title);
    
    virtual ~Application(){}
    void Run();
    virtual void OnRender(){}
    virtual void OnBegin(){}
    virtual void OnUpdate(){}
    virtual void OnImguiRender(){}
    inline void SetEventCallback(std::function<void(const Event&,void*)> func,void* args)const{m_Window->SetEventCallback(func,args);}
};