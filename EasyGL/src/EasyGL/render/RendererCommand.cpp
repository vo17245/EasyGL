#include "RendererCommand.h"
#include "platform/renderer/opengl/OpenGLApi.h"
#include "core/EasyGLDebug.h"

RendererApi* RendererCommand::s_RendererApi=new OpenGLApi();
void RendererCommand::SetPlatform(RendererCommandPlatform platform)
{
    switch (platform)
    {
    case RendererCommandPlatform::OPENGL :
        delete s_RendererApi;
        s_RendererApi=new OpenGLApi();
        break;
    default:
        ASSERT(false,"renderer platform not support");
    }
}

void RendererCommand::BindShader(uint32_t rendererId)
{
    s_RendererApi->BindShader(rendererId);
}

void RendererCommand::SetViewport(int x,int y,size_t width,size_t height)
{
    s_RendererApi->SetViewport(x,y,width,height);
}