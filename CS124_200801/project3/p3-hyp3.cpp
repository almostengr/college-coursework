#include <iostream>
#include <windows.h> // include this header
#include <list>
using namespace std;
int main( )
{ LARGE_INTEGER LI1,LI2,LIF;
QueryPerformanceFrequency(&LIF);
double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
double dt, fq = 1.0/number;
int f = LIF.LowPart;
list<double> listed;
list<double>::iterator listed_i;
double a;
for(a=1.25; a<100010; ++a){
	listed.push_back(a);
}
cout << "Removing elements from front and back of list: " << endl << endl;

QueryPerformanceCounter(&LI1); // here is where we start timing
listed.pop_front();
QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tRemoving from front takes: " << dt << endl;

QueryPerformanceCounter(&LI1); // here is where we start timing
for (int a=1; a<=50000; a++)
listed.pop_back();
QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tRemoving from back takes: " << dt << endl;

system("pause");
return 0;
}


/* START OF OUTPUT

Removing elements from front and back of list:

        Removing from front takes: 1.63653e-005
        Removing from back takes: 1.01255
Press any key to continue . . .

END OF OUTPUT */