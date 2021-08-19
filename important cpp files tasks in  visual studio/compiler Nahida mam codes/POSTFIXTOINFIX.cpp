#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX 50

struct postfix
{
	char stack[MAX][MAX], target[MAX];
	char temp1[2], temp2[2];			//an array of char having 2 indexes
	char str1[MAX], str2[MAX], str3[MAX];
	int i, top;
};

void initpostfix(struct postfix *);
void setexpr(struct postfix *, char *);
void push(struct postfix *, char *);
void pop(struct postfix *, char *);
void convert(struct postfix *);
void show(struct postfix);

int main()
{

	struct postfix q;
	char expr[MAX];

	//clrscr();

	initpostfix(&q);

	printf("\nEnter an expression in postfix form: ");
	gets(expr);

	setexpr(&q, expr);
	convert(&q);

	printf("\nThe infix expression is: ");
	show(q);

	//getch();
	return 0;
}

/* initializes data member */
void initpostfix(struct postfix *p)
{
	p->i = 0;
	p->top = -1;
	strcpy(p->target, "");
}

/* copies given expression to target string */
void setexpr(struct postfix *p, char *c)
{
	strcpy(p->target, c);		// c is a array of character.
}

/* adds an expr. to the stack */
void push(struct postfix *p, char *str)
{
	if (p->top == MAX - 1)
		printf("\nStack is full.");
	else
	{
		p->top++;
		strcpy(p->stack[p->top], str);	// stack is a 2 dimensional array , str is an array of character.
										// it stores the array in index [p->top]
	}
}

/* pops an expr. from the stack */
void pop(struct postfix *p, char *a)
{
	if (p->top == -1)
		printf("\nStack  is empty.");
	else
	{
		strcpy(a, p->stack[p->top]);
		p->top--;
	}
}

/* converts given expr. to infix form */
void convert(struct postfix *p)
{
	while (p->target[p->i])
	{
		/* skip whitespace, if any */
		if (p->target[p->i] == ' ')
			p->i++;
		if (p->target[p->i] == '%' || p->target[p->i] == '*' ||
			p->target[p->i] == '-' || p->target[p->i] == '+' ||
			p->target[p->i] == '/' || p->target[p->i] == '$')

		{
			pop(p, p->str2);	// in postfix expression after 2 variable you will find a operator.
			pop(p, p->str3);	// thats why 2 pop operation
			p->temp1[0] = p->target[p->i];
			p->temp1[1] = '\0';
			strcpy(p->str1, p->str3);
			strcat(p->str1, p->temp1);
			strcat(p->str1, p->str2);
			push(p, p->str1);			// pushes partial string to the  2D array named stack
		}
		else
		{
			p->temp1[0] = p->target[p->i];
			p->temp1[1] = '\0';
			strcpy(p->temp2, p->temp1);
			push(p, p->temp2);
		}
		p->i++;
	}
}

/* displays the expression */
void show(struct postfix p)
{
	char *t;
	t = p.stack[0];
	while (*t)
	{
		printf("%c ", *t);
		t++;
	}
}
