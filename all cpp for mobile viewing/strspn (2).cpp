#include<string.h>
#include<stdio.h>

int main(void)
{
  char string[]="7803 Elm St.";

  printf("The number length is %d.\n",strspn(string,"1234"
            "567890"));
  return 0;
}
