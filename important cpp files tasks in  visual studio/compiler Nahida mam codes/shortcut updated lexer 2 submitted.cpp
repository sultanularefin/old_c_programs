#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <conio.h>
#include <cctype>
#include <stdlib.h>

using namespace std;
int matheop = 0;
string showmathop[10];
string showpunc[10];
int punc = 0;

bool keycheck(string str)
{
	string keyword[] = { "auto", "bool", "break", "case", "char", "const", "continue", "default", "int" };
	//total = 60 , 0-59.
	bool flag = false;
	
	for (int i = 0; i<9; i++)
	{
		if (str == keyword[i])
		{
			flag = true;
			break;	// break causes it to break the for loop
		}
	}
	return flag;
}

int opcheck(string str)
{
	string reloperators[8] = { "==", ">", "<", ">=", "<=" };
	string mathoperators[6] = { "+", "*", "/", "-", "%", "=" };
	string operators[2] = { ";", "," };
	int relationalflag = 0, matheflag = 0, puncflag = 0;

	for (int i = 0; i<2; i++)
	{
		if (str == operators[i])
		{
			showpunc[punc] = str;
			punc++;
			puncflag = 1;

			break;
		}
	}
	if (puncflag == 1)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i<7; i++)
		{
			if (str == reloperators[i])
			{
				relationalflag = 1;
				break;
			}
		}
		if (relationalflag == 1)
		{
			return 1;
		}
		else
		{
			for (int i = 0; i<6; i++)
			{
				if (str == mathoperators[i])
				{
					showmathop[matheop] = str;
					matheop++;
					matheflag = 1;
					break;
				}
			}
			if (matheflag == 1)
				return 1;
			else
				return 0;
		}
	}
}

int isnums(string str)
{
	int flag = 0;
	for (int i = 0; i < str.length(); i++)		// suppose if test case is 525 then it will not even exucute once the the if (!isnum(str[i]) loop.
	{
		if (!isdigit(str[i]))
		{
			if (str[i] != '.')
			{
				flag = 1;  // flag =1 means not point '.'. meaning something else thus not digit.
				break;
			}
		}
	}
		
	if (flag == 1)
		return 0;
	else
		return 1;
}

int main()
{
	int digits;
	int j;

	string showidentifier[10];
	string showkeyword[10];
	string shownumber[10];

	ifstream ifs("input.txt");

	//	ofstream ofs("output.txt");
	int line = 0, flag = 0;
	bool check;
	string str = "", strch, strline;
	int keyword = 0;
	int identifier = 0;
	int number = 0;
	int spacetab = 0;
	// strch , strline are string type objects initialezed to Null / "".
	while (!ifs.eof())
	{
		getline(ifs, strline);	// c++ 11 version , where you will find new methods of getline function.
		line++;	// counts line numbers.

		strline = strline + " ";

		for ( j = 0; j<strline.length(); j++)
		{
			if (strline[j] == ' ' || strline[j] == '\t')
			{
				//' ' = ascii 32 == spcae.
			

				if (str != "")	//meaning str have contents.
				{
					if (isalpha(str[0]))
					
					{
						check = keycheck(str);

						if (check)
						{
							showkeyword[keyword] = str;
							keyword++;
						}
						else 
						{
							
							
								showidentifier[identifier] = str;
								identifier++;
						}
						
					}


					if (isnums(str)){
						shownumber[number] = str;
						number++;
					}

					else
					{
						int a;
						a = opcheck(str);
						if (a==0)
						spacetab++;
											
					}
				}
				str = "";
			}
			else
			{
				str = str + strline[j];
			}
		}
	}
	//cout << "output file is generated : output.txt";

	printf("\n input.txt is the file from where contents are read.\n\n");
	cout.width(35);
	cout << " Keyword: (" << keyword << ")";
	cout.width(10);
	for (int i = 0; i < keyword; i++)
		cout << " " << showkeyword[i];
	cout << "\n\n";
	cout.width(35);
	cout << " IDENTIFIER: (" << identifier << ")";
	cout.width(10);
	for (int i = 0; i < identifier; i++)
		cout << " " << showidentifier[i];
	cout << "\n\n";
	cout.width(35);
	cout << " Constant: (" << number << ")";
	cout.width(10);
	for (int i = 0; i < number; i++)
		cout << " " << shownumber[i];
	cout << "\n\n";
	cout.width(35);
	cout << " matheoperator: (" << matheop << ")";
	cout.width(10);
	for (int i = 0; i < matheop; i++)
		cout << " " << showmathop[i];
	cout << "\n\n";
	cout.width(35);
	cout << " punctuation: (" << punc << ")";
	cout.width(10);
	for (int i = 0; i < punc; i++)
		cout << " " << showpunc[i];

	cout.width(10);
	cout << "\n\n" <<"Space tab character count =" << spacetab;
	cout << "\n\n";
	//getch();
	return 0;
}
