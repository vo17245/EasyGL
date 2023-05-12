#include "GLCall.h"
#include "EasyGL/Log.h"


void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}
GLenum GLGetError()
{
	GLenum err = glGetError();
	return err;
}
void GLPrintError(GLenum err,const char* func,const char* file,int line)
{
	if (err == GL_NO_ERROR)
		return;
	const char* err_str = (const char*)glewGetErrorString(err);
	ERROR("[OpenGL Error]({0}) {1} in {2} {3}:{4}", (uint32_t)err, err_str,func,file,line);
	exit(-1);
}


