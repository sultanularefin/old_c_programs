#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int Max2[3];
char duplicate_char(char A[]);
int* get_max(int M[]);

int R_fib(int n);
int Loop_fib();
char new_duplicate_char(char A[]);

void fib( int n); // dynamic fibonacci


int main() {
	
	// duplicate char (scans from after that charecter which is scanned)
	/*char found;
	char A[100];

	gets_s(A);

	found = duplicate_char(A);

	printf("charecter found   %c", found);*/
	/*
	// new duplicate char (scans from beginning of a string)

	char found;
	char A[100];

	gets_s(A);

	found = new_duplicate_char(A);

	printf("charecter found   %c \n\n", found);
	*/


	/*printf("\n\n get 2 maximum numbers :\n");
	printf("Enter numbers:");
	int s[5];
	for (int q = 0; q < 5; q++)
	{
		scanf("%d", &s[q]);
	}
	int *m1;


	m1 = get_max(s);


	printf("\n\nvalues are %d %d", *(m1), *(m1 + 1));
*/
/*
int n;
printf("\n\nEnter input value (number of terms) for generating a fibonacci series:\n\n");
scanf("%d", &n);
int k = 0;

printf("%\n\n fibonacci of %d is :  ", n);
for (int x = 1; x <= n; x++) {
	printf(" %d ", R_fib(k));
	k++;
}
*/

	//Loop_fib();  //fibonacci using loop
	/*
	// dynamic fibonacci
	int n = 9;
	//printf("%d", fib(9));
	fib(9);
	*/
	



}

char duplicate_char(char A[])
{
	char Temp[100];
	strcpy(Temp, A);

	int i;
	int j = 1;
	int flag = 0;

	for (i = 0; A[i]; i++)
	{
		if (flag == 1)
		{
			j = i + 1;
			flag = 0;
		}

		while (Temp[j])
		{
			if ((A[i] != Temp[j]) && (Temp[j + 1] == '\0'))
			{
				return A[i];

			}

			if (A[i] == Temp[j])
			{
				flag = 1;
				break;

			}
			j++;
		}


	}
	/*int s = 12;*/
}


int* get_max(int M[])
{
	//int length = sizeof(M) / sizeof(M[0]);

	int Tempmax = -100;

	int flag = 0;

	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (flag == 1) {
				if (Max2[0] == M[j])
					continue;
			}
			if (Tempmax < M[j]) {
				Tempmax = M[j];

			}
		}
		Max2[i] = Tempmax;
		flag = 1;
		Tempmax = 0;
	}



	return Max2;
}

int R_fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (R_fib(n - 1) + R_fib(n - 2));

}

int Loop_fib()
{

	int n, first = 0, second = 1, next, c;

	printf("\n\nEnter the number of terms\n");
	scanf("%d", &n);

	printf("\n\nFibonacci for %d terms are :-\n", n);

	for (c = 0; c < n; c++)
	{
		if (c <= 1)
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		printf("%d\n", next);
	}

	return 0;

}

char new_duplicate_char(char A[])
{
	char Temp[100];
	strcpy(Temp, A);

	int i;
	int j = 0;
	int flag = 0;
	

	for (i = 0; A[i]; i++)
	{
		if (flag == 1)// j initialized to 0 again to start searching from beginning
			j = 0;
		if (i == j) 
			j++;
		while (Temp[j])
		{
			if ((A[i] != Temp[j]) && (Temp[j + 1] == '\0'))
			{
				return A[i];

			}

			if ((A[i] == Temp[j])&&(i!=j))
			{// j=0; // could be initialized to 0 again
				flag = 1;
				break;
			}
			j++;
		}
	}
	/*int s = 12;*/
}

void fib( int n)
{
	/* Declare an array to store Fibonacci numbers. */
	
	int * f;
	f = new int[n+1];
	
	
	//f = new int(n + 1);
	//f= malloc(n + 1);
	//int f = new int[n+1];
	
	int i;

	/* 0th and 1st number of the series are 0 and 1*/
	f[0] = 0;
	f[1] = 1;
	printf(" %d  %d ", f[0], f[1]);

	for (i = 2; i <= n; i++)
	{
		/* Add the previous 2 numbers in the series
		and store it */
		f[i] = f[i - 1] + f[i - 2];

		printf(" %d", f[i]);
	}

	//return f[n];
	return ;
}



