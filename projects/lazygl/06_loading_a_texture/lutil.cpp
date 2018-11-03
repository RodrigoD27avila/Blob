#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gLoadedTexture;

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

	// initialize devil
	ilInit();
	ilClearColour(255, 255, 255, 000);
	
	// check for error
	ILenum ilerror = ilGetError();
	if (ilerror != IL_NO_ERROR) {
		fprintf(stderr, "error initializing devil! %s\n",
			iluErrorString(error));
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
	GLfloat x = ((SCREEN_WIDTH  - gLoadedTexture.textureWidth()) / 2.0f);	
	GLfloat y = ((SCREEN_HEIGHT - gLoadedTexture.textureHeight()) / 2.0f);	

	// render checkboard texture
	gLoadedTexture.render(x, y);
	
	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "texture.png";

	// load texture
	if (!gLoadedTexture.loadTextureFromFile(name)) {
		return false;
	}

	return true;
}
