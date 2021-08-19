#include <stdio.h>
#include <stdlib.h>

/*
* To print an int in binary, hex, decimal,
* we build an array of characters and print it out
* in order.
* The values are found least significant digit first,
* and printed most significant digit first.
*/
#define NDIG    32      /* assume max no. of digits */

int getnum(void);

main(){
   int val, i, count;
   char chars[NDIG];

   i = getnum();

   /* print in binary */
   val = i;
   count = 0;
   do{
      chars[count] = val % 2;
      val = val / 2;
      count = count + 1;
   }while(val);
   count = count - 1; /* just incremented above */

   while(count >= 0){
      printf("%d", chars[count]);
      count = count - 1;
   }
   printf("\n");

   /* print in decimal */
   val = i;
   count = 0;
   do{
      chars[count] = val % 10;
      val = val / 10;
      count = count + 1;
   }while(val);
   count = count - 1; /* just incremented above */

   while(count >= 0){
      printf("%d", chars[count]);
      count = count - 1;
   }
   printf("\n");

   /* print in hex */
   val = i;
   count = 0;
   do{
      chars[count] = val % 16;
      val = val / 16;
      count = count + 1;
   }while(val);
   count = count - 1; /* just incremented above */

   while(count >= 0){
      if(chars[count] < 10)
         printf("%d", chars[count]);
      else{
         /* assume 'A' - 'F' consecutive */
         chars[count] = chars[count]-10+'A';
         printf("%c", chars[count]);
      }
      count = count - 1;
   }
   printf("\n");
   exit(EXIT_SUCCESS);
}

int getnum(){
   int c, value;;

   value = 0;
   c = getchar();
   while(c != '\n'){
      value = 10*value + c - '0';   ; c = int getchar() suppose c =5 =53 -'0' =53-48 =5
      c = getchar();
   }
   return (value);
}
