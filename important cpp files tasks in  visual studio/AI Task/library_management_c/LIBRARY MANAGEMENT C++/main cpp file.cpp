
#include"stdafx.h"
//
//#define WIN32_LEAN_AND_MEAN		/*If an #include line is needed for the Windows.h header file, 
//this should be preceded with the    #define WIN32_LEAN_AND_MEAN macro     */

#include<iostream>
#include<fstream>
#include<stdio.h>

#include<conio.h>		//<conio.h> is part of DOS Based Turbo C++ Compiler. Remember the Blue Screen Compiler.

#include<iomanip>
#include<string>
#include<Windows.h>

using namespace std;

void cover();


//************************************************
//***************Class User***********************
class user{
public:
	char Full_Name[20];
	char User_Name[10];
	char Password[10];
	char Issued_Book_number[5];


	void create_user()
	{
		cout << "\n\n\tEnter Full Name:";
		gets(Full_Name);
		cout << "\n\tEnter User Name:";
		gets(User_Name);
		cout << "\n\tEnter Password:";
		cin >> Password;
	}

	friend ostream &operator <<(istream &stream, user &u);
	// fin >> ob[r];		// >> operator overloaded


	friend void add_user();
	friend void login();
	friend void show_all_user();
	friend void admin_menu();
	friend void user_menu();
	friend void issue_book();
	friend void show_account();
};

ofstream &operator <<(ofstream &stream, user &u)  // not ostream ,should be ofstream & stream
{
	stream << u.Full_Name <<"  " << u.User_Name <<"  " << u.Password << "  " << u.Issued_Book_number << "  ";
	return stream;
	

}


//***********************************************
//*************Class Book************************
class book{

	char Book_Id[3];
	char Book_Name[50];
	char Author[20];
	int Book_Count;

	void create_book()
	{
		cout << "\n\n\tEnter The Book_Id. :";
		cin >> Book_Id;
		cout << "\n\tEnter Tha Name of The Book :";
		gets(Book_Name);
		cout << "\n\tEnter The Author Name :";
		gets(Author);
		cout << "\n\tEnter No of Books :";
		cin >> Book_Count;
	}



	void show_book()
	{
		cout << setw(4) << Book_Id << "." << setw(35) << Book_Name << setw(20) << Author << setw(12) << Book_Count << "\n";
	}



	void modify_book()
	{
		cout << "\n\tBook no. : " << Book_Id;
		cout << "\n\tModify Book Name : ";
		gets(Book_Name);
		cout << "\n\tModify Author's Name of Book : ";
		gets(Author);
		cout << "\n\tModify Book Count : ";
		cin >> Book_Count;
	}

	friend void add_book();
	friend void show_all_book();
	friend void show_all_book2();
	friend void book_bno();
	friend void book_bna();
	friend void book_bar();
	friend void delete_book();
	friend void mod_book();
	friend void issue_book();
	friend void deposite_book();
	friend void show_account();
};



//***************************************************
//*****************class Admin***********************
class admin{
private:
	char pass_admin[10];



	void create_admin()
	{
		cout << "Enter the Password:\n";
		cin >> pass_admin;
	}



	friend void admin_login();
	friend void add_admin();
};

//***************************************************
//****************global obj*************************
user u;
book b;
admin a;
//*************************************************************************
//****************global variable for current user*************************
char current_user[10];
char book_serial_no[3];
char current_book_name[50];


//***************************************************
//********************add user***********************

void add_user()
{


	u.create_user();
	ofstream out("user.dat", ios::app);
	if (!out){
		cout << "cannot open the user.dat file. \n";
	}
	strcpy(u.Issued_Book_number, "0");			// Issued_Book_Number = 0;

	out.write((char*)&u, sizeof(user));		// user u is typecast to char * 
	cout << "Your Account Has Been Created";

	//friend istream &operator >>(istream &stream, user &u);
	//out << u;
	
	cout << "\tYour Account Has Been Created";
	out.flush();
	out.close();

}
//***************************************************
//********************add admin***********************
void add_admin()
{


	a.create_admin();
	ofstream out("admin.dat", ios::app);
	if (!out){
		cout << "cannot open the user.dat file. \n";
	}
	

	out.write((char*)&a, sizeof(admin));
	cout << "Your Account Has Been Created";


}

