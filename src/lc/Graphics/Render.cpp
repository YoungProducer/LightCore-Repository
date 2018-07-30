#include "Render.h"

namespace lc { namespace graphics {

	Render::Render()
	{

	}

	Render::~Render()
	{

	}

	void Render::MainRender(int frame)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(65.0f, (GLfloat)1280 / (GLfloat)720, 1.0f, 100.0f);

		// Draw some rotating garbage
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(0.0f, -20.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f);

		//glTranslatef( 1.0f, 1.0f, 0.0f );
		glRotatef(frame, 0.25f, 1.0f, 0.75f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.1f, 0.0f, 0.0f);
		glVertex3f(0.0f, 3.0f, -4.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(3.0f, -2.0f, -4.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-3.0f, -2.0f, -4.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.1f, 0.0f);
		glVertex3f(0.0f, 3.0f, -3.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(3.0f, -2.0f, -2.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-3.0f, -2.0f, 2.0f);
		glEnd();
	}

} }