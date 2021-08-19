#include<stdio.h>

int  main()

{
    int i;
    char str1[100];
    char str2[20];
    gets(str1);
    gets(str2);


    char *s2;
    s2=str2;
    for(i=0;str1[i];i++)
    {


            while(str1[i]==*s2) {
            i++;
            s2++;
            }
            if(*s2=='\0')
                                {
                            printf("%s  found",str2);
                            return 0;
                            }

        }

                 printf("not found\n");
                    return 0;



}

