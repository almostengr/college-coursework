//
#include <iostream>
#include <fstream> // I/O
using namespace std;

void print_average(ifstream& input);


void print_average(ifstream& input)  
{  
 double next;              
 double sum = 0;	
 int count = 0;			

//  add code here
double average_of_numbers = 0;
input >> next;

while (input >> next)
{
    a[count] = next;
    count++;

	sum = sum + next;
}

count = count + 1;
average_of_numbers = sum/count;

if (count > 1)
{
	cout << "Sum = " << sum << endl;
	cout << "Count = " << count << endl;
	cout << "Average = " << average_of_numbers << endl;
}
else
	cout << "No Data in File." << endl;
}