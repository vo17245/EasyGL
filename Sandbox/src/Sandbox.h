#pragma once
#include "EasyGL.h"
class Sandbox:public Application
{
private:
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    float dx,dy;
    float angle;
    bool show_demo_window;
    bool show_another_window;
    ImVec4 clear_color;
public:
    Sandbox();
    ~Sandbox(){}
    virtual void OnBegin() override;
    virtual void OnRender() override;
    virtual void OnImguiRender() override;
};