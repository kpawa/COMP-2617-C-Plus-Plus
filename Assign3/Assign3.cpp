// Assignment 3 : file Assign3.cpp
// Author: Kully Pawa
// Date: Feb. 15, 2017

#include < iostream>
#include <ctime> // contains prototype for function time
#include <cstdlib> // for randomizer
using namespace std;

// Prototypes:
void multiplication(); // Will pose the multiplication questions
void correctMessage(); // Will randomize responses to correct answers
void incorrectMessage(); // Will randomize responses to incorrect answers

const int MIN_VALUE = 0;  // min value in times table
const int MAX_VALUE = 9;  // max value in times table
const int EXIT_VALUE = -1; // value to be entered by user to exit program

int main()
{
	multiplication(); // pose the multiplication questions
	system("pause");
	return 0;
}

// Function for poising multiplication puzzles
void multiplication()
{
	srand(static_cast<unsigned int>(time(0))); // generate rand number
	unsigned int a; // first operand
	unsigned int b; // second operand
	int input = 0; // user response

	cout << "Enter " << EXIT_VALUE << " to End." << endl; // use sentinel-controlled repetition

	while ((input != EXIT_VALUE) && (!cin.fail())) {
		a = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1); // create random int [0, 10) for A
		b = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1); // create random int [0, 10) for B

		cout << "How much is " << a << " times " << b << " (" << EXIT_VALUE << " to End)? ";
		cin >> input;
		if (input == a*b) { // the answer is correct
			correctMessage();
		}
		else if ((input != 1) && (input != -1)) { // the answer is incorrect
			while ((input != EXIT_VALUE) && (input != a*b))
			{
				incorrectMessage(); // display encourangements
				cin >> input;    // get the next guess
				while (cin.rdstate()) {
					cin.clear(); // clear error flag
					cin.ignore(INT_MAX, '\n'); // flush out the input buffer
					cout << "Invalid input entered - try again: ";
					cin >> input;
				} // end while
			} // end while
		}
		else { // user has choosen to exit
			cout << "That's all for now. Bye." << endl;
		}
	} // end while
} // end multiplication

// Handles the case when the user's correctly answers questions
void correctMessage() {
	const int CORRECT_MSGS = 4; // # of variations on corrent answer messages
	unsigned int message = rand() % CORRECT_MSGS; // generate random corrent msg
	switch (message) {
	case 0:
		cout << "Excellent! \n" << endl;
		break;
	case 1:
		cout << "Very good! \n" << endl;
		break;
	case 2:
		cout << "Nice work! \n" << endl;
		break;
	case 3:
		cout << "Keep up the good work! \n" << endl;
		break;
	default:
		cout << "Correct Message randomizer failed \n" << endl;
	}
	cout << "\n" << endl;
}

// Handles the case when the user inputs incorrect answers:
void incorrectMessage() {
	const int NUM_INCORRECT_MSGS = 4; // # of variations on 
	unsigned int message = rand() % 4;
	switch (message) {
	case 0:
		cout << "Wrong. Try once more. \n? ";
		break;
	case 1:
		cout << "No. Keep trying. \n? ";
		break;
	case 2:
		cout << "No. Please try again. \n? ";
		break;
	case 3:
		cout << "Don't give up! \n? ";
		break;
	default:
		cout << "Incorrect Message randomizer failed \n" << endl;
	}
}
