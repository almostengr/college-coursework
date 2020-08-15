#include "2-5-08 weight.h"

Weight::Weight() : pounds(0), ounces(0) { }

Weight::Weight(int p, int o) : pounds(p), ounces(o) { }

Weight::Weight(int p) : pounds(p), ounces(0) { }
	
Weight& Weight::operator++() {
	++ounces;
	if (ounces == 16) { ++pounds; ounces = 0; }
	return *this;
}

Weight Weight::difference(const Weight& w) const {
	Weight diff;
	if (ounces < w.ounces) {
		diff.ounces = ounces + 16 - w.ounces;
		diff.pounds = pounds - 1 - w.pounds;
	}
	else {
		diff.ounces = ounces - w.ounces;
		diff.pounds = pounds - w.pounds;
	}
	return diff;
}

Weight Weight::operator+(const Weight& w) const {
	Weight total;
	total.ounces = ounces + w.ounces;
	total.pounds = pounds + w.pounds;
	if (total.ounces > 15) {
		++total.pounds;
		total.ounces = total.ounces - 16;
	}
	return total;
}

bool Weight::operator>(const Weight& w) const {
	int t1, t2;
	t1 = pounds * 16 + ounces;
	t2 = w.pounds * 16 + w.ounces;
	if (t1 > t2) return true;
	return false;
}

ostream& operator<<(ostream& os, const Weight& w) {
	os << "[" << w.pounds << "lb. " << w.ounces << "oz.]";
	return os;
}

istream& operator>>(istream& is, Weight& w) {
	// input is in the format [pp/oo]
	char ch;
	is >> ch; // read the "["
	is >> w.pounds;
	is >> ch; // read the "/"
	is >> w.ounces;
	is >> ch; // read the "]"
	return is;
}