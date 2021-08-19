
#include "stdafx.h"
#include <iostream>
#include<stdio.h>

using namespace std;


int main() {

	int i, j;
	int x, y;

	

	puts("Enter Matix dimensions for 1st Matrix: ");
	scanf("%d %d", &i, &j);

	

	int Matrix1[10][10];
	int Matrix2[10][10];



	puts("Enter Matix dimensions for 2nd Matrix: ");
	scanf("%d %d", &x, &y);

	int r, l = 0;
	
	printf("Give input for first Matrix: ");

	for (int n = 0; n < i; ++n)
		for (int s = 0; s < j; s++) {
			 Matrix1[n][s]=0;
		}
	
	for (int n = 0; n < i; ++n)
		for (int s = 0; s < j; s++) {
			scanf("%d", &Matrix1[n][s]);
		}

	
	

	printf("Give input for 2nd Matrix: ");

	for (int n = 0; n < x; ++n)
		for (int s = 0; s < y; s++) {
			Matrix2[n][s] = 0;
		}



	for (int n = 0; n < x; ++n)
		for (int s = 0; s < y; s++) {
			scanf("%d", &Matrix2[n][s]);
		}


	printf("\nFirst Matrix: ");
	for (r = 0; r < i; r++){
		for (l = 0; l < j; l++) {
			printf("%d ", Matrix1[r][l]);
		}
	puts("\n");
		}


	printf("\n2nd Matrix: ");
	for (r = 0; r < x; r++){
		for (l = 0; l < y; l++) {
			printf("%d ", Matrix2[r][l]);

		}
		puts("\n");
	}

	int c, d = 0;

	c = i > x?i : x;
	d = j > y?j : y;
	int Multiplication[10][10];
	for (r = 0; r < c; r++) {
		for (l = 0; l < d; l++) {
			Multiplication[r][l] = 0;
		}
	}
//	int c = x;
	int sum;

	for (r = 0; r < c; r++) {
		for (l = 0; l < d; l++) {
			sum = 0;
			for (int k = 0; k < c ; k++) {
				sum = sum + Matrix1[r][k] * Matrix2[k][l];
			}
			Multiplication[r][l] = sum;
		}
	}

	printf("\nMultiplied  Matrix: \n");
	for (r = 0; r < x-1; r++) {
		for (l = 0; l < y; l++) {
			printf("%d ", Multiplication[r][l]);

		}
		puts("\n");
	}


return 0;


}