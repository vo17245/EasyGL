#pragma once
#include <GL/glew.h>
#include "platform/renderer/RendererApi.h"

class OpenGLApi:public RendererApi
{
public:
    OpenGLApi(){}
    ~OpenGLApi(){}
    void BindShader(uint32_t rendererID);
    void SetViewport(int x,int y,size_t width,size_t height)override;
};