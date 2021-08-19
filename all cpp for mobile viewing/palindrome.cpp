/*
* C Program to Check String is Palindrome using Stack.
*/

#include"stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


void push(char);
char pop();

char stack[100];
int top = -1;


void main()
{
	char str[100];
	int i, count = 0, len;

	printf("Enter string to check it is palindrome or not : ");
	scanf("%s", str);

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		push(str[i]);
	}

	for (i = 0; i < len; i++)
	{
		if (str[i] == pop())
			count++;
	}

	if (count == len)
		printf("%s is a Palindrome string\n", str);
	else
		printf("%s is not a palindrome string\n", str);
}

/* Function to push character into stack */
void push(char c)
{
	stack[++top] = c;
}

/* Function to pop the top character from stack */
char pop()
{
	return(stack[top--]);
}



//Enter string to check it is palindrome or not : madam
//madam is a Palindrome string
//
//
//Enter string to check it is palindrome or not : sanfoundry
//sanfoundry is not a palindrome string