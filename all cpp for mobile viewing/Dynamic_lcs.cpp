
/* Dynamic Programming implementation of LCS problem */
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char *X, char *Y, int m, int n)
{
	int i;

	int **L; /// L stores .....


	L = new int*[m];	// see Jumping into C++ Alex Allain page 154  ;; m is rows

						// declare an array of size n of integer type. an arrays of pointer , int *[n] like int [][n]
	for (i = 0; i < n; ++i)
		L[i] = new int[n];		// n is columns ;; m * n matrix


	//int * L;
	//L = new int[m + 1][n+1];
	//int L[m + 1][n + 1];
	int j;

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;				// in dynamic lcs first rows and colums are initialize to 0

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
				
			

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	// Following code is used to print LCS
	int index = L[m][n]; // size of LCS is stored in L[m][n].

	// Create a character array to store the lcs string
	char *lcs;
	lcs = new char[index + 1];
	
	lcs[index] = '\0'; // Set the terminating character

					   // Start from the right-most-bottom-most corner and
					   // one by one store characters in lcs[]
	 i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])		// i is rows and j is colums , if the value in the above row is bigger then i--; else j--;
			i--;
		else
			j--;
	}

	printf(" %s  ", lcs);
	
	/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
	return L[m][n];
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