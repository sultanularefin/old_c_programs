#include<stdio.h>
#include<string.h>
int main(void) {

char str[15];
char bigstr[40]="";
printf("%d\n",strlen(bigstr));
printf("%d\n",sizeof(bigstr));
for(;;){
printf("\n");
gets(str);
     if((strlen(bigstr)+strlen(str))>=40) break;
     else if(!strcmp(str,"quit"))  break;
     strcat(str,"\n");


    (strcat(bigstr, str));


}
printf("\t\tbigstr==> %s",bigstr);


printf("\n");


}
