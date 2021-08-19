#include<stdio.h>


main() {
    char  array[10];
    int count=0;
    int input;
    int j;
    scanf("%d",&input);


        do{
        j=0;
        j=(input%16);
        input=  input/16;


        if(j==10) j='A';
        if(j==11) j='B';
        if(j==12) j='C';
        if(j==13) j='D';
        if(j==14) j='E';
        if(j==15) j='F';

        array[count]=j;
        count++;



    }while(input!=0);
    count--;

    while(count>=0){
     if(array[count]<10) printf(" %d ",array[count]);
     else printf(" %c",array[count]);

        count--;
    }
}
