#include<iostream>
#include<cstring>
using namespace std;


void strto__k();
int main()

{
	strto__k();
	
	return 0;
}

void strto__k()
{
	 
	
	char s[100];
	char str[100];
	
	gets(str);
	
	sprintf(s,str);
	int a=strlen(s);
	// number of spaces
	int i=0;
	while(a!=-1){
		if(str[a] ==' ') i++;
		a--;
	}
	printf("%d",i);
	char *x[i];
	
	cin>>left;
	for(int j=0;j<i;j++)	{
	
		sscanf(s,"%s ",x[i]);
	printf(" %s",x[i] );
		}
	while(a!=-1){
		putchar(s[a]);
		a--;
	}
}
