#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

char opnds[50][80], oprs[50];		// opnds stores string of operands .    oprs stores operators.
int  topr = -1, topd = -1;

void pushd(char *opnd)			// stores operands  a , b , c , 1, 2, 3 ,....
{
	strcpy(opnds[++topd], opnd);
}
char *popd()
{
	return(opnds[topd--]);
}

void pushr(char opr)		// stores operands  - , + , * , / .....
{
	oprs[++topr] = opr;
}
char popr()
{
	return(oprs[topr--]);
}
int empty(int t)
{
	if (t == 0) return(1);
	return(0);
}

int main()
{
	char prfx[50], ch, str[50], opnd1[50], opnd2[50], opr[3];
	
	int i = 0, k = 0, opndcnt = 0;	// opndcnt = operand count
	
	gets(prfx);

	printf(" Given Prefix Expression : %s\n", prfx);
	while ((ch = prfx[i++]) != '\0')
	{
		if (isalnum(ch))	// works for both alphabetic and digit chacracters
					//	checks to see if it is alphabetic character or not ?
		{
			str[0] = ch; str[1] = '\0';
			pushd(str); opndcnt++;		// increment operand count  a , b , c , 1 ,2, ...
			if (opndcnt >= 2)
			{
				strcpy(opnd2, popd());		// opnd2 = operand number 2 
				strcpy(opnd1, popd());			// opnd1 = operand number 1
				strcpy(str, "(");
				strcat(str, opnd1);
				ch = popr();
				opr[0] = ch; opr[1] = '\0';		// opr[2] is a 2 index array
				strcat(str, opr);
				strcat(str, opnd2);
				strcat(str, ")");
				
				pushd(str);			//EACH REFURNISHED STR is sent back to the 2 dimensional
				// opnds character array. 
				opndcnt -= 1;	//again in initial value of opndcnt = -1 assigned
			}
		}
		else
		{
			pushr(ch);			// pushes operator 
											// opndcnt = operand count.
			if (opndcnt == 1)opndcnt = 0;  /* operator followed by single operand*/
											// operator comes after single operand
		}
	}
	if (!empty(topd))			//returns 1 / true if value of  topd = "top operand"  == 0   
	{
		// now if opnd count == more than 1  then it just put the whole pushed string into one single string
		strcpy(opnd2, popd());		
		strcpy(opnd1, popd());
		strcpy(str, "(");
		strcat(str, opnd1);
		ch = popr();
		opr[0] = ch;
		if(ch = popr())
		opr[1] = ch;
		opr[2] = '\n';
		strcat(str, opr);
		strcat(str, opnd2);
		strcat(str, ")");
		pushd(str);			// just a final touch to  put the whole thing in 1 str.
	}
	printf(" Infix Expression: ");
	puts(opnds[topd]); //in opnds array you will find the complete infix arrya which is
	//updated throughout the program execution

	return 0;
}
