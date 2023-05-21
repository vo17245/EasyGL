#pragma once
enum class RendererCommandPlatform
{
    OPENGL
};
class RendererCommand
{
private:
    static RendererCommand* s_Instance;
public:
    static void SetPlatform(RendererCommandPlatform platform);
};