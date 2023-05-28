#include "ImageLayer.h"

ImageLayer::ImageLayer()
{
    
    
    static float vertex[20]=
    {
        // position     // texture 
        -1.0,1.0,0.0,    0.0,1.0,//top left
        1.0,1.0,0.0,    1.0,1.0,//top right
        1.0,-1.0,0.0,   1.0,0.0,//bottom right
        -1.0,-1.0,0.0,     0.0,0.0//bottom left
    };
    static uint32_t indices[6]=
    {
        0,1,2,
        2,3,0
    };


    vb=std::unique_ptr<VertexBuffer>(new VertexBuffer(vertex,20*sizeof(float)));
    vbl=std::unique_ptr<VertexBufferLayout>(new VertexBufferLayout());
    vbl->Push<float>(3);
    vbl->Push<float>(2);
    
    va=std::unique_ptr<VertexArray>(new VertexArray());
    
    va->AddBuffer(*vb,*vbl);
    
    
    ib=std::unique_ptr<IndexBuffer>(new IndexBuffer(indices,6*sizeof(uint32_t)));
    shader=std::unique_ptr<Shader>(new Shader("Sandbox/res/shader/texture_vs.shader","Sandbox/res/shader/texture_fs.shader"));
    JpgImage mystar("Sandbox/res/texture/mystar.jpg");
    tex=std::unique_ptr<Texture2D>(new Texture2D(mystar));
    
}

ImageLayer::~ImageLayer()
{
}

void ImageLayer::OnRender()
{
    // bind texture
    tex->Bind();
    // set model mat uniform
    shader->Bind();
    Eigen::Matrix4f model=Math::Scale(m_Width,m_Height,1);
    model=model*Math::Translate(m_Posx,m_Posy,0);
    shader->SetUniformMat4f("u_Model",model);
    // camera
    Camera camera;
    Renderer::BeginScene(camera);
    Renderer::Submit(*va,*ib,*shader);
    Renderer::EndScene();
}

void ImageLayer::OnImguiRender()
{
    ImGui::Begin("scale");
    ImGui::SliderFloat("x", &m_Width, 0.0f, 1.0f);
    ImGui::SliderFloat("y", &m_Height, 0.0f, 1.0f);
    ImGui::End();
}

void ImageLayer::OnEvent(const Event& event)
{
    if(event.IsOnCategory(EventType::WINDOW_RESIZE))
    {
        WindowResizeEvent windowResizeEvent=*(WindowResizeEvent*)&event;
        RendererCommand::SetViewport(0,0,windowResizeEvent.GetWidth(),windowResizeEvent.GetHeight());
    }
}