#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat spin = 0.0;

float w_src = 25.0;
float h_src = 25.0;

int w = 250;
int h = 250;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);

    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(w_src, h_src);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(-w_src, h_src);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(-w_src, -h_src);
        glColor3f(0.0, 1.0, 1.0);
        glVertex2f(0.0, 0.0);
        glVertex2f(w_src, -h_src);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(w_src, h_src);
        glVertex2f(-w_src, h_src);
        glVertex2f(-w_src, -h_src);
        glVertex2f(w_src, -h_src);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay()
{
    spin = spin + 2.0;
    if (spin > 360.0)
        spin = spin - 360;
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    w = width;
    h = height;

    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void mouse(int button, int state, int x ,int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'a':
            w_src -= 1.0;
            break;
        case 'd':
            w_src += 1.0;
            break;
        case 'w':
            h_src -= 1.0;
            break;
        case 's':
            h_src += 1.0;
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;

}
