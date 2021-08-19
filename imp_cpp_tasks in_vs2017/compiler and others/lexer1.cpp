#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#include "stdafx.h"

using namespace std;
struct pgm
{
	char line[20];
} s[100];
void check(char s[])
{
	cout << "\n";
	if (!_strcmpi(s, "If"))
	{
		cout << "keyword:If";
		return;
	}
	if (!_strcmpi(s, "Then"))
	{
		cout << "keyword:Then";
		return;
	}
	if (!_strcmpi(s, "Else"))
	{
		cout << "keyword:else";
		return;
	}
	if (!_strcmpi(s, "[END]"))
	{
		return;
	}
	cout << "expression:" << s;
}
int main()
{
	char t[20];
	int i = 0, j = 0, k = 0;
	
	cout << "\n\n enter the program code:(to stop input type End)\n";
	do
	{
		gets(s[i].line);
	} while (_strcmpi(s[i++].line, "END"));
	k = k - 1;
	do
	{
		k++;
		for (i = 0; s[k].line[i] != '\0'; i++, j++)
		{
			if (s[k].line[i] == ' ')
			{
				t[j] = '\0';
				j = -1;
				check(t);
			}
			else
				t[j] = s[k].line[i];
		}
		t[j] = '\0';
		j = 0;
		check(t);
	} while (_strcmpi(s[k].line, "END"));

	return 0;
}