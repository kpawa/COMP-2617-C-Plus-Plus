// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Kully Pawa
// Date: Thurs., Feb. 23, 2017

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;

int DEFAULT_NUM = 0;
int DEFAULT_DENOM = 1;

// default constructor taking no arguments
Fraction::Fraction(void): numerator(DEFAULT_NUM), denominator(DEFAULT_DENOM) {}

// default constructor for optional one or two args
Fraction::Fraction(long long num, long long denom)
	: numerator(num), denominator(denom)
{
	if (denominator == 0) {
		numerator = 0;
		denominator = 1;
		cerr << "\n\n Attempt was made to create a Fraction object with a denominator of 0 !!!\n\n";
	}
	else {
		numerator = num;
		denominator = denom; // denominator is set to 1 if no denominator is passed
		simplify(); // reduce the fraction to lowest terms
	}
}

// Implementation of the timesEq() member function
// Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op)
{
	numerator *= op.numerator; // the input parameter of this function is a reference to a Fraction object
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
			//   will invoke gcd() function to reduce fraction
			//   as much as possible

	return (*this); // returns the object which invoked the method
}

// Fraction addition: (a/b) + (c/d) = (a*d + b*c) / (b*d) 
const Fraction & Fraction::plusEq(const Fraction & op)
{

	numerator = (numerator * op.denominator) + (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();  // will make sure that denominator is positive and
				 //   will invoke gcd() function to reduce fraction
				 //   as much as possible

	return (*this); // returns the object which invoked the method
}

// Fraction subtraction: (a/b) - (c/d) = (a*d - b*c) / (b*d) 
const Fraction & Fraction::minusEq(const Fraction & op)
{
	numerator = (numerator * op.denominator) - (op.numerator * denominator);
	denominator = denominator * op.denominator;

	simplify();  // will make sure that denominator is positive and
				 //   will invoke gcd() function to reduce fraction
				 //   as much as possible

	return (*this); // returns the object which invoked the method
}

// Fraction division: (a/b) / (c/d) = (a*d) / (b*c)
const Fraction & Fraction::divideEq(const Fraction & op)
{
	numerator *= op.denominator;
	denominator *= op.numerator;

	simplify();  // will make sure that denominator is positive and
			//   will invoke gcd() function to reduce fraction
			//   as much as possible

	return (*this); // returns the object which invoked the method
}

// negatize the fraction if the denominator is negative
Fraction Fraction::negate(void) const
{
	return Fraction(numerator * -1, denominator); // must negate fraction but still have it as a const
}

// getter for numerator
long long Fraction::getNum(void) const
{
	return numerator;
}

// getter for denominator
long long Fraction::getDenom(void) const
{
	return denominator;
}

// reduce fraction to lowest terms
void Fraction::simplify()
{
	long divisor = gcd(numerator, denominator); // get the gcd
	numerator /= divisor;
	denominator /= divisor;

	if (denominator < 0)
	{
		denominator *= -1; // should really be invoking the negation instead of this
		numerator *= -1;
	}
	if (numerator == 0)
	{
		denominator = 1;
	}

	else
	{
		long long  gcd_value = gcd(numerator, denominator);
		if (gcd_value > 1)
		{
			numerator /= gcd_value;
			denominator /= gcd_value;
		}
	}

}

// Display the fraction
void Fraction::display(void) const
{
	cout << getNum() << "/" << getDenom();
}





