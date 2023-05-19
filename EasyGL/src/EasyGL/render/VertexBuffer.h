#pragma once
#include <stddef.h>
#include <stdint.h>

class VertexBuffer
{
private:
	uint32_t m_RendererID;
public:
	VertexBuffer(void* buffer,size_t size);
	~VertexBuffer();
	void Bind()const;
	void Unbind()const;
};



