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

#include "graphics.h"
#include "invaders.h"
#include "window.h"
#include "game.h"

void graphics_Blit(struct GameObject *obj, SDL_Surface **sprites)
{
	/* if object is not visible just return */
	if (!obj->visible) {
		return;
	}
	
	/* get surface */
	SDL_Surface *sprite = sprites[obj->sprite];

	/* set offset */
	SDL_Rect    rect    = {obj->x, obj->y, 0, 0};

	/* blit surface on screen */
	if (SDL_BlitSurface(sprite, NULL, window_GetScreen(), &rect) < 0 ) {
		fprintf(stderr, "Unable to blit surface. %s\n",
			SDL_GetError());
		invaders_Exit();
	}
}

void graphics_EraseScreen()
{
	/* erase screen */
	SDL_Surface *screen = window_GetScreen();
	SDL_FillRect(screen, &screen->clip_rect,
                SDL_MapRGB(screen->format, 0, 0, 0));
}

