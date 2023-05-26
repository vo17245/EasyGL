#include "OpenGLApi.h"
#include <GL/glew.h>
#include "GLCall.h"
void OpenGLApi::BindShader(uint32_t rendererID)
{
    GLCall(glUseProgram(rendererID));
}