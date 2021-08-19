#include"stdafx.h"
#include <stdio.h>

	void reverse(char *str) {
		char * end = str;
		char tmp;
		if (str) {
			while (*end) {
				++end;
			}
			--end;
			while (str < end) {
				tmp = *str;
				*str = *end;
				str++;
				*end-- = tmp;
			}
		}
	}


int main()
{
	//char *newstr = "sultanul";
	//reverse(newstr);						//doesn't work.


	char str[] = "sultanul";	// works
	reverse(str);
	printf("   %s   ", str);
	return 0;
}