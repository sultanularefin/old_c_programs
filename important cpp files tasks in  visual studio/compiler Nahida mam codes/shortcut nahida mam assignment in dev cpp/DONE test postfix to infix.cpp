#include <cctype>
#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

#define MAX 50
string strnew;
stack <string> st;
void convert(char given[MAX]);

int main()
{
	char expr[MAX];

	printf("\nEnter an expression in postfix form: ");
	gets(expr);
	printf("sending to convert function");
	convert(expr);

	printf("\nThe infix expression is: ");

	cout << strnew;
	getch();
	return 0;
}

void convert(char given[MAX])
{
	char opr;
	int i = 0;
	int j = 0;
	char temp[6];
	string operand1, operand2;

	while (given[i])// while at address p-> s is true, meaning if it contains something
	{
		if ((given[i]) == ' ' || given[i] == '\t')
		{
			i++;
			continue;
		}

			
		if (given[i] == '%' || given[i] == '*' ||given[i] == '-' || given[i] == '+' ||given[i] == '/' )

			{
				strnew = '\0';
				operand1=st.top();
				st.pop();
				operand2 = st.top();
				st.pop();
													// in postfix expression after 2 variable you will find a operator.
													// thats why 2 pop operation
				temp[0]=given[i];
				temp[1] = '\0';
				strnew = strnew + operand2;
				strnew = strnew + temp;
				strnew = strnew + operand1;
				st.push(strnew);	
			}
			else   // this else stores operands , A,B,a,b, 1,2,3......
			{
				temp[0]=given[i];
				temp[1] = '\0';
				st.push(temp);			
				
			}
			i++;// this i always increments.
		}

		
		}




