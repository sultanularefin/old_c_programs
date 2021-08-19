/* A Naive recursive implementation of LCS problem */
#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n) // if you run this in the watch menu you will get lcs(X, Y, m , n ) =4  which is the exact answer.
										/* the vs generates the solution in the watch for you again a recursive solution
										use autos not watch , also here first row and first column are not initialized to zeros (0)*/
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
		return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
	// in recursive implementation of lcs from the end like (6,7) the searching / evaluation begins. not from the 
	// beginning like (1,1) in normal dynamic algorithm.
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Driver program to test above function */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	printf("Length of LCS is %d\n", lcs(X, Y, m, n));

	getchar();
	return 0;
}




