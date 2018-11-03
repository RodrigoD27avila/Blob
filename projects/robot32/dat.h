#ifndef DAT_H_INCLUDED
#define DAT_H_INCLUDED

#include <SDL.h>

#include "vector.h"
#include "stream.h"

#define DAT_TYPE_OBJECS    1
#define DAT_TYPE_SPRITES   2
#define DAT_TYPE_MAP       3
#define DAT_TYPE_DIALOGS   4
#define DAT_TYPE_ANIMATION 5

typedef (void *dat_callback_t)(void *);

struct dat_opration {
	dat_callback_t init;
	dat_callback_t destroy;
	dat_callback_t write;
	dat_callback_t read;
};

struct dat_header {
	Uint16 magic;
	Uint16 type;
	Uint32 version;
	Uint32 count;
};

struct dat_file {
	struct   dat_header;
	vector_t entries;
};

struct sprite_entry {
	Uint16   w, h;
	Uint16   pitch;
	stream_t data;
};

void dat_init(dat_file *dat, Uint16 magic, Uint16 type,
		Uint32 version, Uint32 count);

void dat_destroy(dat_file *dat);

FILE *dat_open(const char *name);
void  dat_close(FILE *file);

void dat_push_sprite_entry(dat_file *dat, sprite_entry *entry);

void dat_write_to(dat_file *file, FILE *file);

#endif // DAT_H_INCLUDED
