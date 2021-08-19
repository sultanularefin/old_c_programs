#include "OpenGL Files/glut.h"
#include<math.h>
#include <stdio.h>
//#include<stdlib.h>
//using namespace std;
int Height = 400, Width = 400;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -30);

	// red circle
	glPushMatrix();
	glColor3ub(244, 42, 65);
	glTranslatef(-1, 0, 10);
	glutSolidSphere(5, 50, 50);
	glPopMatrix();

	// green rect
	glColor3ub(0, 106, 77);
	glutSolidCube(25);

	glFlush();
	glutSwapBuffers();


}
static void Reshape(int w, int h)
{
	/*
	glClear(GL_COLOR_BUFFER_BIT);

	Width = w; Height = h;

	glViewport (0, 0, Width, Height);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glOrtho(-20.0*(GLfloat)w/(GLfloat)h,20.0*(GLfloat)w/(GLfloat)h, -20.0, 20.0, -20.0, 20.0);*/
	////////////////////////
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*if (w <= h)
	glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
	5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
	else*/
	glOrtho(-20.0*(GLfloat)w / (GLfloat)h, 20.0*(GLfloat)w / (GLfloat)h, -20.0, 20.0, -20.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	///////////////////////
}
void init(void)
{
	///* select clearing color */
	//glClearColor(0.0, 0.0, 0.0, 0.0);

	///* initialize viewing values */
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//// glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);


	// new init(void)

	glClearColor(1, 1, 1, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);



}
void reshape(int w, int h)
{
	float aspectRatio = (float)w / (float)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, aspectRatio, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

/*
* Declare initial window size, position, and display mode

* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	init();
	glutReshapeFunc(reshape);		//call the reshape function. or like this see red book
	// glutReshapeFunc(Reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0; /* ANSI C requires main to return int. */


}







/*
 0)   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

/* Clearsthespecifiedbufferstotheircurrentclearingvalues.Themask
argumentisabitwiselogicalORcombinationofthevalues*/
		// 1) glLoadIdentity();

/*
glLoadIdentity — replace the current matrix with the identity matrix

void glLoadIdentity(void);

glLoadIdentity replaces the current matrix with the identity matrix. It is semantically equivalent to calling glLoadMatrix with the identity matrix

1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
but in some cases it is more efficient.

GL_INVALID_OPERATION is generated if glLoadIdentity is executed between the execution of glBegin and the corresponding execution of glEnd.
*/

      // 2)glTranslatef(0, 0, -30);
/*
glTranslate — multiply the current matrix by a translation matrix

void glTranslated(	GLdouble  	x,GLdouble  	y,GLdouble  	z);

void glTranslatef(	GLfloat  	x,GLfloat  	y,GLfloat  	z);

x, y, z Specify the x, y, and z coordinates of a translation vector.

glTranslate produces a translation by x y z . The current matrix (see glMatrixMode) is multiplied by this translation matrix,
with the product replacing the current matrix, as if glMultMatrix were called with the following matrix for its argument:

1 0 0 x
0 1 0 y
0 0 1 z
0 0 0 1
If the matrix mode is either GL_MODELVIEW or GL_PROJECTION, all objects drawn after a call to glTranslate are translated.

Use glPushMatrix and glPopMatrix to save and restore the untranslated coordinate system.


GL_INVALID_OPERATION is generated if glTranslate is executed between the execution of glBegin and the corresponding execution of glEnd.
*/

// red circle

	// 3) glPushMatrix();				// Save the current working matrix.
		 //   4) glColor3ub(244, 42, 65);
/*
The GL stores both a current single-valued color index and a current four-valued RGBA color. glcolor sets a new four-valued
RGBA color. glcolor has two major variants: glcolor3 and glcolor4. glcolor3 variants specify new red, green, and blue values
explicitly and set the current alpha value to 1.0 (full intensity) implicitly. glcolor4 variants specify all four color
components explicitly.

Of course 255 sets it to black. That is 0xff (or 0b11111111), which is -1 using a 2's complement signed 8-bit number...
-1 is less than 0, which you would consider to be the absence of all color. Signed colors really do not make much sense outside of
blending. In a nutshell, that is the difference between these two functions, one is signed and other is unsigned.
When you use the glColor3b (...) function (signed), then your range is -128–127 (-128 maps to -1.0 and 127 maps to 1.0, 0 is the
mid-point),

When you use glColor3ub (...) function (un-signed), the range is 0–255 (0 maps to 0.0 and 255 maps to 1.0).
No matter which function you use, unless it is glColor3f (...), they all do fixed-point to floating-point unit conversion.
During fixed-point to floating-point normalization, the range of the integer data type is mapped directly
between -1.0 (signed) / 0 (unsigned) and 1.0. The u vs. non-u simply indicates that one of them is unsigned (larger positive range).*/

		//  5) //glTranslatef(-1, 0, 10);
  // 6)  glutSolidSphere(5, 50, 50); // The GLUT provides several ready-made 3D objects. These include a sphere, a cone, a torus.......
/*

glutSolidSphere(double radius, int slices, int stacks)
glutWireSphere(double radius, int slices, int stacks)

Renders a sphere centered at the modeling coordinates origin of the specified radius.
The sphere is subdivided around the Z axis into slices and along the Z axis into stacks.

radius is the radius of the sphere
slices is  the number of subdivisions around the Z axis (similar to lines of longitude)
stacks is the number of subdivisions along the Z axis (similar to lines of latitude)

*/
  // 7)  glPopMatrix();	
/*The main idea is: when you use glTranslate(..) or glRotate(..) you affect the modelview matrix.
				{ glMatrixMode(GL_MODELVIEW);}
				This means that when you apply several transformations (translations & rotations) this matrix changes too.
				To get the (modelview) matrix into the original state, you also can use glLoadIdentity();
				*/

// green rect
  // 8)glColor3ub(0, 106, 77);
  // 9)  glutSolidCube(25);
/*  glutSolidCube and   glutWireCube render a solid or wireframe cube respectively.

void glutSolidCube(GLdouble size);
void glutWireCube(GLdouble size);

glutSolidCube and glutWireCube render a solid or wireframe cube respectively. The cube is centered at the modeling coordinates
origin with sides of length size.
*/

  //  10)  glFlush();
		//  11)  glutSwapBuffers();
/*You’ve already used double buffering for animation. Double buffering isdone by making the maincolor buffer have two parts:a front
buffer that’s displayed in your window; and a back buffer, which is where you render
the new image. When you swap the buffers (by calling glutSwapBuffers(),
for example),the front and back buffers are exchanged. Only the maincolor buffer of the default frame buffer is double buffered.
*/
