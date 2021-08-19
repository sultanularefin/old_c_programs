#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(void)

{

    char *p;
    char s1[100]="hello, there how are you";

    p = strtok(s1, ",");
    printf("%s\n",p);

    do{
        p=strtok('\0', ", ");
        if(p) printf("| %s", p);
    }while(p);

	getch();
    return 0;

}
