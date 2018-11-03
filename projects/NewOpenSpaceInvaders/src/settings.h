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

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include <SDL.h>

#define DEFAULT_SCREEN_WIDTH  640
#define DEFAULT_SCREEN_HEIGHT 480
#define DEFAULT_SCREEN_FPS     60
#define DEFAULT_IS_FULLSCREEN   0
#define DEFAULT_IS_RESIZABLE    0
#define DEFAULT_SPRITES_PATH  "./data/sprites"
#define DEFAULT_SCRIPTS_PATH  "./data/scripts"
#define DEFAULT_WINDOW_TITLE  "New Open Space Invaders"

void     settings_InitDefault();
void     settings_InitFromScript();

void     settings_Init(Uint16 width, Uint16 height, Uint16 fps,
	 	SDL_bool fullscreen, SDL_bool resizable);

void     settings_FreeStrings();

Uint16   settings_GetScreenWidth();
Uint16   settings_GetScreenHeight();
Uint16   settings_GetScreenFPS();
Uint16   settings_GetScreenBPP();
Uint32   settings_GetScreenFlags();
SDL_bool settings_IsFullscreen();
SDL_bool settings_IsResizable();
char     *settings_GetSpritesPath();
char     *settings_GetScriptsPath();
char     *settings_GetWindowTitle();
char     *settings_GetErrorLogFile();
char     *settings_GetWarningLogFile();
char     *settings_GetInfoLogFile();

#endif /* SETTINGS_H_INCLUDED */


