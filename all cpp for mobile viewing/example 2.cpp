//Demonstrate peek()
#include<iostream>
#include<fstream>
#include<cctype>

using namespace std;

int main(){
	char ch;
	char str[80],*p;
	ofstream out("test",ios::out | ios::binary);
	
	if(!out){
		cout<<"Cannot open output file.\n";
		return 1;
		}
		
		
		out<<123 <<" this is a test "<<23;
		out<<" Hello there! " << 99 <<" sdf " << endl;
		out.close();
		
		ifstream in("test", ios::in | ios::binary);
		
		if(!in){
			cout<<"Cannot open input file.\n";
			return 1;
		}
		
		do{
			p=str;
			ch=in.peek(); // see what type of char is next
			if(isdigit(ch)){
				
				while(isdigit(*p=in.get()))p++; // read integer
				in.putback(*p);		//return char to stream
				*p='\0';   // null - terminate the string
				cout << "Integer : " <<str ;
			}
			
			else if(isalpha(ch)) { //read a string
			while(isalpha(*p= in.get()) )p++;
			in.putback(*p);       //return char to stream
			*p='\0';            // null -terminate the string
			cout << "string : " << str;
		}
		else in.get(); // ignore
		
		cout<<'\n';
	}while(!in.eof());
	in.close();
	return 0;
}
