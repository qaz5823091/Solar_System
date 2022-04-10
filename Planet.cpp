#include "Planet.h"
#include <GL/glut.h>
#include <math.h>

const int TRACK_NUMBER = 1000;
const GLfloat SPEED_MULT = 100;

Planet::Planet() {
	this->setX(0);
	this->setY(0);
	this->setZ(0);
	this->setMagnitute(0);
	this->setColor(nullptr);
	this->setRotatePeriod(0);
	this->setRevolutePeriod(0);
}

Planet::Planet(int x, int y, int z,
	GLdouble magnitude,
	GLfloat rotate_period, GLfloat revolute_period, GLubyte* color) {
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setMagnitute(magnitude);
	this->setColor(color);
	this->setRotatePeriod(rotate_period);
	this->setRevolutePeriod(revolute_period);
}

Planet::Planet(const Planet& planet) {
	this->setX(planet.x);
	this->setY(planet.y);
	this->setZ(planet.z);
	this->setMagnitute(planet.magnitude);
	this->setColor(planet.color);
	this->setRotatePeriod(planet.rotate_period);
	this->setRevolutePeriod(planet.revolute_period);
}

void Planet::setAttribute(int x, int y, int z,
	GLdouble magnitude, GLfloat rotate_period, GLfloat revolute_period, GLubyte* color) {
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setMagnitute(magnitude);
	this->setColor(color);
	this->setRotatePeriod(rotate_period);
	this->setRevolutePeriod(revolute_period);
}

void Planet::setX(int x) {
	this->x = x;
}

void Planet::setY(int y) {
	this->y = y;
}

void Planet::setZ(int z) {
	this->z = z;
}

void Planet::setMagnitute(GLdouble magnitude) {
	this->magnitude = magnitude;
}

void Planet::setColor(GLubyte* color) {
	this->color = color;
}

void Planet::setRotatePeriod(GLfloat rotate_period) {
	this->rotate_period = rotate_period;
}

void Planet::setRevolutePeriod(GLfloat revolute_period) {
	this->revolute_period = revolute_period;
}

void Planet::rotate()
{
	rotate_angle += (1 / rotate_period);
	if (rotate_angle > 360) {
		rotate_angle = 0;
	}
	
	revolute_angle += (1 / revolute_period) * SPEED_MULT;
	if (revolute_angle > 360) {
		revolute_angle = 0;
	}

	glutPostRedisplay();
}

void Planet::draw() {
	// track part
	glBegin(GL_POINTS);
	for (int i = 0; i < TRACK_NUMBER; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(TRACK_NUMBER);
		float r = sqrt(this->x * this->x + this->z * this->z);
		float x = r * cosf(theta);
		float z = r * sinf(theta);
		glColor3f(1, 1, 1);
		glPointSize(1);
		glVertex3f(x, 0, z);
	}
	glEnd();

	// sphere part
	glPushMatrix();
	glColor3ubv(this->color);
	glRotatef(this->revolute_angle, 0, 1, 0);
	glTranslatef(this->x, 0, this->z);
	glRotatef(this->rotate_angle, 0, 1, 0);
	glutSolidSphere(this->magnitude, 20, 20);
	glPopMatrix();
}