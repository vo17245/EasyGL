#include "EasyGL.h"

class ImageLayer:public Layer
{
private:
    // pos [-1,1]
    float m_Posx=0;
    float m_Posy=0;
    // scale [0,1]
    float m_Width=0.5;
    float m_Height=0.5;
    std::unique_ptr<VertexBuffer> vb;
    std::unique_ptr<VertexBufferLayout> vbl;
    std::unique_ptr<VertexArray> va;
    std::unique_ptr<IndexBuffer> ib;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture2D> tex;
public:
    ImageLayer();
    ~ImageLayer();
    void OnRender()override;
    void OnImguiRender()override;
};