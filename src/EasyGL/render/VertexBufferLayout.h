#pragma once
#include <vector>
#include <GL/glew.h>

class VertexElement
{
public:
	uint32_t m_Type;
	size_t m_Count;
	size_t m_Offset;
	VertexElement(uint32_t type,size_t count,size_t offset):m_Type(type),m_Count(count),m_Offset(offset) {}
	~VertexElement(){}
};
enum class VertexElementType
{
	FLOAT,
	CHAR,
	INT
};
class VertexBufferLayout
{
private:
	std::vector<VertexElement> m_VertexElementArray;
	size_t m_VertexSize;
public:
	VertexBufferLayout()
        :m_VertexSize(0){}
	~VertexBufferLayout(){}
	template<typename T>
	void Push(size_t count);
	inline const std::vector<VertexElement>& GetElements()const { return m_VertexElementArray; }
	inline const size_t GetVertexSize()const { return m_VertexSize; }
};

template<typename T>
void VertexBufferLayout::Push(size_t count)
{
	
}
template<>
inline void VertexBufferLayout::Push<float>(size_t count)
{
	m_VertexElementArray.emplace_back(GL_FLOAT, count,m_VertexSize);
	m_VertexSize += count*sizeof(float);
}
template<>
inline void VertexBufferLayout::Push<char>(size_t count)
{
	m_VertexElementArray.emplace_back(GL_BYTE, count, m_VertexSize);
	m_VertexSize += count*sizeof(char);
}
template<>
inline void VertexBufferLayout::Push<int>(size_t count)
{
	m_VertexElementArray.emplace_back(GL_INT, count, m_VertexSize);
	m_VertexSize += count*sizeof(int);
}

