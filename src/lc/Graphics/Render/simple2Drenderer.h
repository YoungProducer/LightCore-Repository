#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include <deque>

#include "renderer2D.h"
#include "../shaders/shaderManager.h"


namespace lc { namespace graphics {

	class Simple2Drenderer : public Renderer2D
	{
	private:
		std::deque<const Renderable2D*> m_RendererQueue;

	public:
		void submit(const Renderable2D* rendereable) override;
		void flush() override;
	};

} }