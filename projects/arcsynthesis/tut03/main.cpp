#include <array>
#include <vector>
#include <algorithm>

#define GLEW_STATIC 1
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "framework.h"

#define ARRAY_COUNT(a) (static_cast<int>(sizeof(a)))

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

static SDL_Window *window;
static bool       quit_program;

const float vertexData[] = {
	 0.0f,     0.5f, 0.0f, 1.0f,
	 0.5f,  -0.366f, 0.0f, 1.0f,
	-0.5f,  -0.366f, 0.0f, 1.0f,
};

GLuint vertexBufferObject;
GLuint theProgram;

void ComputePositionOffset(float &fXOffset, float &fYOffset)
{
	const float fLoopDuration = 0.5f;
	const float fScale        = 3.14159 * 2.0f / fLoopDuration;

	float fElapsedTime = SDL_GetTicks() / 1000.0f;

	float fCurrTimeThroughLoop = fmodf(fElapsedTime, fLoopDuration);

	fXOffset  = cosf(fCurrTimeThroughLoop * fScale) * 0.5f;
	fYOffset  = sinf(fCurrTimeThroughLoop * fScale) * 0.5f;

}

void AdjustVertexData(float fXOffset, float fYOffset)
{
	std::array<float, ARRAY_COUNT(vertexData)> fNewData;
	memcpy(fNewData.data(), vertexData, sizeof(vertexData));

	for (int i=0; i< ARRAY_COUNT(vertexData); i+=4) {
		fNewData[i]   += fXOffset;
		fNewData[i+1] += fYOffset;
	}

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferSubData(GL_ARRAY_BUFFER, 0,
		sizeof(vertexData), &fNewData[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeVertexBuffer()
{
	glGenBuffers(1, &vertexBufferObject);
	
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData),
		vertexData, GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void InitializeProgram()
{
	std::string vertexShader   =
		Framework::LoadShader("FragPosition.vert");

	std::string fragmentShader = 
		Framework::LoadShader("FragPosition.frag");

	std::array<GLuint, 2> shaderList;
	shaderList[0] = 
		Framework::CreateShader(GL_VERTEX_SHADER, vertexShader);

	shaderList[1] = 
		Framework::CreateShader(GL_FRAGMENT_SHADER, fragmentShader);
	
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
	float fXOffset = 0.0f, fYOffset = 0.0f;
	ComputePositionOffset(fXOffset, fYOffset);
	AdjustVertexData(fXOffset, fYOffset);
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(theProgram);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

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

#if defined (ENABLE_SWAP_INTERVAL)
	int swapInterval = SDL_GL_GetSwapInterval();
	if (swapInterval < 0) {
		fprintf(stderr, "Unable to get swap interval: %s\n",
				SDL_GetError());
	} else {
		printf("The swap interval is %i.\n", swapInterval);
		if (SDL_GL_SetSwapInterval(swapInterval) < 0) {
			fprintf(stderr, "Unable to set swap interval: %s\n",
					SDL_GetError());
		}
	}
#endif

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
