#pragma once
#include "EasyGL.h"

class TrianglerLayer:public Layer
{
private:
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    float dx,dy;
    float angle;


public:
    TrianglerLayer();
    ~TrianglerLayer();
    void OnRender() override;
    void OnEvent(const Event& event)override;

};