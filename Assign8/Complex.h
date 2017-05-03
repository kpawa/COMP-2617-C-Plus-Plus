/**-------------------------------------------------------
* Assignment#8: Complex.h
* Author: Kully Pawa
* Date: Wednesday, April 05, 2017
* Program that adds, subtracts and displays complex numbers
* ------------------------------------------------------*/

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	//default ctor
	Complex(double = 1.0, double = 0.0);
	//add two complex numbers
	Complex & plusEq(const Complex &);
	//subtract one complex number from another
	Complex & minusEq(const Complex &);

	// getters for real and imaginary numbers:
	double Complex::getRealNum(void);
	double Complex::getComplexNum(void);

	// setters for real and imaginary numbers:
	void Complex::setComplexNum(const double & i);
	void Complex::setRealNum(const double & r);
	
	//display the results 
	void display() const;

private:
	double real;
	double imaginary;
};



#endif