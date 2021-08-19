#include<stdio.h>
#include<conio.h>

char * mystrtok(char * str,const char * delimiter);

int main(void)  {
char a[]="my name is sultanul arefin, one of my friend's name is similar to mine.";
//char a[100];
//gets(a);

printf("%d\n",sizeof(a));


char *token;

token=mystrtok(a," ,");
printf("Token is ==> %s\n",token);
while(token) {
    token=mystrtok(NULL," ,");
    if(token)    printf("Token is ==>  %s\n",token);
	else printf("NULL\n");

    }



printf("\n\n\n");

getch();
return 0;

}


char * mystrtok(char * str,const char * delimiter)

{
	    //static char *save={0};
	    static char *save;
	       // static char &save="";//depricated
	    //static char save[72]="";
	     //declared static so save retains string
				//between function calls

	    if(str)
	    {
	      int j=0;
	      char *p ;
	      //p=&str[0];
	     // an array name without an index is a pointer to the
	      //   start of the array.
	      p=str;
	      //save=&str[0];
              // save=str;
               while (str[j])
        {

            for(int i=0;delimiter[i];i++)
            {
                if(str[j]  == delimiter[i])
                 {
                 str[j]='\0';
                 ++j;
                 save=&str[j];

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
        while(*save)
    {
        str1[j]=*save;
        j++;
        save++;
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
                 save=&str1[j];

                 return p;
                }

            }
            j++;

        }

    }

 return NULL;
}

