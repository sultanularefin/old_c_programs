#include<stdio.h>
#include<conio.h>
char * mystrstr(char *s1,char *s2);
main()
{
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    char *p;
    p=mystrstr(s1,s2);
    printf("\n");
    if(p) printf(p);
    else printf("NULL");

}

char * mystrstr(char *str1,char *str2)
{
    int i;
   for(int x=0;str1[x];x++) {


    i=x;
        while(*(str1+x)==*str2)
            {
                x++;
                str2++;
            }
            if(!(*str2)) return (str1+i);

   x=i;

   }


 return NULL;

 }

