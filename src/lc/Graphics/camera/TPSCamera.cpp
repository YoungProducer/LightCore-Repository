#include "TPSCamera.h"

namespace lc {
	namespace graphics {

		TPSCamera::TPSCamera(glm::mat4 projectionMatrix)
			: Camera(projectionMatrix), m_AngleX(90.0f), m_AngleY(45.0f), m_Speed(0.02f), m_Zoom(0.0f), m_Sensitivity(0.2f)
		{
			m_PreviousMousePos = Input::getMousePosition();

			setCameraRotation(m_AngleX, m_AngleY, m_AngleX);
			setCameraPos(0.0f, 8.0f, 8.0f);
			setCameraDir(4.0f, 4.0f, 0.0f);
			setCameraUp(0.0f, 1.0f, 0.0f);
		}

		void TPSCamera::update(GLFWwindow* window)
		{
			m_MousePosition = Input::getMousePosition();
			glm::vec2 windowSize = Input::getWindowSize(window);
			glm::vec2 windowCenter = glm::vec2(windowSize.x / 2.0f, windowSize.y / 2.0f);

			if (Input::isKeyPressed(LC_KEY_W))
			{
				m_CameraPos.x += m_CameraDir.x * m_Speed;
				m_CameraPos.z += m_CameraDir.z * m_Speed;
			}

			if (Input::isKeyPressed(LC_KEY_S))
			{
				m_CameraPos.x -= m_CameraDir.x * m_Speed;
				m_CameraPos.z -= m_CameraDir.z * m_Speed;
			}

			if (Input::isKeyPressed(LC_KEY_A))
			{
				m_CameraPos -= glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
			}

			if (Input::isKeyPressed(LC_KEY_D))
			{
				m_CameraPos += glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
			}

			if (Input::isMouseButtonPressed(LC_MOUSE_RIGHT))
			{

				m_OffsetX = (m_MousePosition.x - m_PreviousMousePos.x) * m_Sensitivity;

				m_Rotation.x += m_OffsetX;
				m_Rotation.z += m_OffsetX;

				m_CameraDir.x = cos(glm::radians(m_Rotation.x + m_OffsetX)) * cos(glm::radians(m_Rotation.y));
				m_CameraDir.y = -tan(glm::radians(m_Rotation.y));
				m_CameraDir.z = sin(glm::radians(m_Rotation.z + m_OffsetX)) * cos(glm::radians(m_Rotation.y));
			}

			Input::getInputManager()->update();
			m_PreviousMousePos = m_MousePosition;
			m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraDir, m_CameraUp);
		}

	}
}