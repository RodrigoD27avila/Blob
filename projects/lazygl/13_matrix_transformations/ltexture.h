#ifndef LTEXTURE_H_INCLUDED
#define LTEXTURE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lopengl.h"
#include "lfrect.h"

class LTexture {
public:
	LTexture();
	~LTexture();

	bool    loadTextureFromPixel32(GLuint *pixels,
		GLuint imgwidth, GLuint imgheight,
		GLuint texwidth, GLuint texheight);
	
	bool    loadTextureFromPixel32();

	bool    loadTextureFromFile(const char *path);

	bool    loadPixelsFromFile(const char *path);

	bool    loadTextureFromFileWithColorKey(const char *path,
		GLubyte r, GLubyte g, GLubyte b, GLubyte a = 000);

	void    freeTexture();

	void    render(GLfloat x, GLfloat y, LFRect *clip = NULL);
	
	bool    lock();
	bool    unlock();

	GLuint  powerOfTwo(GLuint num);

	inline GLuint  getTextureID() {return m_textureid;}
	inline GLuint  textureWidth() {return m_texturewidth;}
	inline GLuint  textureHeight(){return m_textureheight;}
	inline GLuint  imageWidth()   {return m_imagewidth;}
	inline GLuint  imageHeight()  {return m_imageheight;}
	inline GLuint  *getPixelData32()  {return m_pixels;}

	/*
	 *  return pixel at given position
	 */
	inline GLuint  getPixel32(GLuint x, GLuint y)
	{
		return m_pixels[y * m_texturewidth + x];
	}
	
	/*
	 * sets pixel at given position
	 */
	inline void    setPixel32(GLuint x, GLuint y, GLuint pixel)
	{
		m_pixels[y * m_texturewidth + x] = pixel;
	}	

private:
	GLuint m_textureid;
	GLuint m_texturewidth;
	GLuint m_textureheight;
	
	GLuint m_imagewidth;
	GLuint m_imageheight;

	GLuint *m_pixels;
};


#endif // LTEXTURE_H_INCLUDED
