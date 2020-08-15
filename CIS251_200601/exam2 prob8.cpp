//
#include <iostream>
using namespace std;



class Triangle
{
public:
    int triangle(double base, double height, double sidea, double sideb);
	int triangle();
	double area();
	double perimeter();
private:
	double base;
	double height;
	double sidea;
	double sideb;
	};

int Triangle::triangle()
{
	base = 6.0;
	height = 4.0;
	sidea = 5.0;
	sideb = 5.0;
	return 0;
}
int Triangle::triangle(double base, double height, double sidea, double sideb)
{	
	cout << "\nLength of Base:" << base << endl;
	cout << "\nLength of Height:" << height << endl;
	cout << "\nLength of Side A:" << sidea << endl;
	cout << "\nLength of Side B:" << sideb << endl;
	return 0;
}
	
double Triangle::area()
{
	double area;
	area = base * height * 0.5;
	cout << "\nArea: " << area << endl;
    return 0;
}
double Triangle::perimeter()
{
	double per;
	per = sidea + sideb + base;
	cout << "\nPerimeter: " << per << endl;
	return 0;
}

void main()
{
	Triangle mytriangle;
	
	cout << "This program will calculate the area and perimeter \n"
		 << "of a triangle with preset values." << endl;

	mytriangle.triangle();
	mytriangle.triangle(6,4,5,5);
	mytriangle.area();
	mytriangle.perimeter();

	system("pause");
}