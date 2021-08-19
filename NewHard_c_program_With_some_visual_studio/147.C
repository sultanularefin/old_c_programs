#include <string.h>

#include <stdio.h>
#include <conio.h>

int main(void)
{
 char str[80];


 strcpy(str,"");
 printf(str);

 strcat(str, "there");
 printf(str);

 getch();
 return 0;
}
