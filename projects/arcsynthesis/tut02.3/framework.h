#pragma once

#include <string>
#include <vector>

#include <GL/glew.h>

namespace Framework {

GLuint       CreateProgram    (const std::vector<GLuint> &shaderList);
GLuint       CreateShader     (GLenum shaderType, const std::string &shaderStr);
std::string  LoadShader       (const char *filename);

} // end namespace Framework
