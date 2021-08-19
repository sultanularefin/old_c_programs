#include<stdio.h>
#include<iostream>
using namespace std;
 int main(void){
int num;
int i=getnum();
// convert to binary.
int array[5];
int count=0;
do{array[count]=num%2;
    i=i/2;
    count++;
}while(i);
count--;
while(count>=0)printf( " %d  ",array[count]);

}

