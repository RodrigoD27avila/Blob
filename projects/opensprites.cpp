#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>

int main()
{

	FILE *tibia_spr = nullptr;
	char buff[4096];
	SDL_Surface *screen = nullptr;
	char *pixels = nullptr;

	unsigned int       version = 0;
	unsigned int       num_sprites = 0;
	long int           sprites_offset = 0;


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(32, 32, 24, SDL_SWSURFACE);

	if (screen == nullptr) {
		fprintf(stderr, "Unable to set video mode\n");
		exit(EXIT_FAILURE);
	}


	tibia_spr = fopen("Tibia.spr", "rb");

	if (tibia_spr == nullptr) {
		fprintf(stderr, "Unable fo open Tibia.spr\n");
		exit(EXIT_FAILURE);
	}

	// version
	fread(&version, 1, sizeof(int), tibia_spr);
	printf("Version: %u\n", version);

	// number of sprites
	fread(&num_sprites, 1, sizeof(int), tibia_spr);
	printf("Number of sprites: %i\n", num_sprites);

	sprites_offset = ftell(tibia_spr);

	printf("offset = %li\n", sprites_offset);

	int id = 3457;
	fseek(tibia_spr, ((id-1) * 4) + sprites_offset, SEEK_SET);

	int address = 0;
	fread(&address, 1, sizeof(int), tibia_spr);
	fseek(tibia_spr, address + 3, SEEK_SET);
	printf("address = %i\n", address);

	while (1) {
	unsigned short int data_size = 0;
	fread(&data_size, 1, sizeof(short int), tibia_spr);
	printf("data size = %i\n", data_size);

	unsigned short int transparent = 0;
	unsigned short int colored     = 0;
	fread(&transparent, 1, sizeof(short int), tibia_spr);
	fread(&colored, 1, sizeof(short int), tibia_spr);
	printf("trasparent = %i\n", transparent);
	printf("colored = %i\n", colored);

	fread(buff, 1, 4096, tibia_spr);

	//
	SDL_LockSurface(screen);

	pixels = (char *)screen->pixels;
	int j;
	for (j=0; j<data_size; j+=3) {
		pixels[j + 0] = buff[j + 2];
		pixels[j + 1] = buff[j + 1];
		pixels[j + 2] = buff[j + 0];
	}

	SDL_UnlockSurface(screen);

	SDL_Flip(screen);
	SDL_Delay(1);
	}

	SDL_Quit();
	if (tibia_spr) fclose(tibia_spr);
	return 0;
}