//****************************************************
//*********************log in for user****************
void user_login()
{
	char n[25], p[5];
	int flag = 0;
	ifstream in("user.dat", ios::in | ios::out);


	cout << "\n\n\tEnter The User Name: ";
	gets(n);
	cout << "\n\n\tEnter The Password: ";
	cin >> p;

	if (!in)
	{
		cout << "File NOt Found";
	}

	while (in.read((char *)&u, sizeof(user)))
	{
		if (strcmp(u.User_Name, n) == 0 && strcmp(u.Password, p) == 0)
		{
			strcpy(current_user, u.User_Name);
			strcpy(book_serial_no, u.Issued_Book_number);
			flag = 1;
			cout << "\n\tWELCOME  " << u.Full_Name << "\n";
			user_menu();


		}

	}
	if (flag == 0)
	{
		cout << "\tWrong User Name or Password";
		user_login();
	}
	in.close();

}
//****************************************************
//*********************log in for Admin****************
void admin_login()
{
	char x[4];
	ifstream in("admin.dat", ios::in | ios::out);
	cout << "\n\n\tEnter The Password: ";
	cin >> x;
	if (!in)
	{
		cout << "File NOt Found";
	}

	while (in.read((char *)&a, sizeof(admin)))
	{
		if (strcmp(a.pass_admin, x) == 0)
		{

			cout << "\n\tLOGGED IN";
			admin_menu();


		}
		else
		{
			cout << "\twrong Password";
			admin_login();

		}
	}
	in.close();

}


//**********************************************
//****************search book by book no********
void book_bno()
{
	ifstream in;
	char n[3], x;
	int flag = 0;

	do{
		cout << "\n\n\tEnter The Book_Id : ";
		cin >> n;
		in.open("book.dat");
		while (in.read((char*)&b, sizeof(book)))
		{
			if (strcmpi(b.Book_Id, n) == 0)
			{
				cout << "\t\t\t     *Book List*\n\n";
				cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
				cout << "***************************************************************************\n";
				b.show_book();
				flag = 1;
				break;

			}

		}

		if (flag == 0)
		{
			cout << "Book Not Found";

		}
		flag = 0;
		cout << "\n\n\tDo you want to search again..(y/n?)";
		cin >> x;
		in.close();
	} while (x == 'y' || x == 'Y');
	user_menu();

}


//*************************************************
//*******************search book by User_Name***********

void book_bna()
{
	ifstream in;
	char n[50], x;
	int flag = 0;

	do{
		cout << "\n\n\tEnter The Name of The Book:";
		gets(n);
		in.open("book.dat");
		while (in.read((char*)&b, sizeof(book)))
		{
			if (strcmpi(b.Book_Name, n) == 0)
			{
				cout << "\t\t\t     *Book List*\n\n";
				cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
				cout << "***************************************************************************\n";
				b.show_book();
				flag = 1;
				break;
			}

		}
		if (flag == 0)
		{
			cout << "Book Not Found";

		}
		flag = 0;
		cout << "\n\nDo you want to search again..(y/n?)";
		cin >> x;
		in.close();
	} while (x == 'y' || x == 'Y');
	user_menu();

}

//*************************************************
//*******************search book by Author**********

void book_bar()
{
	ifstream in;
	char n[20], x;
	int flag = 0;
	cout << "\n\n\tEnter The Name of The Author:";
	gets(n);
	cout << "\t\t\t     *Book List*\n\n";
	cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
	cout << "***************************************************************************\n";
	do{

		in.open("book.dat");
		while (in.read((char*)&b, sizeof(book)))
		{
			if (strcmpi(b.Author, n) == 0)
			{

				b.show_book();
				flag = 1;
			}



		}

		if (flag == 0)
		{
			cout << "Book Not Found";
		}


		cout << "\n\n\tDo You Want To Search Again..(y/n?)";
		cin >> x;
		in.close();
	} while (x == 'y' || x == 'Y');
	user_menu();

}


