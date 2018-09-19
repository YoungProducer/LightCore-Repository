#include "src\lc.h"

#include "../include/glut.h"

using namespace lc::maths;
using namespace lc::graphics;

int main(void)
{
	lc::Window window = lc::Window(1280, 1280, "app");

	window.createWindow();
	window.init();

	float positions[] =
	{
		0, 0, 0,
		4, 0, 0,
		4, 6, 0,
		0, 6, 0
	};

	unsigned short indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	float ColorA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	float ColorB[] =
	{
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f,
		0.2f, 0.3f, 0.8f, 1.0f
	};

	//***************************************
	// Main matrix initialization
	glm::mat4 projection = glm::perspective(45.f, 1280.f / 720.f, 0.1f, 100.f);
	glm::mat4 ortho = glm::ortho(0.0f, 16.f, 0.0f, 9.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	//***************************************


	lc::Input input;
	input.setCallbacks(window.getWindow());


	//***************************************
	// Camera initialization
	FPSCamera camera(projection);
	//TPSCamera tpsCamera(projection);
	//***************************************


	//***************************************
	// FPScounter initialization
	lc::FPSCounter counter;
	//***************************************


	//***************************************
	// Create and fill buffers
	VertexArray Sprite1, Sprite2;
	IndexBuffer ibo(indices, 6);

	Sprite1.addBuffer(new Buffer(positions, 12, 3), 0);
	Sprite1.addBuffer(new Buffer(ColorA, 16, 4), 1);

	Sprite2.addBuffer(new Buffer(positions, 12, 3), 0);
	Sprite2.addBuffer(new Buffer(ColorB, 16, 4), 1);
	//***************************************

	//***************************************
	// Create and set up shader
	Shader basic("res/shaders/Basic.vert", "res/shaders/Basic.frag");
	basic.enable();

	ShaderManager::setUniform4f(&basic, "u_Color", 0.2f, 0.3f, 0.8f, 1.0f);
	ShaderManager::setUniform4f(&basic, "u_LightPos", 6.0f, 4.5f, 0.5f, 1.0f);
	//***************************************

	//***************************************
	// Create sprites and renderer
	Renderable2D sprite(glm::vec3(0, 0, 0), glm::vec2(4, 4), glm::vec4(0.2f, 0.3f, 0.8f, 1.0f), basic);
	Renderable2D sprite1(glm::vec3(4, 4, 0), glm::vec2(2, 2), glm::vec4(1.0f, 0.0f, 1.0f, 0.0f), basic);
	Simple2Drenderer renderer;
	//***************************************


	std::cout << glGetString(GL_VERSION) << std::endl;
	while (!window.closed())
	{
		int left, top, right, bottom;
		glfwGetWindowFrameSize(window.getWindow(), &left, &top, &right, &bottom);

		glViewport(0, 0, 1280, 1280);
		glLoadIdentity();
		gluPerspective(65.f, 1280.f / 1280.f, 0.1f, 1000.f);
		//glOrtho(left, right, bottom, top, 0.01f, 1000.f);
	//	glFrustum(left, right, bottom, top, 0.1f, 1000.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();



		window.clear();

		counter.calcInstantaneousFPS();

		view = camera.getViewMatrix();
		//view = tpsCamera.getViewMatrix();

		if (lc::Input::isKeyPressed(LC_KEY_R))
		{
			std::cout << "R - pressed!" << std::endl;
			window.resize();
		}

		ShaderManager::setUniformMatrix4f(&basic, "pr_matrix", projection);
		ShaderManager::setUniformMatrix4f(&basic, "vm_matrix", view);
		ShaderManager::setUniformMatrix4f(&basic, "ml_matrix", model);
		renderer.submit(&sprite);
		renderer.submit(&sprite1);

		renderer.flush();

		camera.update(window.getWindow());
		//tpsCamera.update(window.getWindow());
		window.update();
		counter.update();

		//std::cout << counter.getInstantaneousFPS() << std::endl;
	}

	basic.~Shader();

	glfwTerminate();
	return 0;
}
