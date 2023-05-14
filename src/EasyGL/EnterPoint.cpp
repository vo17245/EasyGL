#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <VertexBuffer.h>
#include <VertexArray.h>
#include <VertexBufferLayout.h>
#include <IndexBuffer.h>
#include <memory>
#include <Shader.h>
#include <Renderer.h>
#include "Log.h"
#include "EasyGLDebug.h"
#include "Window.h"




class OnRenderArgs
{
public:
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    OnRenderArgs()
    {
        float vertex[24] =
	    {
	    	-0.5, -0.5, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
	    	 0.5, -0.5, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
	    	 0.0,  0.5, -0.5, 1.0, 0.0, 0.0, 1.0, 1.0
	    };
        vb = std::unique_ptr<VertexBuffer>(new VertexBuffer(vertex, 24 * sizeof(float)));
        vbl = std::unique_ptr<VertexBufferLayout>(new VertexBufferLayout());
        vbl->Push<float>(4);
	    vbl->Push<float>(4);
        va = std::unique_ptr<VertexArray>(new VertexArray());
        va->AddBuffer(*vb, *vbl);

        uint32_t indices[3] =
	    {
	    	0,1,2
	    };
        ib = std::make_unique<IndexBuffer>(indices,3);
        //create shader
	    shader = std::unique_ptr<Shader>(new Shader("res/shader/base_vs.shader", "res/shader/base_fs.shader"));
    }
    ~OnRenderArgs(){}
};


int main(void)
{   
    Window::InitGLFW();
    Window window(640,480,"Application");
    Renderer::InitGLEW();
    window.SetEventCallback([](const Event& event,void* args){
        DEBUG(event.ToString());
    },
    nullptr);
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
    OnRenderArgs args;
    window.SetOnRender([](void* _args){
        OnRenderArgs& args=*(OnRenderArgs*)_args;
        Camera camera;
        Renderer::BeginScene(camera);
        Renderer::Submit(*args.va,*args.ib,*args.shader);
        Renderer::EndScene();
    },
    &args);
    window.Loop();
    return 0;
}