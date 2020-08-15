//slide 3 from notes
#include <iostream>
using namespace std;

int main ( ) {
	cout << "-----Using Pointers-----" << endl;
	double *p, array[5];
	p = array;
	for (int a=0; a<5; ++a) {
		*p = (double) a / (a+1);
		p++; 
		cout << "p inside loop = " << p << endl;}
	p = array;

	cout << *p << endl;
	cout << *(p+1) << endl;
	cout << *(p+3) << endl;
	cout << *(p+4) << endl << endl;

	cout << "-----Using Substring-----" << endl;

	double arrayb[5];
	for (int b=0; b<5; ++b){
		arrayb[b] = (double)b/(b+1);
	}
	cout << arrayb[0] << endl;
	cout << arrayb[0+1] << endl;
	cout << arrayb[0+3] << endl;
	cout << arrayb[0+4] << endl;

	system("pause");
	return 0;
}

/*	OUTPUT

-----Using Pointers-----
p inside loop = 0012FF20
p inside loop = 0012FF28
p inside loop = 0012FF30
p inside loop = 0012FF38
p inside loop = 0012FF40
0
0.5
0.75
0.8

-----Using Substring-----
0
0.5
0.75
0.8
Press any key to continue . . .

OUTPUT */