#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int r,i,m,s,n,p;
int t = 0;
int dis[10];
string a,origin;
char c;
string cityfound[10];

class Greedysearch{
public:
	string city;
	int length;
	string next[8];
};

istream &operator >>(istream &stream, Greedysearch &object){
	c = NULL;
	stream >> object.city >> object.length;
	for (i = 0; i < 4, c != '\n' && c != '\t'&& c != '\r'; i++)	{
		stream >> object.next[i];
		stream.get(c);
		if (stream.eof()) return stream;
	}
	return stream;	
}

int main(){

	ifstream Fin("tamanna");

	if (!Fin){
		cout << " file not found exiting........\n";
		exit(1);
	}
	Greedysearch object[20];
	for (p = 0; p < 20; p++){
		Fin >> object[p];		// >> operator overloaded
	}

	cout << "Enter city:  ";
	
	cin >> origin;
	cout << "\n";
	for (p = 0; p < 20; p++){
		if (object[p].city == origin){ m = object[p].length; }
	}

	for (; ;){
		cityfound[t] = origin;
		dis[t] = m;
		if (origin == "Bucharest") break;
		t++;
		r = 0;
		m = 2000;
		while (r < 20)

			if (origin != object[r].next[0])
				r++;
			else
			{
				i = 1;
				while (object[r].next[i] != ""){

					for (s = 0; s < 20; s++)
						if (object[r].next[i] == object[s].city){
							if (object[s].length < m)
								
								m = object[s].length;
							break;
						}
					i++;
				}
				for (r = 0; r < 20; r++){
					if (m == object[r].length){

						origin = object[r].city;
						break;
					}
				}

				break;
			}
	}
	cout << "city		  " << "			 length"<<"\n\n";
	for (i = 0; i <= t; i++){
		cout<<"\n"<<cityfound[i] <<"\t\t\t" <<dis[i]<<"\n";
			
	}
	return 0;
}