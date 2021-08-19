#include<stdio.h>

char *f1(char *s);

int main(void)

    {
    char s1[]="my name is sultanul arefin, one of my friends name is similar.";

    char *p;
    p=f1(s1);


    printf("\n");
    printf("\n");
    printf("\n");
    if(p) printf("\n\n%s",p);

    else printf("\n\n\nNULL");

    printf("\n");
    printf("\n");
    printf("\n");

 return 0;
    }



char *f1(char *s)

{   int i;
    i=0;
    while(s[i])     // loops until null character of string is  found.
    {
        printf("__\n");
        i++;
        if(i==6) break;
    }
    char *p;
    p=&s[i];


    printf("\n");
    printf('\0');
    printf(p);
    int j=0;
    char str[100];
    while(*p)
    {
        str[j]=*p;
        j++;
        p++;
    }
    str[j]='\0';
    printf("\n");
    printf(str);
    char *w;
    w=&str[0];
    printf("\n");
    printf(w);

    /*
    while(p[i])                 // not possible garbage value comes.
    {   printf("%c",p[i]);
        i+1;
    }
*/
    return &s[6];  // look how string is passed/
                    //"e is sultanul arefin, one of my friends name is similar."

}
