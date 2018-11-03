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


#include "settings.h"
#include "memory.h"
#include "script.h"

static Uint16   screen_width;
static Uint16   screen_height;
static Uint16   screen_fps;
static SDL_bool is_fullscreen;
static SDL_bool is_resizable;
static char     *sprites_path;
static char     *scripts_path;
static char     *window_title;

static char     *error_log_file;
static char     *warning_log_file;
static char     *info_log_file;

static Uint32   screen_flags;
static Uint16   screen_bpp;

static void SetBestFlags(SDL_bool fullscreen, SDL_bool resizable);
static void GetAvaliableVideoMode(SDL_Rect *mode);

void settings_InitDefault()
{
	/* initialize with default values */
	settings_Init(
		DEFAULT_SCREEN_WIDTH ,
		DEFAULT_SCREEN_HEIGHT,
		DEFAULT_SCREEN_FPS   ,
		DEFAULT_IS_FULLSCREEN,
		DEFAULT_IS_RESIZABLE 
	);
	
	/* initialize with default title and paths */
	window_title  = DEFAULT_WINDOW_TITLE;
	scripts_path  = DEFAULT_SCRIPTS_PATH;
	sprites_path  = DEFAULT_SPRITES_PATH; 
}

void settings_InitFromScript() 
{
	/* get width */
	if (script_GetGlobalInt("screen_width",
			 (int *)&screen_width) < 0 ) {
		screen_width = DEFAULT_SCREEN_WIDTH;
	}

	/* get height */
	if (script_GetGlobalInt("screen_height",
			 (int *)&screen_height) < 0 ) {
		screen_height = DEFAULT_SCREEN_HEIGHT;
	}
	
	/* get fps */
	if (script_GetGlobalInt("screen_fps",
			 (int *)&screen_fps) < 0 ) {
		screen_fps = DEFAULT_SCREEN_FPS;
	}
	
	/* get fullscreen */
	if (script_GetGlobalBool("fullscreen",
			 (int *)&is_fullscreen) < 0 ) {
		is_fullscreen = DEFAULT_IS_FULLSCREEN;
	}
	
	/* get resizable */
	if (script_GetGlobalBool("resizable",
			 (int *)&is_resizable) < 0 ) {
		is_resizable = DEFAULT_IS_RESIZABLE;
	}
	
	/* get sprites path */
	if (script_GetGlobalString("sprites_path",
			 &sprites_path) < 0 ) {
		sprites_path = DEFAULT_SPRITES_PATH;
	}
	
	/* get scripts_path path */
	if (script_GetGlobalString("scripts_path",
			 &scripts_path) < 0 ) {
		scripts_path = DEFAULT_SCRIPTS_PATH;
	}
	
	/* get scripts_path path */
	if (script_GetGlobalString("window_title",
			 &window_title) < 0 ) {
		window_title = DEFAULT_WINDOW_TITLE;
	}
	
	/* get error_log_file path */
	if (script_GetGlobalString("error_log_file",
			 &error_log_file) < 0 ) {
		error_log_file = NULL;
	}
	
	/* get warning_log_file path */
	if (script_GetGlobalString("warning_log_file",
			 &warning_log_file) < 0 ) {
		warning_log_file = NULL;
	}
	
	/* get warning_log_file path */
	if (script_GetGlobalString("info_log_file",
			 &info_log_file) < 0 ) {
		info_log_file = NULL;
	}
}

void settings_Init(Uint16 width, Uint16 height, Uint16 fps,
	 SDL_bool fullscreen, SDL_bool resizable)
{
	/* set screen flags */
	SetBestFlags(fullscreen, resizable);

	/* set video mode */
	SDL_Rect mode = {0, 0, width, height};
	GetAvaliableVideoMode(&mode);

	if (mode.w != width || mode.h != height) {
                printf("Video mode not avaliable!\n");
                printf("Width  %i -> %i\n", width , mode.w);
                printf("Height %i -> %i\n", height, mode.h);
        }
	
	screen_width  = mode.w;	
	screen_height = mode.h;

	/* set other properties */
	screen_fps    = fps;
	is_fullscreen = fullscreen;
	is_resizable  = resizable;
}

void settings_FreeStrings()
{
	if (scripts_path != DEFAULT_SCRIPTS_PATH) {
		memory_Free(scripts_path);
	}

	if (sprites_path != DEFAULT_SPRITES_PATH) {
		memory_Free(sprites_path);
	}
	
	if (window_title != DEFAULT_WINDOW_TITLE) {
		memory_Free(window_title);
	}

	/* free log file names */
	memory_Free(error_log_file);
	memory_Free(warning_log_file);
	memory_Free(info_log_file);
}
static void SetBestFlags(SDL_bool fullscreen, SDL_bool resizable)
{
        /* get video information */
        const SDL_VideoInfo *info = SDL_GetVideoInfo();
        if (info == NULL) {
                fprintf(stderr, "Video query failed: %s\n", SDL_GetError());
		system_Exit();
        }

	/* set video bpp */
	screen_bpp = info->vfmt->BitsPerPixel;

	/* set opengl attributes */
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

        /* set default flags */
        screen_flags |= SDL_OPENGL;

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
		system_Exit();
        }

        /* all modes avaliable */
        if (modes == (SDL_Rect **)-1) {
                return;
        }

        /* modes[0] is the best resolution */
        mode->w = modes[0]->w;
        mode->h = modes[0]->h;
}

Uint16   settings_GetScreenWidth()
{ return screen_width; }

Uint16   settings_GetScreenHeight()
{ return screen_height; }

Uint16   settings_GetScreenFPS()
{ return screen_fps; }

Uint16   settings_GetScreenBPP()
{ return screen_bpp; }

Uint32   settings_GetScreenFlags()
{ return screen_flags; }

SDL_bool settings_IsFullscreen()
{ return is_fullscreen; }

SDL_bool settings_IsResizable()
{ return is_resizable; }

char     *settings_GetSpritesPath()
{ return sprites_path; }

char     *settings_GetScriptsPath()
{ return scripts_path; }

char     *settings_GetWindowTitle()
{ return window_title;	}

char     *settings_GetErrorLogFile()
{ return error_log_file; }

char     *settings_GetWarningLogFile()
{ return warning_log_file; }

char     *settings_GetInfoLogFile()
{ return info_log_file; }
