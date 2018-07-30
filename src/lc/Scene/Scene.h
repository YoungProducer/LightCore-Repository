#pragma once

#ifndef _SCENE_H_
#define _SCENE_H_

#include "../Graphics/Render.h"
#include "../Graphics/Camera/Camera.h"

namespace lc {

	using namespace graphics;

	class Scene
	{
	public:
		Scene();
		~Scene();

		void Update(GLFWwindow *window);
		void Reset();

	private:
		
		Render* m_Render;
		Camera* m_Camera;

		int frame; // temp var
	};
}

#endif
