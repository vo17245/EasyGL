#pragma once
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include <stdint.h>

class VertexArray
{
private:
	uint32_t m_RendererID;
public:
	VertexArray();
	~VertexArray();
	void Bind()const;
	void Unbind()const;
	void AddBuffer(const VertexBuffer& vb,const VertexBufferLayout& vbl);
};



