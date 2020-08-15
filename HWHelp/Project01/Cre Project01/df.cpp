#include <iostream>

#include <string.h>
#include <time.h>

#include "df.h"

using namespace std;

// Date constructor that uses functions from ctime
Date::Date()
{
	struct tm *ptr; // pointer of type struct tm
	// which holds calendar time components
	time_t t = time( 0 ); // determine the current calendar time
	// which is assigned to timePtr
	ptr = localtime( &t ); // convert the current calendar time
	// pointed to by timePtr into
	// broken down time and assign it to ptr
	day = ptr->tm_mday; // broken down day of month
	month = 1 + ptr->tm_mon;
	year = ptr->tm_year + 1900; // broken down year since 1900
}

// Date constructor that uses day of year and year
Date::Date( int ddd, int yyyy )
{
	setYear( yyyy );
	convert1( ddd ); // convert to month and day
}

// Date constructor that uses month, day and year
Date::Date( int mm, int dd, int yy )
{
	setYear( yy + 1900 );
	setMonth( mm );
	setDay( dd );
}

// Date constructor that uses month name, day and year
Date::Date( char *mPtr, int dd, int yyyy )
{
	setYear( yyyy );
	convert3( mPtr );
	setDay( dd );
}

// Set the day
void Date::setDay( int d )
{ 
	day = d >= 1 && d <= daysOfMonth() ? d : 1; 
}

// Set the month
void Date::setMonth( int m ) 
{ 
	month = m >= 1 && m <= 12 ? m : 1; 
}

// Set the year
void Date::setYear( int y ) 
{
	year = y >= 1900 && y <= 1999 ? y : 1900; 
}

// Print Date in the form: mm/dd/yyyy
void Date::printDateSlash( void ) const
{ 
	cout << month << '/' << day << '/' << year << '\n'; 
}

// Print Date in the form: monthname dd, yyyy
void Date::printDateMonth( void ) const
{ 
	cout << monthName() << ' ' << day << ", " << year << '\n'; 
}

// Print Date in the form: ddd yyyy
void Date::printDateDay( void ) const
{ 
	cout << convert2() << ' ' << year << '\n'; 
}

// Return the month name
const char *Date::monthName( void ) const 
{
	return monthList( month - 1 ); 
}

// Return the number of days in the month
int Date::daysOfMonth( void ) const
{ 
	return leapYear() && month == 2 ? 29 : days( month ); 
}

// Test for a leap year
int Date::leapYear( void ) const
{
	if ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) )
		return 1;
	else
		return 0;
}

// Convert ddd to mm and dd
void Date::convert1( int ddd ) // convert to mm / dd / yyyy
{
	int dayTotal = 0;

	if ( ddd < 1 || ddd > 366 ) // check for invalid day
		ddd = 1;

	setMonth( 1 );

	for ( int m = 1; m < 13 && ( dayTotal + daysOfMonth() ) < ddd; ++m ) {
		dayTotal += daysOfMonth();
		setMonth( m + 1 );
		setDay( ddd - dayTotal );
		setMonth( m );
	}

}

// Convert mm and dd to ddd
int Date::convert2( void ) const // convert to a ddd yyyy format
{
	int ddd = 0;

	for ( int m = 1; m < month; ++m )
		ddd += days( m );

	ddd += day;
	return ddd;
}

// Convert from month name to month number
void Date::convert3( const char * const mPtr ) // convert to mm / dd / yyyy
{
	int flag = 0;

	for ( int subscript = 0; subscript < 12; ++subscript )
		if ( !strcmp( mPtr, monthList( subscript ) ) ) {
			setMonth( subscript + 1 );
			flag = 1; // set flag
			break; // stop checking for month
		}

		if ( !flag )
			setMonth( 1 ); // invalid month default is january
}

// Return the name of the month
const char *Date::monthList( int mm ) const
{
	char *months[] = { "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December" };

	return months[ mm ];
}

// Return the days in the month
int Date::days( int m ) const
{
	const int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return monthDays[ m - 1 ];
}