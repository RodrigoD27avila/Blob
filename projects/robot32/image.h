#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

struct Sprite;

SDL_Surface   *image_Load(const char *filename);
SDL_Texture   *image_CreateTexture(SDL_Surface *image, SDL_Rect *clip_rect);

#endif /* IMAGE_H_INCLUDED */
