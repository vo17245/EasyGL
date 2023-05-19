#pragma once
#include <GL/glew.h>




void GLClearError();
GLenum GLGetError();
void GLPrintError(GLenum err,const char* func,const char* file,int line);


#ifdef _DEBUG
    #define GLCall(x) GLClearError();\
    x;\
    GLPrintError(GLGetError(),#x,__FILE__,__LINE__)
#else
    #define GLCall(x) x
#endif