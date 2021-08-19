#include <stdio.h>
#include <ctype.h>


int main()
{

char ch;
scanf("%c",&ch);
int a;

a=isalpha(ch);

int b;
b=isalnum(ch);
printf("b :%d",b);

printf("a: %d",a);

return 0;

}
