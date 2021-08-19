
#include<stdio.h>
#include<conio.h>

#define MAX(i,j) ((i)>(j)) ? (i):(j)
int main (void) {
    printf("%d\n",MAX(1,2));
    printf("%d\n",MAX(1,-1));
    // this statement does not work correctly. */
    printf("%d\n",MAX(100 && 5,0));


}
