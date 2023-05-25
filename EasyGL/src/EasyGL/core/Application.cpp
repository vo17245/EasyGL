#include "Application.h"
#include "Renderer.h"

#include "EasyGL/imgui/imgui.h"
#include "EasyGL/imgui/imgui_impl_glfw.h"
#include "EasyGL/imgui/imgui_impl_opengl3.h"

#include "GLCall.h"
#include "Log.h"

const char* Application::glsl_version = "#version 330 core";
void Application::Init()
{
    // init glfw 
    Window::InitGLFW();
    
    // create window and context
    m_Window=std::unique_ptr<Window>(new Window(m_Width,m_Height,m_Title));
    // init glew
    Renderer::InitGLEW();
    // init imgui
    IMGUI_CHECKVERSION();
    ImGuiContext* imguiContext= ImGui::CreateContext();
    ImGui::SetCurrentContext(imguiContext);
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(m_Window->GetWindow(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}
Application::Application()
    :m_Width(640),m_Height(480),m_Title("default")
{
    Init();
}

Application::Application(size_t width,size_t height,const std::string& title)
    :m_Width(width),m_Height(height),m_Title(title)
{
    Init();
}

void Application::Run()
{
    OnBegin();
    m_Window->SetEventCallback(OnEvent,&m_LayerStack);
    while (!glfwWindowShouldClose(m_Window->GetWindow()))
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));
        OnUpdate();
        OnRender();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        OnImguiRender();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(m_Window->GetWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(m_Window->GetWindow());
    glfwTerminate();
}

void Application::OnRender()
{
    for(auto it : m_LayerStack)
    {
        it->OnRender();
    }
}

void Application::OnUpdate()
{
    for(auto it : m_LayerStack)
    {
        it->OnUpdate();
    }
}

void Application::OnImguiRender()
{
    for(auto it : m_LayerStack)
    {
        it->OnImguiRender();
    }
}

void Application::OnEvent(const Event& event,void* args)
{
    LayerStack& layerStack=*(LayerStack*)args;
    for(auto it=layerStack.rbegin();it!=layerStack.rend();it++)
    {
        if(event.m_IsHandled!=true)
        {
            (*it)->OnEvent(event);
        }
    }

}