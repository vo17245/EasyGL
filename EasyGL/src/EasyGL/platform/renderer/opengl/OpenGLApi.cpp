#include "OpenGLApi.h"
#include <GL/glew.h>
#include "GLCall.h"
void OpenGLApi::BindShader(uint32_t rendererID)
{
    GLCall(glUseProgram(rendererID));
}

void OpenGLApi::SetViewport(int x,int y,size_t width,size_t height)
{
    GLCall(glViewport(x,y,width,height));
}