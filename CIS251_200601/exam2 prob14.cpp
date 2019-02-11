//Kenneth Robinson
#include <iostream>
#include <iomanip>
using namespace std;

void problem14();
int getArraySum( const int n[], const int size );



void main()
{

	problem14();

system("pause");
}

void problem14()
{
cout << endl << "Problem 14"  << endl;

// Pass and array to a function
// Sum the array and return the total

const int ARRAYSIZE = 10;
int numbers[ARRAYSIZE] = {10,20,30,40,50,60,70,80,90,100};
int sum = 0;

cout << numbers[9];

sum = getArraySum(numbers, ARRAYSIZE );

cout << "The Array Sum is " << sum;
}


int getArraySum( const int n[], const int size )
{
	int num = 0;
	int sum = 0; 
	int array_num = 0;
	
	array_num = size - 1;


	cout << n[10];
	do{
		num = n[array_num];
		sum = sum + num;
	    array_num--;

	} while (array_num != 0);

	return sum;

// Code getArraySum function here
}