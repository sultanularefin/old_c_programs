#include<stdio.h>
#include <string.h>


int main()
{
	char *a;
	char str[10];
	gets(str);
	strlen(str);
	a=str+5;
	
	printf("%s",a);
	
	a= a-5;
	
	printf("\n");
	printf("%s",a);
	return 0;
	
}
