#pragma once
#include "EasyGL.h"
#include <unordered_map>

class TestMenuLayer:public Layer
{
private:
    Application* m_BelongApplication;
    std::unordered_map<std::string,std::function<std::shared_ptr<Layer>()>> m_TestLayerMap;
public:
    TestMenuLayer(Application* belongApplication);
    ~TestMenuLayer(){}
    void OnImguiRender()override;
    template<typename T>
    void RegisterTest(const std::string& name)
    {
        m_TestLayerMap[name]=[](){return std::shared_ptr<Layer>(new T());};
    }
    
};