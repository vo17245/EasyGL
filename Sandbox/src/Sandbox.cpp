#include "Sandbox.h"
#include "TestLayer/TrianglerLayer.h"
#include "TestLayer/ImageLayer.h"
#include "TestLayer/TestMenuLayer.h"

Sandbox::Sandbox()
{
    
    uint32_t indices[6]=
    {
        0,1,2,
        2,3,0
    };
    
    std::unique_ptr<IndexBuffer> ib=std::unique_ptr<IndexBuffer>(new IndexBuffer(indices,6*sizeof(uint32_t)));
    std::shared_ptr<TestMenuLayer> menuLayer(new TestMenuLayer(this));
    


    menuLayer->RegisterTest<TrianglerLayer>("Triangler");
    menuLayer->RegisterTest<ImageLayer>("Image");
    
    PushLayer(menuLayer);
    
    std::shared_ptr<ImageLayer> imageLayer(new ImageLayer());
    PushLayer(imageLayer);
    
    
    
    
}
void Sandbox::OnBegin() 
{
    //set clear color
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
}
