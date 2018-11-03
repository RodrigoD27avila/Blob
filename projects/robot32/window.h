#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <SDL.h>

void         window_Init();
void         window_Quit();

Uint16       window_GetWidth();
Uint16       window_GetHeight();
SDL_Window   *window_GetMainWindow();
SDL_Renderer *window_GetMainRenderer();

#endif /* WINDOW_H_INCLUDED */
