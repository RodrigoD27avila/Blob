#ifndef LUTIL_H_INCLUDED
#define LUTIL_H_INCLUDED

#include "lopengl.h"

// Screen constants
const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS	=  60;

// VIew port mode
enum ViewPortMode {
	VIEW_PORT_MODE_FULL,
	VIEW_PORT_MODE_HALF_CENTER,
	VIEW_PORT_MODE_HALF_TOP,
	VIEW_PORT_MODE_QUAD,
	VIEW_PORT_MODE_RADAR,
};

bool initGL();
void update();
void render();
void handleKeys(unsigned char key, int x, int y);

#endif // LUTIL_H_INCLUDED
