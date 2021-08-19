//header files needed for this program
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "stdafx.h"

using namespace std; //use the standard namespace.

//tables
const string tableOfOperators[] = { "+", "-", "/", "*", "=", "<", ">", "++", "--", "<<", ">>", "!=", "&", "&&", "|", "||", "[", "]", "==" };
const char tableOfPunctuators[] = { ';', ',', '.', '(', ')', '{', '}' };
const string tableOfKeywords[] = { "auto", "bool", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "asm", "_ss", "interrupt", "_cs", "cdecl", "near", "_ds", "far", "pascal", "_es", "huge", "catch", "class", "delete", "friend", "inline", "new", "operator", "overload", "private", "protected", "public", "template", "this", "throw", "try", "virtual" };
const string booleanValues[] = { "true", "false" };

//function used to skip a directive
void skipDirective(int&);
void skipComment(int&);

//prototypes of the functions used.(DFA's).
bool isStringLiteral(string);
bool isCharLiteral(string);
bool isIdentifier(string);
bool isBooleanValue(string);
bool isPunctuator(char);
bool isOperator(string);
bool isKeyword(string);
bool isInteger(string);
bool isFloat(string);

//prototypes of the functions used to find the ending of each kind of lexeme.
string findEndQuote(int&); //find the endquote if a starting quote is found.
string findEndApostrophe(int&); //find the ending apostrophe if an apostrophe is found.
string findEndOfIdentifier(int&); //find the end of the identifier if a letter or _ is found.
string findEndOperator(int&);
string findEndOfNum(int&);

int charPointer; //pointer to each character in the file

//variables used to count the number of each kind of lexeme.
int numOfStringConstants; //the number of string literal constants.
int numOfCharLiterals; //the number of character literal constants.
int numOfIdentifiers; //the number of identifiers
int numOfBooleanConstants; //the number of boolean constants
int numOfKeywords; //the number of keywords
int numOfOperators; //the number of operators
int numOfPunctuators; //the number of punctuators
int numOfIntegerConstants; //the number of integer constants
int numOfFloatConstants; //the number of float constants