//***********************************************
//*******************add_book********************
void add_book()
{
	char c;
	do{
		b.create_book();
		ofstream out("book.dat", ios::app);
		if (!out){
			cout << "cannot open the user.dat file. \n";
		}
		out.write((char*)&b, sizeof(book));
		cout << "\n\n\tDo You Want To Add More Book To The Record(y/n?)";
		cin >> c;
		out.close();
	} while (c == 'y' || c == 'Y');
	admin_menu();


}

//***********************************************
//*******************show_allb for admin*******************


void show_all_book()
{

	ifstream in("book.dat");
	if (!in)
	{
		cout << "File not Found";
	}
	cout << "\t\t\t     *Book List*\n\n";
	cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
	cout << "***************************************************************************\n";
	while (in.read((char*)&b, sizeof(book)))
	{
		b.show_book();

	}
	admin_menu();
	in.close();

}
//***********************************************
//*******************show_allb for user*******************
void show_all_book2()
{

	ifstream in("book.dat");
	if (!in)
	{
		cout << "File not Found";
	}
	cout << "\t\t\t     *Book List*\n\n";
	cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
	cout << "***************************************************************************\n";
	while (in.read((char*)&b, sizeof(book)))
	{
		b.show_book();

	}
	user_menu();
	in.close();

}



//***********************************************
//*******************show_all_user*******************


void show_all_user()
{

	ifstream in("user.dat");
	if (!in)
	{
		cout << "File not Found";
	}
	cout << "\n\t|Name|" << setw(33) << "|User Name|" << "\n";
	cout << "\t***************************************\n";
	while (in.read((char*)&u, sizeof(user)))
	{

		cout << "\t" << u.Full_Name << "\t\t\t" << u.User_Name << "\n";

	}
	in.close();

}


//***********************************************
//********************Delete Book****************


void delete_book()
{

	char n[3];
	char c2;
	int flag = 0;
	fstream f1;
	fstream f2;

	cout << "\n\n\n\tDELETE Specific Book...";
	do{
		cout << "\n\nEnter The Serial no. of the Book To Delete : ";
		cin >> n;
		f1.open("book.dat", ios::in | ios::out);
		f2.open("temp.dat", ios::out);
		f1.seekg(0, ios::beg);
		while (f1.read((char*)&b, sizeof(book)))
		{
			if (strcmpi(b.Book_Id, n) != 0)
				f2.write((char*)&b, sizeof(book));
			else
				flag = 1;
		}

		f2.close();
		f1.close();
		remove("book.dat");
		rename("temp.dat", "book.dat");
		cout << b.Book_Id;
		if (flag == 1)
		{
			cout << "\n\n\tRecord Deleted ..";
			cout << "\n\nDo you want to add more record..(y/n?)";
			cin >> c2;
		}

		else
		{
			cout << "\n\nRecord not found";
			cout << "\n\nDo you want to add more record..(y/n?)";
			cin >> c2;
		}
	} while (c2 == 'y' || c2 == 'Y');
	admin_menu();


}

