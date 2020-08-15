#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int main( ) {
	vector<int> v;
	list<int> l;
	set<int> s;
	int a, b, num;

	cout << "Demonstration of vectors and lists and sets" << endl << endl;
	cout << endl << "Enter the number of elements to be inserted : ";
	cin >> num;

	cout << "Adding " << num << " elements to a vector" << endl;
	for (a=0; a<num; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		v.push_back(b);
	}
	cout << "\tfinished" << endl;

	cout << "Adding " << num << " elements to a list" << endl;
	for (a=0; a<num; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		l.push_back(b);
	}
	cout << "\tfinished" << endl;

	cout << "Adding " << num << " elements to a set" << endl;
	for (a=0; a<num; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		s.insert(b);
	}
	cout << "\tfinished" << endl;

	vector<int>::iterator vi;
	list<int>::iterator li;
	set<int>::iterator si;
	int num2, yes, no;

	cout << endl << endl << "How many numbers do you want to find in the vector/list/set ? ";
	cin >> num2;

	cout << endl << "Finding " << num2 << " values in a vector" << endl;
	yes = 0; no = 0;
	for (a=0; a<num2; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		vi = find(v.begin(), v.end(), b);
		if (vi != v.end()) ++yes; else ++no;
	}
	cout << "\tVector: searched for " << num2 << " values, found " << yes << " and could not find " << no << endl;

	cout << endl << "Finding " << num2 << " values in a list" << endl;
	yes = 0; no = 0;
	for (a=0; a<num2; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		li = find(l.begin(), l.end(), b);
		if (li != l.end()) ++yes; else ++no;
	}
	cout << "\tList: searched for " << num2 << " values, found " << yes << " and could not find " << no << endl;
	
	cout << endl << "Finding " << num2 << " values in a set" << endl;
	yes = 0; no = 0;
	for (a=0; a<num2; ++a) {
		b = ( (rand()+1)*(rand()+1) ) % num + 1;
		si = s.find(b);
		if (si != s.end()) ++yes; else ++no;
	}
	cout << "\tSet: searched for " << num2 << " values, found " << yes << " and could not find " << no << endl;

	system("pause");
	return 0;
}