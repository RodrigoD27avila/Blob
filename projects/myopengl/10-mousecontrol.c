#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265f

static const char title[]      = "Boucing Ball (2D)";
static int windowWidth   = 640;
static int windowHeight  = 480;
static int windowPosX    = 50;
static int windowPosY    = 50;
static int refreshMillis = 30;

static GLfloat ballRadius = 0.5f;
static GLfloat ballX      = 0.0f;
static GLfloat ballY      = 0.0f;
static GLfloat xSpeed     = 0.02f;
static GLfloat ySpeed     = 0.007f;

static GLfloat ballXMax;
static GLfloat ballXMin;
static GLfloat ballYMax;
static GLfloat ballYMin;

static GLdouble clipAreaXLeft;
static GLdouble clipAreaXRight;
static GLdouble clipAreaYBotton;
static GLdouble clipAreaYTop;

static unsigned int fullscreenMode = 1;
static unsigned int paused          = 0;
static GLfloat xSpeedSaved;
static GLfloat ySpeedSaved;


void initGL()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(ballX, ballY, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0f, 0.0f);
		int i, numSegments = 100;
		GLfloat angle;
		for (i=0; i<=numSegments; i++) {
			angle = i * 2.0f * PI / numSegments;
			glVertex2f(cos(angle) * ballRadius,
				sin(angle) * ballRadius);
		}
	glEnd();

	glutSwapBuffers();

	ballX += xSpeed;
	ballY += ySpeed;

	if (ballX > ballXMax) {
		ballX  = ballXMax;
		xSpeed = -xSpeed; 
	}
	else if (ballX < ballXMin) {
		ballX  = ballXMin;
		xSpeed = -xSpeed;
	}
	
	if (ballY > ballYMax) {
		ballY  = ballYMax;
		ySpeed = -ySpeed; 
	}
	else if (ballY < ballYMin) {
		ballY  = ballYMin;
		ySpeed = -ySpeed;
	}
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) {
		height = 1;
	}

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width >= height) {
		clipAreaXLeft   = -1.0 * aspect;
		clipAreaXRight  =  1.0 * aspect;
		clipAreaYBotton = -1.0;
		clipAreaYTop    =  1.0;
	}
	else {
		clipAreaXLeft   = -1.0;
		clipAreaXRight  =  1.0;
		clipAreaYBotton = -1.0 / aspect;
		clipAreaYTop    =  1.0 / aspect;
	}

	gluOrtho2D(clipAreaXLeft, clipAreaXRight,
		clipAreaYBotton, clipAreaYTop);

	ballXMin = clipAreaXLeft   + ballRadius;
	ballXMax = clipAreaXRight  - ballRadius;
	ballYMin = clipAreaYBotton + ballRadius;
	ballYMax = clipAreaYTop    - ballRadius;
}

void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMillis, Timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

void specialKeys(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_F1:
		fullscreenMode = !fullscreenMode;
		if (fullscreenMode) {
			windowPosX   = glutGet(GLUT_WINDOW_X);
			windowPosY   = glutGet(GLUT_WINDOW_Y);
			windowWidth  = glutGet(GLUT_WINDOW_WIDTH);
			windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
			glutFullScreen();
		}
		else {
			glutReshapeWindow(windowWidth, windowHeight);
			glutPositionWindow(windowPosX, windowPosY);
		}
		break;
	case GLUT_KEY_RIGHT:
		xSpeed *= 1.05f; break;
	case GLUT_KEY_LEFT:
		xSpeed *= 0.95f; break;
	case GLUT_KEY_UP:
		ySpeed *= 1.05f; break;
	case GLUT_KEY_DOWN:
		ySpeed *= 0.95f; break;
	case GLUT_KEY_PAGE_UP:
		ballRadius *= 1.05f;
		ballXMin = clipAreaXLeft   + ballRadius;
		ballXMax = clipAreaXRight  - ballRadius;
		ballYMin = clipAreaYBotton + ballRadius;
		ballYMax = clipAreaYTop    - ballRadius;
		break;
	case GLUT_KEY_PAGE_DOWN:
		ballRadius *= 0.95f;
		ballXMin = clipAreaXLeft   + ballRadius;
		ballXMax = clipAreaXRight  - ballRadius;
		ballYMin = clipAreaYBotton + ballRadius;
		ballYMax = clipAreaYTop    - ballRadius;
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		paused = !paused;
		if (paused) {
			xSpeedSaved = xSpeed;
			ySpeedSaved = ySpeed;
			xSpeed = 0;
			ySpeed = 0;
		}
		else {
			xSpeed = xSpeedSaved;
			ySpeed = ySpeedSaved;
		}
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(windowPosX, windowPosY);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, Timer, 0);
	glutSpecialFunc(specialKeys);
	glutFullScreen();
	glutMouseFunc(mouse);
	initGL();
	glutMainLoop();
	return 0;
}
