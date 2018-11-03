
#define RADIUS 1

void computeGeometry() {
  /* Build our geometry up */
  glNewList(1, GL_COMPILE);
  glColor3f(1,1,1);
  glPointSize(10.0);

// Draw the x/y/z axis
  glBegin(GL_LINE_STRIP);
  glColor3f(1, 0, 0);
  glVertex3f( 0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f( 0, 0, 0);

  glColor3f(0, 1, 0);
  glVertex3f( 0, 0, 0);
  glVertex3f(0, 1, 0);
  glVertex3f( 0, 0, 0);

  glColor3f(0, 0, 1);
  glVertex3f(0, 0,  0);
  glVertex3f(0, 0, 1);
  glEnd();

// Draw the box
  glBegin(GL_LINE_STRIP);

  glColor3f(1, 1, 1);

  glVertex3f( 1, -1, -1);
  glVertex3f( 1,  1, -1);
  glVertex3f(-1,  1, -1);
  glVertex3f(-1, -1, -1);
  glVertex3f( 1, -1, -1);

  glVertex3f( 1, -1,  1);
  glVertex3f( 1,  1,  1);
  glVertex3f(-1,  1,  1);
  glVertex3f(-1, -1,  1);
  glVertex3f( 1, -1,  1);

  glVertex3f( 1,  1,  1);
  glVertex3f( 1,  1, -1);

  glVertex3f(-1,  1, -1);
  glVertex3f(-1,  1,  1);

  glVertex3f(-1, -1,  1);
  glVertex3f(-1, -1, -1);

  glEnd();

  glEndList();
} /* end func computeGeometry */
