//
//#include <ctype.h>
//#include <stdio.h>
//
//void main()
//{
//	char id[21];
//	char *text;
//	int i;
//
//	text = "passwordTESTING";
//
//	/* Copy uppercase "identifier" from text to id. */
//	for (i = 0; i < 20 && islower(text[i]); ++i)
//		id[i] = text[i];
//	id[i] = '\0';
//
//	/* Only the word "password" should be copied. */
//	puts(id);
//}

#include <stdio.h>
#include <ctype.h>

int main()
{
	int i = 0;
	char c;
	char str[] = "Tutorials Point";

	while (str[i])
	{
		putchar(toupper(str[i]));
		i++;
	}

	return(0);
}