#include "df.h"

#include <iostream>
using namespace std;


int main()
{
	Date d1( 7, 4, 98 ), d2( 86, 1999 ),
		d3, d4( "September", 1, 1998 );

	d1.printDateSlash(); // format m / dd / yy
	d2.printDateSlash();
	d3.printDateSlash();
	d4.printDateSlash();
	cout << '\n';

	d1.printDateDay(); // format ddd yyyy
	d2.printDateDay();
	d3.printDateDay();
	d4.printDateDay();
	cout << '\n';

	d1.printDateMonth(); // format "month" d, yyyy
	d2.printDateMonth();
	d3.printDateMonth();
	d4.printDateMonth();
	cout << endl;

	return 0;
}