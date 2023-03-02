/*
 * Description: SimpleView reference design
 * Author: HBF
 * Version: 2021-10-06
 */
#ifndef CHOUSE_H
#define CHOUSE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

class House: public Shape {
protected:
	GLfloat vertex[8][3];  /* 2D array to store cube vertices */
	GLfloat p_vertex[5][3];
	GLint face[6][4];      /* 2D array to store faces */
	GLint triangle_face[4][3];
	GLint base_face[1][4];
	GLfloat cr, cg, cb;       /* color cube */
	GLfloat pr, pg, pb;       /* color cube */
public:
	House();
	void draw();
	void drawFace(int);
	void drawBaseFace();
	void drawPyramidFace(int);
};

#endif
