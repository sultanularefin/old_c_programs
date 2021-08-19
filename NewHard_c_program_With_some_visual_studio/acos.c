#include<stdio.h>
#include<math.h>
#include<conio.h>
int main(void){
double val=-1.0;
do{
    printf("\t\n arc cosine of %f is   %.4f   ",val,acos(val));
    val+=0.1;

    }while(val<=1.0);
    getch();
    return 0;


}
