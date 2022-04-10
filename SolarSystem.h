#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "Planet.h"

#pragma once
class SolarSystem
{
	private:
		GLubyte colors[9][3] = {
			{255, 163, 43},
			{214, 214, 214},
			{166, 173, 21},
			{21, 173, 135},
			{242, 94, 94},
			{247, 247, 247},
			{255, 233, 64},
			{181, 246, 255},
			{0, 105, 153},
		};
		Planet sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune;

	public:
		SolarSystem();
		void rotate();
		void draw();
};

