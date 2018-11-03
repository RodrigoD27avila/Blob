#ifndef LTEXTURE_H_INCLUDED
#define LTEXTURE_H_INCLUDED

#include <stdio.h>

#include "lopengl.h"
#include "lfrect.h"

class LTexture {
public:
	LTexture();
	~LTexture();

	bool    loadTextureFromPixel32(GLuint *pixels,
		GLuint imgwidth, GLuint imgheight,
		GLuint texwidth, GLuint texheight);

	bool    loadTextureFromFile(const char *path);

	void    freeTexture();

	void    render(GLfloat x, GLfloat y, LFRect *clip = NULL);

	GLuint  powerOfTwo(GLuint num);

	inline GLuint  getTextureID() {return m_textureid;}
	inline GLuint  textureWidth() {return m_texturewidth;}
	inline GLuint  textureHeight(){return m_textureheight;}
	inline GLuint  imageWidth()   {return m_imagewidth;}
	inline GLuint  imageHeight()  {return m_imageheight;}

private:
	GLuint m_textureid;
	GLuint m_texturewidth;
	GLuint m_textureheight;
	
	GLuint m_imagewidth;
	GLuint m_imageheight;
	
};


#endif // LTEXTURE_H_INCLUDED
