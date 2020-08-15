#include <iostream>
#include <windows.h> // include this header
#include <list>
using namespace std;
int main( ) 
{ 
	LARGE_INTEGER LI1,LI2,LIF; 
	QueryPerformanceFrequency(&LIF);
	
	double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
	double dt, fq = 1.0/number;
	int f = LIF.LowPart;
	
	list<int> x; 
	
	QueryPerformanceCounter(&LI1); // here is where we start timing
	for (int i=1; i<=100000; i++)
	x.insert(x.begin(),i);
	QueryPerformanceCounter(&LI2); // here is where we finish timing
	dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
	- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
	cout << "\tfinished with time " << dt << endl;
	
	QueryPerformanceCounter(&LI1); // here is where we start timing	
	for (int a=100000; a>=1; a--)
	x.insert(x.begin(),a);
	QueryPerformanceCounter(&LI2); // here is where we finish timing
	dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
	- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
	cout << "\tfinished with time " << dt << endl;

	return 0;
}