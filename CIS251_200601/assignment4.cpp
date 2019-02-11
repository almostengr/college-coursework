/*	 Author: Kenneth Robinson
	Assignment 4
	CIS 251
*/

#include <iostream>
using namespace std;

//conversion values
const double KILOGRAMS_PER_POUND = .454;	//changes kilograms to pounds
const double POUNDS_PER_KILOGRAM= 2.2046;	//changes pounds to kiograms
const int GRAMS_PER_KILOGRAM = 1000;		//changes grams to kilograms
const int OUNCES_PER_POUND = 16;			//changes ounces to pounds

//Functions
void input_kg_g(int& kilograms, double& grams);		//gets input in kilograms and grams
void input_lb_oz(int& pounds, double& ounces);		//get input in pounds and ounces
void convert_kg_to_lb(int kilograms, double grams, int& pounds, double& ounces);	//converts kilograms and grams to pounds and ounces
void convert_lb_to_kg(int pounds, double ounces, int& kilograms, double& grams);	//converts pounds and ounces to kilograms and grams
void kilograms_pounds();	//calls other functions for kilograms to pounds conversion
void pounds_kilograms();	//calls other functions for pounds to kilograms conversion
void output(int kilograms, double grams, int pounds, double ounces);	//displays output of conversion

void main()
{  int which;        // which conversion
   char again;       // repeat loop
   
   cout << "This program can convert pounds and ounces to kilograms and grams\n"
        << "and can convert kilograms and grams to pounds and ounces." << endl;
   do 
   {  cout << "\nEnter 1 for Kilograms to Pounds or\n" 
           << "Enter 2 for Pounds to Kilograms\n"; 
      cout << "Your choice: ";
      cin >> which; 
      
      if (which == 1) 
         kilograms_pounds();	//calls conversion for kilograms to pounds
      else if (which == 2)
         pounds_kilograms();	//calls conversion for pounds to kilograms
      else
          cout << "\n\a" << which << " is an invalid option." << endl;

      cout << "\nDo you want to do another conversion of either kind (Y/N)? ";
      cin >> again; 
   }
	while ( again == 'y' || again == 'Y');

   cout << "\nEnd of Program!" << endl;
	system("pause");
}

void kilograms_pounds()
//function for converting kilograms and grams to pounds and ounces
{
	int pounds, kilograms;		//
	double grams, ounces;		//
	char again;					//repeat conversion
	
	do
	{
		input_kg_g(kilograms, grams);		//calls for input of kilograms and grams
		convert_kg_to_lb(kilograms, grams, pounds, ounces);		//calls for conversion of kilograms and grams to pounds and ounces
		output(kilograms, grams, pounds, ounces);		//calls for output of conversion
		
		cout << "Do you want to do another kilograms to pounds conversion (Y/N)?";
		cin >> again;
	}
	while ( again == 'y' || again == 'Y');
}

void pounds_kilograms()
//function for converting pounds and ounces to kilograms and grams
{
	int pounds, kilograms;
	double grams, ounces;
	char again;					//repeat conversion
	
	do
	{
		input_lb_oz(pounds, ounces);		//calls for input of pounds and ounces
		convert_lb_to_kg(pounds, ounces, kilograms, grams);		//cals for conversion of pounds and ounces to kilograms and grams
		output(kilograms, grams, pounds, ounces);		//calls for output of conversion
	
		cout << "Do you want to do another pounds to kilograms conversion (Y/N)?";
		cin >> again;
	}
	while ( again == 'y' || again == 'Y');
}

void input_kg_g(int& kilograms, double& grams)
//gets input in kilograms and grams
{
	cout << "Enter the number of kilograms as an integer: ";
	cin >> kilograms;
	cout << "Enter the number of grams as a double: ";
	cin >> grams;
}

void input_lb_oz(int& pounds, double& ounces)
//get input in pounds and ounces
{
	cout << "Enter the number of pounds as an integer: ";
	cin >> pounds;
	cout << "Enter the number of ounces as a double: ";
	cin >> ounces;
}

void convert_kg_to_lb(int kilograms, double grams, int& pounds, double& ounces)
//converts kilograms to pounds
{
	double total_kg;		//total kilograms and grams
	double total_lb;		//total pounds and ounces
	
	total_kg = (grams * GRAMS_PER_KILOGRAM) + kilograms;
	total_lb = total_kg * KILOGRAMS_PER_POUND;
	pounds = int(total_lb);
	ounces = (total_lb - pounds) * OUNCES_PER_POUND;
}

void convert_lb_to_kg(int pounds, double ounces, int& kilograms, double& grams)
//converts pounds to kilograms
{
	double total_lb;		//total ounces and pounds
	double total_kg;		//total kilograms and grams

	total_lb = (ounces * OUNCES_PER_POUND) + pounds;
	total_kg = total_lb * POUNDS_PER_KILOGRAM;
	kilograms = int(total_lb);
	grams = (total_lb - kilograms) / GRAMS_PER_KILOGRAM;
}

void output(int kilograms, double grams, int pounds, double ounces)
//displays finalized conversion
{
	cout.setf( ios::showpoint );
	cout.setf( ios::fixed );
	cout.precision(1); 
	cout << "\n" << kilograms << " kilograms and " << grams << " grams " 
		<< "corresponds to\n" << pounds << " pounds and " << ounces << " ounces." << endl; 
}
