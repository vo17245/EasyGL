#include "Renderer.h"
#include "GLCall.h"
#include "EasyGL/Log.h"

Camera Renderer::s_Camera;
Renderer::Renderer()
{
}
Renderer::~Renderer()
{
}
void Renderer::Init()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		ERROR("[OpenGL]glewInit() failed {0}:{1}", __FILE__, __LINE__);
		exit(-1);
	}
}
void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
void Renderer::ClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}
void Renderer::EnableDepthTest()
{
	glEnable(GL_DEPTH_TEST);
}
void Renderer::ClearDepthBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Renderer::SetViewPort(float width, float height)
{
	glViewport(0, 0, width, height);
}


void Renderer::BeginScene(const Camera& camera)
{
    s_Camera=camera;
}
void Renderer::EndScene()
{

}

void Renderer::Submit(const VertexArray& va,const IndexBuffer& ib,const Shader& shader)
{
    shader.SetUniformMat4f("u_View",s_Camera.GetView());
    Draw(va,ib,shader);
}

