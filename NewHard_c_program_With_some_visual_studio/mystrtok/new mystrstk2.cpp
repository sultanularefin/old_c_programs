#include<stdio.h>


char * mystrtok(char * str,const char * delimiter);

int main(void)  {
char a[]="my name is sultanul arefin, one of my friend's name is similar to mine.";
char *token;
token=mystrtok(a," ,");
printf("Token is ==> %s\n",token);
while(token) {
    token=mystrtok(NULL," ,");
    if(token)    printf("Token is ==>  %s\n",token);
        else printf("NULL\n");

    }



printf("\n\n\n");
return 0;

}


char * mystrtok(char * str,const char * delimiter)

{
            static char *s;

            if(str)
            {
              int j=0;
              char *p ;
              p=&str[0];
              s=&str[0];
               while (str[j])
        {

            for(int i=0;delimiter[i];i++)
            {
                if(str[j]  == delimiter[i])
                 {
                 str[j]='\0';
                 ++j;
                 s=&str[j];

                 return p;
                }

            }
            j++;

        }

            }

      if(!str)   //else //if
    {
        int j=0;
        char *p;
        char str1[100];
        while(*s)
    {
        str1[j]=*s;
        j++;
        s++;
    }
    str1[j]='\0';
    p=&str1[0];

    j=0;


    while (str1[j])
        {

            for(int i=0;delimiter[i];i++)
            {
                if(str1[j]  == delimiter[i])
                 {
                 str1[j]='\0';
                 ++j;
                 s=&str1[j];

                 return p;
                }

            }
            j++;

        }

    }

 return NULL;
}
