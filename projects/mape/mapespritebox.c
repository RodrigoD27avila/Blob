#include "mapespritebox.h"

int MAPE_SpriteBoxInit(STK_Widget *widget, Sint16 x, Sint16 y,
	Uint16 w, Uint16 h, SDL_Surface *screen)
{
	if ((STK_WidgetInit(widget, "MAPE_SpriteBox", x, y, w, h,
		sizeof(MAPE_SpriteBox))) < 0) {
		return -1;	
	}

	widget->draw   = MAPE_SpriteBoxDraw;
	widget->handle = MAPE_SpriteBoxHandle; 
	
	MAPE_SpriteBox *sbox = MAPE_SPRITEBOX(widget);
	sbox->workarea       = STK_UtilCreateEmptySurface(screen, w, h); 

	return 0;
}

int MAPE_SpriteBoxDraw(void *widget, SDL_Surface *surface)
{
	MAPE_SpriteBox *sbox = MAPE_SPRITEBOX(widget);
	SDL_Surface    *area = sbox->workarea;

	SDL_FillRect(area, &area->clip_rect,
		SDL_MapRGB(area->format, 0, 0, 255));
	
	SDL_Rect offset;
	STK_WidgetToRect(STK_WIDGET(widget), &offset);
	SDL_BlitSurface(area, NULL, surface, &offset);

	return 0;
}

int MAPE_SpriteBoxHandle(void *widget, SDL_Event *event)
{
	switch (event->type) {
	case SDL_MOUSEBUTTONDOWN:
		printf("DOWN!!\n");
		break;
	}
	return 0;
}

