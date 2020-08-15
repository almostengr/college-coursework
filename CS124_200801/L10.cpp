//slide 3 from notes
#include <iostream>
using namespace std;

int main ( ) {
	cout << "-----Pointer Example-----" << endl;
	int *p, a, array[10];
	p = array;
	a = 0;
	for ( ; p < (array+10); ++p)
	{ *p = a*a; ++a; }
	p = p -1;
	for ( ; p >= array; --p)
		cout << *p << " ";
	cout << endl << endl;

	cout << "-----Array Example-----" << endl;

	int b, arrayb[10];
	for (b=0; b<10; ++b)
		arrayb[b] = b*b;
	for (b=9; b>=0; --b)
		cout << arrayb[b] << " ";
	cout << endl;

	system("pause");
	return 0;
}

/*	output

-----Pointer Example-----
81 64 49 36 25 16 9 4 1 0

-----Array Example-----
81 64 49 36 25 16 9 4 1 0
Press any key to continue . . .

output */