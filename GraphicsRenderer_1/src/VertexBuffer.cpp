#include "VertexBuffer.h"
#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	GLCall(glGenBuffers(1, &m_RendererID)); //creates a named buffer and returns it in the m_ID
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //bind the created name buffer to a target which is according to the need
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data , GL_STATIC_DRAW)); //creates a data store for the buffer and initializes

}

VertexBuffer::~VertexBuffer()
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

void VertexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID));
}

void VertexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
