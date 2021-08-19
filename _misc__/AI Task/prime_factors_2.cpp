/**
* C program to find 
all prime factors of any number
*/

#include "stdafx.h"
#include <stdio.h>  


int main()
{
	int i, j, num, isPrime;

	/*
	* Reads a number from user
	*/
	printf("Enter any number to print Prime factors: ");
	scanf("%d", &num);

	printf("\nAll Prime Factors of %d are: \n", num);

	/*
	* Finds all Prime factors
	*/
	for (i = 2; i <= num; i++)
	{
		/*
		* Checks if i is a factors of num
		*/
		if (num%i == 0)
		{
			/*
			* If i is a factor then check whether it is Prime or not ,, don't store redundant factors.
			*/
			isPrime = 1;
			for (j = 2; j <= i / 2; j++)
			{
				if (i%j == 0)
				{
					isPrime = 0;
					break;
				}
			}

			/*
			* If i is Prime then print i
			*/
			if (isPrime == 1)
			{
				printf("%d\n", i);
			}
		}
	}

	return 0;
}
