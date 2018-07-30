#pragma once

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <Windows.h>
#include "../inlcude/glut.h"
#include "../inlcude/glfw3.h"

#include "../../Maths.h"

namespace lc { namespace graphics {

		class Camera
		{
		public:
			Camera(const glm::mat4& projectionMatrix);
			~Camera();

			void Update() { };

			inline void Translate(glm::vec3& translation) { m_CameraPos += translation; };
			inline void Rotate(const glm::vec3& rotation) { m_CameraDir += rotation; };

			inline void Translate(float x, float y, float z) { m_CameraPos += glm::vec3(x, y, z); };
			inline void Rotate(float x, float y, float z) { m_CameraDir += glm::vec3(x, y, z); };

			inline const glm::vec3& GetCameraPos() const { return m_CameraPos; };
			inline void SetCameraPos(const glm::vec3& cameraPos) { m_CameraPos = cameraPos; };

			inline const glm::vec3& GetCameraDir() const { return m_CameraDir; };
			inline void SetCameraDir(const glm::vec3& cameraDir) { m_CameraDir = cameraDir; };

			inline const glm::vec3& GetCameraUp() const { return m_CameraUp; };
			inline void SetCameraUp(const glm::vec3& cameraUp) { m_CameraUp = cameraUp; };

			inline const glm::vec3& GetCameraRotation() const { return m_Rotation; };
			inline void SetCamerRotation(const glm::vec3& rotation) { m_Rotation = rotation; };

			inline const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; };
			inline void SetProjectionMatrix(const glm::mat4& projectionMatrix) { m_ProjectionMatrix = projectionMatrix; };

			inline const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; };
			inline void SetViewMatrix(const glm::mat4& viewMatrix) { m_ViewMatrix = viewMatrix; };

		protected:

			glm::vec3 m_CameraPos;
			glm::vec3 m_CameraDir;
			glm::vec3 m_CameraUp;
			glm::vec3 m_Rotation;

			glm::mat4 m_ViewMatrix;
			glm::mat4 m_ProjectionMatrix;
		};
} }

#endif
