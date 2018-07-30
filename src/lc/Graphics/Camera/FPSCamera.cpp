#include "FPSCamera.h"

namespace lc { namespace graphics {

	FPSCamera::FPSCamera(const glm::mat4& projectionMatrix)
		: Camera(projectionMatrix)	
	{
		m_MouseSensitivity	= 0.5;
		m_Speed				= 0.4f;
		m_SprinSpeed		= 1.0f;
		m_Pitch				= 0;
		m_Yaw				= 0;

		// Camera var defination
		m_CameraPos = glm::vec3(0.0, 0.0, 0.0);
		m_CameraDir = glm::vec3(0.0, 0.0, 1.0);
		m_CameraUp	= glm::vec3(0.0, 1.0, 0.0);
		m_Rotation	= glm::vec3(0.0, 0.0, 0.0);
	}

	FPSCamera::~FPSCamera()
	{

	}

	void FPSCamera::Update()
	{

	}

} }
