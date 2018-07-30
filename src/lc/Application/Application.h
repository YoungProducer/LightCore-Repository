#pragma once

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Window.h"
#include "../Cursor/Cursor.h"
#include "../Scene/Scene.h"

namespace lc {

	using namespace cursor;

	class Application
	{
	public:
		Application();
		Application(int width, int height, std::string name);
		~Application();

		void Init();
		void Update();
		void Reset();
		void MainLoop();

	private:
		Window*		m_MainWindow;
		Scene*		m_Scene;
		GLFWcursor* m_Cursor;
	};
}

#endif

