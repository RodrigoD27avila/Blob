#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

static int mouse_x = 0;
static int mouse_y = 0;
static int width_t = 250;
static int height_t = 250;

static float p_y = 0.004;
static float p_x = 0.004;

float convert_y(int c)
{
	return (height_t - c) * p_y;
}

float convert_x(int c)
{
	return c * p_x;
}

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	float x = convert_x(mouse_x);
	float y = convert_y(mouse_y);

	printf("x=%f, y=%f\n", x, y);	

	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(x, y, 0.0);
		
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(x/2, y, 0.0);
		
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(x, y/2, 0.0);
		
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(x/2, y/2, 0.0);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glColor3f(x, 1.0, x);
		glVertex3f(x, y, 0.0);
		glVertex3f(x/2, y, 0.0);
		glVertex3f(x/2, y/2, 0.0);
		glVertex3f(x, y/2, 0.0);
	glEnd();

	glBegin(GL_POINTS);
		float i = x/2;
		for (; i < x; i+=(p_x*2))
		{
			float j = y/2;
			for (; j < y; j+=(p_y*2))
			{
				glColor3f(j,i,j);
				glVertex2f(i,j);
			}
		}
	glEnd();
	glutSwapBuffers();
}

void motion(int x, int y)
{
	printf("x=%i,y=%i\n", x, y);
	mouse_x = x;
	mouse_y = y;
	glutPostRedisplay();
}

void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	width_t = width;
	height_t = height;
	p_x = 1.0 / width;
	p_y = 1.0 / height;
	glutPostRedisplay();

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(width_t,height_t);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutPassiveMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
