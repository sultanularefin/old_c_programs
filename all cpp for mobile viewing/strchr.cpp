#include<stdio.h>
#include<string.h>
main()

{
    char *p;
    p=strchr("This is a test ",'t');

    printf(p);
    if(p==NULL) printf("p==> NULL");
    /*
    while(*p){
    printf("%c",*p);
    p++;
    }
    */
}
