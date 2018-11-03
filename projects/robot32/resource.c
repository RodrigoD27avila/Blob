#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resource.h"
#include "memory.h"
#include "graphics.h"
#include "image.h"
#include "vector.h"
#include "pstring.h"

#define FILE_TYPE_OBJECS    1
#define FILE_TYPE_SPRITES   2
#define FILE_TYPE_MAP       3
#define FILE_TYPE_DIALOGS   4
#define FILE_TYPE_ANIMATION 5

struct File {
	FILE  *file;
	Uint16 type;
};

static SpriteVector game_sprites;

static struct File    *OpenFile(const char *name, Uint16 type);
static void            CloseFile(struct File *file);

static void LoadSprites(struct File *file);
static void FreeSprites();

void resource_Init()
{
	vector_init(&game_sprites, sizeof(struct Sprite), 10, 10);

	// load sprites
	struct File *spritefile = OpenFile("./data/sprites.txt",
		FILE_TYPE_SPRITES);

	LoadSprites(spritefile);
	CloseFile(spritefile);
}

void resource_Quit()
{
	FreeSprites();
}

static struct File *OpenFile(const char *name, Uint16 type)
{
	struct File *file = memory_Alloc(sizeof(struct File));

	file->file = fopen(name, "rb");
	if (file->file == NULL) {
		memory_Free(file);
		fprintf(stderr, "Unable to open file %s.\n", name);
		exit(EXIT_FAILURE);
	}

	file->type = type;

	return file;
}

static void CloseFile(struct File *file)
{
	fclose(file->file);
	file->file = NULL;

	memory_Free(file);
}

static void LoadSprites(struct File *file)
{
	if (file->type != FILE_TYPE_SPRITES) {
		return;
	}

	string_t filename;
	string_init(&filename);
	vector_realloc(&filename, 256);

	Uint32   count;
	Uint32   id;
	SDL_Rect clip_rect;

	while (fscanf(file->file, "%s", string_get(&filename))
		&& (strncmp(string_get(&filename), "eof", 3) != 0)) {

		// get sprite count
		fscanf(file->file, "%d", &count);

		SDL_Surface   *image  = image_Load(string_get(&filename));

		// load sprites
		Uint32 i;
		for (i=0; i<count; i++) {
			fscanf(file->file, "%d %d %d %d %d", &id,
				&clip_rect.x, &clip_rect.y,
				&clip_rect.w, &clip_rect.h);

			struct Sprite sprite;
			sprite.id = id;
			sprite.w = clip_rect.w;
			sprite.h = clip_rect.h;
			sprite.texture = image_CreateTexture(image, &clip_rect);

			vector_pushback(&game_sprites, &sprite);
		}

		SDL_FreeSurface(image);
		string_zero(&filename);
	}

	string_destroy(&filename);
}

static void FreeSprites()
{
	int i;
	for (i=0; i < game_sprites.size; i++) {
		struct Sprite *sprite = vector_at(&game_sprites, i);

		SDL_DestroyTexture(sprite->texture);
		sprite->texture = NULL;
	}

	vector_destroy(&game_sprites);
}

SpriteVector *resource_GetSprites()
{ return &game_sprites; }
