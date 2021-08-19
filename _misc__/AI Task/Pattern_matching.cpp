#include <iostream>
#include <cstring>
using namespace std;

char Text[100] = "arefinsultanulppp";
string S = "asdfsdafsdfsadf";
string result;

int bruteforce(char[10], char[30]);

int main() {

	char pattern[10] = "ppp";
	int r = S.find("ghdi");


	cout << r;

	cout << "\n";
	int f = bruteforce(pattern, Text);

	cout << f;
	return 0;

}



int bruteforce(char pattern[10], char Text[30]) {

	int x, y,j = 0; // x is the length of pattern , y is the length of Text , j for global count in for loop,
	for (x = 0; pattern[x] != ('\n' &&'\r' && '\t' && '\0'); ) {

		x++;

	}

	for (y = 0; Text[y] != ('\n' &&'\r' && '\t' && '\0'); ) {

		y++;

	}


	for (int i = 0; i <= y - x; i++)
	{

		j = 0;

		while (j < x && (Text[j + i] == pattern[j])) {

			j++;
		}
	}

		if (j == x) return j;

		else return -1;
		

}
