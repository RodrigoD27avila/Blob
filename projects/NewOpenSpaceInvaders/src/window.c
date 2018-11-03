/*
 * NewOpenSpaceInvaders
 * Another space invaders remake in C + SDL + OpenGL + Lua
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

#include "log.h"
#include "window.h"
#include "settings.h"
#include "system.h"

static SDL_Surface *screen;

void window_Init()
{
	/* replace previous screen */
	screen = SDL_SetVideoMode(settings_GetScreenWidth(),
		 settings_GetScreenHeight(), settings_GetScreenBPP(),
		 settings_GetScreenFlags());

	/* check if screen is NULL */
	if (screen == NULL) {
		log_Error("Unable to set video mode: %s\n",
			SDL_GetError());
		system_Exit();
	}

	/* set window title */
	const char *title = settings_GetWindowTitle();
	SDL_WM_SetCaption(title, title);
}

SDL_Surface *window_GetScreen()
{ return screen; }
