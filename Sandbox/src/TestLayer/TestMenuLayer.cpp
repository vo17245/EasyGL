#include "TestMenuLayer.h"

void TestMenuLayer::OnImguiRender()
{

    ImGui::Begin("TestMenu");
    for(auto& kv:m_TestLayerMap)
    {
        if(ImGui::Button(kv.first.c_str()))
        {
            m_BelongApplication->PopLayer();
            m_BelongApplication->PushLayer(kv.second());
        }
    }
    ImGui::End();
}
TestMenuLayer::TestMenuLayer(Application* belongApplication)
        :m_BelongApplication(belongApplication)
{
 
    
    
}
