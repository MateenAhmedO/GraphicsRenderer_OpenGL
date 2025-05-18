#pragma once

#include<vector>
#include<GL/glew.h>
#include "Renderer.h"
struct VertexBufferElement
{
	unsigned int count;
	unsigned int type;
	unsigned char normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT:
			return 4;
		case GL_UNSIGNED_INT :
			return 4;
		case GL_UNSIGNED_BYTE:
			return 1;
		} 
		ASSERT(false);
		return 0;
	}
		
	VertexBufferElement(unsigned int c, unsigned int t, bool n) :
		count(c), type(t), normalized(n)
	{

	}
};

class VertexBufferLayout
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride; 
public:
	VertexBufferLayout()
		: m_Stride(0) {}

	template<typename T>
	void Push(unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement({ count, GL_FLOAT,false }));
		m_Stride += VertexBufferElement::GetSizeOfType(GL_FLOAT) * count;
	}

	template<>
	void Push<int>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement({ count ,GL_UNSIGNED_INT , false}));
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT) * count; 
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		m_Elements.push_back(VertexBufferElement({count ,  GL_UNSIGNED_BYTE , true}));
		m_Stride += VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);

	}

	inline const std::vector<VertexBufferElement> GetElements() const& { return m_Elements; }
	inline unsigned int GetStride() const { return m_Stride; }
};
