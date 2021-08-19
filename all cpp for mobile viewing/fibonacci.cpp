#include "stdafx.h"
#include <iostream>
using namespace std;

int fib(int n);

// Fibonacci series: 1, 1, 2, 3, 5, 8, 13, 21, 34...
int main()
{

	int n, answer;
	cout << "Enter number to find : ";
	cin >> n;
	cout << "\n\n";

	answer = fib(n);

	cout << answer << " is the " << n << "th Fibonacci number\n";
	return 0;
}
int fib(int n)
{
	cout << "Processing fib(" << n << ")... ";
	if (n < 3)
	{
		cout << "Return 1!\n";
		return (1);
	}
	else
	{
		cout << "Call fib(" << n - 2 << ") and fib(" << n - 1 << ").\n";
		return(fib(n - 2) + fib(n - 1));
	}
}