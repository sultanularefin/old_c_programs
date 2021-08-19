#include <iostream>
#include "stdafx.h"

//  the glut file for windows operations 
// it also includes g1.h and g1u.h for the OpenGL library  calls 

#include<stdio.h>
#include<stdlib.h>
using namespace std;
int printNum(int num)
{
	// the two calls in this function to cout will sandwich an inner
	// sequence containing the numbers (num+1)...99...(num+1)
	cout << num;
	// While begin is less than 9, we need to recursively print
	// the sequence for (num+1) . . . 99 ... (num+1)
	if (num < 9)
	{
		printNum(num + 1);
	}
	return num;
	cout << num;
	
}
int main()
{
	int a;
	printf("%d",printNum(1));

	//printf("%d", a);
	return 0;
}