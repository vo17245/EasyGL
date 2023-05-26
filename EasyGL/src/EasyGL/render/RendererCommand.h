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
};