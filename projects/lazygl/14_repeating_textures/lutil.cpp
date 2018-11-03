#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gRepeatingTexture;

// texture offset
GLfloat gTexX = 0.0f, gTexY = 0.0f;

// texture wrap type
int gTextureWrapType = 0;

// transformation state
int gTransformationCombo = 0;

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
	// scrool texture
	gTexX += 1;
	gTexY += 1;

	// cap scrolling
	if (gTexX >= gRepeatingTexture.textureWidth()) {
		gTexX = 0.0f;
	}
	
	if (gTexY >= gRepeatingTexture.textureHeight()) {
		gTexY = 0.0f;
	}
}

void render()
{
	// clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// calculate texture maxima
	GLfloat textureRight = (GLfloat)SCREEN_WIDTH
		/ (GLfloat)gRepeatingTexture.textureWidth();
	
	GLfloat textureBottom = (GLfloat)SCREEN_HEIGHT
		/ (GLfloat)gRepeatingTexture.textureHeight();

	// use repeating texture
	glBindTexture(GL_TEXTURE_2D, gRepeatingTexture.getTextureID());

	// switch to texture matrix
	glMatrixMode(GL_TEXTURE);

	// reset transformation
	glLoadIdentity();

	// scroll texture
	glTranslatef(gTexX / gRepeatingTexture.textureWidth(),
		gTexY / gRepeatingTexture.textureHeight(), 0.0f);

	// render
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);

	glTexCoord2f(textureRight, 0.0f);
	glVertex2f(SCREEN_WIDTH, 0.0f);

	glTexCoord2f(textureRight, textureBottom);
	glVertex2f(SCREEN_WIDTH, SCREEN_HEIGHT);
	
	glTexCoord2f(0.0f, textureBottom);
	glVertex2f(0.0f, SCREEN_HEIGHT);
	
	glEnd();

	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "texture.png";

	// load texture
	if (!gRepeatingTexture.loadTextureFromFile(name)) {
		return false;
	}

	return true;
}

void handleKeys(unsigned char key, int x, int y)
{
	// if q is pressed
	if (key == 'q') {
		 // Cycle through texture repetitions
		gTextureWrapType += 1;
		if (gTextureWrapType >= 2) {
			gTextureWrapType = 0;
		}

		// set texture repetions
		glBindTexture(GL_TEXTURE_2D, gRepeatingTexture.getTextureID());

		switch (gTextureWrapType) {
		case 0:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
				GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
				GL_REPEAT);
			printf("%d: GL_REPEAT\n", gTextureWrapType);	
			break;

		case 1:
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
				GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
				GL_CLAMP);
			printf("%d: GL_CLAMP\n", gTextureWrapType);	
			break;
			
		}
	}
}
