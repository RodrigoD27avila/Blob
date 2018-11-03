#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL.h>


inline void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *b ^ *a;
}

inline void putpixel(SDL_Surface *surface, Uint32 color, Uint32 x, Uint32 y)
{
	if (x > surface->w || y >surface->h) {
		return;
	}

	Uint32 linewidth = surface->pitch / 4;
	Uint32 *pixels   = (Uint32 *)surface->pixels;

	pixels[(y * linewidth) + x] = color;
}

void bresenham2(SDL_Surface *surface, int x1, int y1, int x2, int y2)
{
	Uint32 steep = abs(y2 - y1) > abs(x2 - x1);
	if (steep) {
		swap(&x1, &y1);
		swap(&x2, &y2);
	}

	if ( x1 > x2) {
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	int deltax = x2 - x1;
	int deltay = abs(y2 - y1);
	int error  = deltax / 2;
	int ystep  = (y1 < y2) ? 1 : -1;
	int y      = y1;

	int x;
	for (x = x1; x <= x2; x++) {
		if (steep) {
			putpixel(surface, 0xffffffff, y, x);
		}
		else {
			putpixel(surface, 0xffffffff, x, y);
		}

		error = error - deltay;
		if (error < 0) {
			y     = y + ystep;
			error = error + deltax;
		}
	}
}


void bresenham(SDL_Surface *surface, int x1, int y1, int x2, int y2)
{
	int slope = 1;
	int dx, dy, INCE, INCNE, d, x ,y;

	// inverte se x1 > x2
	if (x1 > x2) {
		bresenham(surface, x2, y2, x1, y1);
		return;
	}

	dx = x2 - x1;
	dy = y2 - y1;

	if (dy < 0) {
		slope = -1;
		dy    = -dy; 
	}

	// constante de bresenham
	INCE  = (2 * dy);
	INCNE = (2 * dy) - (2 * dx);
	d     = (2 * dy) - dx;
	y     = y1;

	for (x = x1; x <= x2; x++) {
		putpixel(surface, 0xffffffff, x, y);
		
		if (d <= 0) {
			d += INCE;
		}
		else {
			d += INCNE;
			y += slope;
		}
	} 
}

void fill(SDL_Surface *surface, Uint32 color, Uint32 y, Uint32 sx, Uint32 ex)
{
	Uint32 *pixels = (Uint32 *)surface->pixels;
	Uint32 start   = (y * surface->w) + sx;
	Uint32 end     = (y * surface->w) + ex;

	Uint32 i;
	for (i=start; i<end; i++) {
		pixels[i] = color;
	}
}

Uint32 findnext(SDL_Surface *surface, Uint32 y)
{
	Uint32 *pixels = (Uint32 *)surface->pixels;
	int i;
	for (i=0; i < surface->w; i++) {
		if (pixels[(y * surface->w) + i] == 0xffffffff) {
			return i;
		}
	}

	return 0;
}

Uint32 findlast(SDL_Surface *surface, Uint32 y)
{
	Uint32 *pixels = (Uint32 *)surface->pixels;
	int i;
	for (i=surface->w - 1; i >= 0; i--) {
		if (pixels[(y * surface->w) + i] == 0xffffffff) {
			return i;
		}
	}

	return 0;
}

void fillsurface(SDL_Surface *surface)
{
	Uint32 y;
	Uint32 sx = 0, ex  = 0;
	for (y = 0; y < surface->h; y++) {
	
		sx = findnext(surface, y);
		ex = findlast(surface, y);

		if (ex == sx) {
			continue;
		}

		fill(surface, 0xffffffff, y, sx, ex);
	}
}

int main()
{
	SDL_Surface *screen = NULL;
	SDL_Surface *mysurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Unable to initialize SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_PixelFormat *fmt = screen->format;
	mysurface = SDL_CreateRGBSurface(screen->flags, screen->w, screen->h,
		fmt->BitsPerPixel, fmt->Rmask, fmt->Gmask,
		fmt->Bmask, fmt->Amask);

	if (mysurface == NULL) {
		fprintf(stderr, "Unable to create RGB surface: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// draw line
 	bresenham2(mysurface, 10, 10, 10, 30);
 	bresenham2(mysurface, 50, 50, 50, 70);
 	bresenham2(mysurface, 10, 10, 50, 50);
 	bresenham2(mysurface, 10, 30, 50, 70);

	// draw circle
	const float pi     = 3.141592f;
	const float radius = 1.0f;
	
	float angle;
	float x = 200.0f, y = 200.0f;
	float oldx = x, oldy = y;

	for (angle = 0.0f; angle <= pi * 2; angle += 0.01f) {
		x = (x + sin(angle) * radius);
		y = (y + cos(angle) * radius);
		bresenham(mysurface, (int)oldx, (int)oldy, (int)x, (int)y);
		oldx = x; oldy = y;
	}

	// fill surface
	fillsurface(mysurface);
	
	SDL_Rect offset = {0, 0, 0, 0};
	if (SDL_BlitSurface(mysurface, NULL, screen, &offset) < 0) {
		fprintf(stderr, "Unable to blit surface: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (SDL_Flip(screen) < 0) {
		fprintf(stderr, "Unable to flip screen: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}


	SDL_Event event;
	SDL_bool  quit = SDL_FALSE;

	while (!quit) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = SDL_TRUE;
				break;
			}
		}

		SDL_Delay(16);
	}

	SDL_FreeSurface(mysurface);
	SDL_FreeSurface(screen);
	SDL_Quit();

	return 0;
}
