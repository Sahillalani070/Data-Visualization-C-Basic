#include "Pyramid.hpp"

Pyramid::Pyramid()
{
	// set set cordinate values for all vertices
	vertex[0][0] = -1;
	vertex[0][1] = -1;
	vertex[0][2] = 0;

	vertex[1][0] = -1;
	vertex[1][1] = 1;
	vertex[1][2] = 0;

	vertex[2][0] = 1;
	vertex[2][1] = 1;
	vertex[2][2] = 0;

	vertex[3][0] = 1;
	vertex[3][1] = -1;
	vertex[3][2] = 0;

	vertex[4][0] = 0;
	vertex[4][1] = 0;
	vertex[4][2] = 1;


    // other faces
	base_face[0][0] = 0;
	base_face[0][1] = 1;
	base_face[0][2] = 2;
	base_face[0][3] = 3;

	triangle_face[0][0] = 0;
	triangle_face[0][1] = 1;
	triangle_face[0][2] = 4;

	triangle_face[1][0] = 0;
	triangle_face[1][1] = 3;
	triangle_face[1][2] = 4;

	triangle_face[2][0] = 3;
	triangle_face[2][1] = 2;
	triangle_face[2][2] = 4;

	triangle_face[3][0] = 2;
	triangle_face[3][1] = 1;
	triangle_face[3][2] = 4;


	// color
    r = 1.0;
    g = 1.0;
    b = 0.0;
}

void Pyramid::drawBaseFace()
{
	// draw base face
	glBegin(GL_LINE_LOOP);
	glVertex3fv(vertex[base_face[0][0]]);
	glVertex3fv(vertex[base_face[0][1]]);
	glVertex3fv(vertex[base_face[0][2]]);
	glVertex3fv(vertex[base_face[0][3]]);
	glEnd();
}


void Pyramid::drawPyramidFace(int i)
{
	// draw pyramid face i
	glBegin(GL_LINE_LOOP);
	glVertex3fv(vertex[triangle_face[i][0]]);
	glVertex3fv(vertex[triangle_face[i][1]]);
	glVertex3fv(vertex[triangle_face[i][2]]);
	glEnd();
}

void Pyramid::draw()
{
    glPushMatrix();
    this->ctmMultiply();
     glScalef(s, s, s);

     // set color
     glColor3f(r,g,b);

 // draw all faces
     int i;
     for (i = 0; i < 4; i++)
    	 drawPyramidFace(i);

     drawBaseFace();


    glPopMatrix();
}

