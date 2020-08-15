#include <iostream>
#include <string>
using namespace std;
#ifndef WEIGHT
#define WEIGHT

class Weight {
	int pounds;
	int ounces;
public:
	Weight();
	Weight(int, int);
	Weight(int);
	
	Weight& operator++() ;
	Weight difference(const Weight& w) const;
	Weight operator+(const Weight& w) const;
	bool operator>(const Weight& w) const;

	friend ostream& operator<<(ostream& os, const Weight&);
	friend istream& operator>>(istream& is, Weight&);
};

#endif