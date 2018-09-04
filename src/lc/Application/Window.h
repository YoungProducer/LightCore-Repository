#pragma once

#include <string>

#include "../include/glew.h"
#include "../include/glfw3.h"

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

namespace lc {

	class Window
	{
	private:
		int m_Width;
		int m_Height;
		int m_PosX;
		int m_PosY;
		std::string m_Title;

	private:
		GLFWwindow* m_Window;

	public:
		Window();
		Window(int width, int height, std::string title);
		~Window();

		bool createWindow();
		void init();
		void clear();
		void resize();
		void update();
		bool closed();

	public:
		inline GLFWwindow* getWindow() const { return m_Window; };

		inline const glm::vec2 getWindowSize() const { return glm::vec2(m_Width, m_Height); };
		inline const glm::vec2 gerWindowPosition() const { return glm::vec2(m_PosX, m_PosY); };

	};


}
