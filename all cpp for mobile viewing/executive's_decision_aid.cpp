#include<stdio.h>

#include<string.h>

int main( void)

{
    char *p[3]={"Yes",
    "NO",
    "would you mind to ask the Question again"
    };
    char str[80];
    printf("What is your question?  ");
    gets(str);

   // int index;
   // index=strlen(str)%3;
   // printf("Answer is :");
    //printf(p[index]);
    printf(p[strlen(str)%3]);




}
