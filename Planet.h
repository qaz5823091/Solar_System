#include <GL/glut.h>

#pragma once
class Planet
{
	private:
		int x, y, z;
		GLdouble magnitude;
		GLubyte *color;
		GLfloat rotate_angle = 0;
		GLfloat revolute_angle = 0;
		GLfloat rotate_period;
		GLfloat revolute_period;
	public:
		Planet();
		Planet(int x, int y, int z, 
			GLdouble magnitude, GLfloat rotate_period, GLfloat revolute_period, GLubyte* color);
		Planet(const Planet& planet);
		void setAttribute(int x, int y, int z,
			GLdouble magnitude, GLfloat rotate_period, GLfloat revolute_period, GLubyte* color);
		void setX(int x);
		void setY(int y);
		void setZ(int z);
		void setMagnitute(GLdouble magnitude);
		void setColor(GLubyte* color);
		void setRotatePeriod(GLfloat rotate_period);
		void setRevolutePeriod(GLfloat revolute_period);
		void rotate();
		void draw();
};

