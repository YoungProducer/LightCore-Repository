#include "Scene.h"

namespace lc {

	Scene::Scene()
	{
		m_Render = new Render();
	}

	Scene::~Scene()
	{
		
	}

	void Scene::Reset()
	{

	}

	void Scene::Update(GLFWwindow* window)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 0.0);

		m_Render->MainRender(frame++);


	}

}