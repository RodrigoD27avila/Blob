#pragma once

#include <string>
#include <GL/glew.h>

namespace Framework {

template<class List>
GLuint       CreateProgram    (const List &shaderList)
{
	GLuint program = glCreateProgram();
	std::for_each(shaderList.begin(), shaderList.end(),
		[&] (GLuint s) {
			glAttachShader(program, s);
		});
	
	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);

	if (status == GL_FALSE) {
		GLint infoLen;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLen);
	
		GLchar *infoLog = new GLchar[infoLen + 1];
		glGetProgramInfoLog(program, infoLen, NULL, infoLog);

		fprintf(stderr, "Linker failure: %s\n", infoLog);
		delete[] infoLog;
	}

	std::for_each(shaderList.begin(), shaderList.end(),
		[&] (GLuint s) {
			glDetachShader(program, s);
		
		});
	return program;	
}

GLuint       CreateShader     (GLenum shaderType, const std::string &shaderStr);
std::string  LoadShader       (const char *filename);

} // end namespace Framework
