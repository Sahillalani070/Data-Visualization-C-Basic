/*
 * Description: SimpleView reference design
 * Author: HBF
 * Version: 2021-10-06
 */
#ifndef CPYRAMID_H
#define CPYRAMID_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

class Pyramid: public Shape {
protected:
	GLfloat vertex[5][3];  /* 2D array to store pyramid vertices */
	GLint triangle_face[4][3];
	GLint base_face[1][4];      /* 2D array to store faces */
	GLfloat r, g, b;       /* color pyramid */
public:
	Pyramid();
	void draw();
	void drawBaseFace();
	void drawPyramidFace(int);
};

#endif
