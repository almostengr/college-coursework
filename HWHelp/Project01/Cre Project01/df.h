#ifndef DateFormat
#define DateFormat

#include <time.h>
#include <string.h>

class Date {
public:
	Date();
	Date( int, int );
	Date( int, int, int );
	Date( char *, int, int );
	void setMonth( int );
	void setDay( int );
	void setYear( int );
	void printDateSlash( void ) const;
	void printDateMonth( void ) const;
	void printDateDay( void ) const;
	const char *monthName( void ) const;
	int leapYear( void ) const;
	int daysOfMonth( void ) const;
	void convert1( int );
	int convert2( void ) const;
	void convert3( const char * const );
	const char *monthList( int ) const;
	int days( int ) const;
private:
	int day;
	int month;
	int year;
};

#endif