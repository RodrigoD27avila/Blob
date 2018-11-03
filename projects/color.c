#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#define MAX_COLOR 255

struct Color {
	int r;
	int g;
	int b;
};

struct ColorTable {
	char         *name;
	struct Color color;
};

struct ColorTable colortable[] = { 
	{"WHITE", {MAX_COLOR, MAX_COLOR, MAX_COLOR}},
	{"RED"  , {MAX_COLOR, 0        , 0        }},
	{"GREEN", {0        , MAX_COLOR, 0        }},
	{"BLUE" , {0        , 0        , MAX_COLOR}},
	{ NULL  , {0        , 0        , 0        }},
};

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
	printf("---- Stack dump init --------------\n");
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
	printf("---- Stack dump end  --------------\n");
}

static void load(lua_State *L, const char *fname)
{
	if (luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0)) {
		error(L, "cannot run config. file: %s\n",
			lua_tostring(L, -1));
	}
}

static int getfield(lua_State *L, const char *key)
{
	int result = 0;

//	lua_pushstring(L, key);
//	lua_gettable(L, -2);

	lua_getfield(L, -1, key);
	if (!lua_isnumber(L, -1)) {
		error(L, "invalid component in background color");
	}

	result = (int)(lua_tonumber(L, -1) * MAX_COLOR);
	lua_pop(L, 1);
	return result;
}

static void setfield(lua_State *L, const char *index, int value)
{

//	lua_pushstring(L, index);
//	lua_pushnumber(L, (double)value/MAX_COLOR);
//	lua_settable(L, -3);

	lua_pushnumber(L, (double)value/MAX_COLOR);
	lua_setfield(L, -2, index);
}

static void setcolor(lua_State *L, struct ColorTable *ct)
{
	struct Color *color = &ct->color;

	lua_newtable(L);
	setfield(L, "r", color->r);
	setfield(L, "g", color->g);
	setfield(L, "b", color->b);
	lua_setglobal(L, ct->name);
}

static void register_colors(lua_State *L)
{
	int i;
	for (i=0; colortable[i].name != NULL; i++) {
		setcolor(L, &colortable[i]);
	}
}

static void window_size(lua_State *L, int *w, int *h)
{
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

static void background(lua_State *L, struct Color *background)
{
	lua_getglobal(L, "background");
	if (lua_isstring(L, -1)) {
		const char *name = lua_tostring(L, -1);
		int i;
		for (i=0; colortable[i].name != NULL; i++) {
			if (strcmp(name, colortable[i].name) == 0) {
				break;
			}
		}

		if (colortable[i].name == NULL) {
			error(L, "invalid color name (%s)", name);
		}

		memcpy(background, &colortable[i].color,
			sizeof(struct Color));

	}
	else if (lua_istable(L, -1)) {
		background->r = getfield(L, "r");
		background->g = getfield(L, "g");
		background->b = getfield(L, "b");
	}
	else {
		error(L, "invalid value for \'background\'");
	}
}

int main()
{
	int width, height;
	struct Color bg;

	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	register_colors(L);

	load(L, "config.lua");
	window_size(L, &width, &height);
	background(L, &bg);
	stack_dump(L);
	
	printf("width = %i, height = %i\n", width, height);
	printf("color r=%i, g=%i, b=%i\n", bg.r, bg.g, bg.b);

	lua_close(L);
	return 0;
}
