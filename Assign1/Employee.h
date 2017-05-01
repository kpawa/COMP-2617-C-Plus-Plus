#pragma once
#include <string>
using namespace std;

class Employee
{
public:
	Employee(string initFirstName, string initLastName, int initSalary);
	void setFirstName(string);
	string getFirstName();
	void setLastName(string);
	string getLastName();
	void setMonthlySalary(int);
	int getMonthlySalary();

private:
	string firstName;
	string lastName;
	int salary;

	const static int MIN_NAME_LENGTH = 2;  // Minimum valid length of each first and last name
	const static int MIN_SALARY = 0;  // Minimum valid salary
};
