//boshra akroush 
//cis 1202 201
//april 28 2023

#include <iostream>
#include <string>

using namespace std;

char character(char start, int offset);

class invalidCharacterException {};
class invalidRangeException {};

char character(char start, int offset);

int main() {
	
	cout << character('a', 1) << endl; // b

	try 
	{
		character('a', -1); //invalid range
	}
	catch (invalidRangeException i) {
		cout << "Error! Invalid Range Exception" << endl;
	}

	try 
	{
		character('?', 5); // invalid character
	}
	catch (invalidCharacterException i) {
		cout << "Error! Invalid Character Exception" << endl;
	}

	try
	{
		character('Z', -1); // Y
		cout << character('Z', -1);
	}
	catch (invalidRangeException i)
	{
		cout << "Error! Invalid Range Exception" << endl;
	}
	catch (invalidCharacterException i) {
		cout << "Error! Invalid Character Exception" << endl;
	}
	
}

char character(char start, int offset) {
	if ((start < 65 || start > 90) && ((start < 97) || (start > 122)))
		throw invalidCharacterException();
	int exc = start + offset;
	if ((exc < 65 || exc > 90) && ((exc < 97) || (exc > 122)))
		throw invalidRangeException();
	return char(exc);
}
