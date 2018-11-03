Project(OpenSpaceInvaders)


cmake_minimum_required(VERSION 2.6)

set(
	SOURCES
	graphics.c
	handle.c
	invaders.c
	image.c
	main.c
	memory.c
	settings.c
	timer.c
	event.c
	util.c
	window.c
	game.c
	reimu.c
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

if (NOT SDL_FOUND)
	message(FATAL_ERROR "SDL not found!")
endif (NOT SDL_FOUND)

link_libraries (
	${SDL_LIBRARY}
	${SDLIMAGE_LIBRARY}
)

include_directories (
	SYSTEM /usr/include/SDL	
)

add_executable (
	reimu ${SOURCES}
)
