#include "mapeworkarea.h"

int MAPE_WorkAreaInit(STK_Widget *widget, SDL_Surface *screen)
{
	if ((STK_WidgetInit(widget, "MAPE_WorkArea", 0, 0,
		screen->w, screen->h, sizeof(MAPE_WorkArea))) < 0) {
		return -1;
	}

	widget->draw    = MAPE_WorkAreaDraw;
	widget->handle  = MAPE_WorkAreaHandle;
	widget->destroy = MAPE_WorkAreaDestroy;

	MAPE_WorkArea *warea = MAPE_WORKAREA(widget);
	warea->workarea      = STK_UtilCreateEmptySurface(screen,
		screen->w, screen->h); 

	return 0;
}

int MAPE_WorkAreaDestroy(void *widget)
{
	MAPE_WorkArea *warea = MAPE_WORKAREA(widget);
	memset(widget, 0, sizeof(STK_Widget));

	SDL_FreeSurface(warea->workarea);
	free(warea);

	return 0;
}

int MAPE_WorkAreaDraw(void *widget, SDL_Surface *surface)
{
	MAPE_WorkArea *workarea = MAPE_WORKAREA(widget);
	SDL_Surface   *area     = workarea->workarea;

	SDL_FillRect(area, &area->clip_rect,
		SDL_MapRGB(area->format, 255, 0, 255));


	SDL_Rect offset;
	STK_WidgetToRect(STK_WIDGET(widget), &offset);
	SDL_BlitSurface(area, NULL, surface, &offset);

	return 0;
}

static void mape_workarea_resize(STK_Widget *widget, SDL_ResizeEvent *event)
{
	MAPE_WorkArea *workarea = MAPE_WORKAREA(widget);
	STK_WidgetSetGeometry(widget, widget->x, widget->y,
		event->w, event->h);

	workarea->workarea = STK_UtilResizeSurface(workarea->workarea,
		event->w, event->h);
	return;
}

int MAPE_WorkAreaHandle(void *widget, SDL_Event *event)
{
	STK_Widget *workarea = STK_WIDGET(widget);

	switch (event->type) {
	case SDL_VIDEORESIZE:
		mape_workarea_resize(workarea, &event->resize);
		break;

	case SDL_MOUSEBUTTONDOWN:
		printf("button down!\n");
		break;
	}

	return 0;
}
