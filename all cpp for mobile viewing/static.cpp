#include<stdio.h>
int f1(void);
static int p=0;
int main(void) {


    for(int i=0;i<10;i++){
    f1();
    }

    printf("From main p is %d ",p);
return 0;
}



int f1(void)
{



    printf("\np is now ==>%d",p);
    p=p+5;
}
