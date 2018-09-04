#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "../include/glew.h"
#include "../include/glfw3.h"

namespace lc { namespace graphics {

	class Buffer
	{
	private:
		unsigned int m_BufferID;
		unsigned int m_ComponentCount;

	public:
		Buffer() {};
		Buffer(float* data, unsigned int count, unsigned int componentCount);

		void setBufferData(float* data, unsigned int count, unsigned int componentCount);

		void bind() const;
		void unbind() const;

	public:
		inline unsigned int getComponentCount() { return m_ComponentCount; };
	};

} }