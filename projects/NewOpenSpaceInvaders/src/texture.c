#include <stdio.h>
#include <stdlib.h>

#include <IL/il.h>
#include <IL/ilu.h>

#include "texture.h"
#include "opengl.h"


void texture_Init()
{
	// initialize DevIL
	ilInit();
	ilClearColor(255, 255, 255, 000);
	
	ILenum error = ilGetError();
	if (error != IL_NO_ERROR) {
		fprintf(stderr, "Unable to init DevIL.\n");
		exit(EXIT_FAILURE);
	}
}

void texture_Quit()
{
	// quit DevIL
	ilShutDown();
}


void texture_LoadFromPixel32(struct Texture *texture, Uint32 *pixels,
		Uint32 width, Uint32 height)
{
	// free previous texture
	texture_Free(texture);

	texture->w = width;
	texture->h = height;

	// generate id
	glGenTextures(1, &texture->id);
	
	// generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	// set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

	// check for errors
	GLenum error = glGetError();	
	if (error != GL_NO_ERROR) {
		fprintf(stderr, "Unable to load texture: %s\n",
			gluErrorString(error));
		exit(EXIT_FAILURE);
	}

	
}

void texture_Free(struct Texture *texture)
{
	if (texture->id == 0) {
		return;
	}

	glDeleteTextures(1, &texture->id);
	texture->id = 0;
	texture->w  = 0;
	texture->h  = 0;
}

void texture_LoadFromFile(struct Texture *texture, const char *filename)
{
	ILuint id = 0;
	ilGenImages(1, &id);
	ilBindImage(id);

	ILboolean success = IL_FALSE;
	
	success = ilLoadImage(filename);
	if (!success) {
		fprintf(stderr, "Unable to load image: %s\n",
                        filename);
                exit(EXIT_FAILURE);
	}

	success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        if(!success) {
                fprintf(stderr, "Unable to convert texture.\n");
                exit(EXIT_FAILURE);
        }

	// load 
        texture_LoadFromPixel32(texture, (GLuint *)ilGetData(),
                (GLuint)ilGetInteger(IL_IMAGE_WIDTH),
                (GLuint)ilGetInteger(IL_IMAGE_HEIGHT));

        ilDeleteImages(1, &id);
}

