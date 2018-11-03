#include "ltexture.h"

#include <IL/il.h>
#include <IL/ilu.h>

LTexture::LTexture() : m_textureid(0), m_texturewidth(0), m_textureheight(0),
	m_imagewidth(0), m_imageheight(0), m_pixels(NULL)
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

	// initialize dimensions
	GLuint imgwidth  = (GLuint)ilGetInteger(IL_IMAGE_WIDTH);
	GLuint imgheight = (GLuint)ilGetInteger(IL_IMAGE_HEIGHT);

	// calculate required texture dimensions
	GLuint texwidth  = powerOfTwo(imgwidth);
	GLuint texheight = powerOfTwo(imgheight);

	// texture is the wrong size	
	if (imgwidth != texwidth || imgheight != texheight) {
		// place image at upper left
		iluImageParameter(ILU_PLACEMENT, ILU_UPPER_LEFT);
		
		//resize image
		iluEnlargeCanvas((int)texwidth, (int) texheight, 1);
	}

	// create texture from pixels
	texloaded = loadTextureFromPixel32((GLuint *)ilGetData(),
		imgwidth, imgheight, texwidth, texheight);

	// delete files from memory
	ilDeleteImages(1, &imgid);

	if (!texloaded) {
		fprintf(stderr, "unable to load texture!\n");
		return false;
	}

	return true;
}

bool LTexture::loadTextureFromPixel32(GLuint *pixels,
		GLuint imgwidth, GLuint imgheight,
		GLuint texwidth, GLuint texheight)
{
	// free texture if exist
	freeTexture();

	// get texture dimensions
	m_texturewidth  = texwidth;
	m_textureheight = texheight;
	m_imagewidth    = imgwidth;
	m_imageheight   = imgheight;

	// generate texture id
	glGenTextures(1, &m_textureid);

	// bind texture id
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texwidth, texheight,
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
	if (m_textureid) {
		glDeleteTextures(1, &m_textureid);
		m_textureid = 0;
	}

	// delete pixels
	if (m_pixels) {
		delete[] m_pixels;
		m_pixels = NULL;
	}

	m_texturewidth  = 0;
	m_textureheight = 0;
	m_imagewidth    = 0;
	m_imageheight   = 0;
	
}

void LTexture::render(GLfloat x, GLfloat y, LFRect *clip)
{
	// if texture not exists
	if (m_textureid == 0) {
		return;
	}

	// remove any previous transformation
	glLoadIdentity();

	// texture coordinades
	GLfloat textop    = 0.0f;
	GLfloat texbottom = (GLfloat)m_imageheight / (GLfloat)m_textureheight;
	GLfloat texleft   = 0.0f;
	GLfloat texright  = (GLfloat)m_imagewidth / (GLfloat)m_texturewidth;

	// vertex coordinades
	GLfloat quadwidth  = m_imagewidth;
	GLfloat quadheight = m_imageheight;

	if (clip) {
		// texture coordinades
		texleft   = clip->x / m_texturewidth; 
		texright  = (clip->x + clip->w) / m_texturewidth;
		textop    = clip->y / m_textureheight;
		texbottom = (clip->y + clip->h) / m_textureheight;

		//vertex coodinades
		quadwidth  = clip->w;
		quadheight = clip->h; 
	}

	// move to rendering point
	glTranslatef(x, y, 0.0f);

	// set texture id
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// render textured quad
	glBegin(GL_QUADS);
		glTexCoord2f(texleft, textop);
		glVertex2f(0.0f, 0.0f);

		glTexCoord2f(texright, textop);
		glVertex2f(quadwidth, 0.0f);

		glTexCoord2f(texright, texbottom);
		glVertex2f(quadwidth, quadheight);

		glTexCoord2f(texleft, texbottom);
		glVertex2f(0.0f, quadheight);
	glEnd();
}

GLuint LTexture::powerOfTwo(GLuint num)
{
	if (num != 0) {
		num--;
		num |= (num >> 1);  // or first 2 bits
		num |= (num >> 2);  // or next  2 bits
		num |= (num >> 4);  // or next  4 bits
		num |= (num >> 8);  // or next  8 bits
		num |= (num >> 16); // or next 16 bits
		num++;
	}

	return num;
}

bool LTexture::lock()
{
	// if the texture is locked and texture not exists
	if (m_pixels != NULL && m_textureid == 0) {
		return false;
	}

	// allocate memory for texture data
	GLuint size = m_texturewidth * m_textureheight;
	m_pixels    = new GLuint[size];

	// set current texture
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// get the pixels
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pixels);

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}

bool LTexture::unlock()
{
	// if texture is unlocked aln texture not exists
	if (m_pixels == NULL && m_textureid == 0) {
		return false;
	}

	// set current texture
	glBindTexture(GL_TEXTURE_2D, m_textureid);

	// update texture
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_texturewidth, m_textureheight,
		GL_RGBA, GL_UNSIGNED_BYTE, m_pixels);

	// delete pixels
	delete[] m_pixels;
	m_pixels = NULL;

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

	return true;
}
