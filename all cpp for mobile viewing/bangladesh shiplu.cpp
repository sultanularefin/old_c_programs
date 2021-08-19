#include "opengl files/glut.h"
#include <math.h>

#define M_PI 3.1416


void drawCircle(float radius, int segments)
{
	int r;
	glBegin(GL_POLYGON);
	for (r = 0; r<segments; r++)
	{
		float x = radius * cos(r*2.0*M_PI / segments);
		float y = radius * sin(r*2.0*M_PI / segments);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void render(void)
{
	int Circle1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -30);

	// new circle
	glPushMatrix();
	glColor3ub(200, 255, 65);
	glTranslatef(-1, 0, 10);
	glutSolidSphere(3, 50, 50);
	glPopMatrix();



	// red circle
	glPushMatrix();
	glColor3ub(244, 42, 65);
	glTranslatef(-1, 0, 10);
	glutSolidSphere(5, 100, 100);
	glPopMatrix();

	// green rect
	/*glColor3ub(0, 106, 77);
	glutSolidCube(25);*/


	for
		(Circle1 = 0; Circle1<15; Circle1++)
	{

		glPushMatrix();
		glTranslatef(d + 28, 455, 1);
		random_generator(0, 3);
		if (randomValue == 0)
		{
			glColor3f(0, .5, 0);

		}
		else if (randomValue == 1)
		{
			glColor3f(.5, 0, 0);

		}
		else
		{
			glColor3f(0, 0, .5);

		}
		glLineWidth(1.0);
		drawCircle(14, 200);
		glPopMatrix();
	}

	glFlush();
	glutSwapBuffers();
}

void init(void)
{
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 300);
	glutCreateWindow("Flag of Bangladesh");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutMainLoop();
	return 0;
}