#include<stdio.h>
#include<ctype.h>

int mystrcmp(char *s1,char *s2);
main()

{
    char str1[100];
    char str2[100];
    gets(str1);
    gets(str2);
    int m;


    if  (mystrcmp(str1,str2)) printf("they are lexicographically equal\n\n");

    else printf("not equal\n\n");
}

int mystrcmp(char *s1,char *s2)
{
while(*s1!='\n' && *s2!='\n')
    {
     if(*s1==*s2)
        s1++;
        s2++;
      mystrcmp(*s1,*s2);
}
  return 1;
}
/*
char a1,a2;
    a1=toupper(*s1);
    a2=toupper(*s2);
    if(a1!=a2) return 0;
    s1++;
    s2++;
    */
