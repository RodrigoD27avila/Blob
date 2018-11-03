#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <dat.h>

const int WIDTH  = 640;
const int HEIGHT = 480;
const int BPP    = 16;

int main(int argc, char **argv)
{
	int error = 0;

	FILE *file        = fopen("test.dat", "rb");
	DAT_Sint32 size   = 0;
	DAT_Sint64 offset = 0;
	
	SDL_Surface *screen = NULL;
	SDL_Surface *tmp    = NULL;
	SDL_Surface *img    = NULL;
	SDL_RWops   *rw     = NULL;
	char        *buffer = NULL;
	
	SDL_Rect rect = {10, 10, 0, 0};
	SDL_Rect *geo = NULL; 

	error = DAT_GetEntryInfo(0, NULL, &size, &offset, file);
	if (error < 0) {
		goto end_with_error;
	}

	buffer = (char *)malloc(size);
	error = DAT_GetData(buffer, size, offset, file);
	if (error < 0) {
		goto end_with_error;
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		goto end_with_error;
	}

	screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
	if (screen == NULL) {
		goto end_with_error;
	}

	rw = SDL_RWFromMem(buffer, size);
	tmp = SDL_LoadBMP_RW(rw, 1);
	free(buffer);
	fclose(file);

	img = SDL_DisplayFormat(tmp);
	SDL_BlitSurface(img, NULL, screen, &rect);
	SDL_Flip(screen);

	geo = &img->clip_rect;
	printf("GEOMETRY: %i, %i, %i, %i\n",geo->x, geo->y, geo->w, geo->h);
	SDL_Delay(30000);


	return 0;

end_with_error:
	if (error) fprintf(stderr, "%s\n", DAT_GetErrorString(error));
	if (file)  fclose(file);
	free(buffer);
	SDL_Quit();
	exit(EXIT_FAILURE);
}
