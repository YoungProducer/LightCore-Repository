#pragma once

#include <iostream>

#include "camera.h"
#include "../../Application/input.h"

namespace lc { 
namespace graphics {

	class FPSCamera : public Camera
	{
	private:

		float m_OffsetX;
		float m_OffsetY;

		float m_Speed;
		float m_Sensitivity;
		bool m_MouseWasGrabbed;
		glm::vec2 m_MousePosition;
		glm::vec2 m_PreviousMousePosition;

	public:
		FPSCamera();
		FPSCamera(glm::mat4 projectionMatrix);

		void update(GLFWwindow* window);

		inline void setMouseSensitivity(const float& sensitivity) { m_Sensitivity = sensitivity; };
	};

} }