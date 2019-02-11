//Kenneth Robinson
#include <iostream>
using namespace std;



class Triangle
{
public:
	void triangle();
	int triangle(double& base, double& height, double& sidea, double& sideb);
	double area();
	double perimeter();
private:
	double base;
	double height;
	double sidea;
	double sideb;
	};
void Triangle::triangle()		
{	
	//default constructor
	
	base = height = sidea = sideb = 0.0;
}

int Triangle::triangle(double& base, double& height, double& sidea, double& sideb)
{	
	//gets variables to calculate
	
	cout << "Length of base:" << endl;
	cin >> base;
	cout << "Length of height:" << endl;
	cin >> height;
	cout << "Length of side A:" << endl;
	cin >> sidea;
	cout << "Length of side B:" << endl;
	cin >> sideb;
	return 0;
}

double Triangle::area()
{
	//calculates area of triangle 

	return base * height * 0.5;
}

double Triangle::perimeter()
{
	//calculates perimeter of triangle 

	return sidea + sideb + base;
}