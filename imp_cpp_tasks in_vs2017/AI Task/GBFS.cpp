#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int r;
string a;
int i;
char c;
string origin;
int minimum;
string traverse[10];
int t=0; // indexer for traverse
int s; // for searching index not r is used because this will change the r in another case
int value[10];


class GFS{
public:
	string city;
	int length;
	string adjacent[8];

	friend istream &operator >>(istream &stream, GFS &ob);
	friend istream &operator >(istream &stream, GFS &ob);

};

istream &operator >>(istream &stream, GFS &ob){
	stream >> ob.city >> ob.length;
	return stream;
}
istream &operator >(istream &stream, GFS &ob){
	c = NULL;
	for (i = 0; i < 5, c != '\n'; i++)	{
		stream >> ob.adjacent[i];
		stream.get(c);
		if (stream.eof()) return stream;
	}
	return stream;
}

int main(){

	ifstream fin("city");

	if (!fin){

		cout << "Cannot read file.\n";
		exit(1);
	}
	GFS ob[20];
	for (r = 0; r < 20; r++){
		fin >> ob[r];		// >> operator overloaded
	}

	//fin >> a; // don't have to scan new line white space is automatically skipped

	// reads adjacent nodes
	for (r = 0; r < 20; r++){
		fin > ob[r];		// > operator overloaded used for city input

	}

	cout << "Enter origin city:      ";
	cin >> origin;
		
	for (r = 0; r < 20; r++){
		if (origin == ob[r].adjacent[0]) cout << "origin found ." << "\n\n";
		
	}
	for (r = 0; r < 20; r++){
		if (ob[r].city == origin){ minimum = ob[r].length; }
	}

	while (1){
		traverse[t] = origin;

		value[t] = minimum;
		if (origin == "Bucharest") break;
		t++;
		r = 0;
		minimum = 10000;
		while (r < 20)

			if (origin != ob[r].adjacent[0])
				r++;
			else
			{
				i = 1;
				while (ob[r].adjacent[i] != ""){

					for (s = 0; s < 20; s++)
						if (ob[r].adjacent[i] == ob[s].city){
							if (ob[s].length < minimum)
								//if (value[t - 1] | value[t - 2] == ob[s].length)continue;
								minimum = ob[s].length;
							break;
						}
					i++;
				}
				for (r = 0; r < 20; r++){
					if (minimum == ob[r].length){

						origin = ob[r].city;
						break;
					}
				}
				
				break;
			}
	}
		
	for (i = 0; i <= t; i++){
		cout << "cities    :"; 
		cout.width(15);
		cout << traverse[i] ;
		cout.width(15);
		cout << "   value    :" << value[i]<<"\n\n";
	}
			
	return 0;
}