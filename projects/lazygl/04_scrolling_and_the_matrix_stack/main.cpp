#include "lutil.h"

void runMainLoop(int val);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	
	// create a opengl 2.1 context
	glutInitContextVersion(2, 1);
	
	// create a double buffered window
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");

	// do post window/context creation initialization
	if (!initGL()) {
		fprintf(stderr, "Unable to initialize graphics library.\n");
		exit(EXIT_FAILURE);
	}

	// set key function
	glutKeyboardFunc(handleKeys);

	// set rendering function
	glutDisplayFunc(render);

	//set main loop
	glutTimerFunc(1000.0 / SCREEN_FPS, runMainLoop, 0 );

	// start glut main loop
	glutMainLoop();

	return 0;
}

void runMainLoop(int val)
{
	// frame logic
	update();
	render();
	
	//set main loop
	glutTimerFunc(1000.0 / SCREEN_FPS, runMainLoop, 0 );
}

