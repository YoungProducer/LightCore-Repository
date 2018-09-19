#include "Window.h"

namespace lc {

	Window::Window()
	{
		
	}

	Window::Window(int width, int height, std::string title)
	{
		m_Width = width;
		m_Height = height;
		m_Title = title;
	}

	Window::~Window()
	{

	}

	bool Window::createWindow()
	{
		glfwInit();

		if (!(m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL)))
			return 1;
		return 0;
	}

	void Window::init()
	{
		glfwWindowHint(GLFW_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		glfwMakeContextCurrent(m_Window);

		glewInit();

		resize();

		glfwSwapInterval(0);
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 0.0);

		glViewport(0, 0, m_Width, m_Height);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.01f, 100.0f);

		//gluPerspective(65.0f, (float)m_Width / (float)m_Height, 0.1f, 100.0f);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void Window::resize()
	{
		glViewport(0, 0, m_Width, m_Height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		
		//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.01f, 100.0f);
		//gluPerspective(65.0f, (float)m_Width / (float)m_Height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);
	}

	void Window::update()
	{
		glfwGetWindowSize(m_Window, &m_Width, &m_Height);
		glfwGetWindowPos(m_Window, &m_PosX, &m_PosY);
		//resize();
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed()
	{
		if (glfwWindowShouldClose(m_Window))
			return 1;
		return 0;
	}

}
