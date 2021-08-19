
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(void)

{
	char s[100]="The summer soldier,the sunshine patriot";
    char *p;
    p = strtok(s," ");
    printf(p);

    do{
        p=strtok('\0', ", ");
        if(p) printf("| %s", p);
    }while(p);

    return 0;

}
