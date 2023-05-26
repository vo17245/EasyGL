#pragma once
#include <GL/glew.h>
#include "platform/renderer/RendererApi.h"

class OpenGLApi:public RendererApi
{
public:
    OpenGLApi(){}
    ~OpenGLApi(){}
    void BindShader(uint32_t rendererID);
};