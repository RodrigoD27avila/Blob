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

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>

struct Timer;

enum Direction {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
};

struct GameObject {
	Sint16   x, y;
	Uint16   w, h;
	Uint16   sprite;
	SDL_bool visible;
};

void   game_Init();
void   game_Quit();

void   game_Handle();
void   game_Update();
void   game_Render();

struct Timer *game_GetTimer();

void   game_InitializeObject(struct GameObject *obj,
		SDL_Surface **sprites, Uint16 spritenum, SDL_bool visible);

#endif /* GAME_H_INCLUDED */
