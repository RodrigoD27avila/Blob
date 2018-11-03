#include <vector>
#include <algorithm>

#define GLEW_STATIC 1
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

#ifdef COMPILE_WITH_OPENGL_3_3
const char vertexShader[] = {
	"#version 330\n"
	"layout(location = 0) in vec4 position;"
	"void main() {"
	"	gl_Position = position;"
	"}"
};

const char fragmentShader[] = {
	"#version 330\n"
	"out vec4 outputColor;"
	"void main() {"
	"	outputColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);"
	"}"
};

#else
const char vertexShader[] = {
	"#version 120\n"
	"attribute vec4 position;"
	"void main() {"
	"	gl_Position = position;"
	"}"
};

const char fragmentShader[] = {
	"#version 120\n"
	"void main()"
	"{"
	"	float lerpValue = gl_FragCoord.y / 500.0f;"
	"	gl_FragColor = mix(vec4(1.0f, 1.0f, 1.0f, 1.0f),"
	"		vec4(0.2f, 0.2f, 0.2f, 1.0f), lerpValue);"
	"}"
};
#endif

static SDL_Window *window;
static bool       quit_program;

float vertexPositions[] = {
	 0.75f,  0.75f,  0.0f,  1.0f,
	 0.75f, -0.75f,  0.0f,  1.0f,
	-0.75f, -0.75f,  0.0f,  1.0f,
	
};

GLuint positionBufferObject;
GLuint theProgram;

void InitializeVertexBuffer()
{
	glGenBuffers(1, &positionBufferObject);
	
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions),
		vertexPositions, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint CreateProgram(const std::vector<GLuint> &shaderList)
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

GLuint CreateShader(GLenum shaderType, const char *shaderStr)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderStr, NULL);
	
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

void InitializeProgram()
{
	std::vector<GLuint> shaderList;
	shaderList.push_back(CreateShader(GL_VERTEX_SHADER, vertexShader));
	shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, fragmentShader));
	
	theProgram = CreateProgram(shaderList);

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
	glBindBuffer(GL_ARRAY_BUFFER, positionBufferObject);
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
