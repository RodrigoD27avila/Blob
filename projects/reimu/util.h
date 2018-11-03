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

#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <SDL.h>

struct GameObject;

SDL_Surface *util_CreateEmptySurface(SDL_Surface *base,
	Uint16 width, Uint16 height);

Uint16       util_WindowCenterX();
Uint16       util_WindowCenterY();
Uint16       util_CenterXToWindow(Uint16 w);
Uint16       util_CenterYToWindow(Uint16 h);

void         util_ObjectToRect(const struct GameObject *obj, SDL_Rect *rect);
SDL_bool     util_CollideWith(SDL_Rect *a, SDL_Rect *b);
SDL_bool     util_CollideWithCorners(const struct GameObject *obj, Uint16 step);

#endif /* UTIL_H_INCLUDED */
