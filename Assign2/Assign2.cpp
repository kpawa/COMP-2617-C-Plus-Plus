/************************************************************************
*	Assignment #2: Assign2.cpp file					*
*	Roman Numeral to Decimal Conveter				*
*	by Kully Pawa (A00964517)					*
*	Feb. 01, 2017							*
**************************************************************************/

#include <iostream> // program uses standard i/o
#include <string> // program uses C++ standard string class
#include <cctype> // only used to convert lowercase letter to uppercase
using namespace std;

const int NUMBER_OF_VALUES = 10;
const int LARGE_VALUE = 1001;

// function main is the whole of this single file program
int main() {
	char inputChar; // the current input character
	int previous; // used for getting previous roman numeral for subtracting from current
	int sum{ 0 }; // sum of input roman numeral cardinal number
	bool error{ false }; // for recording problem input

	cout << "10 Roman numeral values will be input and converted into " <<
		"their equivalent Hindu - Arabic numeric values.\n" << endl;

	// iterate a fixed 10 times for recieving input roman numerals
	for (int count = 1; count <= NUMBER_OF_VALUES; count++) {
		error = false;
		cout << "Input Roman numeral # " << count << ": ";
		sum = 0;
		inputChar = ' ';
		previous = LARGE_VALUE; // this is to ensure that case M doesn't use a null for comparison
		while ((inputChar = cin.get()) != EOF && (inputChar != '\n') && (error == false)) {
			inputChar = toupper(inputChar); // convert input single char to uppercase
			cout << inputChar;
			switch (inputChar)
			{
			case 'M':
				sum += 1000;
				if (previous < 1000)
				{
					sum -= 2 * previous; // if larger number precedes then we need to remove it
				}				// and remove it again from the sum that we added it to.
				previous = 1000;
				break;
			case 'D':
				sum += 500;
				if (previous < 500)
				{
					sum -= 2 * previous;
				}
				previous = 500;
				break;
			case 'C':
				sum += 100;
				if (previous < 100)
				{
					sum -= 2 * previous;
				}
				previous = 100;
				break;
			case 'L':
				sum += 50;
				if (previous < 50)
				{
					sum -= 2 * previous;
				}
				previous = 50;
				break;
			case 'X':
				sum += 10;
				if (previous < 10)
				{
					sum -= 2 * previous;
				}
				previous = 10;
				break;
			case 'V':
				sum += 5;
				if (previous < 5)
				{
					sum -= 2 * previous;
				}
				previous = 5;
				break;
			case 'I':
				sum += 1;
				previous = 1;
				break;
			case '\n': // ignore newlines...added by default by ENTER keypress
			case '\t': // tabs,
			case ' ': // and spaces in input
				break; // exit switch
			default:
				cerr << "\rError - last character was not valid!!!\n" << endl;
				error = true;
				// cin.clear();
				cin.ignore(256, '\n'); // seems to be about the only way to prevent line from holding onto data after '?'
				break;
			} // switch selection
		} //while loop
		if (error == false) { // don't print out the input nor sum if input is invalid
			cout << " = " << sum << "\n" << endl;
		}
	}// for loop
	cout << "THATS ALL FOLKS :)" << endl;
	system("pause");
	return 0;
}