char ch; //will hold each character in the file.
fstream cppfile; //the stream used to open the file.
string output; //the string in which the contents of the file will be inserted.
string lexeme; //the string used to hold the value of each lexeme

 int main(){

	//initialize all counting variables to zero.
	numOfStringConstants = 0;
	numOfCharLiterals = 0;
	numOfIdentifiers = 0;
	numOfBooleanConstants = 0;
	numOfKeywords = 0;
	numOfOperators = 0;
	numOfPunctuators = 0;
	numOfIntegerConstants = 0;
	numOfFloatConstants = 0;
	char filename[32];

	output = ""; //initialize output to a blank string
	charPointer = 0; //point to the first character

	cout << "Enter the name of the file you want to analyze.\n";
	cout << "Note: It should within the same directory as your program: ";
	cin.getline(filename, 30);

	//read the file and place the contents to output.
	cppfile.open(filename, ios::in);

	while (!cppfile.eof()){
		cppfile.get(ch); //get each character from the file
		output = output + ch; //append each character to the output string.
	}

	cppfile.close(); //close the file

	cout << "\nTHE PROGRAM\n\n";
	while (charPointer<output.length() - 1){
		cout << output[charPointer];
		charPointer++;
	}

	cout << "\n\n";
	//read the output string character by character.
	cout << "\nRESULTS...\n\n";

	charPointer = 0;
	while (charPointer<output.length() - 1){

		//if a quote symbol is encountered use the DFA for the string literal constants
		if (output[charPointer] == '"'){

			//find all characters between the quotes and insert them to the variable lexeme.
			lexeme = findEndQuote(charPointer);

			//if lexeme containts a string literal
			if (isStringLiteral(lexeme))
				numOfStringConstants++;//increments the number of string constants if a string literal is found. 
		}

		else if (output[charPointer] == '/'){
			skipComment(charPointer);
		}

		//if a apostrophe symbol is encountered use the DFA for the string literal constants
		else if (output[charPointer] == '\''){

			//find all characters between the apostrophe's and insert them to the variable lexeme.
			lexeme = findEndApostrophe(charPointer);

			//if the lexeme contains a character literal
			if (isCharLiteral(lexeme))
				numOfCharLiterals++; //increments the number of character literal constants if a character literal is found.
		}

		//if the pound # symbol is found (a directive)
		else if (output[charPointer] == '#'){
			//skip the directive and move the character pointer
			skipDirective(charPointer);
		}

		//if a letter or a _ is found then this may be an identifier...
		else if ((isalpha(output[charPointer])) || (output[charPointer] == '_')){

			//find the entire identifier
			lexeme = findEndOfIdentifier(charPointer);

			//if the identifier happens to be a keyword
			if (isKeyword(lexeme)){
				numOfKeywords++; //increment the number of keywords.
			}

			//if the identifier happens to be a boolean value
			else if (isBooleanValue(lexeme)){
				numOfBooleanConstants++;//increment the number of boolean constants.
			}

			//if it is neither a boolean value or a keyword, then it is a plain identifier
			else if (isIdentifier(lexeme)){
				numOfIdentifiers++;//increment the number of identifiers.
			}
		}

		//if an operator is found 
		else if (strchr("+-/*=<>!&|[]", output[charPointer])){
			lexeme = findEndOperator(charPointer); //check if there are operators beside it too

			if (isOperator(lexeme)){
				numOfOperators++;
			}
		}

		//check if the character is a punctuator
		else if (isPunctuator((output[charPointer]))){
			numOfPunctuators++;
		}

		//check if the character is a number
		else if (isdigit(output[charPointer])){

			//if it is a number, find its end
			lexeme = findEndOfNum(charPointer);

			if (isInteger(lexeme)) //if the number is an integer, increment the number of integer constants
				numOfIntegerConstants++;

			else if (isFloat(lexeme)) //if it is a float, increment the number of float constants
				numOfFloatConstants++;

		}

		charPointer++; //move the pointer to the next character.
	}

	//print the number of string literals,char literals,etc.
	cout << "Number of string literal constants found is: " << numOfStringConstants << '\n';
	cout << "Number of char literal constants found is: " << numOfCharLiterals << '\n';
	cout << "Number of keywords found is: " << numOfKeywords << '\n';
	cout << "Number of boolean constants found is: " << numOfBooleanConstants << "\n";
	cout << "Number of identifiers found is: " << numOfIdentifiers << "\n";
	cout << "Number of operators found is: " << numOfOperators << "\n";
	cout << "Number of punctuators found is: " << numOfPunctuators << "\n";
	cout << "Number of integer constants found is: " << numOfIntegerConstants << "\n";
	cout << "Number of float constants found is: " << numOfFloatConstants << "\n";

	return EXIT_SUCCESS; //program has ended successfully.
}

//function used to determine if the identifier is a string literal
bool isStringLiteral(string lexeme){

	char ch = '\0';
	int x = 1;
	while (x<lexeme.length() - 1){ //loop through each character in the lexeme(ignore the apostrophes)
		ch = lexeme[x];

		//if it contains only a backslash, then it is not a string literal
		if ((ch == '\\') && (lexeme[x + 1] == '"')){
			if ((x + 1) == lexeme.length() - 1)
				return false;//because it is not a string literal
		}

		//if it contains a backslash but the backslash is not followed by a valid character
		if ((ch == '\\') && (!(strchr("\'\\ntabr0", lexeme[x + 1])))){
			return false; //because it is not a character literal
		}

		//if a valid character is found after the backslash, just skip it
		else if ((ch == '\\') && (strchr("\'\"\\", lexeme[x + 1])))
			x++;

		x++;

	}
	return true; //it is a literal string if the loop completes successfully.
}

