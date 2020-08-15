#include "weight.h"
#ifndef PERSON
#define PERSON

class Person {
	Weight weigh;
	int height;
	string name;
public:
	Person();
	Person(const Weight&, int, string);

	friend ostream& operator<<(ostream&, const Person&);
	friend istream& operator>>(istream&, Person&);
};

#endif