#include "lutil.h"
#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

// texture
LTexture gRotatingTexture;

// angle
GLfloat gAngle = 0.0f;

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

	// reset transformation
	glLoadIdentity();

	switch (gTransformationCombo) {
	case 0:
		glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
		glRotatef(gAngle, 0.0f, 0.0f, 1.0f);
		glScalef(2.0f, 2.0f, 0.0f);
		glTranslatef(gRotatingTexture.imageWidth() / -2.0f,
			gRotatingTexture.imageHeight() / -2.0f, 0.0f);
		break;
	case 1:
		glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
		glRotatef(gAngle, 0.0f, 0.0f, 1.0f);
		glTranslatef(gRotatingTexture.imageWidth() / -2.0f,
			gRotatingTexture.imageHeight() / -2.0f, 0.0f);
		glScalef(2.0f, 2.0f, 0.0f);
		break;
	case 2:
		glScalef(2.0f, 2.0f, 0.0f);
		glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
		glRotatef(gAngle, 0.0f, 0.0f, 1.0f);
		glTranslatef(gRotatingTexture.imageWidth() / -2.0f,
			gRotatingTexture.imageHeight() / -2.0f, 0.0f);
		break;
	case 3:
		glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
		glRotatef(gAngle, 0.0f, 0.0f, 1.0f);
		glScalef(2.0f, 2.0f, 0.0f);
		break;
	case 4:
		glRotatef(gAngle, 0.0f, 0.0f, 1.0f);
		glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);
		glScalef(2.0f, 2.0f, 0.0f);
		glTranslatef(gRotatingTexture.imageWidth() / -2.0f,
			gRotatingTexture.imageHeight() / -2.0f, 0.0f);
		break;	
	}

	//render texture
	gRotatingTexture.render(0.0f, 0.0f);

	// update screen
	glutSwapBuffers();
}

bool loadMedia()
{
	const char *name = "texture.png";

	// load texture
	if (!gRotatingTexture.loadTextureFromFile(name)) {
		return false;
	}

	return true;
}

void handleKeys(unsigned char key, int x, int y)
{
	// if q is pressed
	if (key == 'q') {
		// reset rotation 
		gAngle = 0.0f;

		// cycle through compinations
		gTransformationCombo++;
		if (gTransformationCombo > 4) {
			gTransformationCombo = 0;
		}
	}
}
