// myStrTok  P.Conrad for CISC220,06J

// This is a sample implementation of strtok to illustrate the use
// of pointers, and a static variable inside a function.


// I Robot,2004,Will Smith,120000000,144795350
//   or
// Will Smith,Willard Christopher Smith, Jr.,09/25/1968,Philadelphia, PA


#ifndef NULL
#define NULL 0
#endif

#include <cassert>

#include "myStrTok.h"

char * myStrTok(char * s1, char delimit)
{
  static char * whereILeftOff = NULL;
  
  char *start;
  
  if (s1 == NULL)
    start = whereILeftOff;
  else
    start = s1;
  
  char *p = start;
  
  while (*p != '\0' && *p != delimit )
    {
      p++;
    }
  
  if (*p == '\0')
    {
      whereILeftOff = NULL;
      return start;
    }
  
  assert((*p)==delimit);
  
  (*p) = '\0';
  whereILeftOff = (p + 1);
  return start;
  
}
