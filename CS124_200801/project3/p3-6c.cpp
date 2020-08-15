#include <iostream>
#include <windows.h> 
#include <deque>
using namespace std;
int main( ) 
{ 
	LARGE_INTEGER LI1,LI2,LIF; 
	QueryPerformanceFrequency(&LIF);
	
	double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
	double dt, fq = 1.0/number;
	int f = LIF.LowPart;
	
	deque<int> d; 
	QueryPerformanceCounter(&LI1); // here is where we start timing
	for (int a=1; a<=100000; a++)
	d.insert(d.begin(),a);
	QueryPerformanceCounter(&LI2); // here is where we finish timing
	dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
	- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
	cout << "\tfinished with time " << dt << endl;
	

	QueryPerformanceCounter(&LI1); // here is where we start timing	
	for (int a=100000; a>=1; a--)
	d.insert(d.begin(),a);
	QueryPerformanceCounter(&LI2); // here is where we finish timing
	dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
	- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
	cout << "\tfinished with time " << dt << endl;
	
	return 0;
}
