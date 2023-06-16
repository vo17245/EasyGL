#include "Window.h"
#include "EasyGLDebug.h"
#include "event/KeyEvent.h"
#include "event/MouseButtonEvent.h"
#include "Log.h"
#include "event/WindowEvent.h"

std::unordered_map<GLFWwindow*,void*> Window::s_CallbackArgs;
std::unordered_map<GLFWwindow*,std::function<void(const Event&,void*)>> Window::s_CallbackFunc;

Window::Window(size_t width,size_t height,const std::string& title)
    :m_Width(width),m_Height(height),m_Title(title)
{
    m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_Window)
    {
        glfwTerminate();
        ASSERT(false,"glfw failed to create window");
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1); // Enable vsync
    SetEventCallback([](const Event& event,void* args){},nullptr);
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
    glfwSetDropCallback(m_Window, drop_callback);
    glfwSetWindowSizeCallback(m_Window, window_size_callback);
}

Window::~Window()
{
}

void Window::SetSize(size_t width,size_t height)
{
}

void Window::SetTitle(const std::string& title)
{
}
void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    void* args=s_CallbackArgs[window];
    std::function<void(const Event&,void*)> func=s_CallbackFunc[window];
    
    switch(action)
    {
    case GLFW_PRESS:
    {
        KeyPressEvent event(static_cast<KeyCode>(static_cast<uint32_t>(key)));
        func(event,args);
        break;
    }
    case GLFW_RELEASE:
    {
        KeyReleaseEvent event(static_cast<KeyCode>(static_cast<uint32_t>(key)));
        func(event,args);
        break;
    }
    case GLFW_REPEAT:
    {
        KeyRepeatEvent event(static_cast<KeyCode>(static_cast<uint32_t>(key)));
        func(event,args);
        break;
    }
    default:
    {
        std::stringstream ss;
        ss<<"unknown action "<<action;
        ASSERT(false,ss.str().c_str());
        break;
    }
    }
}
void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    void* args=s_CallbackArgs[window];
    std::function<void(const Event&,void*)> func=s_CallbackFunc[window];
    switch(action)
    {
    case GLFW_PRESS:
    {
        MouseButtonPressEvent event(static_cast<MouseButton>(static_cast<uint32_t>(button)));
        func(event,args);
        break;
    }
        
    case GLFW_RELEASE:
    {
        MouseButtonReleaseEvent event(static_cast<MouseButton>(static_cast<uint32_t>(button)));
        func(event,args);
        break;
    } 
    default:
    {
        std::stringstream ss;
        ss<<"unknown action "<<action;
        ASSERT(false,ss.str().c_str());
        break;
    }
    }
}

void Window::SetEventCallback(std::function<void(const Event&,void*)> func,void* args)
{
    s_CallbackArgs[m_Window]=args;
    s_CallbackFunc[m_Window]=func;
    
}

static void glfw_error_callback(int error, const char* description)
{
    EZ_CORE_ERROR("[GLFW] Erro {0}: {1}",error, description);
}
void Window::InitGLFW()
{
    
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        ASSERT(false,"failed to init glfw");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
}




void Window::TerminateGLFW()
{
    glfwTerminate();
}

void Window::drop_callback(GLFWwindow* window, int count, const char** paths)
{
    
    void* args=s_CallbackArgs[window];
    std::function<void(const Event&,void*)> func=s_CallbackFunc[window];
    WindowFileDropEvent event(static_cast<size_t>(count),paths);
    func(event,args);
}

void Window::window_size_callback(GLFWwindow* window, int width, int height)
{
    void* args=s_CallbackArgs[window];
    std::function<void(const Event&,void*)> func=s_CallbackFunc[window];
    WindowResizeEvent event(static_cast<size_t>(width),static_cast<size_t>(height));
    func(event,args);

}