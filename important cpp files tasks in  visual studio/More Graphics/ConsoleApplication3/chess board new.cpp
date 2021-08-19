
#include <stdlib.h>
#include "opengl files/glut.h"

/* 
In older versions of OpenGL this could be accomplished through immediate
mode, which used glBegin/glEnd with the vertex information defined in between or
through display lists that captured and replayed immediate mode commands.
*/

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
	 glVertex2f((x1), (y1)); glVertex2f((x2), (y2)); glEnd();

void init(void)
{
	glClearColor(0.0, 1.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);
}

void display(void)
{
	int i;
	//inner loop in i;
	int j;
	int coordinate1 = 20;
	int coordinate2 = 20;
	int coordinate3 = 100;
	int coordinate4 = 70;

	float color;
	float color1 = 1.0;
	float color2 = 1.0;
	float color3 = 0.0;

	glClear(GL_COLOR_BUFFER_BIT);

	/* select white for all lines  */
	/* glColor3f (1.0, 1.0, 1.0);*/

	/* in 1st row, 3 lines, each with a different stipple  */
	// glEnable (GL_LINE_STIPPLE);
	// glColor3f (1.0, 0.0, 0.0);



	// glRecti(20,20,100,70);
	//color = color1;

	/* 
	
	what is glColor3f , what is glColor3i  , what is glRecti is the things (some of the things that MAM will 
	ask ? . .....
	...................................
	.............
	
	*/
	glColor3f(color1, color2, color3);

	glRecti(80, 50, 160, 100);

	for (i = 0; i < 8; i++)
	{
		glColor3f(color1, color2, color3); // set new color
		for (j = 0; j<8; j++)
		{
			glColor3f(color1, color2, color3); // set new color

			glRecti(coordinate1, coordinate2, coordinate3, coordinate4);
			coordinate1 = coordinate1 + 80;
			coordinate3 = coordinate3 + 80;



			if (color2 == 1.0)
			{

				color2 = 0.0;
				color3 = 1.0;
			}
			else if (color2 == 0.0)
				color2 = 1.0;
			color3 = 0.0;

		}
		// change color in inner loop.

		if (color2 == 1.0)
		{

			color2 = 0.0;
			color3 = 1.0;
		}
		else if (color2 == 0.0)
			color2 = 1.0;
		color3 = 0.0;

		coordinate2 = coordinate2 + 50;
		coordinate4 = coordinate4 + 50;

		coordinate1 = 20;
		coordinate3 = 100;
		glColor3f(color1, color2, color3); // set new color

	}

	
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

/*
glEnable() and glDisable()

Enabling and Disabling Operations in OpenGL
One important feature that we didn’t need to use in our first program, but
will use throughout this book, is enabling and disabling modes of operation
in OpenGL. Most operational features are turned on and off by the
glEnable() and glDisable() commands.
void glEnable(GLenum capability);
void glDisable(GLenum capability);
glEnable() turns on a capability and glDisable() turns it off. There are
numerous enumerated values that can be passed as parameters to
glEnable() or glDisable(). Examples include GL_DEPTH_TEST for
turning on and off depth testing; GL_BLEND to control blending and
GL_RASTERIZER_DISCARD for advanced rendering control while doing
transform feedback.
*/