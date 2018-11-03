#include "ltexture.h"

#include <IL/il.h>

LTexture::LTexture() : m_textureid(0), m_texturewidth(0), m_textureheight(0)
{}

LTexture::~LTexture()
{
	freeTexture();
}

bool LTexture::loadTextureFromFile(const char *path)
{
	// Texture loading success
	bool texloaded = false;

	// generate and set the current image id
	ILuint imgid = 0;
	ilGenImages(1, &imgid);
	ilBindImage(imgid);

	// load image
	ILboolean success = ilLoadImage(path);

	// check if image is loaded
	if (!success) {
		fprintf(stderr, "unable to load image!\n");
		return false;
	}

	// convert image to rgba
	success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
	
	// check if image is converted
	if (!success) {
		fprintf(stderr, "unavle to convert image!\n");
		return false;
	}

	// create texture from pixels
	texloaded = loadTextureFromPixel32((GLuint *)ilGetData(),
		(GLuint)ilGetInteger(IL_IMAGE_WIDTH),
		(GLuint)ilGetInteger(IL_IMAGE_HEIGHT));

	// delete files from memory
	ilDeleteImages(1, &imgid);

	if (!texloaded) {
		fprintf(stderr, "unable to load texture!\n");
		return false;
	}

	return true;
}

bool LTexture::loadTextureFromPixel32(GLuint *pixels,
	GLuint width, GLuint height)
{
	// free texture if exist
	freeTexture();

	// get texture dimensions
	m_texturewidth  = width;
	m_textureheight = height;

	// generate texture id
	glGenTextures(1, &m_textureid);

	// bind texture id
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	// set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

	// check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		fprintf(stderr, "Error loading texture from %p pixels! %s\n",
			pixels, gluErrorString(error));
		return false;
	}
	return true;	
}

void LTexture::freeTexture()
{
	// delete texture
	if (m_textureid != 0) {
		glDeleteTextures(1, &m_textureid);
		m_textureid = 0;
	}

	m_texturewidth  = 0;
	m_textureheight = 0;
}

void LTexture::render(GLfloat x, GLfloat y)
{
	// if texture not exists
	if (m_textureid == 0) {
		return;
	}

	// remove any previous transformation
	glLoadIdentity();

	// move to rendering point
	glTranslatef(x, y, 0.0f);

	// set texture id
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// render textured quad
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f          , 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(m_texturewidth, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(m_texturewidth, m_textureheight);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f          , m_textureheight);
	glEnd();
}
