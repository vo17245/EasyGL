#include "Sandbox.h"

Sandbox::Sandbox()
        :Application(640,480,"Sandbox"),
        show_demo_window (true),
        show_another_window(false),
        clear_color(0.45f, 0.55f, 0.60f, 1.00f)
{}
void Sandbox::OnBegin() 
{
    // init data
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
    shader = std::unique_ptr<Shader>(new Shader("res/shader/base_vs.shader", "res/shader/base_fs.shader"));
    // set event callback
    SetEventCallback([](const Event& event,void* _args){
        Sandbox& args=*(Sandbox*)_args;
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
    this);
    //set clear color
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);



    
}
void Sandbox::OnRender() 
{
    Camera camera;
    camera.Rotate(angle);
    camera.Move(dx,dy,0.0);
    Renderer::BeginScene(camera);
    Renderer::Submit(*va,*ib,*shader);
    Renderer::EndScene();
}

void Sandbox::OnImguiRender()
{
    bool isClose;
    ImGui::Begin("imgui",&isClose,ImGuiWindowFlags_NoCollapse);
    ImGui::Text("This is some useful text.");   
    ImGui::End();
    //ImGuiIO& io = ImGui::GetIO(); (void)io;
    //if (show_demo_window)
    //    ImGui::ShowDemoWindow(&show_demo_window);
    //// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    //{
    //    static float f = 0.0f;
    //    static int counter = 0;
    //    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
    //    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    //    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    //    ImGui::Checkbox("Another Window", &show_another_window);
    //    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    //    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
    //    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
    //        counter++;
    //    ImGui::SameLine();
    //    ImGui::Text("counter = %d", counter);
    //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    //    ImGui::End();
    //}
    //// 3. Show another simple window.
    //if (show_another_window)
    //{
    //    ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    //    ImGui::Text("Hello from another window!");
    //    if (ImGui::Button("Close Me"))
    //        show_another_window = false;
    //    ImGui::End();
    //}
}