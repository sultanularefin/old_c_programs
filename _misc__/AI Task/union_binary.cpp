#include "stdafx.h"

#include <iostream>
using namespace std;

union bits {
	bits(int n);
	void show_bits();
	int d;
	unsigned char c[sizeof(int)];
};

bits::bits(int n)
{
	d = n;
}

void bits::show_bits()
{
	int i, j;
	for (j = sizeof(int) - 1; j >= 0; j--) {
		cout << "Bit pattern in byte: " << j << ": ";
		for (i = 128; i; i = i >> 1)
			if (i&c[j])cout << "1";
			else cout << 0;
			cout << "\n";
	}
}

int main() {
	bits ob(126);
	ob.show_bits();
	return 0;
}
		
	
