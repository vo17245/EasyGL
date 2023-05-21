#include "Window.h"
#include "EasyGLDebug.h"
#include "event/KeyEvent.h"
#include "event/MouseButtonEvent.h"
#include "Log.h"

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
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Make the window's context current */
    glfwMakeContextCurrent(m_Window);
    SetOnRender([](void* args){},nullptr);
    SetEventCallback([](const Event& event,void* args){},nullptr);
    glfwSetKeyCallback(m_Window, key_callback);
    glfwSetMouseButtonCallback(m_Window, mouse_button_callback);

    
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
    ERROR("[GLFW] Erro {0}: {1}",error, description);
}
void Window::InitGLFW()
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        ASSERT(false,"failed to init glfw");
    }
        
}
void Window::SetOnRender(std::function<void(void* args)> func,void* args)
{
    m_OnRender=func;
    m_OnRenderArgs=args;
}
void Window::Loop()
{
    while (!glfwWindowShouldClose(m_Window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
 
        m_OnRender(m_OnRenderArgs);

        /* Swap front and back buffers */
        glfwSwapBuffers(m_Window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
}

void Window::TerminateGLFW()
{
    glfwTerminate();
}