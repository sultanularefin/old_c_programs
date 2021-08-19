#include<stdio.h>
int getnum(void);
using namespace std;
 int main(void){


int i=getnum();

// convert to binary.
int  array[10];
int count=0;
do{
    array[count]=i%2;
    i=i/2;
    count++;
}while(i);
count--;
while(count>=0){printf( " % d",array[count]);
count--;
    }
 }

int getnum(void){
    int val,c;
    val=0;
    c=getchar();
    while(c!='\n'){
    val=10*val+c-'0';
    c=getchar();
    }
return val;
}

