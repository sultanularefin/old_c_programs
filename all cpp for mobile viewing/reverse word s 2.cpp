#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void reverse(char *des, char * const s);
int main ()
{    
    char* s = (char*)"my name is arefin";
    char *x = (char*)"whats your name";

    printf("Before: |%s|\n", x);
    printf("Before: |%s|\n", s);

    char *d = (char*)malloc((strlen(s)+1)*sizeof(char));  
    char *i = (char*)malloc((strlen(x)+1)*sizeof(char));

    reverse(d,s);
    reverse(i,x);

    printf("After: |%s|\n", i);
    printf("After: |%s|\n", d);

    free (i);
    free (d);

    return 0;
}

void reverse(char *dest, char *const s) {
    // create a temporary pointer
    if (strlen(s)==0) return;
    unsigned long offset = strlen(s)+1;

    char *buf = (char*)malloc((offset)*sizeof(char));
    memset(buf, 0, offset);

    char *p;
    // iterate from end to begin and count how much words we have
    for (unsigned long i = offset; i != 0; i--) {
        p = s+i;
        // if we discover a whitespace we know that we have a whole word
        if (*p == ' ' || *p == '\0') {
            // we increment the counter
            if (*p != '\0') {
                // we write the word into the buffer
                ++p;
                int d = (int)(strlen(p)-strlen(buf));
                strncat(buf, p, d);
                strcat(buf, " ");
            }
        }
    }

    // copy the last word
    p -= 1;
    int d = (int)(strlen(p)-strlen(buf));
    strncat(buf, p, d);
    strcat(buf, "\0");

    // copy stuff to destination string
    for (int i = 0; i < offset; ++i) {
        *(dest+i)=*(buf+i);
    }

    free(buf);
}
