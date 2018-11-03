#include "lutil.h"
#include "ltexture.h"
#include "lvertexpos2d.h"

#include <IL/il.h>
#include <IL/ilu.h>

// quad vertices
LVertexPos2D gQuadVertices[4];

bool initGL()
{
	// initialize GLEW
	GLenum glewerror = glewInit();
	if (glewerror != GLEW_OK) {
		printf("Error initializing GLEW! %s\n",
			glewGetErrorString(glewerror));
		return false;
	}

	// Make sure OpenGL 2.1 is supported
	if (!GLEW_VERSION_2_1) {
		printf("Opengl 2.1 not supported!\n");
		return false;
	}

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

	// initialize devil and devilu
	ilInit();
	iluInit();
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

	// enable vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);

	// set vertex data
	glVertexPointer(2, GL_FLOAT, 0, gQuadVertices);

	// draw quad using vertex data
	glDrawArrays(GL_QUADS, 0, 4);

	// disable vertex arrays
	glDisableClientState(GL_VERTEX_ARRAY);

	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	// set quad vertices
	gQuadVertices[0].x = SCREEN_WIDTH  * 1.0f / 4.0f;
	gQuadVertices[0].y = SCREEN_HEIGHT * 1.0f / 4.0f;
	gQuadVertices[1].x = SCREEN_WIDTH  * 3.0f / 4.0f;
	gQuadVertices[1].y = SCREEN_HEIGHT * 1.0f / 4.0f;
	gQuadVertices[2].x = SCREEN_WIDTH  * 3.0f / 4.0f;
	gQuadVertices[2].y = SCREEN_HEIGHT * 3.0f / 4.0f;
	gQuadVertices[3].x = SCREEN_WIDTH  * 1.0f / 4.0f;
	gQuadVertices[3].y = SCREEN_HEIGHT * 3.0f / 4.0f;
	return true;
}

void handleKeys(unsigned char key, int x, int y)
{
}
