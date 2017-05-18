// Assignment# 5: file Assign5.cpp
// Author: Kully Pawa
// Date: March 08, 2017
// Program to display unique numbers of twenty numbers entered

#include <iostream> 
#include <array>
#include <iomanip> // for the setw print formatting class
using namespace std;

const int ARRAY_SIZE = 20; // size of array to hold the unique numbers
const int MIN_VALUE = 10; // minimum allowed value for
const int MAX_VALUE = 100; // maximum allowed value for
array< unsigned int, ARRAY_SIZE > uniques = {}; // array of unique integers initialized to zeros

bool isUnique(int, int); // prototype for uniqueness checker function
bool exists;		// Boolean to record whether the entered number exists in array

int main()
{
	int input;		// used for storing user input numbers
	int position = -1;	// points to position in array of last unique number

	// Promt for the input of the 20 integers
	for (int i = 1; i <= uniques.size(); i++)
	{
		exists = false; // initialize uniqueness flag to false
		cout << "\nEnter # " << i << " : ";
		cin >> input;

		// ignore all numbers outside [10, 100]
		while (cin.rdstate() || input < MIN_VALUE || input > MAX_VALUE)
		{
			cout << "The number enetered is not in the valid range of 10 to 100" << endl;
			cout << "\nEnter # " << i << " : ";
			cin >> input;

			if (!cin || cin.bad() || cin.eof()) { // input validation -- DOESN'T WORK
				cin.clear();
				cin.ignore(INT_MAX, '\n'); // flush the input buffer
				cout << "\nEnter # " << i << " : ";
				cin >> input;
			}
		}

		// check to see if the number already exists in array
		if (!isUnique(position, input))	// the number is unique
		{
			uniques[++position] = input;  // advance the current position in array and save the unique number
			cout << "The number: " << input << " is unique" << endl;
		}
	} // for loop ends

	// Print results
	cout << "\n\nThe unique numbers are: \n";
	for (int i = 0; i <= position; ++i) {
		cout << setw(5) << uniques[i];
		if (i % 5 == 4) { // if you've reached the fifth element in the display then do a carriage return
			cout << '\n';
		}
	}
	cout << '\n' << endl;
	system("pause");
	return 0;
}

 // function to determine if the inputed number is unique
bool isUnique(const int position, const int input)
{
	int count = 0;
	while (count <= position)
	{
		if (uniques[count] == input)
		{
			exists = true; // the number isn't unique
			break;
		}
		count++;
		exists = false; // the number is unique
	}
	return exists;
}
