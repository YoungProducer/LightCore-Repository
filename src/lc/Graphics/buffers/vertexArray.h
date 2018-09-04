#pragma once

#include "../include/glew.h"

#include "buffer.h"

namespace lc { namespace graphics {

	class VertexArray
	{
	private:
		unsigned int m_ArrayID;
		std::vector<Buffer*> m_Buffers;

	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* vertexBuffer, unsigned int index);
		void bind() const;
		void unbind() const;
	};

} }