//***************************************************
//*********************modify book*******************
void mod_book()
{
	char n[6], ch;
	fstream fp;
	int found = 0;
	// clrscr();
	cout << "\n\n\tMODIFY BOOK REOCORD.... ";
	cout << "\n\n\tEnter The book no. of The book :";
	cin >> n;
	fp.open("book.dat", ios::in | ios::out);
	while (fp.read((char*)&b, sizeof(book)) && found == 0)
	{
		if (strcmpi(b.Book_Id, n) == 0)
		{
			do{
				// clrscr();
				cout << "\n\t\t\t     *Book List*\n\n";
				cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
				cout << "***************************************************************************\n";
				b.show_book();

				cout << "\n\n\t**********************";
				cout << "\n\tBook Modifiaction Menu";
				cout << "\n\t**********************";
				cout << "\n\t1.Modify Book Book_Id";
				cout << "\n\t2.Modify Book Name";
				cout << "\n\t3.Modify Book Author";
				cout << "\n\t4.Modify Book Count";
				cout << "\n\t5.Go To Admin Menu\n";
				cout << "\n\tEnter Your Choice: ";
				ch = getche();

				switch (ch)
				{
				case '1':
				{
					cout << "\n\tModify Book Book_Id : ";
					cin >> b.Book_Id;
					int pos = -1 * sizeof(b);
					fp.seekp(pos, ios::cur);
					fp.write((char*)&b, sizeof(book));

					found = 1;
					fp.close();
					break;
				}

				case '2':
				{
					cout << "\n\tModify Book Name : ";
					gets(b.Book_Name);
					int pos = -1 * sizeof(b);
					fp.seekp(pos, ios::cur);
					fp.write((char*)&b, sizeof(book));
					cout << "\n\n\t Record Updated";
					found = 1;
					fp.close();
					break;
				}
				case '3':
				{
					cout << "\n\tModify Book Author Name : ";
					gets(b.Author);
					int pos = -1 * sizeof(b);
					fp.seekp(pos, ios::cur);
					fp.write((char*)&b, sizeof(book));
					cout << "\n\n\t Record Updated";
					found = 1;
					fp.close();
					break;
				}
				case '4':
				{
					cout << "\n\tModify Book count : ";
					cin >> b.Book_Count;
					int pos = -1 * sizeof(b);
					fp.seekp(pos, ios::cur);
					fp.write((char*)&b, sizeof(book));
					cout << "\n\n\t Record Updated";
					found = 1;
					fp.close();
					break;
				}
				case '5':
				{
					// clrscr();
					admin_menu();
					break;
				}
				}
			} while (ch != '5');

		}
	}

	fp.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	admin_menu();


}




//********************************************
//*****************issue Book*****************
void issue_book()
{
	char n[3];
	fstream fp, f;
	int found = 0;
	// clrscr();
	cout << "\n\n\tEnter The serial no. of The book:";
	cin >> n;
	fp.open("book.dat", ios::in | ios::out);
	while (fp.read((char*)&b, sizeof(book)) && found == 0)
	{
		if (strcmpi(b.Book_Id, n) == 0)
		{
			found = 1;

			cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
			cout << "***************************************************************************\n";
			b.show_book();
			if (b.Book_Count == 0)
			{
				cout << "\n\n\t   ********This Book Is Not Available For Issuing.********\n";
				break;
			}
			else
			{
				b.Book_Count = b.Book_Count - 1;
				strcpy(current_book_name, b.Book_Name);
				int pos = -1 * sizeof(b);
				fp.seekp(pos, ios::cur);
				fp.write((char*)&b, sizeof(book));
				cout << "\n\n\tBook Has Been Issued For 7 Days.Late Fee 1 Rs Per Day\n";

			}

		}
	}


	fp.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";

	f.open("user.dat", ios::in | ios::out);
	while (f.read((char*)&u, sizeof(user)))
	{
		if (strcmpi(u.User_Name, current_user) == 0)
		{
			strcpy(u.Issued_Book_number, n);
			strcpy(book_serial_no, u.Issued_Book_number);
			int pos = -1 * sizeof(u);
			f.seekp(pos, ios::cur);
			f.write((char*)&u, sizeof(user));
		}
	}
	user_menu();

}

//*************************************
//***************book_deposite*********
void deposite_book()
{
	char n[6];
	fstream fp, f;
	int found = 0;
	// clrscr();
	f.open("user.dat", ios::in | ios::out);
	while (f.read((char*)&u, sizeof(user)))
	{
		if (strcmpi(u.User_Name, current_user) == 0)
		{
			strcpy(n, u.Issued_Book_number);
			strcpy(u.Issued_Book_number, "0");

			int pos = -1 * sizeof(u);
			f.seekp(pos, ios::cur);
			f.write((char*)&u, sizeof(user));


		}
	}
	fp.open("book.dat", ios::in | ios::out);
	while (fp.read((char*)&b, sizeof(book)) && found == 0)
	{
		if (strcmpi(b.Book_Id, n) == 0)
		{
			cout << "\t\t\t     *Book List*\n\n";
			cout << "|Book No.|" << setw(20) << "|Book Name|" << setw(25) << "|Author|" << setw(20) << "|Book Count|\n";
			cout << "***************************************************************************\n";
			b.show_book();
			b.Book_Count = b.Book_Count + 1;

			int pos = -1 * sizeof(b);
			fp.seekp(pos, ios::cur);
			fp.write((char*)&b, sizeof(book));
			cout << "\n\n\tBook Has Been Deposited\n";

			found = 1;
		}
	}

	fp.close();
	if (found == 0)
		cout << "\n\n\t No Book To Deposite ";
	user_menu();

}




