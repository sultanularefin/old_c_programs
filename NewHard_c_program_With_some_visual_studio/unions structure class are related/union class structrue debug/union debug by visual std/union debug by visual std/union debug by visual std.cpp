// union debug by visual std.cpp : Defines the entry point for the console application.
//

using namespace std;
#include "stdafx.h"
#include<conio.h>


union swapbytes {
	unsigned char c[2];
	unsigned i;
	swapbytes(unsigned x);
	void swp();
	
};

		swapbytes::swapbytes(unsigned x)
{
	i=x;
}

	void swapbytes::swp()
	{
		unsigned char temp;
		temp = c[0];
		c[0] =c[1];
		c[1]= temp;
		}
		

int _tmain(int argc, _TCHAR* argv[])
{
			swapbytes ob(2);
			ob.swp();
			printf("%d",ob.i);
			getch();
			return 0;
}





	
