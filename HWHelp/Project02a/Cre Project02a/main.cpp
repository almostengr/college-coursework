#include <iostream>
#include "Time1.h"
using namespace std;

const int MAX_TICKS = 3000;

int main()
{
	Time t;

	t.setTime( 23, 59, 57 );

	for ( int ticks = 1; ticks < MAX_TICKS; ++ticks ) {
		t.printStandard();
		cout << endl;
		t.tick();
	}

	return 0;
}