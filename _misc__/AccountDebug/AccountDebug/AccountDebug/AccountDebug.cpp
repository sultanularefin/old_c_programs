// AccountDebug.cpp : Defines the entry point for the console application.
//
//
//#include "stdafx.h"
//
//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}
// Fig. I.3: figI_03.cpp
// Create and manipulate Account objects.

#include "stdafx.h"
#include "Account.h"


using namespace std;

// function main begins program execution
int main()
{
	Account account1(50); // create Account object

	// display initial balance of each object
	cout << "account1 balance: $" << account1.getBalance() << endl;

	

	int withdrawalAmount; // stores withdrawal amount read from user

	cout << "\nEnter withdrawal amount for account1: "; // prompt
	cin >> withdrawalAmount; // obtain user input
	cout << "\nattempting to subtract " << withdrawalAmount
		<< " from account1 balance\n\n";
	account1.debit(withdrawalAmount); // try to subtract from account1

	// display balances
	cout << "account1 balance: $" << account1.getBalance() << endl;

	
	return 0;
} // end main


