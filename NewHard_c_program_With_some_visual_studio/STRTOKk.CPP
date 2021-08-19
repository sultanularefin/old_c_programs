
#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
   char input[36] = "abc,drasdf,asdfsd,asdfasdf";
   char *p;

   /* strtok places a NULL terminator
   in front of the token, if found */
   p = strtok(input, ",");      //prints        abc
   if (p)   printf("%s\n", p);

   /* A second call to strtok using a NULL
   as the first parameter returns a pointer
   to the character following the token  */


    while(p){
   p = strtok(NULL, ",");
      printf("%s\n", p);

    }

   getch();
   return 0;
}
