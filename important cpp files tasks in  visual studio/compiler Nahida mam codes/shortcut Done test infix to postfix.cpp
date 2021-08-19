
#include <stdio.h>
#include <stack>
#include <conio.h>
#include <cctype>

using namespace std;

#define MAX 50
char target[MAX];
stack <char> st; 
void convert(char given[MAX]);
int priority(char c);

int main()
{
	char expr[MAX];
	
	printf("\nEnter an expression in infix form: ");
	gets(expr);
	printf("sending to convert function");
	convert(expr);

	printf("\nThe postfix expression is: ");
	printf(" %s", target);
	getch();
	return 0;
}

void convert(char given[MAX])
{
	char opr;
	int i=0;
	int j = 0;
	
	while (given[i])// while at address p-> s is true, meaning if it contains something
	{
		if ((given[i]) == ' ' || given[i] == '\t')
		{
			i++;
			continue;
		}
		if ((isdigit(given[i])) || isalpha(given[i]))
		{
			while (isdigit(given[i]) || isalpha(given[i]))
			{
				target[j] = given[i];
				i++;
				j++;
			}
		}
		

		if ((given[i]) == '*' || (given[i]) == '+' || (given[i]) == '/' || (given[i]) == '%' || (given[i]) == '-' )
		{
			if (!st.empty())	// top initialized to -1 first
			{
				opr = st.top();
				
				 	// opr = operator = A, B, C , ....a, b,c.... 1,2,3......
				
				while (priority(opr) >= priority((given[i])))/* NOT EXECUTE IF given[i] 's priority is greater than priority(opr).
																for that case given[i] will be poped.			*/
				{
					target[j] = opr;
					j++;	
					st.pop();
					break;
				}
				
				st.push(given[i]);
							
			}
			else
				st.push(given[i]);

			i++; //this i++ is not part of the else statement.		
		}
	}

	while (!st.empty())
	{
		
		char opr = st.top();
		st.pop();
		target[j] = opr;
		j++;
	}

	target[j] = '\0';
}

/* returns the priority of an operator */
int priority(char c)
{
	
	if (c == '*' || c == '/' || c == '%')
		return 2;
	else
	{
		if (c == '+' || c == '-')
			return 1;
		else return 0;
	}
}


