#include <vector>
#include <algorithm>

#define GLEW_STATIC 1
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "framework.h"

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

static SDL_Window *window;
static bool       quit_program;

float vertexPositions[] = {
	 -1.0f,   1.0f,  0.0f,  1.0f,
          1.0f,   1.0f,  0.0f,  1.0f,
         -1.0f,  -1.0f,  0.0f,  1.0f,
          1.0f,  -1.0f,  0.0f,  1.0f,

};

GLuint positionBufferObject;
GLuint theProgram;
static GLfloat thevalue;

void InitializeVertexBuffer()
{
	glGenBuffers(1, &positionBufferObject);
	
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions),
		vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
	std::string vertexShader   =
		Framework::LoadShader("Squircle.vert");

	std::string fragmentShader = 
		Framework::LoadShader("Squircle.frag");

	std::vector<GLuint> shaderList;
	shaderList.push_back(
		Framework::CreateShader(GL_VERTEX_SHADER, vertexShader));

	shaderList.push_back(
		Framework::CreateShader(GL_FRAGMENT_SHADER, fragmentShader));
	
	theProgram = Framework::CreateProgram(shaderList);

	std::for_each(shaderList.begin(), shaderList.end(),
		[] (GLuint s) {
			glDeleteShader(s);	
		});
}

void handle()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
				glViewport(0, 0,
				(GLsizei)event.window.data1,
				(GLsizei)event.window.data2);
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_DOWN) {
				thevalue -= 0.10f;
			} else if (event.key.keysym.sym == SDLK_UP) {
				thevalue += 0.10f;
			}
			break;
		case SDL_QUIT:
			quit_program = true;
			break;
		}
	}
}

void render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(theProgram);
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	GLuint t = glGetUniformLocation(theProgram, "t");
	glUniform1f(t, thevalue);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableVertexAttribArray(0);
	glUseProgram(0);
	
	SDL_GL_SwapWindow(window);
}


void mainloop()
{
	while (!quit_program) {
		handle();
		render();
	}
}

int main(int argc, char **argv)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "Unable to init SDL: %s\n",
			SDL_GetError());
		exit(EXIT_FAILURE);
	}

	window = SDL_CreateWindow(
		"SDL2 - Opengl", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN
	);

	if (window == nullptr) {
		fprintf(stderr, "Unable to create window: %s\n",
			SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	SDL_GLContext glcontext = SDL_GL_CreateContext(window);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,          1);

	
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "Unagle to init glew!!\n");
		exit(EXIT_FAILURE);
	}

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	InitializeVertexBuffer();
	InitializeProgram();

	mainloop();

	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
