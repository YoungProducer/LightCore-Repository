#pragma once

#include <Windows.h>
#include "../inlcude/glut.h"
#include "../inlcude/glfw3.h"

#include "../Maths.h"
#include "../Common.h"
#include "../Types.h"

namespace lc {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class InputManager
	{
	private:
		bool m_KeyState[MAX_KEYS];
		bool m_LastKeyState[MAX_KEYS];

		bool m_MouseButtons[MAX_BUTTONS];
		bool m_MouseClicked[MAX_BUTTONS];
		bool m_MouseState[MAX_BUTTONS];
		bool m_MouseGrabbed;

		glm::vec2 m_MousePosition;
	public:
		InputManager();

		void Update();

		void SetCallbacks(GLFWwindow* window);

		void ClearKeys();
		void ClearMouseButtons();

		bool IsKeyPressed(int keycode) const;

		bool IsMouseButtonPressed(int button) const;
		bool IsMouseButtonClicked(int button) const;

		void SetMousePistion(const glm::vec2& position) { m_MousePosition = position; };
		const glm::vec2& GetMousePosition() const { return m_MousePosition; };

		void SetMouseGrabbed(const bool& isGrabbed) { m_MouseGrabbed = isGrabbed; };
		const bool& IsMouseFrabbed() const { return m_MouseGrabbed; };

	private:
		friend static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		friend static void CursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	};


	class Input
	{
	private:
		friend class InputManager;
	public:

		inline static void SetCallbacks(GLFWwindow* window) { return s_InputManager->SetCallbacks(window); };
		inline static bool IsKeyPressed(int keycode) { return s_InputManager->IsKeyPressed(keycode); };
		inline static bool IsMouseButtonPressed(int button) { return s_InputManager->IsMouseButtonPressed(button); };
		inline static bool IsMouseButtonClicked(int button) { return s_InputManager->IsMouseButtonClicked(button); };

		inline static InputManager* GetInputManager() { return s_InputManager; };

		inline static const glm::vec2& GetMousePosition() { return s_InputManager->GetMousePosition(); };
	private:
		static InputManager* s_InputManager;

	};
}

#define LC_MOUSE_LEFT	  GLFW_MOUSE_BUTTON_LEFT
#define LC_MOUSE_MIDDLE	  GLFW_MOUSE_BUTTON_MIDDLE
#define LC_MOUSE_RIGHT    GLFW_MOUSE_BUTTON_RIGHT

#define LC_NO_CURSOR	  NULL

#define LC_MODIFIER_LEFT_CONTROL	GLFW_KEY_LEFT_CONTROL
#define LC_MODIFIER_LEFT_ALT		GLFW_KEY_LEFT_ALT
#define LC_MODIFIER_LEFT_SHIFT		GLFW_KEY_LEFT_SHIFT
#define LC_MODIFIER_RIGHT_CONTROL	GLFW_KEY_RIGHT_CONTROL
#define LC_MODIFIER_RIGHT_ALT		GLFW_KEY_RIGHT_ALT
#define LC_MODIFIER_RIGHT_SHIFT		GLFW_KEY_RIGHT_SHIFT

#define LC_KEY_TAB			  GLFW_KEY_TAB

#define LC_KEY_0			  GLFW_KEY_0
#define LC_KEY_1			  GLFW_KEY_1
#define LC_KEY_2			  GLFW_KEY_2
#define LC_KEY_3			  GLFW_KEY_3
#define LC_KEY_4			  GLFW_KEY_4
#define LC_KEY_5			  GLFW_KEY_5
#define LC_KEY_6			  GLFW_KEY_6
#define LC_KEY_7			  GLFW_KEY_7
#define LC_KEY_8			  GLFW_KEY_8
#define LC_KEY_9			  GLFW_KEY_9

