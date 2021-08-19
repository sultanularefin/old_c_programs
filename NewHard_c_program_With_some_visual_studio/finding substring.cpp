#include<stdio.h>

 main()

{
    int i;
    char str1[100];
    char str2[20];
    gets(str1);
    gets(str2);


    char *s2;
  //  s2=str2;
    int j=0;
    for(i=0;str1[i];i++)
    {
        s2=str2;


            while(str1[i]==*s2) {
            i++;
            s2++;
            }
            if(*s2=='\0')
                                {j++;




                                }

        }
 printf("%s  found %d time",str2,j );
return 0 ;


}
