#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
//#include <algorithm>

using namespace std;
multimap<int, string>m;
multimap<int, string>::iterator p;

int q;	// indexer for searching inner city distance
int r;	// indexer for GFS objects;
int i;
char c;		// character storage for file error debugging and cheking.
string origin;
int minimum;
string traverse[10];
int t = 0; // indexer for traverse
int s; // for searching index not r is used because this will change the r in another case
int value[10];	// stores min values for GBFS and A Search
int temp; //stores f value f = g + h value 
string tempstring1, tempstring2;
int d;// for cityTo  distance indexing where multiple distance from one city is possible
int g; // stores g value (inner city distance
int flag = 0;

class GFS{
public:
	string city;
	int length;
	string adjacent[8];
	string cityTo[6];
	int distance[6];

	friend istream &operator >>(istream &stream, GFS &ob);
	friend istream &operator >(istream &stream, GFS &ob);

};

istream &operator >>(istream &stream, GFS &ob){
	c = NULL;
	stream >> ob.city >> ob.length;
	for (i = 0; i < 5, c != '\n' & c != '\t'& c != '\r'; i++)	{
		if (r == 11)break;
		stream >> ob.cityTo[i] >> ob.distance[i];
		stream.get(c);
		if (stream.eof()) return stream;	// needed for the end of file operation in end no "\n" present just EOF is present
	}
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

	ifstream fin("city star");

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
		if (ob[r].city == origin){ minimum = ob[r].length; }	// value from origin to bucharest saved in min
	}


	do{

		// each time origin updated
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
				flag = 0;

				for (s = 0; s < 20; s++){
					if (ob[r].adjacent[i] == ob[s].city){
						tempstring1 = ob[r].adjacent[0] + "_" + ob[r].adjacent[i];
						tempstring2 = ob[r].adjacent[i] + "_" + ob[r].adjacent[0];

						for (q = 0; q < 20; q++){
							for (d = 0; d < 6, ob[q].cityTo[d] != ""; d++){
								if (ob[q].cityTo[d] == tempstring1){
									g = ob[q].distance[d];
									flag = 1;
									break;

								}
								if (ob[q].cityTo[d] == tempstring2){
									g = ob[q].distance[d];
									flag = 1;
									break;
								}

							}
							if (flag == 1)break;
						} // end of q loop ,, should there be break statement.
					}
					// executes only if s loop succeds
					if (flag == 1){
						temp = g + ob[s].length;				//g(n) + h(n)
						break;
					}
				}// end of s loop


				// this m.insert is executed even flag ==1.
				m.insert(pair<int, string>(temp, ob[r].adjacent[i]));

				//break;

				/*p = m.begin();
				if (temp < minimum){
				minimum = temp;*/
				p = m.begin();
				i++;
			}		// error is here.
			minimum = p->first;	// have to find less values	
			origin = p->second;
			//	origin = ob[r].city;
			break;
		}	/* end of else of while r<20 ; break statement used since when it comes to
			these far then while needs to be ended.*/

		//p++;
		/*
		minimum = p->first;	// have to find less values
		origin = p->second;
		//	origin = ob[r].city;*/
	} while (p->first != NULL & origin != "Bucharest");


	for (i = 0; i <= t; i++){
		cout << "cities    :";
		cout.width(15);
		cout << traverse[i];
		cout.width(15);
		cout << "   value    :" << value[i] << "\n\n";
	}

	return 0;
}