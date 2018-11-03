#ifndef SPRITEBOX_H_INCLUDED
#define SPRITEBOX_H_INCLUDED

#include <SDL.h>
#include <stk.h>

#define MAPE_SPRITEBOX(w) ((MAPE_SpriteBox *)(STK_WIDGET(w))->data);

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	SDL_Surface *workarea;
} MAPE_SpriteBox;

int MAPE_SpriteBoxInit(STK_Widget *widget, Sint16 x, Sint16 y,
	Uint16 w, Uint16 h, SDL_Surface *screen);

int MAPE_SpriteBoxDestroy(void *widget);
int MAPE_SpriteBoxDraw(void *widget, SDL_Surface *surface);
int MAPE_SpriteBoxHandle(void *widget, SDL_Event *event);

#ifdef __cplusplus
}
#endif

#endif /*SPRITEBOX_H_INCLUDED*/
