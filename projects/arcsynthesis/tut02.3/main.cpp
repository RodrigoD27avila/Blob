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

const float vertexData[] = {
	 0.0f,     0.5f, 0.0f, 1.0f,
	 0.5f,  -0.366f, 0.0f, 1.0f,
	-0.5f,  -0.366f, 0.0f, 1.0f,
	 1.0f,     0.0f, 0.0f, 1.0f,
	 0.0f,     1.0f, 0.0f, 1.0f,
	 0.0f,     0.0f, 1.0f, 1.0f,
};

GLuint vertexBufferObject;
GLuint theProgram;

void InitializeVertexBuffer()
{
	glGenBuffers(1, &vertexBufferObject);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData),
		vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
	std::string vertexShader   =
		Framework::LoadShader("FragPosition.vert");

	std::string fragmentShader = 
		Framework::LoadShader("FragPosition.frag");

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
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void *)48);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
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

	InitializeVertexBuffer();
	InitializeProgram();

	mainloop();

	SDL_GL_DeleteContext(glcontext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
