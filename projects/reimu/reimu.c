#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "reimu.h"
#include "memory.h"
#include "timer.h"
#include "event.h"
#include "image.h"
#include "graphics.h"
#include "game.h"
#include "handle.h"
#include "invaders.h"

#define MAX_SPRITES 7

static struct Timer       *timer;
static struct Event       *animate;
static struct Handle      *handle;
static struct GameObject  *reimu;
static        SDL_Surface *sprites[MAX_SPRITES];

static void InitializeObjects();
static void DeleteObjects();
static void Animate(void *);

void reimu_Init()
{ InitializeObjects(); }

void reimu_Quit()
{ DeleteObjects(); }

void reimu_Handle()
{
	handle_PollEvent(handle);
}

void reimu_Update()
{
	event_Start(animate);
	event_Callback(animate);
}

void reimu_Render()
{
	graphics_EraseScreen();
	graphics_Blit(reimu, sprites);
}

static void InitializeObjects()
{
	/* get timer */
	timer = game_GetTimer();

	/* initialize animate event*/
	animate = memory_Alloc(sizeof(struct Event));
	event_RegisterCallback(animate, timer, Animate, NULL, 123);

	/* initialize handle */
	handle = memory_Alloc(sizeof(struct Handle));
	handle_EnableEvents(handle, EVENT_SYSTEM);
	handle->system = invaders_DefaultSystemHandle;
	

	/* load sprites */
	image_LoadSprite(sprites, 0,  "hitSpin000.png");
	image_LoadSprite(sprites, 1,  "hitSpin001.png");
	image_LoadSprite(sprites, 2,  "hitSpin002.png");
	image_LoadSprite(sprites, 3,  "hitSpin003.png");
	image_LoadSprite(sprites, 4,  "hitSpin004.png");
	image_LoadSprite(sprites, 5,  "hitSpin005.png");
	image_LoadSprite(sprites, 6,  "hitSpin006.png");

	/* create reimu */
	reimu = memory_Alloc(sizeof(struct GameObject));
	game_InitializeObject(reimu, sprites, 0, SDL_TRUE);
	reimu->x = 100;
	reimu->y = 100;
}

static void DeleteObjects()
{
	memory_Free(reimu);
	memory_Free(animate);
	memory_Free(handle);

	int i;
	for (i=0; i<MAX_SPRITES; i++) {
		SDL_FreeSurface(sprites[i]);
		sprites[i] = NULL;
	}
}

static void Animate(void *data)
{
	(void)data;
	Uint16 sprite = reimu->sprite;
	sprite += 1;
	sprite %= MAX_SPRITES;
	reimu->sprite = sprite;
	printf("sprite -> %u/%u\n", sprite, animate->count_ticks);
}
