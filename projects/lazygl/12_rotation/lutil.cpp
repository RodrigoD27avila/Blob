#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gRotatingTexture;

// angle
GLfloat gAngle = 0.0f;

// texture filtering
GLenum gFiltering = GL_LINEAR;

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

	// set blending
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
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
	// rotate
	gAngle += 360.0f / SCREEN_FPS;


	// cap angle
	if (gAngle > 360.0f) {
		gAngle -= 360.0f;
	}
		
}

void render()
{
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	gRotatingTexture.render(
		(SCREEN_WIDTH  - gRotatingTexture.imageWidth())  / 2.0f,
		(SCREEN_HEIGHT - gRotatingTexture.imageHeight()) / 2.0f,
		NULL, NULL, gAngle);
	
	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "arrow.png";

	// load texture
	if (!gRotatingTexture.loadTextureFromFileWithColorKey(name,
		000, 255, 255)) {
		return false;
	}

	return true;
}

void handleKeys(unsigned char key, int x, int y)
{
	// if q is pressed
	if (key == 'q') {
		// bind texture for modification
		glBindTexture(GL_TEXTURE_2D, gRotatingTexture.getTextureID());
		
		// toggle linear/nearest filtering
		if (gFiltering != GL_LINEAR) {
			glTexParameteri(GL_TEXTURE_2D,
				GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,
				GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			gFiltering = GL_LINEAR;
			
		}
		else {
			glTexParameteri(GL_TEXTURE_2D,
				GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D,
				GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			gFiltering = GL_NEAREST;
		}
	}

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);
}
