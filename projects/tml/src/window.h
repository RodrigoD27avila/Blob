#ifndef WINDOW_H
#define WINDOW_H

#include "window_priv.h"

/*
* This struct represents a Window
*/

typedef struct
{
    int x, y;
    unsigned int width, height;
    char *title;

    tml_window_priv_t *priv;

} tml_window_t;

tml_window_t *tml_window_create();
void tml_window_destroy(tml_window_t *w);

void tml_window_move(tml_window_t *w, int x, int y);
void tml_window_resize(tml_window_t *w, unsigned int w,unsigned int h);

#endif /*TML_WINDOW_H*/
