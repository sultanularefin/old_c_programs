#include<stdio.h>
size_t mystrlen(char *p);
main()

{
    int j;
    char str1[100];
    gets(str1);
    j=mystrlen(str1);
    printf("%d",j);
}
size_t mystrlen(char *p)
{
    int i=0;

     while(*p)
    {
        p++;
        i++;
    }
return i;
}
