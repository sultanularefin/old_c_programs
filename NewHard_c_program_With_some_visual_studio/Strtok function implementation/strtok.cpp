#include<stdio.h>

#include<string.h>

int main(void)
{
    char *p;
    char s[100]="The summer soldier, the sunshine patriot.";

    p=strtok(s , " e");

    printf(p);
    do{

        p=strtok('\0'," ");
        if(p)printf("|%s",p);

        }while(p);
        printf("\n\n");





    return 0;
}


/*The|summer|soldier|the|sunshine|patriot


Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.

*/
