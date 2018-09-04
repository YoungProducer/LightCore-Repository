#pragma once

#include <iostream>

#include "camera.h"
#include "../../Application/input.h"

namespace lc { namespace graphics {

	class TPSCamera : public Camera
	{
	private:

		bool m_KeyboardEnabled;

		float m_OffsetX;
		float m_OffsetY;
		float m_AngleX;
		float m_AngleY;
		float m_Zoom;
		float m_Speed;
		float m_Sensitivity;

		glm::vec2 m_MousePosition;
		glm::vec2 m_PreviousMousePos;
	public:

		TPSCamera(glm::mat4 projectionMatrix);
		void update(GLFWwindow* window);

	};

} }