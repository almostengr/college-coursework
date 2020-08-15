#include <iostream>

using namespace std;

class Weight {
	int pounds;
	int ounces;
public:
	Weight() : pounds(0), ounces(0) { }
	Weight(int p, int o) : pounds(p), ounces(o) { }
	Weight(int p) :  ounces(0) { }
	
	Weight& operator++()  {
		++ounces;
		if (ounces == 16) { ++pounds; }
		return *this;
	}

	Weight difference(const Weight& w) const {
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

	Weight operator+(const Weight& w) const {
		Weight total;
		total.ounces = ounces + w.ounces;
		total.pounds = pounds + w.pounds;
		if (total.ounces > 15) {
			++total.pounds;
			total.ounces = total.ounces - 16;
		}
		return total;
	};

	bool operator>(const Weight& w) const {
		int t1, t2;
		t1 = pounds * 16 + ounces;
		t2 = w.pounds * 16 + w.ounces;
		if (t1 > t2) return true;
		return false;
	}

	friend ostream& operator<<(ostream& os, const Weight&);
	friend istream& operator>>(istream& is, Weight&);
};

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

int main( ) {
	Weight w1, w2(100,10), w3(50,10);
	cout << w3 << endl;
	cout << "Enter a weight of your choice [pp/oo] : ";
	cin >> w1;
	cout << "you just entered : " << w1 << endl;
	++w1;
	cout << w1 << endl;
	Weight w4;
	w4 = w2 + w3;
	cout << w4 << endl;
	w4 = w4 + 20;
	cout << w4 << endl;
	if (w2 > w3) cout << "correct" << endl;
	else cout << "incorrect" << endl;
	cout << "w1 is : " << w1 << endl;
	cout << "w2 is : " << w2 << endl;
	cout << "w3 is : " << w3 << endl;
	cout << w2.difference(w3) << endl;
	cout << w1.difference(w2) << endl;

	return 0;
}