#include "stdafx.h"


int main()

{
int * pt;
int(*pa)[3];		// like pa[][3] , 2D array
int ar1[2][3];
int ar2[3][2];
int **p2;					 // a pointer to a pointer 

pt = &ar1[0][0];	    	// both pointer-to-int	, it can be done since 2D array's first element is assigned to 1 D array.

pt = ar1[0];			   // both pointer-to-int	ar1[0] an 1 D array assigned to and 1D pointer pt.

//pt = ar1;				  // not valid , 2D assigned to 1D

pa = ar1;				// both pointer-to-int[3]	,both 3 column array and pointer

//pa = ar2;			   // not valid ,// column mismatch

p2 = &pt;			  // both pointer-to-int *	// p2 2D  array , pt 1D array

*p2 = ar2[0];		 // both pointer-to-int   // 1st row of ar2[0] assigned to 1D p2

//p2 = ar2;			// not valid 

return 0;
}