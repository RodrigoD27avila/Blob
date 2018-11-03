#include "lutil.h"

// the current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// the projection scale
GLfloat gProgectionScale = 1.0f;

bool initGL()
{
	// initialize projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f, -1.0f);

	// initialize model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		fprintf(stderr, "Error initializing OpenGL! %s\n",
			gluErrorString(error));
		return false;
	}

	return true;
}

void update()
{
}

void render()
{
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// reset modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// move to center of the screen
	glTranslatef(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f, 0.0f);

	if (gColorMode == COLOR_MODE_CYAN) {	

		// render quads
		glBegin(GL_QUADS);
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex2f(-50.0f, -50.0f);
			glVertex2f( 50.0f, -50.0f);
			glVertex2f( 50.0f,  50.0f);
			glVertex2f(-50.0f,  50.0f);
		glEnd();
	}
	else {
		glBegin(GL_QUADS);
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex2f(-50.0f, -50.0f);

			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex2f( 50.0f, -50.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f( 50.0f,  50.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(-50.0f,  50.0f);
		glEnd();
		
	}

	// update screen
	glutSwapBuffers();

}

void handleKeys(unsigned char key, int x, int y)
{
	if (key == 'q') {

		if (gColorMode == COLOR_MODE_CYAN)
			gColorMode = COLOR_MODE_MULTI;
		else
			gColorMode = COLOR_MODE_CYAN;
	}
	else if (key == 'e') {
		if (gProgectionScale == 1.0f)
			gProgectionScale = 2.0f;
		else if (gProgectionScale == 2.0f)
			gProgectionScale = 0.5f;
		else
			gProgectionScale = 1.0f;
	}

	// update projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH * gProgectionScale,
		SCREEN_HEIGHT * gProgectionScale,
		0.0, 1.0, -1.0);
}
