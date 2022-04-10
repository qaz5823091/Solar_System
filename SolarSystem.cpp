#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	sun.setAttribute(0, 0, 0, 69.6f, 58, 88, colors[0]);
	mercury.setAttribute(130, 0, 130, 2.4f, 243, 224, colors[1]);
	venus.setAttribute(150, 0, 150, 6.0f, 243, 224, colors[2]);
	earth.setAttribute(170, 0, 170, 6.0f, 1, 365.24, colors[3]);
	mars.setAttribute(200, 0, 200, 6.0f, 1.02, 687, colors[4]);
	jupiter.setAttribute(220, 0, 220, 14.2f, 0.41, 4015, colors[5]);
	saturn.setAttribute(240, 0, 240, 12.0f, 0.44, 10950, colors[6]);
	uranus.setAttribute(260, 0, 260, 9.0f, 0.72, 30660, colors[7]);
	neptune.setAttribute(280, 0, 280, 8.8f, 0.67, 60225, colors[8]);
}

void SolarSystem::rotate() {
	sun.rotate();
	mercury.rotate();
	venus.rotate();
	earth.rotate();
	mars.rotate();
	jupiter.rotate();
	saturn.rotate();
	uranus.rotate();
	neptune.rotate();
}

void SolarSystem::draw() {
	sun.draw();
	mercury.draw();
	venus.draw();
	earth.draw();
	mars.draw();
	jupiter.draw();
	saturn.draw();
	uranus.draw();
	neptune.draw();
}