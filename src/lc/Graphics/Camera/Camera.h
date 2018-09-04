#pragma once

#include "../include/glew.h"
#include "../include/glfw3.h"
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtc\matrix_transform.hpp>

namespace lc { namespace graphics {

	class Camera
	{
	protected:
		glm::vec3 m_CameraPos;
		glm::vec3 m_CameraDir;
		glm::vec3 m_CameraUp;
		glm::vec3 m_Rotation;

		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectionMatrix;
	public:

		Camera(const glm::mat4& projectionMatrix)
			:	
				m_ProjectionMatrix(projectionMatrix),
				m_ViewMatrix(glm::mat4(1)),
				m_CameraPos(glm::vec3(0)),
				m_CameraDir(glm::vec3(0)),
				m_CameraUp(glm::vec3(0)),
				m_Rotation(glm::vec3(0)) 
		{
		}

		inline const glm::vec3& getCameraPos() const { return m_CameraPos; };
		inline void setCameraPos(const glm::vec3& cameraPos) { m_CameraPos = cameraPos; };
		inline void setCameraPos(const float& x, const float& y, const float& z) { m_CameraPos = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraDir() const { return m_CameraDir; };
		inline void setCameraDir(const glm::vec3& cameraDir) { m_CameraDir = cameraDir; };
		inline void setCameraDir(const float& x, const float& y, const float& z) { m_CameraDir = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraUp() const { return m_CameraUp; };
		inline void setCameraUp(const glm::vec3& cameraUp) { m_CameraUp = cameraUp; };
		inline void setCameraUp(const float& x, const float& y, const float& z) { m_CameraUp = glm::vec3(x, y, z); };

		inline const glm::vec3& getCameraRotation() const { return m_Rotation; };
		inline void setCameraRotation(const glm::vec3& rotation) { m_Rotation = rotation; };
		inline void setCameraRotation(const float& x, const float& y, const float& z) { m_Rotation = glm::vec3(x, y, z); };

		inline const glm::mat4& getViewMatrix() const { return m_ViewMatrix; };
		inline void setViewMatrix(const glm::mat4& viewMatrix) { m_ViewMatrix = viewMatrix; };

		inline const glm::mat4& getProjectionMatrix() const { return m_ProjectionMatrix; };
		inline void setProjectionMatrix(const glm::mat4& projectionMatrix) { m_ProjectionMatrix = projectionMatrix; };

	};

} }
