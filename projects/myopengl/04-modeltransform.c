#include <stdio.h>
#include <GL/glut.h>

struct Color {
	float r; 
	float g; 
	float b;
	float a; 
};

void initGL()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glCullFace(GL_BACK);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void display()
{
	struct Color color = {1.0f, 0.0f, 0.0f, 1.0f};

	// clear buffer color
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(-0.5f,  0.4f,  0.0f);
	glBegin(GL_QUADS);
		glColor4fv((const GLfloat *)&color);
		glVertex2f(-0.3f, -0.3f);
		glVertex2f( 0.3f, -0.3f);
		glVertex2f( 0.3f,  0.3f);
		glVertex2f(-0.3f,  0.3f);
	glEnd();

	glTranslatef( 0.1f, -0.7f,  0.0f);
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.3f, -0.3f);
		glVertex2f( 0.3f, -0.3f);
		glVertex2f( 0.3f,  0.3f);
		glVertex2f(-0.3f,  0.3f);
	glEnd();

	glTranslatef(-0.3f, -0.2f,  0.0f);
	glBegin(GL_QUADS);
		glColor4f(0.2f, 0.2f, 0.2f, 1.0);
		glVertex2f(-0.2f, -0.2f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0);
		glVertex2f( 0.2f, -0.2f);
		glColor4f(0.2f, 0.2f, 0.2f, 1.0);
		glVertex2f( 0.2f,  0.2f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0);
		glVertex2f(-0.2f, 0.2f);
	glEnd();

	glTranslatef( 1.1f, 0.2f,  0.0f);
	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(-0.3f, -0.2f);
		glVertex2f( 0.3f, -0.2f);
		glVertex2f( 0.0f,  0.3f);
	glEnd();

	glTranslatef( 0.2f, -0.3f,  0.0f);
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f(-0.3f, -0.2f);
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f( 0.3f, -0.2f);
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f( 0.0f,  0.3f);
	glEnd();

	glRotatef(-180.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.1f,  1.0f,  0.0f);
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.1f, -0.2f);
		glVertex2f( 0.1f, -0.2f);
		glVertex2f( 0.2f,  0.0f);
		glVertex2f( 0.1f,  0.2f);
		glVertex2f(-0.1f,  0.2f);
		glVertex2f(-0.2f,  0.0f);
	glEnd();

	glFlush(); // render Now!!
}

void reshape(GLsizei width, GLsizei height)
{
	if (height == 0) {
		height = 1;
	}

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	printf("ASPECT = %f\n", aspect);
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if (width >= height) {
		gluOrtho2D(-1.0f * aspect, 1.0f * aspect, -1.0f, 1.0f);
	}
	else {
		gluOrtho2D(-1.0f , 1.0f , -1.0f / aspect, 1.0f / aspect);
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Vertex Primitives");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();
	return 0;
}
