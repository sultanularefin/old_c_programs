// Fig. I.2: Account.cpp
// Member-function definitions for class Account.
#include <iostream>

#include "stdafx.h"
using namespace std;

// Fig. I.1: Account.h
// Definition of Account class.
class Account
{
public:
	Account(int); // constructor initializes balance
	void credit(int); // add an amount to the account balance
	void debit(int); // subtract an amount from the account balance
	int getBalance(); // return the account balance
private:
	int balance; // data member that stores the balance
}; // end class Account
//Fig. I.1 | Header file for the Account class.

// Account constructor initializes data member balance
Account::Account(int initialBalance)
{
	balance = 0; // assume that the balance begins at 0

	// if initialBalance is greater than 0, set this value as the
	// balance of the Account; otherwise, balance remains 0
	if (initialBalance > 0)
		balance = initialBalance;

	// if initialBalance is negative, print error message
	if (initialBalance < 0)
		cout << "Error: Initial balance cannot be negative.\n" << endl;
} // end Account constructor

// credit (add) an amount to the account balance
void Account::credit(int amount)
{
	balance = balance + amount; // add amount to balance
} // end function credit

// debit (subtract) an amount from the account balance
void Account::debit(int amount)
{
	if (amount <= balance) // debit amount does not exceed balance
		balance = balance - amount;
	else // debit amount exceeds balance
		cout << "Debit amount exceeded account balance.\n" << endl;
} // end function debit


int Account::getBalance()
{
	return balance; // gives the value of balance to the calling function
} // end function getBalance

