#include "EasyGL.h"
#include <memory>


class Sandbox:public Application
{
public:
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture2D> tex; 
public:
    Sandbox();
    ~Sandbox();
    virtual void Run()override;
};