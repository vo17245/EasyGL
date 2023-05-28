#pragma once
#include <stdint.h>
#include <stddef.h>

class RendererApi
{
public:
    RendererApi(){}
    virtual ~RendererApi(){}
    virtual void BindShader(uint32_t rendererID)=0;
    virtual void SetViewport(int x,int y,size_t width,size_t height)=0;
};