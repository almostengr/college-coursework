#include <iostream>
#include <windows.h> // include this header
#include <vector>
using namespace std;
int main( )
{ LARGE_INTEGER LI1,LI2,LIF;
QueryPerformanceFrequency(&LIF);
double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
double dt, fq = 1.0/number;
int f = LIF.LowPart;
vector<int> v;
vector<int>::iterator vi;
vector<int>::reverse_iterator vr;
int a;
for (a=1; a<2000000; ++a)
v.push_back(a);
cout << "Iterating through the vector: \n\n";
QueryPerformanceCounter(&LI1); // here is where we start timing
for(vi=v.begin(); vi!=v.end();++vi)
QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tIterating forward takes: " << dt << endl;

QueryPerformanceCounter(&LI1); // here is where we start timing
for(vr=v.rbegin(); vr!=v.rend();++vr)
QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tIterating backwards takes: " << dt << endl;

system("pause");
return 0;
}


/*	START OF OUTPUT
 

 Iterating through the vector:

        Iterating forward takes: 3.35133
        Iterating backwards takes: 13.8331
Press any key to continue . . .


END OF OUTPUT	*/