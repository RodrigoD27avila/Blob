#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gCircleTexture;

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
	
	// render arrows
	gCircleTexture.render((SCREEN_WIDTH - gCircleTexture.imageWidth())
		/ 2.0f,
		(SCREEN_HEIGHT - gCircleTexture.imageHeight())
		/ 2.0f);

	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "circle.png";

	// load texture
	if (!gCircleTexture.loadTextureFromFile(name)) {
		return false;
	}

	// lock texture for modifications
	gCircleTexture.lock();

	// set target color
	GLuint targetcolor = 0xffffff00;

	// replace target color with transparent back
	GLuint *pixels    = gCircleTexture.getPixelData32();
	GLuint pixelcount = gCircleTexture.textureWidth()
		* gCircleTexture.textureHeight();

	unsigned int i, j;
	for (i=0; i< pixelcount; i++) {
		if (pixels[i] == targetcolor) {
			pixels[i] = 0;
		}
	}

	// diagonal lines
	for (i=0; i <gCircleTexture.imageWidth(); i++) {
		for (j=0; j<gCircleTexture.imageHeight(); j++) {
			if (i % 10 != j % 10) {
				gCircleTexture.setPixel32(i, j, 0);
			}
		}
	}

	// update texture
	gCircleTexture.unlock();

	return true;
}
