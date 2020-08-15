#include <iostream>
#include <cmath>

using namespace std;

class Point {
	double x, y;
public:
	Point() : x(0), y(0) { }
	Point(double a, double b) : x(a), y(b) { }

	void incX() { x = x + 1; }
	void incX(double a) { x = x + a; }
	void incY() { y = y + 1; }
	void incY(double a) { y = y + a; }
	int getX() { return x; }
	int getY() { return y; }
	void set(double a, double b) { x = a; y = b; }
	void print(){cout << "(" << x << "," << y << ")" << endl;}
	double dist(Point& p) {
		double d = sqrt( pow((x-p.x),2) + pow((y-p.y),2) );
		return d;
	}

	Point mid(const Point& p) const {
		Point q;
		q.x = (x + p.x)/2;
		q.y = (y + p.y)/2;
		return q;
	}

	 
};

int main( ) {
	Point p(5,2), q(3,4), r;
	cout << p.dist(q) << endl;
	r = p.mid(q);
	r.print();
	p.incX();
	p.incY();
	p.print();
	q.incX(-3);
	q.incY(-4);
	q.print();
	cout << q.getX() << " " << q.getY() << endl;
	q.set(6,8);
	q.print();
	return 0;
}