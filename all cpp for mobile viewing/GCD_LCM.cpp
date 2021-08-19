#include"stdafx.h"

#include <stdio.h>

#include <conio.h>

int gcd(int m, int n)
{
	while (m != n) // execute loop until m == n
	{
		if (m > n)
			m = m - n; // large - small , store the results in large variable
		else
			n = n - m;
	}
	return (m); // m or n is GCD
}

int lcm(int m, int n)  // loghistho shadharon gunitok  for (m,n) = (12 ,18) gcd (m,n)=6 and lcm = 36
{
	int gcd(int, int);
	return(m * n / gcd(m, n)); // product of 2 numbers / gcd is lcm
}

int main()
{
	int m, n, lcm(int, int), gcd(int, int);
	printf(" enter anyu 2 values \n");
	scanf("%d%d", &m, &n);
	printf(" gcd is %d\n", gcd(m, n));
	printf(" lcm is %d\n", lcm(m, n));
	
	//getch();
	return 0;
}

/* 


o / p:
If u enter m = 12, n = 15 output gcd is 3 and output lcm is 60

NOTE 1 :
	gcd(12, 15) = 3
	gcd(12, 18) = 6
	gcd(4, 7) = 1
*/