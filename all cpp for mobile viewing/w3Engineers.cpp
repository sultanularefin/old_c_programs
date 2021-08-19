// w3Engineers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include <iostream>
using namespace std;

int main()
{
	int rows = 1;
	int j = 0;
	int number = 1;

	for (; rows < 12; rows++) {
		for (j=0 ; j <rows; j++) {

			cout << number;
			cout << " ";
			number++;
			
		}

		cout << endl;
	}
	return 0;
}
