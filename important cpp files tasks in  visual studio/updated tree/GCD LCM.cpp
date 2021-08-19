#include "stdafx.h"
#include <stdio.h>

int main() {
	int a, b, x, y, t, gcd, lcm;
	// is the smallest positive integer that is divisible by both a and b
	printf("Enter two integers\n");
	scanf("%d%d", &x, &y);

	a = x;
	b = y;

	while (b != 0) {
		t = b;
		b = a % b;
		a = t;
	}

	gcd = a;
	lcm = (x*y) / gcd;

	printf("Greatest common divisor of %d and %d = %d\n", x, y, gcd);
	printf("Least common multiple of %d and %d = %d\n", x, y, lcm);

	return 0;
}


/*
Recursive GCD
 Recursive Standard C Function: Greatest Common Divisor 
int
gcdr(int a, int b)
{
	if (a == 0) return b;
	return gcdr(b%a, a);
}

*/