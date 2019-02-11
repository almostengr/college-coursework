//Kenneth Robinson
#include <iostream>
using namespace std;



class Circle
{ public:
	circle();
	calc_circle(double& radius, double& area, double& circumference);
	get_info(double radius, double area, double circumference);
  private:
	double radius;
	double area;
	double circumference;

};

Circle::circle()
{
	radius = 1;
	return 0;
}

Circle::calc_circle(double& radius, double& area, double& circumference)
{
	cin >> radius;
	circumference = 2 * 3.14 * radius;
	area = radius * radius * 3.14;
	return 0;
}
