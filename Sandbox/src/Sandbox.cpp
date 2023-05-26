#include "Sandbox.h"
#include "TestLayer/TrianglerLayer.h"
#include "TestLayer/ImageLayer.h"

Sandbox::Sandbox()
{
    //std::shared_ptr<TrianglerLayer> trianglerLayer(new TrianglerLayer());
    //PushLayer(trianglerLayer);
    std::shared_ptr<ImageLayer> imageLayer(new ImageLayer());
    PushLayer(imageLayer);
}
void Sandbox::OnBegin() 
{
    //set clear color
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
}
