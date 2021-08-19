#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define RANGE(i,min ,max) (i<min) || (i>max) ? 1 : 0

 main(void){

        int r;
        /* print random numbers between 1 and 100*/
        do{
            do{
        r=rand();


        }while(RANGE(r,1,100)); // do loop stops when the expression becomes falase
        printf("%d\n",r);

        }while(!kbhit());
        getch();

}

