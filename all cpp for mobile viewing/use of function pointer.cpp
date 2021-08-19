#include<stdio.h>
#include<string.h>
#include<ctype.h>
void check(char *a,char *b,
          int (*cmp)(const char *,const char *));
check(s1,s2,numcmp);

main()
{
    char s1[80],s2[80];
    gets(s1);
    gets(s2);
    if(isalpha(*s1))

    check(s1,s2,strcmp);
    else check(s1,s2,numcmp);
    return 0;


}

void check(char *a,char *b,
          int (*cmp)(const char *,const char *))

           {
               printf("Testing for equality.\n");

               if(!(*cmp)(a,b)) printf("Equal"); //HERE CMP IS a FUNCTION POINTER NOT THE
                                                    //THE NAME OF a FUNCTION
               else printf("Not equal");



           }

int numcmp(const char *a,const char *b)

{
    if(atoi(a)==atoi(b)) return 0;
    else return 1;
}
