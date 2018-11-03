/*
* This file contais private functions 
*/

#ifndef WINDOW_PRIV_H
#define WINDOW_PRIV_H

struct tml_window_priv_t;
typedef struct tml_window_priv_t tml_window_priv_t;

tml_window_priv_t *tml_window_priv_create();
tml_object_priv_t *tml_object_priv_create();

void tml_window_priv_destroy(tml_window_priv_t *w);
void tml_object_priv_destroy(tml_object_priv_t *o);

#endif /*WINDOW_PRIV_H*/
