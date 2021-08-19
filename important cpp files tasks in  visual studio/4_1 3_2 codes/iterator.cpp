 // Fig. 22.5:Fig22_05.cpp
 // Demonstrating inputand output with iterators.
 #include <iostream>
#include <iterator>
 using namespace std;

 int main()
 {
	 cout << "Enter two integers:";

	 // createistream_iterator for reading int valuesfromcin
	 istream_iterator< int >inputInt(cin);
	 int number1 = *inputInt; // read intfromstandard input
	 ++inputInt; // move iterator to nextinput value
	 int number2 = *inputInt; // read intfromstandard input
	 // createostream_iterator for writing int valuestocout
	 ostream_iterator< int >outputInt(cout);
		 cout << "The sum is: ";
		 *outputInt = number1 + number2; // output result to cout
	
		 cout << endl;
		 return 0;
	 } // end main