//Kenneth Robinson
#include <iostream>
using namespace std;
void problem16();

void main()
{
	problem16();
	system("pause");
}

void problem16()
{
struct person 
{
	char name[20];
	int age;
	
};


typedef person* PersonPtr;

cout << endl << "Problem 16"  << endl;

// add your code here


PersonPtr student;

student = new person;

strcpy( student->name, "Kenneth Robinson");
student->age = 20;
}


