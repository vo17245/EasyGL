#include "Sandbox.h"
#include "TestLayer/TrianglerLayer.h"

Sandbox::Sandbox()
{
    std::shared_ptr<TrianglerLayer> trianglerLayer(new TrianglerLayer());
    PushLayer(trianglerLayer);
}
void Sandbox::OnBegin() 
{
    //set clear color
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
}
