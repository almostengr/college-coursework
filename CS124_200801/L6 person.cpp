#include "2-5-08 person.h"

Person::Person() : weigh(), height(0), name("BigAl") { }

Person::Person(const Weight& w, int h, string n) : weigh(w), height(h), name(n) { }

ostream& operator<<(ostream& os, const Person& p) {
	os << "[" << p.weigh << " " << p.height << " " << p.name << "]";
	return os;
}

istream& operator>>(istream& is, Person& p) {
	is >> p.name >> p.height >> p.weigh;
	return is;
}