//function used to determine if the identifier is a character literal
bool isCharLiteral(string lexeme){

	char ch = '\0';
	int x = 1;

	while (x<lexeme.length() - 1){ //loop through each character in the lexeme(ignore the apostrophes)
		ch = lexeme[x];

		//if it contains only a backslash, then it is not a character literal
		if ((ch == '\\') && (lexeme[x + 1] == '\'')){
			if ((x + 1) == lexeme.length() - 1)
				return false; //because it is not a character literal
		}

		//if it contains a backslash but the backslash is not followed by a valid character
		if ((ch == '\\') && (!(strchr("\'\\ntabr0", lexeme[x + 1])))){
			return false; //because it is not a character literal
		}

		//if a valid character is found after the backslash, just skip it
		else if ((ch == '\\') && (strchr("\'\"\\", lexeme[x + 1])))
			x++;

		x++;

	}
	return true; //it is a character literal if the loop completes successfully
}

//function used to determine if the identifier is just a plain identifier.
bool isIdentifier(string lexeme){
	for (int x = 1; x<lexeme.length(); x++){
		if ((!(isalnum(lexeme[x]))) && (!(lexeme[x] == '_'))) //an identifier should only be followed by an alphanumeric character or a _ character.
			return false; //return false if it is followed by something else
	}
	return true; //if it is an identifier
}

//function used to determine if the identifier is a boolean value.
bool isBooleanValue(string lexeme){
	for (int x = 0; x<2; x++){
		if (lexeme == booleanValues[x]) //if the lexeme is a boolean value
			return true; //return true if it is a boolean value
	}
	return false; //if it is not a boolean value.
}

//function used to determine if the lexeme is an operator
bool isOperator(string lexeme){
	for (int x = 0; x<19; x++){
		if (lexeme == tableOfOperators[x]) //check if the lexeme is inside the table of operators
			return true;
	}
	return false;
}

//function used to determine if the lexeme is punctuator
bool isPunctuator(char lexeme){
	for (int x = 0; x<8; x++){
		if (lexeme == tableOfPunctuators[x]) //check if the lexeme is inside the table of punctuators
			return true;
	}
	return false;
}

//function used to determine if the identifier is a keyword.
bool isKeyword(string lexeme){

	//loop through the table of keywords
	for (int x = 0; x<60; x++){
		if (lexeme == tableOfKeywords[x]) //check if the lexeme is a keyword
			return true; //return true if it is a keyword
	}
	return false; //if it is not a keyword
}

//function used to determine if the lexeme is an integer
bool isInteger(string lexeme){
	for (int x = 0; x<lexeme.length(); x++){
		if (lexeme[x] == '.')
			return false; //it is not an integer if it contains
	}
	return true;
}

//function used to determine if the lexeme is a float
bool isFloat(string lexeme){
	for (int x = 0; x<lexeme.length(); x++){
		if (lexeme[x] == '.') //it is a float if it contains a decimal point
			return true;
	}
	return false;
}

//if a starting quote is found, find its corresponding end quote while moving the pointer.
string findEndQuote(int &cpointer){

	string tempstring = ""; //tempstring will hold the string literal from quote to quote
	tempstring += output[cpointer];

	do{
		cpointer++; //point to the next character in the file
		tempstring += output[cpointer]; //append the character to tempstring
	} while (!(output[cpointer] == '"')); //end the loop once the end quote is found.

	return tempstring; //pass tempstring back to where this function was called
}

//if a starting apostrophe is found, find its corresponding end apostrophe while moving the pointer.
string findEndApostrophe(int &cpointer){

	string tempstring = "";//tempstring will hold the character literal from apostrophe to apostrophe
	tempstring += output[cpointer];

	do{
		cpointer++; //point to the next character in the file
		tempstring += output[cpointer]; //append the character to tempstring
	} while (!(output[cpointer] == '\'')); //end the loop once the end apostrophe is found

	return tempstring; //pass tempstring back to where this function was called
}

