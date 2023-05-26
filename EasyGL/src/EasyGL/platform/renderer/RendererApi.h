#pragma once
#include <stdint.h>
class RendererApi
{
public:
    RendererApi(){}
    virtual ~RendererApi(){}
    virtual void BindShader(uint32_t rendererID)=0;
};