#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  char search_string[]="Woody Norm Cliff";
  char *array[50];
  int loop;

  array[0]=strtok(search_string," ");
  if(array[0]==NULL)
   {
    printf("No test to search.\n");
    exit(0);
   }

  for(loop=1;loop<50;loop++)
   {
    array[loop]=strtok(NULL," ");
    if(array[loop]==NULL)
      break;
   }

  for(loop=0;loop<50;loop++)
   {
    if(array[loop]==NULL)
      break;
    printf("Item #%d is %s.\n",loop,array[loop]);
   }

  return 0;
}
