#include <EasyGL.h>
#include <iostream>
#include <memory>
#include "Sandbox.h"



class OnRenderArgs
{
public:
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    float dx,dy;
    float angle;
    OnRenderArgs()
        :dx(0.0),dy(0.0),angle(0.0)
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
class MoveWithTriangle:public Application
{
public:
    MoveWithTriangle(){}
    ~MoveWithTriangle(){}
    virtual void Run()
    {
        //init
        Window::InitGLFW();
        Window window(640,480,"Application");
        Renderer::InitGLEW();
        // create args
        OnRenderArgs args;
        window.SetEventCallback([](const Event& event,void* _args){
            OnRenderArgs& args=*(OnRenderArgs*)_args;
            if(event.IsOnCategory(EventType::KEY_PRESS))
            {
                KeyPressEvent& keyPressEvent=*(KeyPressEvent*)&event;
                if(keyPressEvent.GetKeyCode()==KeyCode::KEY_A)
                {
                    args.dx-=0.1;
                }
                else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_D)
                {
                    args.dx+=0.1;
                }
                else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_W)
                {
                    args.dy+=0.1;
                }
                else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_S)
                {
                    args.dy-=0.1;
                }
                else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_X)
                {
                    args.angle+=0.1;
                }
            }
            else if(event.IsOnCategory(EventType::KEY_REPEAT))
            {
                KeyRepeatEvent& keyRepeatEvent=*(KeyRepeatEvent*)&event;
                if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_A)
                {
                    args.dx-=0.1;
                }
                else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_D)
                {
                    args.dx+=0.1;
                }
                else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_W)
                {
                    args.dy+=0.1;
                }
                else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_S)
                {
                    args.dy-=0.1;
                }
                else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_X)
                {
                    args.angle+=0.1;
                }
            }
        },
        &args);
        Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);

        window.SetOnRender([](void* _args){
            OnRenderArgs& args=*(OnRenderArgs*)_args;
            Camera camera;
            camera.Rotate(args.angle);
            camera.Move(args.dx,args.dy,0.0);
            Renderer::BeginScene(camera);
            Renderer::Submit(*args.va,*args.ib,*args.shader);
            Renderer::EndScene();
        },
        &args);
        window.Loop();
    }
};
Application* CreateApplication(); 
Application* CreateApplication()
{
    return new Sandbox();
}
int main(void)
{   
    Application* app=CreateApplication();
    app->Run();
    delete app;
    return 0;
}