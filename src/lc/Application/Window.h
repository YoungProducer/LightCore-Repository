#pragma once

#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <iostream>
#include <string>

#include "Input.h"

namespace lc {

	class Window
	{
	public:
		Window();
		Window(int width, int height, std::string name);
		virtual ~Window();

		int		CreateNewWindow();
		void	CenterWindow();
		void	SetFullScreen();
		void	Update();
		bool	Closed();
		void	UpdateWindowPos();

		// Setters
		inline void					SetWindowPos(glm::vec2 windowPos) { m_WindowPosX = windowPos.x; m_WindowPosY = windowPos.y; };
		inline void					SetWindowPos(GLint windowPosX, GLint windowPosY) { m_WindowPosX = windowPosX; m_WindowPosY = windowPosY; };

		// Getters
		inline glm::vec2			GetWindowPos() const { return glm::vec2(m_WindowPosX, m_WindowPosY); };
		inline glm::vec2			GetWindowSize() const { return glm::vec2(m_WindowWidth, m_WindowHeight); };
		inline GLFWwindow*			GetWindow() const { return m_Window; };
		inline const GLFWvidmode*	GetVideoMode() const { return m_Mode; };
		inline GLFWmonitor*			GetMonitor() const { return m_Monitor; };
	private:

		std::string			m_WindowName;
		GLint				m_WindowPosX;
		GLint				m_WindowPosY;
		GLint				m_WindowWidth;
		GLint				m_WindowHeight;
		GLboolean			m_FullScreen;

	private:
		GLFWwindow*			m_Window;
		const GLFWvidmode*	m_Mode;
		GLFWmonitor*		m_Monitor;

	private:
		Input m_Input;
	};
}

#endif
