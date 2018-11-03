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

#include "game.h"
#include "memory.h"
#include "invaders.h"
#include "settings.h"
#include "window.h"
#include "graphics.h"
#include "timer.h"
#include "handle.h"

#include "reimu.h"

static struct Timer *game_timer;

void game_InitializeObject(struct GameObject *obj, SDL_Surface **sprites,
	Uint16 spritenum, SDL_bool visible)
{
	/* initialize game object */
	obj->w       = sprites[spritenum]->w; 
	obj->h       = sprites[spritenum]->h;
	obj->sprite  = spritenum;
	obj->visible = visible; 
}

void game_Init()
{
	/* initialize game timer */
	game_timer = memory_Alloc(sizeof(struct Timer));
	timer_Start(game_timer);
	
	/* initialize reimu */
	reimu_Init();
}

void game_Quit()
{
	/* quit  reimu */
	reimu_Quit();

	/* delete timer */
	memory_Free(game_timer);
}

void game_Update()
{
	/* update reimu */
	reimu_Update();
}

void game_Render()
{
	graphics_EraseScreen();
	
	/* render reimu*/
	reimu_Render();
}

void game_Handle()
{
	/* handle reimu */
	reimu_Handle();
}

struct Timer *game_GetTimer()
{
	return game_timer;
}
