#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Camera.h"


class Renderer
{
private:
	static Camera s_Camera;
public:
	Renderer();
	~Renderer();
	static void Init();
	static void Draw(const VertexArray& va,const IndexBuffer& ib,const Shader& shader);
	static void ClearColor(float r, float g, float b, float a);
	static void EnableDepthTest();
	static void ClearDepthBuffer();
	static void SetViewPort(float width, float height);
	static void BeginScene(const Camera& camera);
	static void EndScene();
	static void Submit(const VertexArray& va,const IndexBuffer& ib,const Shader& shader);
};



