#include "Sandbox.h"
#include "TestLayer/TrianglerLayer.h"
#include "TestLayer/ImageLayer.h"
#include "TestLayer/TestMenuLayer.h"
#include "TestLayer/FileDropLayer.h"

Sandbox::Sandbox()
{
    
    
    std::shared_ptr<TestMenuLayer> menuLayer(new TestMenuLayer(this));
    // register test layer
    menuLayer->RegisterTest<TrianglerLayer>("Triangler");
    menuLayer->RegisterTest<ImageLayer>("Image");
    menuLayer->RegisterTest<FileDropLayer>("File Drop");
    PushLayer(menuLayer);
    // set default layer to show
    std::shared_ptr<ImageLayer> imageLayer(new ImageLayer());
    PushLayer(imageLayer);
}
void Sandbox::OnBegin() 
{
    //set clear color
    Renderer::ClearColor(0.45, 0.55, 0.6, 1.0);
}
