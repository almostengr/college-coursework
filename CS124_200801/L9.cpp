#include <iostream>
#include <string>
using namespace std;

int main( ) {
	int *p1, *p2, v1, v2;	
	v1=0;
	p1=&v1;
	*p1=42;
	v2=0;
	p2=&v2;
	*p2=35;

	cout << "v1 = " << v1 << " v2 = " << v2 << endl;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << endl;

	p1 = p2;
	*p1 = *p2;

	cout << " v1 = " << v1 << " v2 = " << v2 << endl;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << endl;

	system("pause");
	return 0;
}

/*	OUTPUT

v1 = 42 v2 = 35
*p1 = 42 *p2 = 35
v1 = 42 v2 = 35
*p1 = 35 *p2 = 35
Press any key to continue . . .

OUTPUT	*/