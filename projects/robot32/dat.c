#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dat.h"
#include "vector.h"
#include "stream.h"

static void init_objects(dat_file *dat);
static void init_sprites(dat_file *dat);
static void init_map(dat_file *dat);
static void init_dialogs(dat_file *dat);
static void init_animations(dat_file *dat);

static void destroy_objects(dat_file *dat);
static void destroy_sprites(dat_file *dat);
static void destroy_map(dat_file *dat);
static void destroy_dialogs(dat_file *dat);
static void destroy_animations(dat_file *dat);

static void write_objects(dat_file *dat, FILE *file);
static void write_sprites(dat_file *dat, FILE *file);
static void write_map(dat_file *dat, FILE *file);
static void write_dialogs(dat_file *dat, FILE *file);
static void write_animations(dat_file *dat, FILE *file);

void dat_init(dat_file *dat, Uint16 magic, Uint16 type,
                Uint32 version, Uint32 count)
{
	dat->dat_header.magit = magic;
	dat->dat_header.type  = type;

	dat->dat_header.version = version;
	dat->dat_header.count   = 0;

	switch (dat->dat_header.type) {
	case DAT_TYPE_OBJECS:
		init_objects(dat);
		break;
	case DAT_TYPE_SPRITES:
		init_sprites(dat);
		break;
	case DAT_TYPE_MAP:
		init_map(dat);
		break;
	case DAT_TYPE_DIALOGS:
		init_dialogs(dat);
		break;
	case DAT_TYPE_ANIMATION:
		init_animations(dat);
		break;
	};
}

void dat_destroy(dat_file *dat)
{
{	int i;
	for (i=0; i<dat->entries.size; i++) {
		switch (dat->dat_header.type) {
		case DAT_TYPE_OBJECS:
			destroy_objects(vector_at(i));
			break;
		case DAT_TYPE_SPRITES:
			destroy_sprites(vector_at(i));
			break;
		case DAT_TYPE_MAP:
			destroy_map(vector_at(i));
			break;
		case DAT_TYPE_DIALOGS:
			destroy_dialogs(vector_at(i));
			break;
		case DAT_TYPE_ANIMATION:
			destroy_animations(vector_at(i));
			break;
		};
	}
}

FILE *dat_open(const char *name)
{
	FILE *file = fopen(name);
	if (file == NULL) {
		perror("dat error");
		exit(EXIT_FAILURE);
	}
}

void  dat_close(FILE *file)
{
	fflush(file);
	fclose(file);
}

void dat_push_entry(dat_file *dat, void *entry)
{
	vector_pushback(&dat->entries, entry);
	dat->dat_header.count = dat->entries.size;
}

void dat_write_to(dat_file *dat, FILE *file)
{
	rewind(file);

	fwrite(&dat->dat_header.magic,    sizeof(Uint16), 1, file);
	fwrite(&dat->dat_header.type,     sizeof(Uint16), 1, file);
	fwrite(&dat->dat_header.version,  sizeof(Uint32), 1, file);
	fwrite(&dat->dat_header.count,    sizeof(Uint32), 1, file);

	int i;
	for (i=0; i<dat_header->entries.size; i++) {
		switch (dat->dat_header.type) {
		case DAT_TYPE_OBJECS:
			write_objects(dat, file);
			break;
		case DAT_TYPE_SPRITES:
			write_sprites(vector_at(i), file);
			break;
		case DAT_TYPE_MAP:
			write_map(dat, file);
			break;
		case DAT_TYPE_DIALOGS:
			write_dialogs(dat, file);
			break;
		case DAT_TYPE_ANIMATION:
			write_animations(dat, file);
			break;
		};
	}
}

static void init_objects(dat_file *dat)
{
	vector_init(&dat->entries,
		sizeof(struct object_entry), 100, 100);
}

static void init_sprites(dat_file *dat)
{
	vector_init(&dat->entries,
		sizeof(struct sprite_entry), 100, 100);
}

static void init_map(dat_file *dat)
{
	vector_init(&dat->entries,
		sizeof(struct map_entry), 100, 100);

}

static void init_dialogs(dat_file *dat)
{
	vector_init(&dat->entries,
		sizeof(struct dialogs_entry), 100, 100);

}
static void init_animations(dat_file *dat)
{
	vector_init(&dat->entries,
		sizeof(struct animations_entry), 100, 100);
}

static void destroy_objects(dat_file *dat)
{
}

static void destroy_sprites(sprite_entry *sprite)
{
	stream_destroy(sprite->data);
	sprite->w = 0;
	sprite->h = 0;
	sprite->pitch = 0;
	sprite->data  = NULL;
}

static void destroy_map(dat_file *dat)
{
}

static void destroy_dialogs(dat_file *dat)
{
}

static void destroy_animations(dat_file *dat)
{
}

static void write_objects(dat_file *dat, FILE *file)
{
}

static void write_sprites(sprite_entry *sprite, FILE *file)
{
	fwrite(&sprite->w,     sizeof(Uint16), 1, file);
	fwrite(&sprite->h,     sizeof(Uint16), 1, file);
	fwrite(&sprite->pitch, sizeof(Uint16), 1, file);
	fwrite(stream_get(&sprite->data), sprite->data.size, 1, file);
}

static void write_map(dat_file *dat, FILE *file)
{
}

static void write_dialogs(dat_file *dat, FILE *file)
{
}

static void write_animations(dat_file *dat, FILE *file)
{
}
