#include <conio.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
#include <cctype>

using namespace std;

#define MAX 50
stack <string> st;
stack <char>stchar;
						// stores operands  a , b , c , 1, 2, 3 ,....
int main()
{
	char prefix[MAX], ch, str[MAX], opr[MAX];
	string strnew;
	string opnd22, opnd11;
	int i = 0, opndcnt = 0;	// opndcnt = operand count
	printf("Enter prefix expression to convert it to infix: ");
	gets(prefix);

	printf(" Given Prefix Expression : %s\n", prefix);
	while ((ch = prefix[i++]) != '\0')
	{
		if (isalnum(ch))	// works for both alphabetic and digit chacracters
			//	checks to see if it is alphabetic character or not ?
		{
			str[0] = ch; str[1] = '\0';

			st.push(str);
						 opndcnt++;		// increment operand count  a , b , c , 1 ,2, ...
			if (opndcnt >= 2)
			{
				 opnd22 = st.top();
				st.pop();
				 opnd11 = st.top();
												// opnd2 = operand number 2 
				st.pop();						// opnd1 = operand number 1
				strnew = "(";
				strnew = strnew + opnd11;
				ch = stchar.top();
				stchar.pop();

				opr[0] = ch; opr[1] = '\0';		// opr[2] is a 2 index array
				strnew = strnew + opr;
				strnew = strnew + opnd22;
				
				strnew = strnew + ")";
				st.push(strnew);

						//EACH REFURNISHED STR is sent back to the 2 dimensional
				// opnds character array. 
				opndcnt =opndcnt - 1;	//again in initial value of opndcnt = -1 assigned
			}
		}
		else
		{
			stchar.push(ch);
						// pushes operator 
			// opndcnt = operand count.
			if (opndcnt == 1)opndcnt = 0;  /* operator followed by single operand*/
			// operator comes after single operand
		}
	}

	if (!st.empty())			//returns 1 / true if value of  topd = "top operand"  == 0   
	{
		// now if opnd count == more than 1  then it just put the whole pushed string into one single string
		strnew ="\0";
		opnd22= st.top();
		st.pop();
		opnd11 = st.top();
		st.pop();

		strnew = strnew + "(";	
		strnew = strnew + opnd11;		
		ch = stchar.top();
		stchar.pop();
		
		opr[0] = ch;
		opr[1] = '\0';
	
		strnew = strnew + opr;
		strnew = strnew + opnd22;
		strnew = strnew + ")";

		// just a final touch to  put the whole thing in 1 str.
	}

	printf(" Infix Expression: ");

	cout << strnew;

	getch();
	return 0;
}
