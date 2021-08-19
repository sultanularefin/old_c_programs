#include<iostream>
using namespace std;
int gcd(int a, int b);
int recurse_gcd(int a, int b);

int main()
{
	int a, b;


	do {
		cin >> a >> b;
	} while (a < b);

	// continues until a < b is true, i.e. breaks do loop when a > b .e.g. 12  6.. 
	cout << "gcd:" << gcd(a, b) << "\n";
	cout << "recurse gcd: " << recurse_gcd(a, b);
	return 0;
}
int gcd(int a, int b)
{
	int temp;
	while (b) {
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
int recurse_gcd(int a, int b)
{
	int temp;
	temp = a%b;
	if (temp == 0) return b;
	else {
		return recurse_gcd(b, temp);
	}

}