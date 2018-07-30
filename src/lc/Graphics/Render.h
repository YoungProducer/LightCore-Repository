#pragma once

#ifndef _RENDER_H_
#define _RENDER_H_

#include <Windows.h>
#include "../inlcude/glut.h"
#include "../inlcude/glfw3.h"

namespace lc { namespace graphics {

		class Render
		{
		public:
			Render();
			~Render();

			void MainRender(int frame);
		};
} }

#endif

