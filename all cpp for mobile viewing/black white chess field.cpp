/*
 * Copyright (c) 1993-2003, Silicon Graphics, Inc.
 * All Rights Reserved
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright
 * notice and this permission notice appear in supporting documentation,
 * and that the name of Silicon Graphics, Inc. not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS" AND
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION, LOSS OF
 * PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF THIRD
 * PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN ADVISED OF
 * THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE POSSESSION, USE
 * OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor clauses
 * in the FAR or the DOD or NASA FAR Supplement.  Unpublished - rights
 * reserved under the copyright laws of the United States.
 *
 * Contractor/manufacturer is:
 *	Silicon Graphics, Inc.
 *	1500 Crittenden Lane
 *	Mountain View, CA  94043
 *	United State of America
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 *  lines.c
 *  This program demonstrates geometric primitives and
 *  their attributes.
 */
#include <stdlib.h>
#include "OpenGL Files\glut.h"


#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
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

   float color ;
	float color1 = 0.6;
	float color2 = 0.2;

   glClear (GL_COLOR_BUFFER_BIT);

/* select white for all lines  */
  /* glColor3f (1.0, 1.0, 1.0);*/

/* in 1st row, 3 lines, each with a different stipple  */
  // glEnable (GL_LINE_STIPPLE);
  // glColor3f (1.0, 0.0, 0.0);

   

  // glRecti(20,20,100,70);
	color = color1;
   glColor3f (color, color, color);
   glRecti(80,50,160,100);

   for (i = 0; i < 4; i++)
   {
	   glColor3f (color, color, color); // set new color
	   for (j=0 ; j<4;j++)
   {
	   glColor3f (color, color, color); // set new color

	   glRecti(coordinate1,coordinate2,coordinate3,coordinate4);
	   coordinate1  = coordinate1  + 80;
	   coordinate3  = coordinate3 + 80;

		

	   if (color == color1)
		   color = color2;

	   else if (color == color2)
		   color = color1;
	
	   }
		// change color in inner loop.

	   if (color == color1)
		   color = color2;

	   else if (color == color2)
		   color = color1;


    coordinate2 = coordinate2 + 50;
	coordinate4 = coordinate4 + 50;

	coordinate1 = 20; 
	coordinate3 = 100;
	glColor3f (color, color, color); // set new color

   }

/*

   glLineStipple (1, 0x0101);  //  dotted  
   drawOneLine (50.0, 125.0, 150.0, 125.0);
   glLineStipple (1, 0x00FF);  //  dashed  
   drawOneLine (150.0, 125.0, 250.0, 125.0);
   glLineStipple (1, 0x1C47);  //  dash/dot/dash  
   drawOneLine (250.0, 125.0, 350.0, 125.0);
*/


/* in 2nd row, 3 wide lines, each with different stipple */
   
   /*
   glLineWidth (5.0);
   glLineStipple (1, 0x0101);  //  dotted  
   drawOneLine (50.0, 100.0, 150.0, 100.0);
   glLineStipple (1, 0x00FF);  //  dashed  
   drawOneLine (150.0, 100.0, 250.0, 100.0);
   glLineStipple (1, 0x1C47);  //  dash/dot/dash  
   drawOneLine (250.0, 100.0, 350.0, 100.0);
   glLineWidth (1.0);
   glColor3f (0.0, 1.0, 0.0);


   */

/* in 3rd row, 6 lines, with dash/dot/dash stipple  */
/* as part of a single connected line strip         */

/*
   glLineStipple (1, 0x1C47);  // dash/dot/dash  
   glBegin (GL_LINE_STRIP);
   for (i = 0; i < 7; i++)
      glVertex2f (50.0 + ((GLfloat) i * 50.0), 75.0);
   glEnd ();
   glColor3f (0.0, 0.0, 1.0);

   */


// in 4th row, 6 independent lines with same stipple  
/*  
   for (i = 0; i < 6; i++) {
      drawOneLine (50.0 + ((GLfloat) i * 50.0), 50.0,
         50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
   }
*/

/* in 5th row, 1 line, with dash/dot/dash stipple    */
/* and a stipple repeat factor of 5                  */

/*
   glLineStipple (5, 0x1C47);  //  dash/dot/dash  
   drawOneLine (50.0, 25.0, 350.0, 25.0);

   glDisable (GL_LINE_STIPPLE);

*/
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
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

   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (800, 800); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

/*
glEnable() and glDisable()

Enabling and Disabling Operations in OpenGL
One important feature that we didn?t need to use in our first program, but
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