//if an identifier is found, find its end
string findEndOfIdentifier(int &cpointer){

	string tempstring = ""; //this variable will hold the identifier string

	//while alphanumeric characters or the _ character is found do this...	
	while (isalnum(output[cpointer]) || (output[cpointer] == '_')){
		tempstring += output[cpointer]; //append the character to tempstring
		cpointer++; //point to the next character in the file.
	}
	cpointer--;
	return tempstring; //pass tempstring back to where this function was called
}

//function to find the ending operator if an operator is found

string findEndOperator(int &cpointer){
	string tempstring;
	tempstring += output[cpointer];


	//look for the ==,!=,<<.>>,||,&& operators
	//(operators which are repeated)
	switch (output[cpointer]){

	case '=':
		if (output[cpointer + 1] == '='){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;


	case '+':
		if (output[cpointer + 1] == '+'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '-':
		if (output[cpointer + 1] == '-'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '<':
		if (output[cpointer + 1] == '<'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '>':
		if (output[cpointer + 1] == '>'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '&':
		if (output[cpointer + 1] == '&'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '|':
		if (output[cpointer + 1] == '|'){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;

	case '!':
		if (output[cpointer + 1] == '='){
			tempstring += output[cpointer + 1];
			cpointer++;
		}
		break;
	}
	return tempstring;
}

//this function is called when a number is found.
string findEndOfNum(int &cpointer){

	string tempstring; //the string where the number will be placed.
	tempstring = output[cpointer];

	//if the number starts with zero.
	if (output[cpointer] == '0'){

		//if zero is followed by a decimal point
		if (output[cpointer + 1] == '.'){

			cpointer++;
			tempstring += output[cpointer];
			cpointer++;

			//move the pointer until a none numeric character is found.
			while (strchr("0123456789", output[cpointer])){
				tempstring += output[cpointer];
				cpointer++;
			}

			//move the pointer one step backwards since an excess of 1 step was added to it in the loop.
			cpointer--;
			return tempstring; //return tempstring to the caller
		}

	}

	else{ //if it is a number other than zero

		cpointer++; //move to the next character

		//if the next character is a decimal point
		if (output[cpointer] == '.'){

			tempstring += output[cpointer]; //append the decimal point to tempstring
			cpointer++; //move to the next character

			//move the pointer to the next character until it is no longer a number.
			while ((strchr("0123456789", output[cpointer]))){

				tempstring += output[cpointer]; //append the next number to tempstring.
				cpointer++; //point to the next character.

			}
		}

		//if the next number is not a decimal point
		else{

			//move the pointer until a non-numeric character is found
			while (strchr("0123456789", output[cpointer])){

				tempstring += output[cpointer]; //append the numeric character to tempstring
				cpointer++; //point to the next character

				//if a decimal point is encountered within the number

				if (strchr(".", output[cpointer])){

					tempstring += output[cpointer]; //append the decimal point to tempstring
					cpointer++; //point to the next character.
				}
			}
		}

		cpointer--;//move the pointer one step backwards since an excess of 1 step was added to it in the loop.

		return tempstring; //return tempstring to the caller
	}

	return tempstring; //return tempstring if only a single number is found.
}

//function to skip a comment if it is found
void skipComment(int &cpointer){

	//if the "/" sign is followed by another "/" sign
	if (output[cpointer + 1] == '/'){

		//move the pointer until a newline character is found (this is the end of the comment)
		while (output[cpointer] != '\n'){
			cpointer++;
		}

	}

	//if an asterisk* is found
	if (output[cpointer + 1] == '*'){

		//move to the character next to the asterisk
		cpointer += 2;

		//move the pointer to the next character until the */ is found (end of the comment)
		while ((output[cpointer] != '*') && (output[cpointer + 1] != '/')){
			cpointer++;
		}

	}
}


//function to skip a directive if it is found
void skipDirective(int &cpointer){
	while (output[cpointer] != '\n') //look for the newline character (end of directive)
		cpointer++; //point to the next character in the file until the newline character is found.
}