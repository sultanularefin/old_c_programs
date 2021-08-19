#include<stdio.h>
#include<conio.h>
char * mystrchar(char *s1,char ch);
main()
{
    char s1[100];
    char c;
    gets(s1);
    c = getche();
    char *p;
    p=mystrchar(s1,c);
    printf("\n");
    printf(p);


}

char * mystrchar(char *s1,char ch)
{


    int i=-1;
    do{ i++;
        if(*(s1+i)==ch)
            return (s1+i);

    }while (*(s1+i)!='ch' && *(s1+i)!='\0');    /*here && ==> short circuit and
                                                it means that only if one condition is
                                                satisfied then do loop will exit */

 return NULL;

 }
