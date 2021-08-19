#include<stdio.h>
#include "stdafx.h"
void F1(int a[]);
int main()
{
	int a[10] = { 1, 2, 3, 4 };
	int *p = a;
	F1(p);
	return 0;
}
void F1(int a[])
{

}