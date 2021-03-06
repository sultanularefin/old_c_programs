// Program to print all prime factors
# include <stdio.h>
# include <math.h>

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		printf("%d ", 2);
		n = n / 2;
	}

	// n must be odd at this point.  So we can skip one element (Note i = i +2)
	int j = sqrt(n);
	for (int i = 3; i <= j; i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			printf("%d ", i);
			n = n / i;
		}
	}

	// This condition is to handle the case whien n is a prime number
	// greater than 2
	if (n > 2)
		printf("%d ", n);
}

/* Driver program to test above function */
int main()
{
	int n = 1317;
	primeFactors(n);
	return 0;
}