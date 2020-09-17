// Mickie Blair
// CIST 2361 - CRN 63227
// Summer 2019 Final Project
// Part 1 Payroll
// Payroll program with four arrays to hold employee ID, hours worked
// pay rate, and gross wages.  The gross wages will be calculated using
// pay rate and hours worked.

#include <iostream>
#include <iomanip>

using namespace std;

void displayIntro();
void getEmployeeData(long[], double[], double[], int);
void calcGrossWages(long[], double[], double[], double[], int);
void displayResults(long[], double[], int);

int main()
{
	

	long empID[] = { 5658845, 4520125, 7895122, 
					8777541, 8451277, 1302850, 
					7580489};					//array for Employee ID
	const int SIZE = 7;							//constant to hold size of arrays
	double hours[SIZE];							//array for hours worked
	double payRate[SIZE];						//array for hourly payrate
	double wages[SIZE];							//array for calculated gross wages

	//display introduction
	displayIntro();

	//get the data
	getEmployeeData(empID, hours, payRate, SIZE);

	//calculate gross wages
	calcGrossWages(empID, hours, payRate, wages, SIZE);

	//display results
	displayResults(empID, wages, SIZE);


}

//display introduction
void displayIntro()
{
	cout << "Payroll Program\n" << endl;
	cout << "The program will display an employee ID then ask the " << endl;
	cout << "user to enter the hours the employee worked and their " << endl;
	cout << "hourly pay rate.  After all data has been entered," << endl;
	cout << "the gross wages will be calculated and displayed" << endl;
}

//get employee data from user
void getEmployeeData(long idNumber[], double hoursWorked[], double hourlyPay[], 
						int arraySize)
{
	//step through employee ID array and ask user for the hours worked
	// and the hourly pay Rate. 

	for (int index = 0; index < arraySize; index++)
	{
		cout << endl;
		cout << "Enter the data for Employee ID: " << idNumber[index];
		cout << "\nHours Worked:  ";
		cin >> hoursWorked[index];

		//validation loop
		while (hoursWorked[index] < 0.0)
		{
			cout << "The hours worked must be 0 or greater." << endl;
			cout << "\nHours Worked:  ";
			cin >> hoursWorked[index];
		}

		cout << "Hourly Pay Rate: $ ";
		cin >> hourlyPay[index];

		//validation loop
		while (hourlyPay[index] < 15.00)
		{
			cout << "The hourly pay must be $15.00 or greater." << endl;
			cout << "Hourly Pay Rate: $ ";
			cin >> hourlyPay[index];
		}
	}
}

//calculate gross wages
void calcGrossWages(long idNumber[], double hoursWorked[], double hourlyPay[],
	double grossWages[], int arraySize)
{
	for (int index = 0; index < arraySize; index++)
	{
		grossWages[index]= hoursWorked[index] * hourlyPay[index];
	}
}

//display results
void displayResults(long idNumber[], double grossWages[], int arraySize)
{
	cout << setprecision(2) << fixed;

	cout << "\nWage Information\n" << endl;

	cout << setw(15) << left << "Employee ID";
	cout<< setw(15) << right << "Gross Wages" << endl;
	cout << "------------------------------\n";

	for (int index = 0; index < arraySize; index++)
	{
		cout << setw(15) << left << idNumber[index];
		cout << setw(4) << right << "$";
		cout << setw(10) << right << grossWages[index] << endl;
	}

}