
#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
   char input[36] = "abc,erasdfdfdfsdfadsfaerfsadfasdf";
   char *p;

   /* strtok places a NULL terminator
   in front of the token, if found */
   p = strtok(input, ",");      //prints        abc
   if (p)   printf("%s\n", p);

   /* A second call to strtok using a NULL
   as the first parameter returns a pointer
   to the character following the token  */


do{
   p = strtok(NULL, "\ads");
   if (p)   printf("%s\n", p);

}while(p);
   getch();
   return 0;
}
