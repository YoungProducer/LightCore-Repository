#pragma once

#include <iostream>
#include <string>
#include <sstream>

#include "../include/glew.h"
#include "../include/glfw3.h"

namespace lc { namespace graphics {

		class IndexBuffer
		{
		private:
			unsigned int m_BufferID;
			unsigned int m_Count;

		public:
			IndexBuffer() {};
			IndexBuffer(unsigned short* data, unsigned int count);

			void setIndexBufferData(unsigned short* data, unsigned int count);

			void bind() const;
			void unbind() const;

		public:
			inline unsigned int getCount() const { return m_Count; };
		};

} }
