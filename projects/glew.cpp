#include <iostream>

#define GLEW_STATIC 1
#include <GL/glew.h>

int main()
{
	GLenum glewError = glewInit();
	if( glewError != GLEW_OK ) {
		std::cerr << "Error initializing GLEW!\n"
			<< glewGetErrorString( glewError ) << std::endl;
	}

	std::cout << GLEW_VERSION_MAJOR << std::endl;
	std::cout << GLEW_VERSION_MINOR << std::endl;
	std::cout << GLEW_VERSION_1_3 << std::endl;
}
