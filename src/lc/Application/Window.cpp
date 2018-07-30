#include "Window.h"

namespace lc {

	Window::Window()	
	{
		m_WindowWidth	= 1280;
		m_WindowHeight	= 720;
		m_WindowPosX	= 0;
		m_WindowPosY	= 0;
		m_WindowName	= "App";
		m_FullScreen	= false;
	}

	Window::Window(int width, int height, std::string name)
		
	{
		m_WindowWidth	= width;
		m_WindowHeight	= height;
		m_WindowPosX	= 40;
		m_WindowPosY	= 40;
		m_WindowName	= name;
		m_FullScreen	= false;
	}


	Window::~Window()
	{
		delete m_Window;
		delete m_Monitor;
		delete m_Mode;
	}

	int Window::CreateNewWindow()
	{
		if (!(m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, m_WindowName.c_str(), NULL, NULL)))
		{
			glfwTerminate();
			return 1;
		}

		glfwWindowHint(GLFW_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 4);

		glfwMakeContextCurrent(m_Window);

		Input::SetCallbacks(m_Window);

		return 0;
	}

	void Window::Update()
	{
		glfwGetWindowSize(m_Window, &m_WindowWidth, &m_WindowHeight);
		m_Monitor = glfwGetPrimaryMonitor();
		m_Mode = glfwGetVideoMode(m_Monitor);

		std::cout << Input::GetMousePosition().x << " " << Input::GetMousePosition().y << std::endl;
	}

	void Window::UpdateWindowPos()
	{
		glfwSetWindowPos(m_Window, m_WindowPosX, m_WindowPosY);
	}

	void Window::SetFullScreen()
	{
		glfwSetWindowMonitor(m_Window, m_Monitor, 0, 0, m_Mode->width, m_Mode->height, m_Mode->refreshRate);

		glfwWindowHint(GLFW_RED_BITS, m_Mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, m_Mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, m_Mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, m_Mode->refreshRate);
	}

	void Window::CenterWindow()
	{
		m_WindowPosX = (m_Mode->width - m_WindowWidth) / 2;
		m_WindowPosY = (m_Mode->height - m_WindowHeight) / 2;
		glfwSetWindowPos(m_Window, m_WindowPosX, m_WindowPosY);
	}

	bool Window::Closed()
	{
		return glfwWindowShouldClose(m_Window);
	}
}
