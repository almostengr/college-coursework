#include <iostream>
#include <set>
#include <windows.h>
using namespace std;
int main( ) 
{ 
	LARGE_INTEGER LI1,LI2,LIF; 
	QueryPerformanceFrequency(&LIF);
	double number = (double)LIF.HighPart * UINT_MAX + (double)LIF.LowPart;
	double dt, fq = 1.0/number;
	int f = LIF.LowPart;

	set<int> yo;
	set<int>::iterator j;
	QueryPerformanceCounter(&LI1); // here is where we start timing
  
	// set some initial values:
  
	for (int i=1; i<=5; i++) yo.insert(i*10);  // set: 10 20 30 40 50
	j=yo.find(20);
	yo.erase (j);
	yo.erase (yo.find(40));

  cout << "yo holds:";
  for (j=yo.begin(); j!=yo.end(); j++)
    cout << " " << *j;
  cout << endl;
  QueryPerformanceCounter(&LI2); // here is where we finish timing
dt = ( ( (double)(LI2.HighPart)*UINT_MAX + (double)LI2.LowPart )
- ( (double)(LI1.HighPart)*UINT_MAX + (double)LI1.LowPart ) )*fq;
cout << "\tfinished with time " << dt << endl;
return 0;
}


/*
#include <iostream>
#include <set>
#include <windows.h>
using namespace std;
int main( ) 
{
  set<int> yo;
  set<int>::iterator j;

  // set some initial values:
  for (int i=1; i<=5; i++) yo.insert(i*10);    // set: 10 20 30 40 50

  j=yo.find(20);
  yo.erase (j);
  yo.erase (yo.find(40));

  cout << "yo holds:";
  for (j=yo.begin(); j!=yo.end(); j++)
    cout << " " << *j;
  cout << endl;

  return 0;
}
*/