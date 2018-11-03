/*
 * OpenSpaceInvaders - Another space invaders remake in C + SDL.
 * Copyright (C) 2012  Rodrigo D'avila <r0dra42@gmail.com>
 * Copyright (C) 2013  Rodrigo D'avila <r0dra42@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "invaders.h"
#include "window.h"
#include "game.h"

SDL_Surface *util_CreateEmptySurface(SDL_Surface *base,
	Uint16 width, Uint16 height)
{
	SDL_Surface *newsurface = NULL;

	SDL_PixelFormat *fmt = base->format;
	newsurface = SDL_CreateRGBSurface(base->flags, width, height,
		fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask,
		fmt->Bmask, fmt->Amask);

	if (newsurface == NULL) {
		fprintf(stderr, "Unable to create a empty surface: %s\n",				SDL_GetError());
		invaders_Exit(EXIT_FAILURE);
	}
	return newsurface;
}

Uint16 util_WindowCenterX()
{ return (window_GetWidth() / 2); }

Uint16 util_WindowCenterY()
{ return (window_GetHeight() / 2); }

Uint16 util_CenterXToWindow(Uint16 w)
{ return util_WindowCenterX() - (w / 2) ; }

Uint16 util_CenterYToWindow(Uint16 h)
{ return util_WindowCenterY() - (h / 2); }

void util_ObjectToRect( const struct GameObject *obj, SDL_Rect *rect)
{
	/* set rectangle geometry */
	rect->x = obj->x;
	rect->y = obj->y;
	rect->w = obj->w;
	rect->h = obj->h;
}

SDL_bool util_CollideWith(SDL_Rect *a, SDL_Rect *b)
{
	/* a bounds */
	int la = a->x;
	int ra = a->x + a->w;
	int ta = a->y;
	int ba = a->y + a->h;

	/* b bounds */
	int lb = b->x;
	int rb = b->x + b->w;
	int tb = b->y;
	int bb = b->y + b->h;
	
	return !(la <= lb || ra >= rb || ta <= tb || ba >= bb);
}

SDL_bool util_CollideWithCorners(const struct GameObject *obj, Uint16 step)
{
	/* check if is not visible */
	if (!obj->visible) {
		return SDL_FALSE;
	}

	/* screen width */
	Uint32 w = window_GetWidth();

	/* check collision */
	if (((obj->x + obj->w) + step) >= w || (obj->x - step) <= 0) {
		return SDL_TRUE;
	}

	return SDL_FALSE;
}

