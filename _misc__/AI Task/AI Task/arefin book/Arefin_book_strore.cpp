
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <typeinfo>
#include <stdio.h>
#include <conio.h>
using namespace std;

int i;
void add_student();
void admin();
void student_details();
void book_details();
void book_entry();
int book_id();

class Student{
public:
	string Full_Name;
	string User_Name;
	string Password;
	int Student_ID;
	int Issued_Book_number;

	//friend ifstream &operator >>(ifstream &stream, Student &ob);
};

Student s;
Student AS[30];  // Student Array


class Book{
public:
	string subject;
	string Book_Name;
	string count;
	int BookID;
	int Price;
	

	//friend ifstream &operator >>(ifstream &stream, Student &ob);
};

Book bo;
Book AB[30];


void menu()
{
	cout << "1. view as admin" << endl;
	cout << "2. view as student" << endl;
	cout << "3. create student account" << endl;

	cout << "Choose 1 or 2 or 3:" << endl;

	char ch;
	//ch = getche();
	//switch (ch)
	//{
		//case '1':// clrscr();
			admin();
		//	break;
		//case '2':// clrscr();
		//	student_view();
		//	break;
		//case '3':// clrscr();
		add_student();
		//break;
	//}

}

int checkid(){

	fstream FS("Arefin.txt", ios::in, ios::binary);

	if (!FS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	   char ch; //for id calculation.
		char nochar;	
		int id = 0;
		nochar = FS.peek();  // see page 328
								// ensures if it is the first time the file operation is performed here.
		if (isalpha(nochar)){
			while (!FS.eof()){
				FS.get(ch);
				if (ch == '\n')
					id = id + 1;
			}
		}

		
		FS.close(); 
		return id;



}

int book_id(){

	fstream BS("book.txt", ios::in, ios::binary);

	if (!BS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	char ch; //for id calculation.
	char nochar;
	int id = 0;
	nochar = BS.peek();  // see page 328
	// ensures if it is the first time the file operation is performed here.
	if (isalpha(nochar)){
		while (!BS.eof()){
			BS.get(ch);
			if (ch == '\n')
				id = id + 1;
		}
	}


	BS.close();
	return id;



}




ifstream &operator >> (ifstream &stream, Student &ob)
{

	stream >> ob.Full_Name >> ob.User_Name >> ob.Password >> ob.Student_ID ;

	return stream;
}



fstream &operator << (fstream &stream, Student &ob)  // not ostream ,should be ofstream & stream
{


	stream << ob.Full_Name << "  " << ob.User_Name << "  " << ob.Password << "  " << ob.Student_ID << "  " << endl;
	return stream;


}

fstream &operator << (fstream &stream, Book &ob)  // not ostream ,should be ofstream & stream
{


	stream << ob.subject << "  " << ob.Book_Name << "  " << ob.count << "  " << ob.BookID << "  " <<ob.Price<< endl;
	return stream;


}

ifstream &operator >> (ifstream &stream, Book &ob)
{

	stream >> ob.subject >> ob.Book_Name >> ob.count >> ob.BookID >> ob.Price;

	return stream;
}


void add_student()  // prototype declared at top
{
	int newid;
	fstream FS("Arefin.txt", ios::app, ios::binary);

	if (!FS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	cout << endl << "Enter Student description: ";

	cout << "Full name:";
	cin >> s.Full_Name;

	cout << "user name:";
	cin >> s.User_Name;

	cout << "password";
	cin >> s.Password;
	FS.close();
	newid = checkid();

	// opening file again.

	FS.open("Arefin.txt", ios::out|ios::binary|ios::app);

	s.Student_ID = newid;


	FS << s;

	//friend istream &operator >>(istream &stream, user &u);
	//out << u;

	cout << "\tYour Account Has Been Created";
	FS.flush();
	FS.close();


}

void book_entry(){

	int bid;  // book id
	fstream BS("book.txt", ios::app, ios::binary);

	if (!BS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	cout << endl ;

	cout << "Enter Subject:";
	cin >> bo.subject;

	cout << "Book name:";
	cin >> bo.Book_Name;

	cout << "Book Quantity:";
	cin >> bo.count;
	cout << "price:";
	cin >> bo.Price;

	BS.close();   // BS stream closed ,calling book_id function where BS stream will be invoked again.

	bid = book_id();

	// opening file again.

	BS.open("book.txt", ios::out | ios::binary | ios::app);

	bo.BookID = bid;


	BS << bo;

	//friend istream &operator >>(istream &stream, user &u);
	//out << u;

	cout << "\tBooks Have Been entered";
	BS.flush();
	BS.close();

}

void admin(){

	student_details();
	book_entry();

	book_details();
}


int main(){

	menu();

	
}

void book_details()
{
	cout << endl << "Book details" << endl;
	ifstream BS("book.txt", ios::in, ios::binary);  // check if it is ifstream or fstream other wise errore will occur

	if (!BS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	// opening file again.

	//FS.open("Arefin.txt", ios::in | ios::binary );
	int Book_count;
	Book_count = book_id();


	for (int j = 0; j < Book_count; j++){
		BS >> AB[j];
		cout << AB[j].BookID << " " << AB[j].Book_Name << " " << AB[j].subject << " " << AB[j].count << endl;
	}

}

void student_details()
{
	cout << endl << "student details" << endl;
	ifstream FS("Arefin.txt", ios::in, ios::binary);  // check if it is ifstream or fstream other wise errore will occur

	if (!FS){

		cout << "Cannot open file.\n";
		exit(1);
	}
	// opening file again.

	//FS.open("Arefin.txt", ios::in | ios::binary );
	int student_count;
	student_count= checkid();
	student_count = student_count - 1;


	for (int j = 0; j < student_count; j++){
		FS >> AS[j];
		cout << AS[j].Student_ID << " " << AS[j].User_Name << " " << AS[j].Full_Name << " " << AS[j].Password << endl;
	}


	
}






