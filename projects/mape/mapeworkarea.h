#ifndef MAPEWORKAREA_H_INCLUDED
#define MAPEWORKAREA_H_INCLUDED

#include <SDL.h>
#include <stk.h>

#define MAPE_WORKAREA(w) ((MAPE_WorkArea *)(STK_WIDGET(w))->data);

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	SDL_Surface *workarea;
} MAPE_WorkArea;

int MAPE_WorkAreaInit(STK_Widget *widget, SDL_Surface *screen);
int MAPE_WorkAreaDestroy(void *widget);
int MAPE_WorkAreaDraw(void *widget, SDL_Surface *surface);
int MAPE_WorkAreaHandle(void *widget, SDL_Event *event);

#ifdef __cplusplus
}
#endif

#endif /*MAPEWORKAREA_H_INCLUDED*/
