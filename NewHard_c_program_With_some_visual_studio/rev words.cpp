#include <cstdio>
#include <iostream>
#include<cstring>
using namespace std;
	void reverse(char *str)
	{
	int len = strlen(str);
	int I =0;
	char *start=str, * end= str+len-1;
		while(end>=start)
		{
		
		char temp = *start;
		
		*start = *end;
		
		*end=temp;
		
		start++;
		
		end--;
		}
	char * pch;
	pch = strtok (str," ,.-");
	while (pch!= NULL)
 		{

			//printf ("%sn", pch).
			
			int l = strlen(pch);
			
			char *a=pch,*b= pch+l-1;

		while(b>=a)
		{
		
		char temp = *a;
		
		*a = *b;
		
		*b=temp;
		
		a++;
		
		b--;
		}

    	 printf ("%s ", pch);

  	 pch = strtok (NULL, " ,.-");
  }

 }

	int main()
	{
	char a[] = " I like this program very much ";
	reverse(a);
	getchar();
	return 0;
	}
