#include "Input.h"

namespace lc {

	InputManager* Input::s_InputManager = new InputManager();

	InputManager::InputManager()
	{
		ClearKeys();
		ClearMouseButtons();

		Input::s_InputManager = this;

		m_MouseGrabbed = true;


	}

	void InputManager::Update()
	{
		for (size_t i = 0; i < MAX_BUTTONS; i++)
		{

		}
	}

	void InputManager::SetCallbacks(GLFWwindow* window)
	{
		glfwSetWindowUserPointer(window, this);
		glfwSetKeyCallback(window, KeyCallback);
		glfwSetMouseButtonCallback(window, MouseButtonCallback);
		glfwSetCursorPosCallback(window, CursorPositionCallback);
	}

	void InputManager::ClearKeys()
	{
		for (size_t i = 0; i < MAX_KEYS; i++)
		{
			m_KeyState[i] = false;
			m_LastKeyState[i] = false;
		}
	}

	void InputManager::ClearMouseButtons()
	{
		for (size_t i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
			m_MouseState[i] = false;
			m_MouseClicked[i] = false;
		}
	}

	bool InputManager::IsKeyPressed(int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_KeyState[keycode];
	}

	bool InputManager::IsMouseButtonPressed(int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}

	bool InputManager::IsMouseButtonClicked(int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseClicked[button];
	}

	void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_KeyState[key] = action != GLFW_RELEASE;
	}

	void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void CursorPositionCallback(GLFWwindow *window, double xpos, double ypos)
	{
		InputManager* inputManager = (InputManager*)glfwGetWindowUserPointer(window);
		inputManager->m_MousePosition = glm::vec2(xpos, ypos);
	}

}