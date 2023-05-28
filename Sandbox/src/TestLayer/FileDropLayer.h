#pragma once
#include "EasyGL.h"

class FileDropLayer:public Layer
{
private:
    std::vector<std::string> m_Paths;
public:
    FileDropLayer(){}
    ~FileDropLayer(){}
    void OnImguiRender()override;
    virtual void OnEvent(const Event& event)override;
};