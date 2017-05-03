#pragma once

// Exercise 6.32 Solution: Ex06_32.cpp
// Finds greatest common divisor (GCD) of 2 inputs.
// Note this is not the recursive solution, which is more elegant.

#include <iostream>

template <typename T>
T gcd(T x, T y)
{
	int greatest = 1; // current greatest common divisor, 1 is minimum

	if (x < 0) {
		x *= -1;
	}
	if (y < 0) {
		y *= -1;
	}

	// loop from 2 to smaller of x and y
	for (T i = 2; i <= ((x < y) ? x : y); i++)
	{
		// if current i divides both x and y
		if (x % i == 0 && y % i == 0)
		{
			greatest = i; // update greatest common divisor
		}
	} // end for

	return greatest; // return greatest common divisor found
} // end function gcd

  /**************************************************************************
  * (C) Copyright 1992-2005 by Deitel & Associates, Inc. and               *
  * Pearson Education, Inc. All Rights Reserved.                           *
  *                                                                        *
  * DISCLAIMER: The authors and publisher of this book have used their     *
  * best efforts in preparing the book. These efforts include the          *
  * development, research, and testing of the theories and programs        *
  * to determine their effectiveness. The authors and publisher make       *
  * no warranty of any kind, expressed or implied, with regard to these    *
  * programs or to the documentation contained in these books. The authors *
  * and publisher shall not be liable in any event for incidental or       *
  * consequential damages in connection with, or arising out of, the       *
  * furnishing, performance, or use of these programs.                     *
  **************************************************************************/


