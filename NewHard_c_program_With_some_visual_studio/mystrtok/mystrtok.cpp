#include<stdio.h>

char * mystrtok(char * str,const char * delimiter);

int main(void)  {
char a[]="my name is sultanul arefin, one of my friend's name is similar to my name.";
char *token;
token=mystrtok(a," ,");
printf("Token is ==> %s\n",token);
while(token) {
    token=mystrtok(NULL," ,");
    if(token)    printf("Token is ==>  %s\n",token);
   else printf("NULL\n");

    }

char b[]="mynamesarefin";
char c[]="Hello arefin";
//while(token)
   // {
   token=  mystrtok(b,"ie");
 if(token)    printf("Token is ==>  %s\n",token);
   else printf("NULL");
   token=  mystrtok(c,"w");
   if(token) printf("Token is ==>  %s\n",token);
    else printf("NULL");


   // }


printf("\n\n\n");
return 0;

}


char * mystrtok(char * str,const char * delimiter)

{


            int j=0;
            char *p ;


            static char *s;
            if(str==NULL) p=s;

            else
            p=&str[0];

            while (str[j])
        {

            for(int i=0;delimiter[i];i++)
            {
                if(str[j] == delimiter[i])
                 {
                 str[j]='\0';
                 ++j;
                 s=&str[j];
                 return p;
                }

            }
            j++;

        }

 return NULL;
}
