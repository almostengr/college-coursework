//Kenneth Robinson
// Assignment 2
// CIS-251

#include <iostream>
using namespace std;

int main()
{
	
	cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   char   again; 
   double HOURS_WORKED;
   int REGULAR_HOURS;
   double OVERTIME_HOURS;
   double PAY_RATE = 16.78;
   int DEPENDENTS;
   double GROSS_PAY;
   double NET_PAY;
   
// deductions
	const double SOCIAL_SECURITY = .06;
	double SOCIAL_AFTER;
	const double FEDERAL_INCOME = .14;
	double FEDERAL_AFTER;
	const double STATE_INCOME = .05;
	double STATE_AFTER;
	int INSURANCE;
	const int UNION_DUES = 10;
	double TOTAL_DEDUCTIONS;

// input
  do
   {
	cout << "\nEnter number of hours worked: ";
	cin >> HOURS_WORKED;
	cout << "Enter number of dependents: ";
	cin >> DEPENDENTS;


// process

	if (HOURS_WORKED > 40)
	{
		REGULAR_HOURS = 40;
		OVERTIME_HOURS = HOURS_WORKED - REGULAR_HOURS;
		GROSS_PAY = (REGULAR_HOURS * PAY_RATE) + (OVERTIME_HOURS * PAY_RATE * 1.5);
	}
	else
	{
		REGULAR_HOURS = HOURS_WORKED;
		GROSS_PAY = REGULAR_HOURS * PAY_RATE;
	}

	if (DEPENDENTS > 2)
		INSURANCE = 35;
	else
		INSURANCE = 0;

	SOCIAL_AFTER = SOCIAL_SECURITY * GROSS_PAY;
	FEDERAL_AFTER = FEDERAL_INCOME * GROSS_PAY;
	STATE_AFTER = STATE_INCOME * GROSS_PAY;
    	
	TOTAL_DEDUCTIONS = SOCIAL_AFTER + FEDERAL_AFTER + STATE_AFTER + INSURANCE + UNION_DUES;

	NET_PAY = GROSS_PAY - TOTAL_DEDUCTIONS;

//output

cout << "\nGross Pay: " << GROSS_PAY <<
	"\n Deductions:" <<
	"\n  Social Security Tax: " << SOCIAL_AFTER <<
	"\n  Federal Income Tax: " << FEDERAL_AFTER <<
	"\n  State Income Tax: " << STATE_AFTER <<
	"\nNet Pay: " << NET_PAY << endl;

      cout << "\nDo you want to do another employee(Y/N)? ";
      cin >> again;
} while (again == 'y' || again == 'Y');

   cout << "\nHope they enjoy the money!" << endl;

system("pause");
return 0;
}
