#ifndef LUTIL_H_INCLUDED
#define LUTIL_H_INCLUDED

#include "lopengl.h"

// Screen constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS	=  60;

// color modes
const int COLOR_MODE_CYAN  = 0;
const int COLOR_MODE_MULTI = 1;

bool initGL();
void update();
void render();
void handleKeys(unsigned char key, int x, int y);

#endif // LUTIL_H_INCLUDED
