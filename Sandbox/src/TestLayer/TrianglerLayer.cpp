#include "TrianglerLayer.h"
#include <iostream>

TrianglerLayer::TrianglerLayer()
    :dx(0),dy(0),angle(0)
{
    // init data
    float vertex[24] =
    {
    	-0.5, -0.5, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    	 0.5, -0.5, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    	 0.0,  0.5, -0.5, 1.0, 0.0, 0.0, 1.0, 1.0
    };
    uint32_t indices[3] =
    {
    	0,1,2
    };   
    vb = std::unique_ptr<VertexBuffer>(new VertexBuffer(vertex, 24 * sizeof(float)));
    vbl = std::unique_ptr<VertexBufferLayout>(new VertexBufferLayout());
    vbl->Push<float>(4);
    vbl->Push<float>(4);
    va = std::unique_ptr<VertexArray>(new VertexArray());
    va->AddBuffer(*vb, *vbl);
    
    ib = std::make_unique<IndexBuffer>(indices,3);
    shader = std::unique_ptr<Shader>(new Shader("Sandbox/res/shader/base_vs.shader", "Sandbox/res/shader/base_fs.shader"));
}

TrianglerLayer::~TrianglerLayer()
{

}

void TrianglerLayer::OnRender()
{
    Camera camera;
    camera.Rotate(angle);
    camera.Move(dx,dy,0.0);
    Renderer::BeginScene(camera);
    Renderer::Submit(*va,*ib,*shader);
    Renderer::EndScene();
}





void TrianglerLayer::OnEvent(const Event& event)
{
    if(event.IsOnCategory(EventType::KEY_PRESS))
    {
        KeyPressEvent& keyPressEvent=*(KeyPressEvent*)&event;
        if(keyPressEvent.GetKeyCode()==KeyCode::KEY_A)
        {
            dx-=0.1;
        }
        else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_D)
        {
            dx+=0.1;
        }
        else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_W)
        {
            dy+=0.1;
        }
        else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_S)
        {
            dy-=0.1;
        }
        else if(keyPressEvent.GetKeyCode()==KeyCode::KEY_X)
        {
            angle+=0.1;
        }
    }
    else if(event.IsOnCategory(EventType::KEY_REPEAT))
    {
        KeyRepeatEvent& keyRepeatEvent=*(KeyRepeatEvent*)&event;
        if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_A)
        {
            dx-=0.1;
        }
        else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_D)
        {
            dx+=0.1;
        }
        else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_W)
        {
            dy+=0.1;
        }
        else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_S)
        {
            dy-=0.1;
        }
        else if(keyRepeatEvent.GetKeyCode()==KeyCode::KEY_X)
        {
            angle+=0.1;
        }
    }
}

