#include<stdio.h>
#include<string.h>

main()

{
    char str1[100];
    char str2[80];
    char str3[500];
    int i,j;
    gets(str1);
    gets(str2);
    for( i=0;str1[i];i++)
        (str3[i]=str1[i]);

    for( j=0;str2[j];j++)
        {
        (str3[i]=str2[j]);
           i++;
    }
    str3[i]='\0';
    printf("%s",str3);

}
