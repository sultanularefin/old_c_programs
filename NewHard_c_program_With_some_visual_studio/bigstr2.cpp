#include<stdio.h>
#include<string.h>
int main(void) {

char bigstr [40]="";
char str [10];
for(;;) {
    printf("Enter a string: ");
    gets(str);
    if(!strcmp(str,"quit"))break;
    strcat(str,"\n");
    /* prevent an array overrun */
    if(strlen(bigstr)+strlen(str)>=40) break;
    strcat(bigstr,str);

}
printf(bigstr);

    }
