#include "Sandbox.h"

Sandbox::Sandbox()
{

}

Sandbox::~Sandbox()
{

}

void Sandbox::Run()
{
    //init
    Window::InitGLFW();
    Window window(640,480,"Sandbox");
    Renderer::InitGLEW();

    float vertex[32] =
	{
        // vertex coordinate    // texture coordinate       // vertex color
		-0.5, -0.5,  0.0,       0.0,  0.0,                  1.0,0.0,0.0,          
		-0.5,  0.5,  0.0,       0.0,  1.0,                  0.0,1.0,0.0,
		 0.5,  0.5,  0.0,       1.0,  1.0,                  0.0,0.0,1.0,
         0.5, -0.5,  0.0,       1.0,  0.0,                  0.0,0.0,0.0
	};
    vb = std::unique_ptr<VertexBuffer>(new VertexBuffer(vertex, 32 * sizeof(float)));
    vbl = std::unique_ptr<VertexBufferLayout>(new VertexBufferLayout());
    vbl->Push<float>(3);
    vbl->Push<float>(2);
    vbl->Push<float>(3);
    va = std::unique_ptr<VertexArray>(new VertexArray());
    va->AddBuffer(*vb, *vbl);
    uint32_t indices[6] =
	{
		0,1,2,
        0,3,2
	};
    ib = std::make_unique<IndexBuffer>(indices,6);
    //create shader
	shader = std::unique_ptr<Shader>(new Shader("res/shader/texture_vs.shader", "res/shader/texture_fs.shader"));
    // texture
    JpgImage jpg("res/texture/onnanoko.jpg");
    tex=std::unique_ptr<Texture2D>(new Texture2D(jpg));
    window.SetOnRender([](void* _args){
        Sandbox& args=*(Sandbox*)_args;
        Camera camera;
        args.tex->Bind();
        Renderer::BeginScene(camera);
        Renderer::Submit(*args.va,*args.ib,*args.shader);
        Renderer::EndScene();
    },
    this);
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
    window.Loop();
}