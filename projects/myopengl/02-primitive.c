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

	glBegin(GL_QUADS);
		glColor4fv((const GLfloat *)&color);
		glVertex2f(-0.8f,  0.1f);
		glVertex2f(-0.2f,  0.1f);
		glVertex2f(-0.2f,  0.7f);
		glVertex2f(-0.8f,  0.7f);
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-0.7f, -0.6f);
		glVertex2f(-0.1f, -0.6f);
		glVertex2f(-0.1f,  0.0f);
		glVertex2f(-0.7f,  0.0f);
		
		glColor4f(0.2f, 0.2f, 0.2f, 1.0);
		glVertex2f(-0.9f, -0.7f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0);
		glVertex2f(-0.5f, -0.7f);
		glColor4f(0.2f, 0.2f, 0.2f, 1.0);
		glVertex2f(-0.5f, -0.3f);
		glColor4f(1.0f, 1.0f, 1.0f, 0.0);
		glVertex2f(-0.9f, -0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f( 0.1f, -0.6f);
		glVertex2f( 0.7f, -0.6f);
		glVertex2f( 0.4f, -0.1f);
		
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex2f( 0.3f, -0.4f);
		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex2f( 0.9f, -0.4f);
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f);
		glVertex2f( 0.6f, -0.9f);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f( 0.4f,  0.2f);
		glVertex2f( 0.6f,  0.2f);
		glVertex2f( 0.7f,  0.4f);
		glVertex2f( 0.6f,  0.6f);
		glVertex2f( 0.4f,  0.6f);
		glVertex2f( 0.3f,  0.4f);
	glEnd();

	glFlush(); // render Now!!
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Vertex Primitives");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}
