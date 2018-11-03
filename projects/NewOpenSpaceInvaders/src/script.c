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


#include "script.h"
#include "log.h"
#include "memory.h"
#include "system.h"

static lua_State *L;

void script_Init()
{
	/* create new state */
	L = luaL_newstate();
	
	/* open lua libs */
	luaL_openlibs(L);
}

void script_Quit()
{
	/* close lua state */
	lua_close(L);
}

lua_State *script_GetState()
{
	/* retrun lua state */
	return L;
}

void  script_Load(const char *sname)
{
	if (luaL_loadfile(L, sname) || lua_pcall(L, 0, 0, 0)) {
		log_Error("Unable to load script: %s\n",
			lua_tostring(L, -1));
		system_Exit();
	}
}

int script_GetGlobalInt(const char *name, int *number)
{
	/* push name to top of stack */
	lua_getglobal(L, name);

	/* check if is nil */
	if (lua_isnil(L, -1)) {
		return -1;
	}

	/* check if is a number */
	if (!lua_isnumber(L, -1)) {
		log_Error("\'%s\' should be a number.\n", name);
		system_Exit();
	}

	*number = lua_tointeger(L, -1);
	return 0;
}

int script_GetGlobalBool(const char *name, int *boolean)
{
	/* push name to top of stack */
	lua_getglobal(L, name);

	/* check if is nil */
	if (lua_isnil(L, -1)) {
		return -1;
	}

	/* check if is a number */
	if (!lua_isboolean(L, -1)) {
		log_Error("\'%s\' should be a boolean.\n", name);
		system_Exit();
	}

	*boolean = lua_toboolean(L, -1);
	return 0;
}

int script_GetGlobalString(const char *name, char **string)
{
	int len;
	const char *luastring;
	char       *newstring;

	/* push name to top of stack */
	lua_getglobal(L, name);

	/* check if is nil */
	if (lua_isnil(L, -1)) {
		return -1;
	}

	/* check if is a number */
	if (!lua_isstring(L, -1)) {
		log_Error("\'%s\' should be a string.\n", name);
		system_Exit();
	}

	len = lua_objlen(L, -1);
	newstring = memory_Alloc(len+1);
	luastring = lua_tostring(L, -1);

	/* copy lua string to a new string*/
	memcpy(newstring, luastring, len);
	*string = newstring;

	return 0;
}
