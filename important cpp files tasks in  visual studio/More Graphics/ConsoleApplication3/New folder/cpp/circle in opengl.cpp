#include <Windows.h>
#include "OpenGL Files/glu.h"
#include "OpenGL Files/glut.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define window_width  1080  
#define window_height 720 
#define PI 3.1416

void drawFilledSun(){
	//static float angle;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -10);
	int i, x, y;
	double radius = 0.30;
	//glColor3ub(253, 184, 19);     
	glColor3ub(255, 0, 0);
	double twicePi = 2.0 * 3.142;
	x = 0, y = 0;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 20; i++)   {
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
			);
	}
	glEnd(); //END
}

void main_loop_function() {
	int c;
	drawFilledSun();
	//DrawCircle(0, 0, 0.7, 100);
	glutSwapBuffers();
	c = getchar();
}
void GL_Setup(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	gluPerspective(45, (float)width / height, .1, 100);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(window_width, window_height);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("GLUT Example!!!");
	glutIdleFunc(main_loop_function);
	GL_Setup(window_width, window_height);

	//drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
	//drawFilledCircle(100, 100, 8);
	glutMainLoop();
	return 0;
}
