#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
        float i = 0.004;
        for (; i < 1.0; i+=0.018)
        {
            float j = 0.004;
            for (; j < 1.0; j+=0.018)
            {
                glColor3f(j,i,j);
                glVertex2f(i,j);
                glVertex2f(i * -1,j * -1);
                glVertex2f(i * -1, j);
                glVertex2f(i, j * -1);
                printf("x=%f y=%f\n", i, j);
            }
        }
    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
