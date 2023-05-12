#include "VertexArray.h"
#include "GLCall.h"

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
}

VertexArray::~VertexArray()
{
    GLCall(glDeleteVertexArrays(1,&m_RendererID));
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& vbl)
{
	Bind();
	vb.Bind();
	const auto& elements = vbl.GetElements();
	for (size_t i = 0;i < elements.size();i++)
	{
		const auto& element = elements[i];
		GLCall(glVertexAttribPointer(i, element.m_Count, element.m_Type, GL_FALSE, vbl.GetVertexSize(), (const void*)element.m_Offset));
		GLCall(glEnableVertexAttribArray(i));
	}
}
