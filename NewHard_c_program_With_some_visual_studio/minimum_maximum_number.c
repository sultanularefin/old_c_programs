#include<stdio.h>

main(){

int min,max;
min=10;
max=-127;
int count;
printf("%s","count:");
scanf("%d",&count);
int a[count];
int i;

for(i=0;i<count;i++)
scanf("%d",&a[i]);


    for(i=0;i<count;i++){

    if(a[i]<min)
      min=a[i];
      if(a[i]>max)max=a[i];

    }
    printf("\n\nmin =>%d max =>%d",min,max);
}
