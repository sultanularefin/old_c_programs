#include <iostream>
using namespace std;

union bits {
	bits (double n);
	void show_bits();
	double d;
	unsigned char c[sizeof(double)];


};

	bits::bits(double n)

	{
		d=n;
	}

	void bits::show_bits()
	{
		int i,j;
		for( j= sizeof(double)-1; j>=0 ;j--){

			cout<< "Bit pattern in byte " << j <<":  ";

			for(i=128; i; i >>=1){
				int y= (i& c[j]);	/*declared y explicitly for de
									;bugging purpose */

			if (y)cout<< "1";
			else cout <<"0";
				}
			cout<<"\n";
			}

		}
		int main()
		{
			bits ob(1991.829);
			ob.show_bits();
			return 0;
		}


