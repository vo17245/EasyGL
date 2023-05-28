#pragma once
#include "platform/renderer/RendererApi.h"
enum class RendererCommandPlatform
{
    OPENGL
};
class RendererCommand
{
private:
    static RendererApi* s_RendererApi;
public:
    static void SetPlatform(RendererCommandPlatform platform);
    static void BindShader(uint32_t rendererId);
    static void SetViewport(int x,int y,size_t width,size_t height);
};