#include "lutil.h"

GLfloat gCameraX = 0.0f, gCameraY = 0.0f;

bool initGL()
{
	//Set the view port
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

	// initialize projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f,  1.0f, -1.0f);

	// initialize model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// save the default modelview matrix
	glPushMatrix();

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
	
	// pop default matrix onto current matrix
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	// save default matrix again
	glPushMatrix();

	// move to the center of the screen
	glTranslatef(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);

	// red quad
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
		glVertex2f(-SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
	glEnd();
	
	// move to the right of the screen
	glTranslatef(SCREEN_WIDTH, 0.0f, 0.0f);

	// green quad
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
		glVertex2f(-SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
	glEnd();
	
	// move to the lower right of the screen
	glTranslatef(0.0f, SCREEN_HEIGHT, 0.0f);

	// blue quad
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
		glVertex2f(-SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
	glEnd();
	
	// move to the below of the screen
	glTranslatef(-SCREEN_WIDTH, 0.0f, 0.0f);

	// blue quad
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0, -SCREEN_HEIGHT / 4.0);
		glVertex2f( SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
		glVertex2f(-SCREEN_WIDTH / 4.0,  SCREEN_HEIGHT / 4.0);
	glEnd();
	
	// update screen
	glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		gCameraY -= 16.0f;
		break;
	case 's':
		gCameraY += 16.0f;
		break;
	case 'a':
		gCameraX -= 16.0f;
		break;	
	case 'd':
		gCameraX += 16.0f;
		break;	
	}

	// take the matrix off of the stack and reset it
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();

	// move camera to position
	glTranslatef(-gCameraX, -gCameraY, 0.0f);

	// Save Default matrix again with camera translation
	glPushMatrix();
}
