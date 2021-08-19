#include<stdio.h>
#include<conio.h>

   char * mystrtok(char * str,const char * delimiter);

   int main(void)  {

   char a[100]="my name is sultanul arefin one of my friend's name is similar to mine. ";
//   clrscr();


   char *token;

   token = mystrtok(a," ");
   printf("Token is ==> %s\n",token);
   while(token) {
    token=mystrtok(NULL," ");


    if(token)    printf("Token is ==>  %s\n",token);
	else printf("NULL\n");

    }



  printf("\n\n\n");
  getch();
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
	int k=0;
	char *q;
	char str1[100];
	while(*s)
    {
	str1[k]=*s;
	k++;
	s++;
    }
    str1[k]='\0';
    
	q=&str1[0];
						//s =&str1[0];
    k=0;



    while (str1[k])
	{

	    for(int i=0;delimiter[i];i++)
	    {
		if(str1[k]  == delimiter[i])
		 {
		 str1[k]='\0';
		 ++k;
		 s=&str1[k];

		 return q;
		}

	    }
	    k++;

	}

    }

 return NULL;
}

