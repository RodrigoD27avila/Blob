#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static void error(lua_State *L, const char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	lua_close(L);
	exit(EXIT_FAILURE);
}

static void stack_dump(lua_State *L)
{
	int i;
	int top = lua_gettop(L);
	printf("top stack index is %i\n", top);
	for (i=1; i<= top; i++) {
		int t = lua_type(L, i);
		switch (t) {
		case LUA_TSTRING:
			printf("\'%s\'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			printf("%g", lua_tonumber(L, i));
			break;
		default:
			printf("%s", lua_typename(L, t));
			break;
		}
		printf("\n");
	}
}

static void load(lua_State *L, const char *fname, int *w, int *h)
{
	if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0)) {
		error(L, "cannot run config. file: %s\n",
			lua_tostring(L, -1));
	}

	lua_getglobal(L, "width");
	lua_getglobal(L, "height");

	if (!lua_isnumber(L, -2)) {
		error(L, "\'width should be a number\n\'");
	}
	
	if (!lua_isnumber(L, -1)) {
		error(L, "\'height should be a number\n\'");
	}

	*w = lua_tointeger(L, -2);
	*h = lua_tointeger(L, -1);
}

int main()
{
	int width, height;

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	load(L, "config.lua", &width, &height);
	stack_dump(L);
	printf("width = %i, height = %i\n", width, height);

	lua_close(L);
	return 0;
}
