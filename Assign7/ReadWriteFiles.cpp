// Assignment #7: file ReadWriteFiles.cpp
// Author: Kully Pawa
// Date: March 29, 2017
// Calculates gross pay, net pay, pension and deductions for employees of Rogers Hostpital Supplies Company.
// Reads from EmployeePayInput.txt file, writes to EmployeePayOutput.txt file, and writes errors to console.

#include <iostream>
#include <conio.h>  // Required for _getch() function
#include <fstream>  // Required for file input/output
#include <iomanip>  // setw(), setprecision
#include <string>	// to_string
using namespace std;

//global constants
const int MAX_REGULAR_WORK_HOURS = 40; // maximum regular weekly regular work hours
const int MAX_WEEKLY_HOURS = 54; // maximum total weekly work hours
const double OVERTIME_PAYRATE_MULTIPLE = 0.5; // overtime pay rate above regular hours

const double TAXABLE_CONSTANT1 = 14.00;
const double TAXABLE_CONSTANT2 = 11.00;
const double FEDERAL_CONSTANT1 = 0.14;
const double FEDERAL_CONSTANT2 = 0.00023;
const double PROVINCIAL_CONSTANT1 = 0.35;
const double PENSION_CONSTANT1 = 16.50;
const double PENSION_CONSTANT2 = 0.077;

const int SIN_NUM_MAX_LENGTH = 9;
const int MIN_EXEMPTION = 0;
const int MAX_EXEMPTION = 19;
const int MIN_HOURS_WORKED = 0;
const int MAX_HOURS_WORKED = 54;
const double MIN_WEEKLY_WAGE = 0.00;
const double MAX_WEEKLY_WAGE = 99.99;

//prototypes
bool checkSocialSecurityNumber(long socialInsuranceNum);
bool checkExemptions(int numberOfExemptions);
bool checkHoursWorked(double hoursWorked);
bool checkPayRate(double payRate);

double calculateGrossPay(double payRate, double hoursWorked);
double calculateDeductions(double grossPay, int numberOfExemptions);
double calculatePension(double grossPay);
double calculateNetPay(double grossPay, double deductions, double pension);

// One way to specify a file name:
const char * IN_FILE = "../EmployeePayInput.txt";

// A second way to specify a file name:
#define OUT_FILE "../EmployeePayOutput.txt"

int main()
{
	//Declare variables
	long socialInsuranceNum;	// social security number of employee
	int numberOfExemptions;		// stores total number of excemptions for employee

	double payRate = 0.0,			// pay rate for the employee
		hoursWorked = 0.0,		// hours worked for the employee
		grossPay = 0.0,			// gross pay for the employee
		netPay = 0.0,			// netpay for the employee
		pension = 0.0,			// pension for the employee
		deductions = 0.0,		// deductions for the employee
		totalGrossPay = 0.0,		// total gross pay of all employees
		totalNetPay = 0.0,		// total net pay for all all employees
		totalPension = 0.0,		// total pension pay for all employees
		totalDeductions = 0.0;		// total deductions for all employees

	//Define ifstream object and open file
	ifstream ins;
	ins.open(IN_FILE);

	//Check that file opened without any issues
	if (ins.fail())
	{
		cerr << "ERROR--> Unable to open input file : " << IN_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -1; //error return code
	}

	//Define ofstream object and open file
	ofstream outs;
	outs.open(OUT_FILE);

	//Check that file opened without any issues
	if (outs.fail())
	{
		cerr << "ERROR--> Unable to open output file : " << OUT_FILE << endl;
		cerr << '\n' << endl;
		_getch(); // causes execution to pause until a char is entered
		return -2; //error return code
	}

	outs << fixed << setprecision(2); //defaults double to 0.00

	outs << "Rogers Hospital Supplies Company\n";
	outs << "--------------------------------\n\n";

	outs << left << setw(20) << "Social insurance no." <<
		right << setw(12) << "gross pay" <<
		right << setw(11) << "net pay" <<
		right << setw(11) << "pension" <<
		right << setw(14) << "deductions\n";
	outs << "--------------------------------------------------------------------\n";

	int employeeCounter = 0; // employee counter, increments every time a valid line of data is found
	ins >> socialInsuranceNum; // Read in first social security number

	// Process data until end of file is reached
	while (!ins.eof())
	{
		// Read in data for the employee and validate
		ins >> payRate >> numberOfExemptions >> hoursWorked;
		bool validNumber = checkSocialSecurityNumber(socialInsuranceNum); // Should be a 9 digit integral value not starting with 0
		bool validExemptions = checkExemptions(numberOfExemptions); // should be int within [0, 19]
		bool validHoursWorked = checkHoursWorked(hoursWorked); // should be floating point within [0, 54]
		bool validPayRate = checkPayRate(payRate); // should be a floating point value within [0.00, 99.99]

		if (validNumber && validExemptions && validHoursWorked && validPayRate) // process valid data line
		{
			employeeCounter++;
			grossPay = calculateGrossPay(payRate, hoursWorked);
			totalGrossPay += grossPay;

			pension = calculatePension(grossPay);
			totalPension += pension;

			deductions = calculateDeductions(grossPay, numberOfExemptions) + pension;
			totalDeductions += deductions;

			netPay = calculateNetPay(grossPay, deductions, pension);
			totalNetPay += netPay;

			outs << left << setw(20) << socialInsuranceNum <<
				right << setw(12) << grossPay <<
				right << setw(11) << netPay <<
				right << setw(11) << pension <<
				right << setw(14) << deductions << "\n";
		}
		else
		{	// print out errors to console
			cerr << fixed << setprecision(2);
			//setfill(' ');
			if (!validNumber)
			{
				cerr << setw(12) << right << socialInsuranceNum << setw(20) << left << "    INPUT DATA ERROR:   " << "Invalid social security #" << endl;
			}

			if (!validPayRate)
			{

				cerr << setw(12) << right << socialInsuranceNum << setw(20) << left << "    INPUT DATA ERROR:   " << "Invalid pay rate: " << payRate << endl;
			}

			if (!validExemptions)
			{
				cerr << setw(12) << right << socialInsuranceNum << setw(20) << left << "    INPUT DATA ERROR:   " << "Invalid number of exemptions: " << numberOfExemptions << endl;
			}

			if (!validHoursWorked)
			{
				cerr << setw(12) << right << socialInsuranceNum << setw(20) << left << "    INPUT DATA ERROR:   " << "Invalid hours worked: " << hoursWorked << endl;
			}
		} //end of if block
	} //end of while 

	//outs << "\n\n\n";
	outs << "\n\n\nSummary\n-------\n\n";
	outs << left << setw(37) << "Number of employees processed:" << right << setw(14) << employeeCounter << "\n";
	outs << left << setw(37) << "Total gross pay for all employees:" << right << setw(14) << totalGrossPay << "\n";
	outs << left << setw(37) << "Total net pay for all employees:" << right << setw(14) << totalNetPay << "\n";
	outs << left << setw(37) << "Total pension withheld for all employees:" << right << setw(10) << totalPension << "\n";
	outs << left << setw(37) << "Total deductions for all employees:" << right << setw(14) << totalDeductions << "\n";

	// Close files
	ins.close();
	outs.close();

	_getch(); // causes execution to pause until char is entered
}

