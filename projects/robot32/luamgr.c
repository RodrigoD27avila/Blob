#include "luamgr.h"

#include "window.h"

/* window.h */
static int lua_window_GetWidth(Lua *l);
static int lua_window_GetHeight(Lua *l);
static int lua_window_GetMainWindow(Lua *l);
static int lua_window_GetMainRenderer(Lua *l);

static const struct luaL_Reg robot32[] = {
	{"lua_window_GetWidth"       , "GetWidth"       },
	{"lua_window_GetHeight"      , "GetHeight"      },
	{"lua_window_GetMainWindow"  , "GetMainWindow"  },
	{"lua_window_GetMainRenderer", "GetMainRenderer"},
	{NULL, NULL},
};
