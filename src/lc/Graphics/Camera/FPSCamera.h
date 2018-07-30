#pragma once

#include "Camera.h"

namespace lc {
	namespace graphics {

		class FPSCamera : public Camera
		{
		public:
			FPSCamera(const glm::mat4& projectionMatrix);
			~FPSCamera();

			void Update();

		private:

			GLfloat m_Speed;
			GLfloat m_SprinSpeed;
			GLfloat m_MouseSensitivity;
			GLfloat m_Yaw;
			GLfloat m_Pitch;
			GLboolean m_MouseWasGrabbed;
		};
	}
}


