// Simple demonstration of multiple windows.

#include <gl\glut.h>
#include <iostream.h>

// Constants for window sizes (also needed fo mouse functions).
const int WIN_SIZE = 200;
const int GAP = WIN_SIZE / 4;
const int SPACING = GAP + WIN_SIZE;
const GLfloat F_SIZE = WIN_SIZE;

// Handles for three windows.
int window[3];

// Mouse positions in each window.
GLfloat x0, y0, x1, y1, x2, y2;

// Spin agle
double angle = 0;

void display (void) {
	// Display callback function.
	// Assumes MODEL_VIEW matrix.
	glClear(GL_COLOR_BUFFER_BIT);	
	glLoadIdentity();

	// Choose point of view depending on the window.
	int win = glutGetWindow();
	if (win == window[0])
		gluLookAt(5.0, 0.0, 5.0,   0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	else if (win == window[1])
		gluLookAt(0.0, 5.0, 5.0,   0.0, 0.0, 0.0,  0.0, 1.0, 0.0);
	else if (win == window[2])
		gluLookAt(5.0, 5.0, 0.0,   0.0, 0.0, 0.0,  0.0, 1.0, 0.0);

	// Draw the cube, rotated and scaled.
	glPushMatrix();
		glTranslatef(-1.0, 0.0, 0.0);
		glRotatef(360.0 * x0, 1.0, 0.0, 0.0);
		glRotatef(360.0 * y0, 0.0, 1.0, 0.0);
      glRotatef(angle, 0.0, 0.0, 1.0);
		glScalef(x1 + 1.0, y1 + 1.0, 1.0);
		glColor3f(0.8f, 0.0f, 0.8f);
		glutWireCube(2.0);
	glPopMatrix();

	// Draw thre cone, rotated and scaled.
	glPushMatrix();
		glTranslatef(1.0, 0.0, 0.0);
		glRotatef(360.0 * x2, 1.0, 0.0, 0.0);
		glRotatef(360.0 * y2, 0.0, 1.0, 0.0);
		glScalef(x1 + 1.0, y1 + 1.0, 1.0);
		glTranslatef(0.0, 0.0, -1.0);
		glColor3f(0.0f, 0.8f, 0.8f);
		glutWireCone(1.0, 3.0, 10, 10);
	glPopMatrix();
	glutSwapBuffers();
}

void refresh () {
	// Request redisplay of all three windows.
	for (int i = 0; i < 3; i++) {
		glutSetWindow(window[i]);
		glutPostRedisplay();
	}
}

void mouse0 (int x, int y) {
	// Mouse function for window 0.
	x0 = x / F_SIZE;
	y0 = y / F_SIZE;
	refresh();
}

void mouse1 (int x, int y) {
	// Mouse function for window 1.
	x1 = x / F_SIZE;
	y1 = y / F_SIZE;
	refresh();
}

void mouse2 (int x, int y) {
	// Mouse function for window 2.
	x2 = x / F_SIZE;
	y2 = y / F_SIZE;
	refresh();
}

void keyboard (unsigned char key, int x, int y) {
	// Keyboard function works for all windows.
	if (key == 27)
		exit(0);
}

void spin()
{
   angle += 1;
   if (angle > 360)
      angle -= 360;
   refresh();
}

void main (int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Set up three windows. The properties of each window are the same
	// except for their position and mouse function.  The common code
	// has to be repeated, so that it gets attached to each window.

	glutInitWindowSize(WIN_SIZE, WIN_SIZE);
	glutInitWindowPosition(GAP, GAP);
	window[0] = glutCreateWindow("Window 0");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
//   glutIdleFunc(spin);
	glutMotionFunc(mouse0);

	// Set up second window.
	glutInitWindowPosition(GAP + SPACING, GAP);
	window[1] = glutCreateWindow("Window 1");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
//   glutIdleFunc(spin);
	glutMotionFunc(mouse1);

	// Set up third window.
	glutInitWindowPosition(GAP + 2 * SPACING, GAP);
	window[2] = glutCreateWindow("Window 2");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
//   glutIdleFunc(spin);
	glutMotionFunc(mouse2);

   glutIdleFunc(spin);

   // Help the user.
	cout <<
		"The three windows show the same scene from different angles." << endl <<
		"Each window has a different mouse function." << endl <<
		"Mouse in Window 0 rotates the cube." << endl <<
		"Mouse in Window 1 rescales both objects." << endl <<
		"Mouse in Window 2 rotates the cone." << endl <<
		"Press ESC in any window to quit." << endl;

	glutMainLoop();
}
