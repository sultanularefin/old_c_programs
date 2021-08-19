#include <string.h>
#include <stdio.h>

int main( void )
    {
   char string[] = "cabbacaaaraaaa";
   int  result;
   result = strspn( string, "abc" );
   printf( "The portion of '%s' containing only a, b, or c "
           "is %d bytes long\n", string, result );
    }

/*
Output
The portion of 'cabbage' containing only a, b, or c is 5 bytes long
*/
