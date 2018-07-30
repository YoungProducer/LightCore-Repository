#include "Cursor.h"

namespace lc { namespace cursor {

		Cursor::Cursor()
		{

		}

		Cursor::~Cursor()
		{
			
		}

		GLFWcursor* Cursor::CreateCursor(int shape)
		{
			return glfwCreateStandardCursor(shape);
		}

		GLFWcursor* Cursor::CreateCursor(GLFWimage* image, int x, int y)
		{
			return glfwCreateCursor(image, x, y);
		}

		void Cursor::SetCursor(GLFWwindow* window, GLFWcursor* cursor)
		{
			glfwSetCursor(window, cursor);
		}
} }
