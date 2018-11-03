#include <fstream>
#include <sstream>
#include <algorithm>

#include "framework.h"

namespace Framework {

GLuint CreateShader(GLenum shaderType, const std::string &shaderStr)
{
	GLuint shader = glCreateShader(shaderType);
	
	const GLchar *str = shaderStr.c_str();
	glShaderSource(shader, 1, &str, NULL);
	
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint infoLen;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
	
		GLchar *infoLog = new GLchar[infoLen + 1];
		glGetShaderInfoLog(shader, infoLen, NULL, infoLog);

		const char *shaderTypeStr = NULL;
		switch (shaderType) {
		case GL_VERTEX_SHADER:   shaderTypeStr = "vertex";   break;
		case GL_GEOMETRY_SHADER: shaderTypeStr = "geometry"; break;
		case GL_FRAGMENT_SHADER: shaderTypeStr = "fragment"; break;
		}

		fprintf(stderr, "Compile failure in %s shader:\n%s\n",
			shaderTypeStr, infoLog);

		delete[] infoLog;
	}

	return shader;
}

std::string LoadShader(const char *filename)
{
	std::stringstream shader;

	std::fstream fs;
	fs.open(filename, std::fstream::in);

	shader << fs.rdbuf();
	fs.close();

	return shader.str();
}

} // end namespace Framework
