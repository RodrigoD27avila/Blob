#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "settings.h"

#define DEFAULT_SCREEN_WIDTH  640
#define DEFAULT_SCREEN_HEIGHT 576
#define DEFAULT_SCREEN_FPS     60

static Uint16   screen_width;
static Uint16   screen_height;
static Uint16   screen_fps;
static char     *screen_title;

void settings_Init()
{
	screen_width  = DEFAULT_SCREEN_WIDTH;
	screen_height = DEFAULT_SCREEN_HEIGHT;
	screen_fps    = DEFAULT_SCREEN_FPS;
	screen_title  = "::: robot32 example :::";

}

Uint16 settings_GetScreenWidth()
{ return screen_width; }

Uint16 settings_GetScreenHeight()
{ return screen_height; }

Uint16 settings_GetScreenFPS()
{ return screen_fps; }

void settings_SetScreenWidth(Uint16 width)
{ screen_width = width; }

void settings_SetScreenHeight(Uint16 height)
{ screen_height = height; }

void settings_SetScreenFPS(Uint16 fps)
{ screen_fps = fps; }

const char *settings_GetWindowTitle()
{ return screen_title; }
