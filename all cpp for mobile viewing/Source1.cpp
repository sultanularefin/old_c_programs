#include <stdio.h>

int power(void);
int m, e;
int main()
{
	m = 2; 
	e = 3;
	printf("%d raised to the power %d power is %d", m, e, power());

	return 0;

}

int power(void)
{
	int temp, temp2;
	temp = 1; temp2 = e;
	for (; temp2 > 0; temp2--)temp = temp*m;
	return temp;
}