#include "Camera.h"

namespace lc { namespace graphics {

	Camera::Camera(const glm::mat4& projectionMatrix)
	{
		m_ProjectionMatrix	= projectionMatrix;
		m_ViewMatrix		= glm::mat4();
		m_CameraPos			= glm::vec3();
		m_CameraDir			= glm::vec3();
		m_CameraUp			= glm::vec3();
		m_Rotation			= glm::vec3();
	}

	Camera::~Camera()
	{

	}

} }