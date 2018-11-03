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

#include "image.h"
#include "memory.h"
#include "invaders.h"
#include "settings.h"

static char        *GetSpriteByName(const char *filename);
static SDL_Surface *OptimizeSurface(SDL_Surface *surface);

SDL_Surface *image_LoadFromFile(const char *filename)
{
	SDL_Surface *loaded    = NULL;
	SDL_Surface *optimized = NULL;

	char *path = GetSpriteByName(filename);

	/*load image*/
	loaded = IMG_Load(path);
	if (loaded == NULL) {
		fprintf(stderr, "[image] Unable to load %s: %s\n",
			path, SDL_GetError());

		/*free path */
		memory_Free(path);

		/* exit invaders */
		invaders_Exit();
	}
	
	/*free path */
	memory_Free(path);

	/* optimize surface */
	optimized = OptimizeSurface(loaded);
	SDL_FreeSurface(loaded);

	return optimized;
}

static SDL_Surface *OptimizeSurface(SDL_Surface *surface)
{
	/* optimize surface */
	SDL_Surface *optimized = SDL_DisplayFormat(surface);
	if (optimized == NULL) {
		fprintf(stderr, "[image] Unable to optimize surface: %s\n",
			SDL_GetError());
		invaders_Exit();
	}

	/* set color key*/
//	SDL_SetColorKey(optimized, SDL_SRCCOLORKEY,
//		SDL_MapRGB(optimized->format, 0x2f, 0x5f, 0x73));

	return optimized;
}

static char *GetSpriteByName(const char *filename)
{
	/* get string and sizes */
	const char *data_dir  = settings_GetDataDir();

	size_t     bytes_dir  = strlen(data_dir);
	size_t     bytes_file = strlen(filename);
	
	/* set full path */
	char *path = memory_Alloc(bytes_dir + bytes_file + 1);
	strcat(path, data_dir);
	strcat(path, filename);

	return path;

	
}

void image_LoadSprite(SDL_Surface **array, unsigned int index,
	const char *filename)
{
	array[index] = image_LoadFromFile(filename);
}
