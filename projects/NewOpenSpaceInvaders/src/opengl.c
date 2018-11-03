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


#include "opengl.h"
#include "system.h"
#include "log.h"
#include "settings.h"

void opengl_Init()
{
	Uint16 width  = settings_GetScreenWidth();
	Uint16 height = settings_GetScreenHeight(); 
	/* set the viwer port */
	glViewport(0.0f, 0.0f, width, height);
	
	/*initialize projection matrix */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, height, 0.0f, 1.0f, -1.0f);

	/* initialize model matrix */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* enable blend */
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/* initialize clear color */
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	/* enable texturing */
	glEnable(GL_TEXTURE_2D);

	/* set blending */
	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	/* check for error */
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		log_Error("Error initializing OpenGL! %s\n",
				gluErrorString(error));
		system_Exit();
	}
}

