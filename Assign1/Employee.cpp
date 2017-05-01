// Assgnment 1: Employee.cpp file
// Member-function definitions for Employee class
// January 25, 2017

#include <iostream>
#include "Employee.h"
using namespace std;

// Initialization of Employee with constructor
Employee::Employee(string initFirstName, string initLastName, int initSalary)
	:firstName(initFirstName), lastName(initLastName), salary(initSalary)
{
	if (firstName.length() < MIN_NAME_LENGTH)
	{
		cerr << "\nWarning - invalid length string entered for first name in ctor: " << firstName;
		cerr << "\nThe string that was entered will be used for now." << endl;
	}

	if (lastName.length() < MIN_NAME_LENGTH)
	{
		cerr << "\nWarning - invalid length string entered for last name in ctor: " << lastName;
		cerr << "\nThe string that was entered will be used for now." << endl;
	}

	if (salary < MIN_SALARY)
	{
		cerr << "\nInvalid salary amount specified in ctor: $" << salary;
		cerr << "\nSalary set to $" << MIN_SALARY << " instead." << endl;
		this->salary = MIN_SALARY;
	}
}

// Function to set first name
void Employee::setFirstName(string initFirstName)
{
	if (initFirstName.length() >= MIN_NAME_LENGTH)
	{
		firstName = initFirstName;
	}
	else
	{
		cerr << "\nERROR - invalid length string entered for first name in setFirstName(): " << initFirstName;
		cerr << "\nThe first name was left unchanged: " << initFirstName << endl;
	}
}

// Function for getting first name
string Employee::getFirstName()
{
	return firstName;
}

// Function to set last name
void Employee::setLastName(string initLastName)
{
	if (initLastName.length() >= MIN_NAME_LENGTH)
	{
		lastName = initLastName;
	}
	else
	{
		cerr << "\nERROR - invalid length string entered for last name in setLastName(): " << initLastName;
		cerr << "\nThe last name was left unchanged: " << initLastName << endl;
	}
}

// Function to get last name
string Employee::getLastName()
{
	return lastName;
}

// Function to set salary
void Employee::setMonthlySalary(int initSalary)
{
	if (initSalary >= MIN_SALARY) // if salary is less than the minimum
	{
		salary = initSalary; // set salary to entered value
	}
	else
	{
		cerr << "\nERROR - Invalid salary amount specified: $" << salary;
		cerr << "\nSalary was left unchanged at: $" << initSalary << endl;
	}
}

// Function for getting salary
int Employee::getMonthlySalary()
{
	return salary;
}
