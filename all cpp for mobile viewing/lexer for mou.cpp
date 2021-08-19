#include "stdafx.h"
#include<iostream>
#include <cctype>
#include<string>
#include <stdio.h>
//#include <conio.h>


using namespace std;

int iskeyword(string str)
{
	string key[] = { "char", "double", "else", "float", "for", "goto", "if", "int", "void", "while", "private", "protected", "public" };
	int flag = 0;
	int i = 0;
	while (i < 12)
	{
		if (str == key[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	return flag;
}

int isnums(string str)
{
	
	str.c_str();		// converts string str to character string.

	/*
	std::string str ("Please split this sentence into tokens");

  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str
	*/
	
	int flag = 0;
	int i = 0;
	
	while (i < str.length()){
		
		if (isdigit(str[i]))
		flag = 1;

		else flag = 0;

		i++;
	}
	return flag;
}

int main()
{
	string token[20];
	string klist[5];
	string conlist[5];
	int cons = 0;
	int check;
	string str = "", strch, strline;
	int keyword = 0;
	int tok = 0;
	char str1[80];
	cin.getline(str1, 80);
	char *p;

	p = strtok(str1, "\n ");
	
	puts("\n");

	do {
		if (p)
		str = string(p);
		token[tok] = str;
		tok++;
		p = strtok(NULL, ", ");
				
	} while (p != NULL);
	for (int t = 0; t < tok; t++)
		cout << " " << token[t];


	for (int t = 0; t < tok; t++)
	{
		str = token[t]; // puts each token in str for checking.


		if ((check = iskeyword(str)) == 1){
			klist[keyword] = str;
			keyword++;
		}

		else 

		if (check = isnums(str)){
			conlist[cons] = str;
			cons++;
		}

		
	}
	cout << "\n";

	cout << " Keyword: ";
	for (int i = 0; i < keyword; i++)
		cout << klist[i];

	cout << "\n";

	cout << " constant: ";
	for (int i = 0; i < cons; i++)
		cout  << conlist[i];
	
	return 0;
}