#define LC_KEY_A			  GLFW_KEY_A
#define LC_KEY_B			  GLFW_KEY_B
#define LC_KEY_C			  GLFW_KEY_C
#define LC_KEY_D			  GLFW_KEY_D
#define LC_KEY_E			  GLFW_KEY_E
#define LC_KEY_F			  GLFW_KEY_F
#define LC_KEY_G			  GLFW_KEY_G
#define LC_KEY_H			  GLFW_KEY_H
#define LC_KEY_I			  GLFW_KEY_I
#define LC_KEY_J			  GLFW_KEY_J
#define LC_KEY_K			  GLFW_KEY_K
#define LC_KEY_L			  GLFW_KEY_L
#define LC_KEY_M			  GLFW_KEY_M
#define LC_KEY_N			  GLFW_KEY_N
#define LC_KEY_O			  GLFW_KEY_O
#define LC_KEY_P			  GLFW_KEY_P
#define LC_KEY_Q			  GLFW_KEY_Q
#define LC_KEY_R			  GLFW_KEY_R
#define LC_KEY_S			  GLFW_KEY_S
#define LC_KEY_T			  GLFW_KEY_T
#define LC_KEY_U			  GLFW_KEY_U
#define LC_KEY_V			  GLFW_KEY_V
#define LC_KEY_W			  GLFW_KEY_W
#define LC_KEY_X			  GLFW_KEY_X
#define LC_KEY_Y			  GLFW_KEY_Y
#define LC_KEY_Z			  GLFW_KEY_Z

#define LC_KEY_ESCAPE         GLFW_KEY_ESCAPE
#define LC_KEY_MENU           GLFW_KEY_MENU
#define LC_KEY_ALT	          LC_KEY_MENU
#define LC_KEY_PAUSE          GLFW_KEY_PAUSE

#define LC_KEY_LCACE          0x20
#define LC_KEY_PRIOR          0x21
#define LC_KEY_NEXT           0x22
#define LC_KEY_END            0x23
#define LC_KEY_HOME           0x24
#define LC_KEY_LEFT           0x25
#define LC_KEY_UP             0x26
#define LC_KEY_RIGHT          0x27
#define LC_KEY_DOWN           0x28
#define LC_KEY_SELECT         0x29
#define LC_KEY_PRINT          0x2A
#define LC_KEY_EXECUTE        0x2B
#define LC_KEY_SNAPSHOT       0x2C
#define LC_KEY_INSERT         0x2D
#define LC_KEY_DELETE         0x2E
#define LC_KEY_HELP           0x2F

#define LC_KEY_NUMPAD0        0x60
#define LC_KEY_NUMPAD1        0x61
#define LC_KEY_NUMPAD2        0x62
#define LC_KEY_NUMPAD3        0x63
#define LC_KEY_NUMPAD4        0x64
#define LC_KEY_NUMPAD5        0x65
#define LC_KEY_NUMPAD6        0x66
#define LC_KEY_NUMPAD7        0x67
#define LC_KEY_NUMPAD8        0x68
#define LC_KEY_NUMPAD9        0x69
#define LC_KEY_MULTIPLY       0x6A
#define LC_KEY_ADD            0x6B
#define LC_KEY_SEPARATOR      0x6C
#define LC_KEY_SUBTRACT       0x6D
#define LC_KEY_DECIMAL        0x6E
#define LC_KEY_DIVIDE         0x6F
#define LC_KEY_F1             0x70
#define LC_KEY_F2             0x71
#define LC_KEY_F3             0x72
#define LC_KEY_F4             0x73
#define LC_KEY_F5             0x74
#define LC_KEY_F6             0x75
#define LC_KEY_F7             0x76
#define LC_KEY_F8             0x77
#define LC_KEY_F9             0x78
#define LC_KEY_F10            0x79
#define LC_KEY_F11            0x7A
#define LC_KEY_F12            0x7B
#define LC_KEY_F13            0x7C
#define LC_KEY_F14            0x7D
#define LC_KEY_F15            0x7E
#define LC_KEY_F16            0x7F
#define LC_KEY_F17            0x80
#define LC_KEY_F18            0x81
#define LC_KEY_F19            0x82
#define LC_KEY_F20            0x83
#define LC_KEY_F21            0x84
#define LC_KEY_F22            0x85
#define LC_KEY_F23            0x86
#define LC_KEY_F24            0x87

#define LC_KEY_NUMLOCK        0x90 
#define LC_KEY_SCROLL         0x91

#define LC_KEY_LSHIFT         GLFW_KEY_LEFT_SHIFT
#define LC_KEY_RSHIFT         GLFW_KEY_RIGHT_SHIFT
#define LC_KEY_LCONTROL       GLFW_KEY_LEFT_CONTROL
#define LC_KEY_RCONTROL       GLFW_KEY_RIGHT_CONTROL
#define LC_KEY_LMENU          GLFW_KEY_LEFT_ALT
#define LC_KEY_RMENU          GLFW_KEY_LEFT_ALT
