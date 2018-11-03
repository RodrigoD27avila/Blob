#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>
#include <stk.h>

#include "mape.h"
#include "mapeworkarea.h"
#include "mapespritebox.h"

int main()
{
	STK_Init();

	STK_Window window;
	STK_WindowInit(&window, MAPE_TITLE, MAPE_WIDTH, MAPE_HEIGHT,
		MAPE_BPP, MAPE_FLAGS, MAPE_FPS, SDL_FALSE);
	STK_WindowShow(&window);

	STK_Widget workarea;
	MAPE_WorkAreaInit(&workarea, window.screen);
	STK_WidgetSetVisible(&workarea, SDL_TRUE);
	
	STK_Widget spritebox;
	MAPE_SpriteBoxInit(&spritebox, 100, 100, 300, 400, window.screen);
	STK_WidgetSetVisible(&spritebox, SDL_TRUE);

	STK_WindowPushBack(&window, &workarea);
	STK_WindowPushBack(&window, &spritebox);
	STK_WindowSetFocusWidget(&window, 0);

	STK_MainLoop(&window);
	STK_Quit();

	return 0;
}