//Fuction to check if the social insurance number is a 9 digit number
bool checkSocialSecurityNumber(long socialInsuranceNum)
{
	string sin = to_string(socialInsuranceNum);
	while (sin.length() == SIN_NUM_MAX_LENGTH && sin.at(0) != 0) {
		return true;
	}
	return false;
}

//Function to check if number of exemptions is between 0 to 19
bool checkExemptions(int numberOfExemptions)
{
	while (numberOfExemptions >= MIN_EXEMPTION && numberOfExemptions <= MAX_EXEMPTION) {
		return true;
	}
	return false;
}

//Function to check number of hours worked
bool checkHoursWorked(double hoursWorked)
{
	while (hoursWorked >= MIN_HOURS_WORKED && hoursWorked <= MAX_HOURS_WORKED) {
		return true;
	}
	return false;
}

// Function to check whether the hourly pay is between 0.00 to 99.99
bool checkPayRate(double payRate)
{
	while (payRate >= MIN_WEEKLY_WAGE && payRate <= MAX_WEEKLY_WAGE) {
		return true;
	}
	return false;
}

//Function to calculate Gross Pay = Regular pay for the first 40 hours and 
// 0.5 * (54-40 overtime hours) up to max 54 weekly allowed hours.
double calculateGrossPay(double payRate, double hoursWorked) {
	double grossPayAmount = 0;

	if (hoursWorked <= MAX_REGULAR_WORK_HOURS) {
		grossPayAmount = payRate * hoursWorked; // Regular pay for the first 40 hours		
	}
	else {

		if (hoursWorked <= MAX_WEEKLY_HOURS) { // if there were any overtime hours
			grossPayAmount = payRate * MAX_REGULAR_WORK_HOURS;
			payRate += (payRate * OVERTIME_PAYRATE_MULTIPLE); 
			grossPayAmount += (payRate * (hoursWorked - MAX_REGULAR_WORK_HOURS)); // 0.5*(54-40)
			return grossPayAmount;
		}
	}
	return grossPayAmount;
}

// function to calculate total deductions
double calculateDeductions(double grossPay, int numberOfExemptions) {

	double taxable = 0;
	double federal = 0;
	double provincial = 0;
	double totalDeduction = 0; // federal and provincial

	taxable = grossPay - (TAXABLE_CONSTANT1 * numberOfExemptions) - TAXABLE_CONSTANT2; // calculate taxable salary

	if (taxable >= 0) { // if taxable pay positive
		federal = taxable * (FEDERAL_CONSTANT1 + (FEDERAL_CONSTANT2  * taxable));
		provincial = federal * PROVINCIAL_CONSTANT1;
		totalDeduction = federal + provincial;
		return totalDeduction;
	}

	return totalDeduction; // if taxable is negative
}

// Function to calculate pension pay
double calculatePension(double grossPay) {
	double pension = 0;
	pension = grossPay * PENSION_CONSTANT2;

	if (pension > PENSION_CONSTANT1) {
		return PENSION_CONSTANT1; // the lesser of 16.50 or 7.7% of gross
	}
	return pension;
}

//Net pay = Gross pay less all deductions.
double calculateNetPay(double grossPay, double deductions, double pension) {
	double netPay = 0;

	if (grossPay >= (deductions - pension)) { // check that the gross pay is positive
		netPay = grossPay - deductions;
		return netPay;
	}
	return 0; // if deductions (inc. pension) are greater than gross pay
}