//****************************************************
//***************Show Account Detail************************

void show_account()
{
	ifstream in, i;
	i.open("book.dat");
	while (i.read((char*)&b, sizeof(book)))
	{
		if (strcmpi(b.Book_Id, book_serial_no) == 0)
		{
			strcpy(current_book_name, b.Book_Name);

		}
	}


	in.open("user.dat");
	while (in.read((char*)&u, sizeof(user)))
	{
		if (strcmpi(u.User_Name, current_user) == 0)
		{

			cout << "\n\t|Name|" << setw(25) << "|Password|" << setw(30) << "|Issued Book|" << "\n";
			cout << "\t**********************************************************\n";
			cout << "\t" << u.Full_Name << setw(20) << u.Password << setw(30) << current_book_name << "\n\n";



		}
	}
	in.close();


	user_menu();

}


//*********************************************
//**************admin_menu*********************
void admin_menu()
{
	char c1;
	cout << "\n\n\t*****************";
	cout << "\n\t    Admin Menu";
	cout << "\n\t*****************";
	cout << "\n\t 1.Show All Book";
	cout << "\n\t 2.Add Book";
	cout << "\n\t 3.Modify Book";
	cout << "\n\t 4.Delete Book";
	cout << "\n\t 5.Show All User";
	cout << "\n\t 6.LogOut\n";
	cout << "\n\t Enter Your Choice: ";
	c1 = getche();
	switch (c1)
	{
	case '1':// clrscr();
		show_all_book();
		break;
	case '2':// clrscr();
		add_book();
		break;
	case '3':// clrscr();
		mod_book();
		break;
	case '4':// clrscr();
		delete_book();
		break;
	case '5':// clrscr();
		show_all_user();
		break;
	case '6':// clrscr();
		cover();
		break;

	}

}

//************************************
//****************user_menu***********
void user_menu()
{
	char c1;

	cout << "\n\t*****************";
	cout << "\n\t    User Menu";
	cout << "\n\t*****************";
	cout << "\n\t 1.Show Account Detail";
	cout << "\n\t 2.Show All Book";
	cout << "\n\t 3.Search Book By No";
	cout << "\n\t 4.Search Book By Name";
	cout << "\n\t 5.Search Book By Author";
	cout << "\n\t 6.Issue Book";
	cout << "\n\t 7.Deposite Book";
	cout << "\n\t 8.LogOut\n";
	cout << "\n\t Enter Your Choice: ";


	c1 = getche();
	switch (c1)
	{
	case '1':// clrscr();
		show_account();
		break;
	case '2':// clrscr();
		show_all_book2();
		break;
	case '3':// clrscr();
		book_bno();
		break;
	case '4':// clrscr();
		book_bna();
		break;
	case '5':// clrscr();
		book_bar();
		break;
	case '6':// clrscr();
		issue_book();
		break;
	case '7':// clrscr();
		deposite_book();
		break;
	case '8':// clrscr();
		strcpy(current_user, "");
		cover();
		break;



	}


}
/* FROM STACK OVERFLOW ,,, WINDOWS.H DOESN'T SOLVE GOTOXY PROBLEM NOR CONIO.H*/

/*

void gotoxy(int x, int y)
{
    COORD c = { x, y };  
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

*/


void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void cover()		 // execution begins here
{
	char ch;
	cout << "\n\n\t\t\t  ***************************\n";
	cout << "\t\t\t  [LIBRARY MANAGEMENT SYSTEM]";
	cout << "\n\t\t\t  ***************************";
	gotoxy(10, 15);
	cout << "\n\t1.User Login";
	cout << "\n\t2.Admin Login";
	cout << "\n\t3.Create An User Account\n\t";

	ch = getche();
	switch (ch)
	{
	case '1':// clrscr();
		user_login();
		break;
	case '2':// clrscr();
		admin_login();
		break;
	case '3':// clrscr();
		add_user();
		break;
	}
}
void main()	 // main function at the end
{
	cover();

}
