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

#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <SDL.h>

/* allocate memory and exit if unable to allocate */
void *memory_Alloc(size_t bytes);

/* free memory */
void memory_Free(void *obj);

#endif /* MEMORY_H_INCLUDED */
