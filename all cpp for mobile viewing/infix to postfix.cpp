#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX 50

struct infix
{
	char target[MAX];
	char stack[MAX];
	char *s, *t;
	int top;
};

void initinfix(struct infix *);		// initialize infix expression
void setexpr(struct infix *, char *);	
void push(struct infix *, char);
char pop(struct infix *);
void convert(struct infix *);
int priority(char);
void show(struct infix);

int main()
{
	struct infix p;
	char expr[MAX];

	initinfix(&p);

	//clrscr();

	printf("\nEnter an expression in infix form: ");
	gets(expr);

	setexpr(&p, expr);
	convert(&p);

	printf("\nThe postfix expression is: ");
	show(p);

	//getch();
	return 0;
}

/* initializes structure elements */
void initinfix(struct infix *p)
{
	p->top = -1;
	strcpy(p->target, "");
	strcpy(p->stack, "");
	p->t = p->target;
	p->s = "";
}

/* sets s to point to given expr. */
void setexpr(struct infix *p, char *str)
{
	p->s = str;
}

/* adds an operator to the stack */
void push(struct infix *p, char c)
{
	if (p->top == MAX)		// may be should be max-1 , from 0 to max-1;
		printf("\nStack is full.\n");
	else
	{
		p->top++;
		p->stack[p->top] = c;
	}
}

/* pops an operator from the stack */
char pop(struct infix *p)
{
	if (p->top == -1)
	{
		printf("\nStack is empty.\n");
		return -1;
	}
	else
	{
		char item = p->stack[p->top];
		p->top--;
		return item;
	}
}

/* converts the given expr. from infix to postfix form */
void convert(struct infix *p)
{
	char opr;

	while (*(p->s))// while at address p-> s is true, meaning if it contains something
	{
		if (*(p->s) == ' ' || *(p->s) == '\t')
		{
			p->s++;
			continue;
		}
		if (isdigit(*(p->s)) || isalpha(*(p->s)))
		{
			while (isdigit(*(p->s)) || isalpha(*(p->s)))
			{
				*(p->t) = *(p->s);
				p->s++;
				p->t++;
			}
		}
		if (*(p->s) == '(')
		{
			push(p, *(p->s));
			p->s++;
		}

		if (*(p->s) == '*' || *(p->s) == '+' || *(p->s) == '/' || *(p->s) == '%' || *(p->s) == '-' || *(p->s) == '$')
		{
			if (p->top != -1)	// top initialized to -1 first
			{
				opr = pop(p);	// opr = operator = A, B, C , ....a, b,c.... 1,2,3......
				while (priority(opr) >= priority(*(p->s)))
				{
					*(p->t) = opr;
					p->t++;
					opr = pop(p);
				}
				push(p, opr);
				push(p, *(p->s));
			}
			else
				push(p, *(p->s));
			p->s++;
		}

		if (*(p->s) == ')')
		{
			opr = pop(p);
			while ((opr) != '(')
			{
				*(p->t) = opr;
				p->t++;
				opr = pop(p);
			}
			p->s++;
		}
	}

	while (p->top != -1)
	{
		char opr = pop(p);
		*(p->t) = opr;
		p->t++;
	}

	*(p->t) = '\0';
}

/* returns the priority of an operator */
int priority(char c)
{
	if (c == '$')
		return 3;
	if (c == '*' || c == '/' || c == '%')
		return 2;
	else
	{
		if (c == '+' || c == '-')
			return 1;
		else return 0;
	}
}

/* displays the postfix form of given expr. */
void show(struct infix p)
{
	printf(" %s", p.target);
}
