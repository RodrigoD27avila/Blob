#include "lutil.h"

// View port mode
int gViewportMode = VIEW_PORT_MODE_FULL;

bool initGL()
{
	// set the view  port
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);	

	// initialize projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f, -1.0f);

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


static inline void render_viweport_full()
{
	// fill the screen
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	// red quad
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
	glEnd();
	
}

static inline void render_viweport_half_center()
{
	// fill the screen
	glViewport(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 4.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	
	// green quad
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
	glEnd();
}

static inline void render_viweport_half_top()
{
	// fill the screen
	glViewport(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 2.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	
	// blue quad
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
		glVertex2f( SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
		glVertex2f(-SCREEN_WIDTH / 2.0f,  SCREEN_HEIGHT / 2.0f);
	glEnd();
}


static inline void render_viweport_quad()
{
	// bottom left red quad
	glViewport(0.0f, 0.0f, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
	glEnd();
	
	// bottom right green quad
	glViewport(SCREEN_WIDTH / 2.0f, 0.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
	glEnd();
	
	// top left blue quad
	glViewport(0.0f, SCREEN_HEIGHT / 2.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
	glEnd();
	
	// top right yellow quad
	glViewport( SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f, -SCREEN_HEIGHT / 4.0f);
		glVertex2f( SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
		glVertex2f(-SCREEN_WIDTH / 4.0f,  SCREEN_HEIGHT / 4.0f);
	glEnd();
}

static inline void render_viweport_radar()
{
	// full size quad
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-SCREEN_WIDTH / 8.0f, -SCREEN_HEIGHT / 8.0f);
		glVertex2f( SCREEN_WIDTH / 8.0f, -SCREEN_HEIGHT / 8.0f);
		glVertex2f( SCREEN_WIDTH / 8.0f,  SCREEN_HEIGHT / 8.0f);
		glVertex2f(-SCREEN_WIDTH / 8.0f,  SCREEN_HEIGHT / 8.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 16.0f, -SCREEN_HEIGHT / 16.0f);
		glVertex2f( SCREEN_WIDTH / 16.0f, -SCREEN_HEIGHT / 16.0f);
		glVertex2f( SCREEN_WIDTH / 16.0f,  SCREEN_HEIGHT / 16.0f);
		glVertex2f(-SCREEN_WIDTH / 16.0f,  SCREEN_HEIGHT / 16.0f);
	glEnd();
	
	// radar quad
	glViewport(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f,
		SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-SCREEN_WIDTH / 8.0f, -SCREEN_HEIGHT / 8.0f);
		glVertex2f( SCREEN_WIDTH / 8.0f, -SCREEN_HEIGHT / 8.0f);
		glVertex2f( SCREEN_WIDTH / 8.0f,  SCREEN_HEIGHT / 8.0f);
		glVertex2f(-SCREEN_WIDTH / 8.0f,  SCREEN_HEIGHT / 8.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-SCREEN_WIDTH / 16.0f, -SCREEN_HEIGHT / 16.0f);
		glVertex2f( SCREEN_WIDTH / 16.0f, -SCREEN_HEIGHT / 16.0f);
		glVertex2f( SCREEN_WIDTH / 16.0f,  SCREEN_HEIGHT / 16.0f);
		glVertex2f(-SCREEN_WIDTH / 16.0f,  SCREEN_HEIGHT / 16.0f);
	glEnd();
}



void render()
{
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// reset the modelview matrix
	glLoadIdentity();
	
	// move to the center of the screen
	glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

	switch (gViewportMode) {

	// render full view
	case VIEW_PORT_MODE_FULL:
		render_viweport_full();
		break;
	
	// render at center of screen 
	case VIEW_PORT_MODE_HALF_CENTER:
		render_viweport_half_center();
		break;

	// render at top center of screen
	case VIEW_PORT_MODE_HALF_TOP:
		render_viweport_half_top();
		break;	
	
	//render four viewports
	case VIEW_PORT_MODE_QUAD:
		render_viweport_quad();
		break;

	// render with radar subview port
	case VIEW_PORT_MODE_RADAR:
		render_viweport_radar();
		break;
	}

	// update screen
	glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y)
{
	if (key == 'q') {
		gViewportMode += 1;
		if (gViewportMode > VIEW_PORT_MODE_RADAR)
			gViewportMode = VIEW_PORT_MODE_FULL;
	}
}
