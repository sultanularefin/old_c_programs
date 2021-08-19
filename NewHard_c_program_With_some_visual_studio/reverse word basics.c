#include<stdio.h>
#include<string.h>

int main()

{
	
	char str[100] ;
	
	*str =0;
	if(str)
	printf("%s",str);
	if(!*str) printf("str is blank");
	
	
	return 0;
}

