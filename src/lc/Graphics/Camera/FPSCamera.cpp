#include "FPSCamera.h"

namespace lc { namespace graphics {

	FPSCamera::FPSCamera()
		: Camera(glm::mat4(1.0f)), m_Speed(0.2f), m_Sensitivity(0.003f), m_MouseWasGrabbed(false)
	{
		m_PreviousMousePosition = Input::getMousePosition();

		setCameraPos(0.0f, 0.0f, 30.0f);
		setCameraDir(0.f, 0.f, 0.0f);
		setCameraUp(0.0f, 1.0f, 0.0f);
		setCameraRotation(-90.0f, 0.0f, 0.0f);
	}

	FPSCamera::FPSCamera(glm::mat4 projectionMatrix)
		: Camera(projectionMatrix), m_Speed(0.2f), m_Sensitivity(0.003f), m_MouseWasGrabbed(false)
	{
		m_PreviousMousePosition = Input::getMousePosition();

		setCameraPos(0.0f, 0.0f, 30.0f);
		setCameraDir(0.f, 0.f, 2.f);
		setCameraUp(0.0f, 1.0f, 0.0f);
		setCameraRotation(-90.0f, 0.0f, -90.0f);
	}

	void FPSCamera::update(GLFWwindow* window)
	{
		glm::vec2 windowSize = Input::getWindowSize(window);
		glm::vec2 windowCenter = glm::vec2(windowSize.x / 2.0f, windowSize.y / 2.0f);
		m_MousePosition = Input::getMousePosition();
		m_PreviousMousePosition = Input::getInputManager()->getPreviousMousePosition();

		if (Input::isKeyPressed(LC_KEY_W))
		{
			m_CameraPos += m_Speed * m_CameraDir;
		}

		if (Input::isKeyPressed(LC_KEY_S))
		{
			m_CameraPos -= m_Speed * m_CameraDir;
		}

		if (Input::isKeyPressed(LC_KEY_D))
		{
			m_CameraPos += glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
		}

		if (Input::isKeyPressed(LC_KEY_A))
		{
			m_CameraPos -= glm::normalize(glm::cross(m_CameraDir, m_CameraUp)) * m_Speed;
		}

		if (Input::isMouseButtonPressed(LC_MOUSE_RIGHT))
		{
			if (!Input::getInputManager()->isMouseGrabbed())
			{
				Input::getInputManager()->setMouseGrabbed(true);
			}

			if (Input::getInputManager()->isMouseGrabbed())
			{
				m_MousePosition.x -= windowCenter.x;
				m_MousePosition.y -= windowCenter.y;

				m_OffsetX = m_MousePosition.x * m_Sensitivity;
				m_OffsetY = m_MousePosition.y * m_Sensitivity;
				//Input::getInputManager()->setMousePosition(window, windowCenter);

				m_Rotation.x += m_OffsetX;
				m_Rotation.y += m_OffsetY;
				m_Rotation.z += m_OffsetX;

				m_CameraDir.x = cos(glm::radians(m_Rotation.x + m_OffsetX)) * cos(glm::radians(m_Rotation.y + m_OffsetY));
				m_CameraDir.y = -tan(glm::radians(m_Rotation.y + m_OffsetY));
				m_CameraDir.z = sin(glm::radians(m_Rotation.z + m_OffsetX)) * cos(glm::radians(m_Rotation.y + m_OffsetY));
			}
 		}


		if (Input::isKeyPressed(LC_KEY_ESCAPE))
		{
			Input::getInputManager()->setMouseGrabbed(false);
			m_MouseWasGrabbed = false;
		}

		Input::getInputManager()->update();
		m_ViewMatrix = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraDir, m_CameraUp);
	}

} }