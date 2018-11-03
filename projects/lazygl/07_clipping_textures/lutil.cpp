#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gArrowTexture;

//sprite area
LFRect gArrowClips[4];

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
	gArrowTexture.render(0.0f, 0.0f, &gArrowClips[0]);

	gArrowTexture.render(SCREEN_WIDTH - gArrowClips[1].w,
		0.0f, &gArrowClips[1]);

	gArrowTexture.render(0.0f, SCREEN_HEIGHT - gArrowClips[2].h,
		&gArrowClips[2]);

	gArrowTexture.render(SCREEN_WIDTH - gArrowClips[3].w,
		SCREEN_HEIGHT - gArrowClips[3].h, &gArrowClips[3]);
	
	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "arrows.png";

	// set clip rectangles
	gArrowClips[0].x = 0.0f;
	gArrowClips[0].y = 0.0f;
	gArrowClips[0].w = 128.0f;
	gArrowClips[0].h = 128.0f;

	gArrowClips[1].x = 128.0f;
	gArrowClips[1].y = 0.0f;
	gArrowClips[1].w = 128.0f;
	gArrowClips[1].h = 128.0f;

	gArrowClips[2].x = 0.0f;
	gArrowClips[2].y = 128.0f;
	gArrowClips[2].w = 128.0f;
	gArrowClips[2].h = 128.0f;

	gArrowClips[3].x = 128.0f;
	gArrowClips[3].y = 128.0f;
	gArrowClips[3].w = 128.0f;
	gArrowClips[3].h = 128.0f;

	// load texture
	if (!gArrowTexture.loadTextureFromFile(name)) {
		return false;
	}

	return true;
}
