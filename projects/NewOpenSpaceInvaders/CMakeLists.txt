Project(OpenSpaceInvaders)


cmake_minimum_required(VERSION 2.6)

set(
	SOURCES
	src/main.c
	src/window.c
	src/load.c
	src/log.c
	src/memory.c
	src/script.c
	src/settings.c
	src/system.c
	src/opengl.c
	src/timer.c
	src/event.c
	src/texture.c
)

set (
	CMAKE_C_FLAGS_DEBUG
	"-ggdb -O0"
)

set (
	CMAKE_C_FLAGS_RELEASE
	"-O2"
)

Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(Lua51 REQUIRED)
Find_Package(OpenGL REQUIRED)
Find_Package(DevIL REQUIRED)

if (NOT SDL_FOUND)
	message(FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

link_libraries (
	${SDL_LIBRARY}
	${SDLIMAGE_LIBRARY}
	${LUA_LIBRARY}
	${OPENGL_LIBRARY}
	${GLU_LIBRARY}
	${IL_LIBRARIES}
	${ILU_LIBRARIES}
)

include_directories (
	SYSTEM /usr/include/SDL	
)

add_executable (
	osinvaders ${SOURCES}
)
