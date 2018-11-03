#include <iostream>

#define GLEW_STATIC 1
#include <GL/glew.h>

#include <SDL.h>

static  std::string vert =
	"#version 120\n"
	"vec2 position;"
	"void main()"
	"{"
	"	gl_Position = vec4(position, 0.0, 1.0f);"
	"}";

static std::string frag =
	"#version 120"
	"vec4 outColor;"
	"void main()"
	"{"
	"	outColor = vec4(1.0, 1.0, 1.0, 1.0);"
	"}";

static GLfloat vertices[] {
	 0.0f,  0.5f,
	 0.5f, -0.5f,
	-0.5f, -0.5f,
};

static GLuint vbo;

void checkShader(GLuint shader)
{
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		std::cerr << "Unable to compile shader!!"
			<< std::endl;

		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
		std::cerr << buffer << std::endl;

		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv)
{
	SDL_Surface *surface = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Unable to init SDL:"
			<< SDL_GetError() << std::endl;
		exit(EXIT_FAILURE);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	surface = SDL_SetVideoMode(800, 600, 32,
		SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);

	if (surface == NULL) {
		std::cerr << "Unable to set video mode:"
			<< SDL_GetError() << std::endl;

		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Opengl", "Opengl");

	// init glew
	glewExperimental = GL_TRUE;
	glewInit();

	// start Opengl things
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
			vertices, GL_STATIC_DRAW);

	const char *vshadersrc = vert.c_str();

	GLuint vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &vshadersrc, NULL);
	glCompileShader(vshader);
	checkShader(vshader);
	
	const char *fshadersrc = frag.c_str();
	GLuint fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &fshadersrc, NULL);
	glCompileShader(fshader);

	GLuint shaderprogram = glCreateProgram();
	glAttachShader(shaderprogram, vshader);
	glAttachShader(shaderprogram, fshader);

	glLinkProgram(shaderprogram);
	glUseProgram(shaderprogram);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	SDL_Event event;
	bool      quit  = false;
	Uint32    start = 0;


	while (!quit) {

		start = SDL_GetTicks();

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				quit = true;
		}
	
		glDrawArrays(GL_TRIANGLES, 0, 3);

		SDL_GL_SwapBuffers();

		Uint32 current = SDL_GetTicks();
		if ((current - start) < (1000.0 / 60.0)) {
			SDL_Delay((1000.0 / 60.0) - (current - start));
		}
	}
}
