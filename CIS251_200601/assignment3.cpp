// Author: 
// Date: Feb 16, 2006
// CIS-251

#include <iostream>  
using namespace std;

double liters;		//amount in liters
double gallons;		//amount in gallons
double miles;		//number of miles
double miles_per_gallon(double gallons, double miles);
double liters_gallon(double liters);		//convert liters to gallons

int main()
{
   double mpg;
	char   again;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);

   cout << "This program will calculate miles per gallon" << endl;
   cout << "from liters to gallons." << endl;
   
   do
   {  cout << "\n\nEnter number of liters: ";
      cin >> liters;
      cout << "\nEnter number of miles: ";
      cin >> miles;

	  gallons = liters_gallon(liters);

	  mpg = miles_per_gallon(gallons, miles);

      cout.precision(2);
      cout << "\nWith " << liters << " liters and " << miles <<" miles,\n";
      cout << "the miles per gallon would be " << mpg << endl;

      cout << "\nDo you want to do another calculation(Y/N)? ";
      cin >> again;
   } while (again == 'y' || again == 'Y');

   cout << "\nEnd of Program!" << endl;

    system("pause"); // Hold message on screen until key is pressed

   return 0;
}

double liters_gallon(double liters)
{
	double liters_gallon;

	liters_gallon = liters * 0.264179;

	return liters_gallon;
}

double miles_per_gallon(double gallons, double miles)
{
   double mpg;   

   mpg = miles/gallons;

   return mpg;
}
