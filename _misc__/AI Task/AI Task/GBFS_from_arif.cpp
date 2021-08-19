#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <vector>
using namespace std;

vector<string> a;
vector<string>::iterator it;

typedef map <string, vector <string> >  m;
typedef map <string, int> base;
base pairs;
m adjacents;


//std::map< std::pair<int, int>, std::string > Code;

//std::map< std::pair<int,int>, char[50] > Code;

//--------------------------
char c;		// character storage for file error debugging and cheking.
int i;
int r;	// indexer for GFS objects;
string origin;


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
	for (i = 0; i < 5, c != '\n' && c != '\t'&& c != '\r'; i++)	{
		if (r == 11)break;
		stream >> ob.cityTo[i] >> ob.distance[i];
		stream.get(c);
		if (stream.eof()) return stream;	// needed for the end of file operation in end no "\n" present just EOF is present
	}
	pairs.insert(base::value_type(ob.city, 0));
	
	return stream;
}
istream &operator >(istream &stream, GFS &ob){
	c = NULL;
	for (i = 0; i < 5, c != '\n'; i++)	{
		stream >> ob.adjacent[i];
		stream.get(c);
		if (stream.eof()) return stream;
		string temp = ob.adjacent[i];

		//adjacents.insert(m::value_type(temp));
		adjacents[ob.adjacent[0]].push_back(ob.adjacent[i+1]);
	}
	
	return stream;
}



//------------------


//
//class GFS{
//public:
//	string city;
//	int length;
//	string adjacent[8];
//
//	friend istream &operator >>(istream &stream, GFS &ob);
//	friend istream &operator >(istream &stream, GFS &ob);
//
//};
//
//istream &operator >>(istream &stream, GFS &ob){
//	stream >> ob.city >> ob.length;
//	return stream;
//}
//istream &operator >(istream &stream, GFS &ob){
//	c = NULL;
//	for (i = 0; i < 5, c != '\n'; i++)	{
//		stream >> ob.adjacent[i];
//		stream.get(c);
//		if (stream.eof()) return stream;
//	}
//	return stream;
//}

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
	//adjacents = pairs;

	


	//fin >> a; // don't have to scan new line white space is automatically skipped

	// reads adjacent nodes
	for (r = 0; r < 20; r++){
		fin > ob[r];		// > operator overloaded used for city input

		
		
		/*for (i = 1; ob[r].adjacent[i] ;i++)
		adjacents[ob[r].adjacent[0]].push_back(ob[r].adjacent[i]);*/

		//          THIS OCCURS IN THE ABOVE LINE
		/*ms.insert(pair<string,string>("asdfd","asdf"));
		string city = "arefin";
		string city1 = "kss";
		m[city].push_back("k");
		m[city].push_back("ss");
		m[city1].push_back("sadfasdf");
		m[city1].push_back("zxa");*/
	}

	/*for (r = 0; r < 20; r++){
		base.insert(ob[r].city, 0);
		
	}*/

	cout << "Enter origin city:      ";
	cin >> origin;

	/*ms.insert(pair<string,string>("asdfd","asdf"));
	string city = "arefin";
	string city1 = "kss";
	m[city].push_back("k");
	m[city].push_back("ss");
	m[city1].push_back("sadfasdf");
	m[city1].push_back("zxa");*/

	//m.insert("arefin_new", "sultan");

	//map<string, vector<string>>::iterator it;
	

	/*it = m.find("arefin");
	if (it != m.end())
		cout << it->first;
	

	else
		cout << "key not in the map.\n";*/
	return 0;
}
