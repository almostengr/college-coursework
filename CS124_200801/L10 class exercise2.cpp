#include <iostream>
#include <string>
using namespace std;

int main ( ) {
	cout << "-----Using Subscripts-----" << endl;
	string s[3];
	char ch = ' ';
	s[0] = "Roll";
	s[1] = "Tide";
	s[2] = s[0] + ch + s[1];
	cout << s[2] << endl;

	cout << "-----Using Pointers-----" << endl;
	string *p, sp[3];
	p = sp;
	*p = "Roll";
	*(p+1) = "Tide";
	*(p+2) = *p + ch + *(p+1);
	cout << *(p+2) << endl;


	system("pause");
	return 0;
}

/* OUTPUT

-----Using Subscripts-----
Roll Tide
-----Using Pointers-----
Roll Tide
Press any key to continue . . .

OUTPUT */