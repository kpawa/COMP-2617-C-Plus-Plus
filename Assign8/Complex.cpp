/**-------------------------------------------------------
* Assignment #8: Complex.cpp
* Author: Kully Pawa
* Date: Wednesday, April 05, 2017
* Program that adds and subtracts two complex numbers and displays 
* the results as a comma-separted tuple.
* ------------------------------------------------------*/

#include "Complex.h"
#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

Complex::Complex(double r, double i): real(r), imaginary(i) {}

// Add the two complex numbers
Complex &Complex::plusEq(const Complex &tuple)
{
	real += tuple.real;
	imaginary += tuple.imaginary;
	return *this;
}

// Subtract one complex number from the earlier instance
Complex &Complex::minusEq(const Complex &tuple)
{
	real -= tuple.real;
	imaginary -= tuple.imaginary;
	return *this;
}

double Complex::getRealNum(void)
{
	return this->real;
}

double Complex::getComplexNum(void)
{
	return this->imaginary;
}

void Complex::setRealNum(const double & r)
{
	this->real = real;
}

void Complex::setComplexNum(const double & i)
{
	this->imaginary = imaginary;
}

// Display the results as [( r1 + r2 ), i( i1 + i2 )]
void Complex::display() const
{
	cout << fixed << setprecision(4) << "( " << real << " , " << imaginary << " )";
}
