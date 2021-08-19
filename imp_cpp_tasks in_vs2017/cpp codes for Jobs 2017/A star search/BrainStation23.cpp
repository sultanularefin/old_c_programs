
//#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <Windows.h>
#include <stack>
#include <queue>


using namespace std;
void changecase();
void problem1();
int reverse(int x);
bool palindrome(int n);
stack <char>  ch;
stack <int> Rnumber;

int DecimalToBinary(int x);
queue <int> r;
int binaryTodecimal(int n);

void Character_count();

//basic_string<int> test;
//void new_reverse();


int main() {
	// change case completed.

	changecase();


	// Brain Station23 problem 1
	//palindrome related problem ; 3 numbers inputed while no palindrome found reverse number and add the original (123+321=444; palindrome!)until palindrome found
	problem1();

	// decimal to binary
	int n;
	printf("Enter nuber : ");
	scanf(" %d", &n);
	int s= DecimalToBinary(n);
	//
	printf("%d", s);

	
	// binary to Decimal
//	int ans = binaryTodecimal(1110);

//	printf("\n BinaryToDecimal:%d", ans);

	

	//character count in a string
	Character_count();

	return 0;

}

void changecase() {

	char inputString[100];

	printf("Enter a String :");
	//gets_s(inputString);
	gets(inputString);

	char p[100];
	//p = inputString;
	char x;
	int s; // used for '\0' value to be putted.


	cout << "\n";
	//cout << inputString;

	for (int i = 0; inputString[i]; i++) {
		if (islower(inputString[i])) {
			char temp = (unsigned)inputString[i];
			x = toupper(temp);
			//printf("%c",x);
		//	*p++ = x;
			p[i] = x;
		}

		if (isupper(inputString[i])) {
			char temp = inputString[i];
			x = tolower(temp);
			//	printf("%c", x);
			p[i] = x;
		}
		s = i + 1;


		//	cout << "\n";
			//	cout << inputString;

	}
	p[s] = '\0';
	cout << "\n";

	puts("Result:   ");
	printf("  %s", p);

	cout << "\n";
	cout << "Original String:   " << inputString;
}


void problem1() {

	//palindrome related problem
	int N = 3;// test cases

	int number[3];

	printf("\nEnter numbers:");
	for (int i = 0; i < N; i++) {
		scanf("%d", &number[i]);


	}

	for (int i = 0; i < N; i++) {

		while (1) {

			bool result = palindrome(number[i]);
		//	Sleep(12);					// use     include <windows.h>

			if (result) {
				printf("\n palindrome found : %d", number[i]);  break;
			}
			if (!result) {
				int r1 = reverse(number[i]);

				int sum = number[i] + r1;
				number[i] = sum;
				result = palindrome(sum);


			}
			/*if(!result){
			i = i - 1;
			}*/

			if (result) {
				printf("\n palindrome found : %d", number[i]);  break;
			}
		}
	}
}

// probrem 1 calls this method
int reverse(int x) {    // probem1 calls this method



	char buffer[100];
	_itoa(x, buffer, 10);
	string str = "";
	int divider = 1;

	for (int i = 0; buffer[i]; i++) {
		str = str + buffer[i];
		divider = divider * 10;
	}
	const char *test;
	test= str.c_str();

	//cout <<"\n\n string to char:" << test;
	divider = divider / 10;

	int tempdivider = divider;

	int len = str.length();
	int quotient;
	int remainder;
	for (int i = 0; i < len; i++) {

		quotient = x / divider;
		remainder = x % divider;
		divider = divider / 10;
		Rnumber.push(quotient);
		x = remainder;


	}
	int newnumber = 0;

	for (int i = 0; i < len; i++) {
		newnumber = newnumber + tempdivider* Rnumber.top();
		Rnumber.pop();
		tempdivider = tempdivider / 10;
	}

	return newnumber;



}

// probrem 1 calls this method
bool palindrome(int n) {		
	int temp = n;
	char buffer[20];
	_itoa(n, buffer, 10);
	string str = "";

	for (int i = 0; buffer[i]; i++) {
		ch.push(buffer[i]);
		str = str + buffer[i];
	}

	int len = str.length();

	int count = 0;

	for (int i = 0; i < len / 2; i++) {

		if (buffer[i] == ch.top()) {
			ch.pop();
			count++;
		}


		else break;
	}


	if (count == len / 2) return 1;
	else return 0;

	//printf("%s   ", buffer);



	//return 0;


}

int DecimalToBinary(int x) {

	int quotient, remainder;
	int count=0;
	do {

		remainder = x % 2;
		quotient = x / 2;
		
		r.push(remainder);
		x = quotient;
		count++;
		

	} while (x != 0);
	int newnumber=0;
	int j = 1;

	for (int i = 0; i < count; i++) {
		newnumber = newnumber + j*  r.front();
		r.pop();  //remove element
		j = j * 10;
		
	}

	//long dec, rem, i = 1, sum = 0;
	//cout << "Enter the decimal to be converted:";
	//cin >> dec;
	//do
	//{
	//	rem = dec % 2;
	//	sum = sum + (i*rem);
	//	dec = dec / 2;
	//	i = i * 10;
	//} while (dec>0);

	return newnumber;
}

int binaryTodecimal(int n) {
	
	char buffer[100];
	_itoa(n, buffer, 10);

	string s = buffer;
	int l = s.length();

	for (int c = 0; c < l; c++) {
		if ((buffer[c] != '0') && (buffer[c] != '1')) return 0;
	}
	int remainder = 0;
	int decimal = 0;
	int j = 1;
	while (n!=0){
		remainder = n % 10;

		decimal = decimal + remainder*j;
		j = j * 2;
		n = n / 10;

	}
	int ans = decimal;
	
	return ans;


}

void Character_count() {


	int count[89];
	for (int i = 0; i < 89; i++) {
		count[i] = 0;
	}
	char str[200];
	
	gets(str);
	//gets_s(str);

	//char ch;
	for (int i = 0; str[i]; i++) {
		//count[str[i] - int(str[i] ]=str[i];
		//ch = str[i];
		count[str[i] - '!']++;				//'!' =33 122-33 =89 122='z'


	}
	for (int i = 0; str[i]; i++) {
		printf("\n %c occured %d times", str[i], count[str[i] - '!']);
	}

	return ;
}


