#pragma once
#include <string>
#include <functional>
#include "event/Event.h"
#include <string>
#include <unordered_map>
#include <GLFW/glfw3.h>

class Window
{
private:
    static std::unordered_map<GLFWwindow*,void*> s_CallbackArgs;
    static std::unordered_map<GLFWwindow*,std::function<void(const Event&,void*)>> s_CallbackFunc;
    size_t m_Width;
    size_t m_Height;
    GLFWwindow* m_Window;
    std::string m_Title;
    std::function<void(void* args)> m_OnRender;
    void* m_OnRenderArgs;
public:
    Window(size_t width,size_t height,const std::string& title);
    ~Window();
    void SetSize(size_t width,size_t height);
    void SetTitle(const std::string& title);
    void SetEventCallback(std::function<void(const Event&,void*)> func,void* args);
    static void InitGLFW();
    static void TerminateGLFW();
    inline GLFWwindow* GetWindow()const{return m_Window;}

private:
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
};