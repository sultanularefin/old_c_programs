#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(void)

{

    char *p;
    char a[100]="The summer soldier, the sunshine patriot,amar nam arefin ,sultan";
    p = strtok(a, ",");
    printf("%s\n",p);

    do{
        p=strtok('\0', ",");
        if(p) printf("\n| %s", p);
    }while(p);

    return 0;

}
