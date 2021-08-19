#include "mystrtok.h"

int i, j;
char * save;

char * mystrtok(char * str, const char * delim)
{
    for(i=0; i<sizeof(str) && str[i]!='\0'; i++)
    {
        for(j=0; j<sizeof(delim) && delim[j]; j++)
        {
            if (str[i]==delim[j])
                    str[i]='\0';
            save=str;
            return str;
        }
    }
};
