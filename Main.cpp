#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "SolarSystem.h"

using namespace std;

const char TITLE[] = "Solar Sytem";
const GLdouble DEFAULT_ZOOM = 1000;
GLdouble zoom = 0;

SolarSystem solar_system;

void mouseControl(int button, int state, int x, int y) {
	// printf("%d %d\n", button, state);
	if (state > 0) {
		if (button == 0) {
			zoom += 100;
		}
		else if (button == 2) {
			zoom -= 100;
		}
	}

	glutPostRedisplay();
}

void idle()
{	
	solar_system.rotate();

	glutPostRedisplay();
}

void draw() {
	solar_system.draw();
}

void renderScene() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	GLdouble ortho = DEFAULT_ZOOM + zoom;
	glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
	gluLookAt(50, 50, 10, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void display()
{
	renderScene();
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	draw();

	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-DEFAULT_ZOOM, DEFAULT_ZOOM, -DEFAULT_ZOOM, DEFAULT_ZOOM, -DEFAULT_ZOOM, DEFAULT_ZOOM);

	gluLookAt(50, 50, 10, 0, 0, 0, 0, 1, 0);
}

int main()
{
	glutInitWindowSize(800, 500);
	glutCreateWindow(TITLE);
	glutIdleFunc(idle);
	glutMouseFunc(mouseControl);
	glutDisplayFunc(display);

	init();

	glutMainLoop();

	return 0;
}