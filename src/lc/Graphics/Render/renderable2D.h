#pragma once

#include "../shaders/shaderManager.h"
#include "../buffers/buffer.h"
#include "../buffers/indexBuffer.h"
#include "../buffers/vertexArray.h"

namespace lc {
	namespace graphics {

		class Renderable2D
		{
		private:
			glm::vec3 m_Pos;
			glm::vec2 m_Size;
			glm::vec4 m_Color;

			Shader&		 m_Shader;
			IndexBuffer* m_IndexBuffer;
			VertexArray* m_VertexArray;

		public:
			Renderable2D(glm::vec3 position, glm::vec2 size, glm::vec4 color, Shader& shader)
				: m_Pos(position), m_Size(size), m_Color(color), m_Shader(shader)
			{
				m_VertexArray = new VertexArray();
				m_IndexBuffer = new IndexBuffer();

				float vertices[] =
				{
					0, 0, 0.5f,
					0, m_Size.y, 0.5f,
					m_Size.x, m_Size.y, 0.5f,
					m_Size.x, 0, 0.5f
				};

				unsigned short indicies[] =
				{
					0, 1, 2,
					2, 3, 0
				};

				float colors[] =
				{
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w,
					m_Color.x, m_Color.y, m_Color.z, m_Color.w
				};

				m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
				m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

				m_IndexBuffer->setIndexBufferData(indicies, 6);
			}

			virtual ~Renderable2D()
			{
				delete m_VertexArray;
				delete m_IndexBuffer;
			}

		public:

			inline const VertexArray* getVertexArray() const { return m_VertexArray; };
			inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; };
			inline Shader& getShader() const { return m_Shader; };

			inline const glm::vec3& getPosition()	const { return m_Pos; };
			inline const glm::vec2& getSize()		const { return m_Size; };
			inline const glm::vec4& getColor()		const { return m_Color; };
		};

	}
}
