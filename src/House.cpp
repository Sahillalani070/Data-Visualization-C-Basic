#include "House.hpp"

House::House()
{
	// set set cordinate values for all vertices
	vertex[0][0] = -1; vertex[0][1] = -1; vertex[0][2] = -1;
	vertex[1][0] = -1; vertex[1][1] = 1;  vertex[1][2] = -1;
	vertex[2][0] = 1;  vertex[2][1] = 1;  vertex[2][2] = -1;
	vertex[3][0] = 1;  vertex[3][1] = -1; vertex[3][2] = -1;
	vertex[4][0] = -1; vertex[4][1] = -1; vertex[4][2] = 1;
	vertex[5][0] = -1; vertex[5][1] = 1;  vertex[5][2] = 1;
	vertex[6][0] = 1;  vertex[6][1] = 1;  vertex[6][2] = 1;
	vertex[7][0] = 1;  vertex[7][1] = -1; vertex[7][2] = 1;

    // other faces
	face[0][0] = 0; face[0][1] = 1; face[0][2] = 2; face[0][3] = 3;
	face[1][0] = 7; face[1][1] = 6; face[1][2] = 5; face[1][3] = 4;
	face[2][0] = 0; face[2][1] = 4; face[2][2] = 5; face[2][3] = 1;
	face[3][0] = 2; face[3][1] = 1; face[3][2] = 5; face[3][3] = 6;
	face[4][0] = 3; face[4][1] = 2; face[4][2] = 6; face[4][3] = 7;
	face[5][0] = 0; face[5][1] = 3; face[5][2] = 7; face[5][3] = 4;

	// Pyramid Related Stuff
	// set set cordinate values for all vertices
	p_vertex[0][0] = -1;
	p_vertex[0][1] = -1;
	p_vertex[0][2] = 1;

	p_vertex[1][0] = -1;
	p_vertex[1][1] = 1;
	p_vertex[1][2] = 1;

	p_vertex[2][0] = 1;
	p_vertex[2][1] = 1;
	p_vertex[2][2] = 1;

	p_vertex[3][0] = 1;
	p_vertex[3][1] = -1;
	p_vertex[3][2] = 1;

	p_vertex[4][0] = 0;
	p_vertex[4][1] = 0;
	p_vertex[4][2] = 2;


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


	// Cube color
	cr = 1.0;
	cg = 0.0;
	cb = 0.0;

	// Pyramid color
    pr = 1.0;
    pg = 1.0;
    pb = 0.0;
}

void House::drawFace(int i)
{
// draw face i
	glColor3f(cr,cg,cb);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(vertex[face[i][0]]);
	glVertex3fv(vertex[face[i][1]]);
	glVertex3fv(vertex[face[i][2]]);
	glVertex3fv(vertex[face[i][3]]);
	glEnd();
}

void House::drawBaseFace()
{
	glColor3f(pr,pg,pb);
	// draw base face
	glBegin(GL_LINE_LOOP);
	glVertex3fv(p_vertex[base_face[0][0]]);
	glVertex3fv(p_vertex[base_face[0][1]]);
	glVertex3fv(p_vertex[base_face[0][2]]);
	glVertex3fv(p_vertex[base_face[0][3]]);
	glEnd();
}


void House::drawPyramidFace(int i)
{
	glColor3f(pr,pg,pb);
	// draw pyramid face i
	glBegin(GL_LINE_LOOP);
	glVertex3fv(p_vertex[triangle_face[i][0]]);
	glVertex3fv(p_vertex[triangle_face[i][1]]);
	glVertex3fv(p_vertex[triangle_face[i][2]]);
	glEnd();
}

void House::draw()
{
    glPushMatrix();
    this->ctmMultiply();
     glScalef(s, s, s);
 // set color



//  draw all faces
     int i;
     for (i = 0; i < 6; i++)
    	 drawFace(i);

     int j;
     for (j = 0; j < 4; j++)
         drawPyramidFace(j);

     drawBaseFace();

    glPopMatrix();
}

