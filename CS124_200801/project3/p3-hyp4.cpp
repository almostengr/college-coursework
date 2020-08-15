#include <iostream>
#include <windows.h> // include this header
#include <set>
#include <algorithm>
using namespace std;

int main( ){

	set<int> s;
	set<int>::iterator si, fi;
	int r, w,x,y,z;
	cout << "First enter the desired size of testing set: ";
	cin >> z;

	cout << "Choose a number at random between 1 and " << z << ": ";
	cin >> r;
	cout << "The test number wil be the " << r << "th number we put in the set." << endl;

	for (x=0;x<z; ++x){
		y = rand()%100;
		if(x==r-1)
			w=y;
		s.insert(y);
	}

	LARGE_INTEGER LI1,LI2,LIF;
	QueryPerformanceFrequency(&LIF);
	double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
	double dt, fq = 1.0/number;
	int f = LIF.LowPart;

	QueryPerformanceCounter(&LI1); // here is where we start timing

	fi = s.find(w);

	QueryPerformanceCounter(&LI2); // here is where we finish timing
	dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
		- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
	cout << endl << "The time for this one is: " << dt << endl;

	system("pause");
	return 0;
}

/*	START OF OUTPUT

First enter the desired size of testing set: 5
Choose a number at random between 1 and 5: 2
The test number wil be the 2th number we put in the set.

The time for this one is: 7.06995e-006
Press any key to continue . . .

END OF OUTPUT */