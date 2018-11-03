#ifndef LTEXTURE_H_INCLUDED
#define LTEXTURE_H_INCLUDED

#include <stdio.h>

#include "lopengl.h"

class LTexture {
public:
	LTexture();
	~LTexture();

	bool    loadTextureFromPixel32(GLuint *pixels,
		GLuint width, GLuint height);

	bool    loadTextureFromFile(const char *path);

	void    freeTexture();

	void    render(GLfloat x, GLfloat y);

	inline GLuint  getTextureID() {return m_textureid;}
	inline GLuint  textureWidth() {return m_texturewidth;}
	inline GLuint  textureHeight(){return m_textureheight;}

private:
	GLuint m_textureid;
	GLuint m_texturewidth;
	GLuint m_textureheight;
	
};


#endif // LTEXTURE_H_INCLUDED
