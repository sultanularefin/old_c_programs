/* Driver program to test above functions */
#include "stdafx.h"
#include <iostream>
void swap(char &m, char &n)
{
	char temp = n;
	n = m;
	m = temp;
}
void permute(char *A, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", A);
	else
	{
		for (i = l; i <= r; i++) //in i, l is assigned .
		{
			swap(*(A + l), *(A + i));
			permute(A, l + 1, r);
			swap(*(A + l), *(A + i)); //backtrack
		}
	}

}
int main()
{
	char str[] = "WXYZ";
	int n = strlen(str);
	permute(str, 0, n - 1);
	return 0;
}

/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */


//void permute(char *a, int l, int r)
//{
//	int i;
//	if (l == r)
//		printf("%s\n", a);
//	else
//	{
//		for (i = l; i <= r; i++)
//		{
//			swap((a + l), (a + i));
//			permute(a, l + 1, r);
//			swap((a + l), (a + i)); //backtrack
//		}
//	}
//}