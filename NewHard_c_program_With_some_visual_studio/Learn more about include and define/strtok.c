


#include<stdio.h>
#include<conio.h>
#include<limits.h>

char * strtok(char * str,const char * delimiter);

int main(void)  {
char a[100]="my name is sultanul arefin,"
            "one of my friend's name is similar to mine.";
char *token;

token=strtok(a," ,");
printf("Token is ==> %s\n",token);
while(token) {
    token=strtok(NULL," ,");
    if(token)    printf("Token is ==>  %s\n",token);
	else printf("NULL\n");

    }



printf("\n\n\n");
getch();
return 0;

}

char * strtok(char * s, const char * toks)
{
    static char * last = 0;
    char * ret = 0;
    if (toks) {
        s = s ? s : last;
        if (s) {
            unsigned long tokmap[1 << (CHAR_BIT - 5)] = {0};
            /* ^ a map of token dividers, containing 256 bits. */
            char * p;
            unsigned char tmp;
            while (tmp = (unsigned char) *toks++) {
                tokmap[ (tmp & ~31) >> 5 ] |= 1u << (tmp & 31);
            }
            p = s;
            /* We find the first character that is not a token
             * divider. */
            while (tokmap[(*p & ~31) >> 5 ] & (1u << (*p & 31))) {
                ++p;
            }

            /* It may be that there are no more tokens. */
            if (! *p) {
                last = 0;
            } else {
                /* But in this path, there are. */

                ret = p;
                /* Now we loop until we get a nontoken
                 * character. We want NUL to be a non-token
                 * character, so we first modify our map to
                 * take that in account.
                 */
                tokmap[0] |= 1;
                do {
                    ++p;
                } while (!(tokmap[(*p & ~31) >> 5] &
                      (1u << (*p & 31))));
                /* Now p points at a non-token character. */
                 *p = 0;
                last = p + 1;
            }
        }
    }
    return ret;
}
