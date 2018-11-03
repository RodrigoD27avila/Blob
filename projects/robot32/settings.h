#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <SDL.h>

void settings_Init();

Uint16   settings_GetScreenWidth();
Uint16   settings_GetScreenHeight();
Uint16   settings_GetScreenFPS();


void     settings_SetScreenWidth(Uint16 width);
void     settings_SetScreenHeight(Uint16 height);
void     settings_SetScreenFPS(Uint16 fps);

const char *settings_GetWindowTitle();

#endif /* SETTINGS_H_INCLUDED */
