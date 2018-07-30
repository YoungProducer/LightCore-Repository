#include "Application.h"

namespace lc {

	Application::Application()
	{
		m_MainWindow = new Window();
		m_Scene = new Scene();
	}

	Application::Application(int width, int height, std::string name)
	{
		m_MainWindow = new Window(width, height, name);
		m_Scene = new Scene();
	}

	Application::~Application()
	{
		//delete m_MainWindow;
		//delete m_Cursor;

		glfwTerminate();
	}
	
	void Application::Init()
	{
		glfwInit();
		m_MainWindow->CreateNewWindow();
		Reset();
	}

	void Application::Update()
	{
		m_MainWindow->Update();
		m_Scene->Update(m_MainWindow->GetWindow());

		glfwPollEvents();
		glfwSwapBuffers(m_MainWindow->GetWindow());

	}

	void Application::Reset()
	{
		m_Cursor = lc::Cursor::CreateCursor(GLFW_ARROW_CURSOR);
		lc::Cursor::SetCursor(m_MainWindow->GetWindow(), m_Cursor);

		m_MainWindow->UpdateWindowPos();
	}

	void Application::MainLoop()
	{
		while (!m_MainWindow->Closed())
		{
			Update();
		}
	}
}
