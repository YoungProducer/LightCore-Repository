#pragma once

#ifndef _CURSOR_H_
#define _CURSOR_H_

#include <Windows.h>
#include "../inlcude/glut.h"
#include "../inlcude/glfw3.h"

namespace lc { namespace cursor {

		class Cursor
		{
		public:
			Cursor();
			virtual ~Cursor();

			static GLFWcursor* CreateCursor(int shape);
			static GLFWcursor* CreateCursor(GLFWimage* image, int x, int y);
			static void SetCursor(GLFWwindow* window, GLFWcursor* cursor);

		private:


		};
} }
#endif

