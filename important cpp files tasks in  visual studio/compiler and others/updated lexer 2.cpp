#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
//#include <conio.h>
#include "stdafx.h"

using namespace std;
int matheop = 0;
string showmathop[10];
string showpunc[10];
int punc = 0;

/* The grammar follwed by this analyser is : you have to give a blank to differentite between two different entities, for eg
instead of writing "int c=a+b;", write it as "int c = a + b ;".

To execute this program first create an "input.txt" file where the program is written or specify the path of the file which has
to be analysed, after compiling you will see the result in your console.
*/

bool keycheck(string str)
{
	string keyword[] = { "auto", "bool", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "asm", "_ss", "interrupt", "_cs", "cdecl", "near", "_ds", "far", "pascal", "_es", "huge", "catch", "class", "delete", "friend", "inline", "new", "operator", "overload", "private", "protected", "public", "template", "this", "throw", "try", "virtual" };
	//total = 60 , 0-59.
	int flag = 0;
	if (!(str[0] >= 97 && str[0] <= 122))	// to see str[0] just expand the vs watch "str" then you will see str[0], str[1], str[2] .
		return false;
	for (int i = 0; i<59; i++)
	{
		if (str == keyword[i])
		{
			flag = 1;
			break;
		}
	}



	if (flag == 1)
		return true;
	else
		return false;
}

int opcheck(string str)
{
	string reloperators[8] = { "==", ">", "<", ">=", "<=" };
	string mathoperators[6] = { "+", "*", "/", "-", "%", "=" };
	string operators[2] = { ";", "," };
	int flag1 = 0, flag2 = 0, flag = 0;


	for (int i = 0; i<2; i++)
	{
		if (str == operators[i])
		{
			showpunc[punc] = str;
			punc++;
			flag = 1;

			break;
		}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{

		for (int i = 0; i<7; i++)
		{
			if (str == reloperators[i])
			{
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1)
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
					flag2 = 1;
					break;
				}
			}

			if (flag2 == 1)
				return 1;
			else
				return 0;
		}
	}
}

int ischar(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))	// 65 =A and 90 =Z , 97 = a and 122 = z
		return 1;
	else
		return 0;
}


int isnum(char c)
{
	if (c >= 48 && c <= 57)	//48 = 0 and 57 = a.
		return 1;
	else
		return 0;
}

int isnums(string str)
{
	int flag = 0;
	for (int i = 0; i<str.length(); i++)		// suppose if test case is 525 then it will not even exucute once the the if (!isnum(str[i]) loop.
	{
		if (!isnum(str[i]))
		{
			if (str[i] != 46)	//46 = .  point or dot
			{
				flag = 1;
				break;
			}
		}
	}

	if (flag == 1)
		return 0;
	else
		return 1;
}

int isidentifier(string str)
{
	int flag = 0;
	for (int i = 1; i<str.length(); i++)
	{
		if (!ischar(str[i]))
		{
			if (!isnum(str[i]))
			{
				if (str[i] != 95)	// 95 == underscore . '_'
				{
					if (str[i] == 91)	// 91 == [
					{
						i++;
						for (; str[i] != 93;)		// 93 ==  ]
						{
							if (!isnum(str[i]))
							{
								flag = 1;
								break;
							}
							i++;
						}
					}
					else
					{
						flag = 1;

					}

					if (flag == 1)
						break;
				}
			}
		}
	}

	return flag;
}

int main()
{
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


	// strch , strline are string type objects initialezed to Null / "".


	while (!ifs.eof())
	{

		getline(ifs, strline);	// c++ 11 version , where you will find new methods of getline function.
		line++;

		strline = strline + " ";
		for (int j = 0; j<strline.length(); j++)
		{
			if (strline[j] == ' ' || strline[j] == '\t')
			{
				//' ' = ascii 32 == spcae.

				if (str != "")	//meaning str have contents.
				{
					if (ischar(str[0]))
					{
						check = keycheck(str);

						if (check)
						{
							showkeyword[keyword] = str;
							keyword++;
						}
						else
						{

							flag = isidentifier(str);

							if (flag == 1)
							{
								("%s \t error", str);
								flag = 0;

							}
							else
							{
								showidentifier[identifier] = str;
								identifier++;

							}


						}
					}
					else
					{
						if (isnum(str[0]))
						{
							if (isnums(str))
							{

								shownumber[number] = str;
								number++;

							}
							else

								printf("ERROR");
						}
						else
						{
							int a;
							a = opcheck(str);
							if (a == 0)
								printf("ERROR\n");
						}
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

	cout << "\n\n";
//	getch();
	return 0;
}
