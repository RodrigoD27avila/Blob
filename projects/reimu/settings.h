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

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <SDL.h>

void settings_InitScale4();
void settings_InitScale2();
void settings_InitScale1();

void settings_Init(Uint16 width, Uint16 height, Uint16 fps,
	SDL_bool fullscreen, SDL_bool resizable);

void settings_InitDefault();

Uint16   settings_GetScreenWidth();
Uint16   settings_GetScreenHeight();
Uint16   settings_GetScreenBPP();
Uint16   settings_GetScreenFPS();
Uint32   settings_GetScreenFlags();
Uint16   settings_GetSpriteScale();


void     settings_SetScreenWidth(Uint16 width);
void     settings_SetScreenHeight(Uint16 height);
void     settings_SetScreenBPP(Uint16 bpp);
void     settings_SetScreenFPS(Uint16 fps);
void     settings_SetScreenFlags(Uint32 flags);
void     settings_SetSpriteScale(Uint16 scale);
void     settings_SetDataDir(char *dir);
void     settings_SetWindowTitle(char *title);

const char *settings_GetWindowTitle();
const char *settings_GetDataDir();

#endif /* SETTINGS_H_INCLUDED */
