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

#include "settings.h"
#include "invaders.h"

#define DEFAULT_SCREEN_WIDTH  640
#define DEFAULT_SCREEN_HEIGHT 480
#define DEFAULT_SCREEN_BPP     32
#define DEFAULT_SCREEN_FPS     95

static Uint16   screen_width;
static Uint16   screen_height;
static Uint16   screen_bpp;
static Uint32   screen_flags;
static Uint16   screen_fps;
static char     *screen_title;
static char     *data_dir;

static void SetBestFlags(SDL_bool fullscreen, SDL_bool resizable);
static void GetAvaliableVideoMode(SDL_Rect *mode);

void settings_InitDefault()
{
	settings_Init(DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT,
		DEFAULT_SCREEN_FPS, SDL_FALSE, SDL_FALSE);
}

void settings_Init(Uint16 width, Uint16 height, Uint16 fps,
	SDL_bool fullscreen, SDL_bool resizable)
{
	/* init default settings */
	screen_bpp = DEFAULT_SCREEN_BPP;

	/* set best SDL flags */
	SetBestFlags(fullscreen, resizable);

	SDL_Rect mode = {0, 0, width, height};
	
	/* get a valid video mode */
	GetAvaliableVideoMode(&mode);

	if (mode.w != width || mode.h != height) {
		printf("Screen mode not avaliable!\n");
		printf("Width  %i -> %i\n", width , mode.w);
		printf("Height %i -> %i\n", height, mode.h);
	}

	/* set screen geometry */
	screen_width  = mode.w;
	screen_height = mode.h;
	screen_fps    = fps;

	/* set default data dir*/
	data_dir = "./data/";

	/* set screen title */
	screen_title  = "::: Reimu :::";
}

Uint16 settings_GetScreenWidth()
{ return screen_width; }

Uint16 settings_GetScreenHeight()
{ return screen_height; }

Uint32 settings_GetScreenFlags()
{ return screen_flags; }

Uint16 settings_GetScreenBPP()
{ return screen_bpp; }

Uint16 settings_GetScreenFPS()
{ return screen_fps; }

const char *settings_GetWindowTitle()
{ return screen_title; }

const char *settings_GetDataDir()
{ return data_dir; }

void settings_SetScreenWidth(Uint16 width)
{ screen_width = width; }

void settings_SetScreenHeight(Uint16 height)
{ screen_height = height; }

void settings_SetScreenBPP(Uint16 bpp)
{ screen_bpp = bpp; }

void settings_SetScreenFPS(Uint16 fps)
{ screen_fps = fps; }

void settings_SetScreenFlags(Uint32 flags)
{ screen_flags = flags; }

void settings_SetDataDir(char *dir)
{ data_dir = dir; }

void settings_SetWindowTitle(char *title)
{ screen_title = title; }

static void SetBestFlags(SDL_bool fullscreen, SDL_bool resizable)
{
        /* get video information */
        const SDL_VideoInfo *info = SDL_GetVideoInfo();
        if (info == NULL) {
                fprintf(stderr, "Video query failed: %s\n", SDL_GetError());
                invaders_Exit();
        }

        /* set default flags */
        screen_flags |= SDL_HWPALETTE;

	/* SDL_DOUBLEBUF only avaliable with SDL_HWSURFACE */
        if (info->hw_available) {
                screen_flags |= SDL_HWSURFACE;
		screen_flags |= SDL_DOUBLEBUF;
	}
        else
                screen_flags |= SDL_SWSURFACE;

        if (info->blit_hw)
                screen_flags |= SDL_HWACCEL;

        if (resizable)
                screen_flags |= SDL_RESIZABLE;

        if (fullscreen)
                screen_flags |= SDL_FULLSCREEN;
}

static void GetAvaliableVideoMode(SDL_Rect *mode)
{
        /* get video modes */
        SDL_Rect **modes = SDL_ListModes(NULL, screen_flags);

        /* no video modes avaliable */
        if (modes == (SDL_Rect **)0) {
                fprintf(stderr, "no modes avaliable!\n");
                invaders_Exit();
        }

        /* all modes avaliable */
        if (modes == (SDL_Rect **)-1) {
                return;
        }

        /* modes[0] is the hight resolution */
        mode->w = modes[0]->w;
        mode->h = modes[0]->h;
}

