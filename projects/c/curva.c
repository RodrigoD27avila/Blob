#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define LARGURA 500
#define ALTURA 500

float p[4][2];
int indice;

// Função callback chamada para gerenciar eventos do mouse
void Inicia()
{

   p[0][0] = -1.0f;
   p[0][1] =  0.0f;

   p[1][0] = -0.5f;
   p[1][1] = -0.5f;

   p[2][0] =  0.5f;
   p[2][1] =  0.5f;

   p[3][0] =  1.0f;
   p[3][1] =  0.0f;
}

void atualiza(int x, int y)
{
   float cx, cy;

   cx = ((float)(2.0f*x)/(float)LARGURA)    - 1.0f;
   cy = ((float)(2.0f*y)/(float)ALTURA)    - 1.0f;
   cy *= -1.0f;

   p[indice][0] = cx;
   p[indice][1] = cy;
   glutPostRedisplay();
}

void escolha(int botao, int estado, int x, int y)
{
   if ((botao == GLUT_LEFT_BUTTON) && (estado == GLUT_DOWN))
      indice = 1;

   if ((botao == GLUT_RIGHT_BUTTON) && (estado == GLUT_DOWN))
      indice = 2;

   atualiza(x,y);
}

void captura(int x, int y)
{
   atualiza(x,y);
}

float fatorial(int a)
{
   int i;
   float produto;

   produto = 1.0f;
   for (i=a;i>0;i--)
      produto *= (float) i;
   return produto;
}

float combinacao(int a, int b)
{
   return fatorial(b)/(fatorial(a)*fatorial(b-a));
}


void exibe(void)
{   
   GLint i;
   GLfloat u,x,y;

   glClear(GL_COLOR_BUFFER_BIT);

   glColor3f(1.0f,0.0f,0.0f);
   glBegin(GL_LINE_STRIP);
   for (i=0;i<4;i++)   
      glVertex2f(p[i][0],p[i][1]);
   glEnd();   

   glColor3f(0.0f,1.0f,0.0f);
   glBegin(GL_POINTS);
   for (u=0.0f;u<=1.0f;u+=0.001f)
   {
      x = 0.0f;
      y = 0.0f;
      for (i=0;i<4;i++)
      {
         x += combinacao(i,3)*pow(u,i)*pow(1.0f-u,3-i)*p[i][0];
         y += combinacao(i,3)*pow(u,i)*pow(1.0f-u,3-i)*p[i][1];
      }   
      glVertex2f(x,y);
   }      
   glEnd();

   glFlush();
}


int main(int argc, char** argv)
{
   Inicia();
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(ALTURA,LARGURA);
   glutInitWindowPosition(20,20);
   glutCreateWindow("Desenhando uma curva de Bézier");
   glutDisplayFunc(exibe);
   glutMouseFunc(escolha);
   glutMotionFunc(captura);
   glutMainLoop();

   return 0;
}
