#pragma once

#include "../include/glew.h"
#include "renderable2D.h"

namespace lc { namespace graphics {

		class Renderer2D
		{
		private:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
		};

} }
