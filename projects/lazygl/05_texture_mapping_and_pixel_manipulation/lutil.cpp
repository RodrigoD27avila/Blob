#include "lutil.h"
#include "ltexture.h"

// checker board texture
LTexture gCheckerBoardtexture;

bool initGL()
{
	//set the viwer port
	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	// initialize projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 1.0f, -1.0f);

	// initialize model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// initialize clear color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// enable texturing
	glEnable(GL_TEXTURE_2D);
	
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
	
	// calculate centered offsets
	GLfloat x = ((SCREEN_WIDTH - gCheckerBoardtexture.textureWidth())
		/ 2.0f);	

	GLfloat y = ((SCREEN_HEIGHT - gCheckerBoardtexture.textureHeight())
		/ 2.0f);	

	// render checkboard texture
	gCheckerBoardtexture.render(x, y);
	
	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	// check board pixels
	const int CHECKERBOARD_WIDTH  = 128;
	const int CHECKERBOARD_HEIGHT = 128;
	const int CHECKERBOARD_PIXEL_COUNT =
		CHECKERBOARD_WIDTH * CHECKERBOARD_HEIGHT;

	GLuint checkerboard[CHECKERBOARD_PIXEL_COUNT];

	// go through pixels
	int i;
	for (i=0; i < CHECKERBOARD_PIXEL_COUNT; i++) {
		
		// get the individual color components
		GLubyte *colors = (GLubyte *)&checkerboard[i];

		// set pixel white
		if ((i / 128 & 16) ^ (i % 128 & 16)) {
			colors[0] = 0xff;
			colors[1] = 0xaa;
			colors[2] = 0xff;
			colors[3] = 0xff;
		}
		// set pixel red
		else {
			colors[0] = 0xff;
			colors[1] = 0xff;
			colors[2] = 0x00;
			colors[3] = 0xff;
		}
	}

	if (!gCheckerBoardtexture.loadTextureFromPixel32(checkerboard,
		CHECKERBOARD_WIDTH, CHECKERBOARD_HEIGHT)) {
		fprintf(stderr, "Unable to load checkerboard texture!\n");
		return false;
	}

	return true;
}
