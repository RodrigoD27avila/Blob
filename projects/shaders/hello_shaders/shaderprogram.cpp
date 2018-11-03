#include <stdio.h>
#include <stdlib.h>

#include "shaderprogram.h"

ShaderProgram::ShaderProgram()
	: programid(0)
{
}

ShaderProgram::~ShaderProgram()
{
	free();
}

void ShaderProgram::free()
{
	glDeleteProgram(programid);
}

bool ShaderProgram::load()
{
	glUseProgram(programid);

	// check for errors
	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
		fprintf(stderr, "[Error]: Unable to binding shader: %s\n",
			gluErrorString(error));

		// print log
		print_program_log();

		return false;
	}

	return true;
}

void ShaderProgram::unbind()
{
	// unbind current program
	glUseProgram(0);
}

void ShaderProgram::print_program_log(GLuint program)
{
	if (!glIsProgram(program)) {
		return;
	}

	// shader log length
	size_t infolength = 0;
	size_t maxlength  = 0;

	// get log string length
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxlength);

	char *infolog = new char[maxlength + 1];
	
	
}
