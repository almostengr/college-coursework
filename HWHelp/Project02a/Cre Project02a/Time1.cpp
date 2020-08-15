#include <iostream>
#include "Time1.h"
using namespace std;



Time::Time( int hr, int min, int sec ) { setTime( hr, min, sec ); }

void Time::setTime( int h, int m, int s )
{
	setHour( h );
	setMinute( m );
	setSecond( s );
}

void Time::setHour( int h ) { hour = ( h >= 0 && h < 24 ) ? h : 0; }

void Time::setMinute( int m )
{
	minute = ( m >= 0 && m < 60 ) ? m : 0;
}

void Time::setSecond( int s )
{
	second = ( s >= 0 && s < 60 ) ? s : 0;
}

int Time::getHour( void ) { return hour; }

int Time::getMinute( void ) { return minute; }

int Time::getSecond( void ) { return second; }

void Time::printStandard( void )
{
	cout << ( ( hour % 12 == 0 ) ? 12 : hour % 12 ) << ':'
		<< ( minute < 10 ? "0" : "" ) << minute << ':'
		<< ( second < 10 ? "0" : "" ) << second
		<< ( hour < 12 ? " AM" : " PM" );
}

void Time::tick( void )
{
	setSecond( getSecond() + 1 );

	if ( getSecond() == 0 ) {
		setMinute( getMinute() + 1 );

		if ( getMinute() == 0 )
			setHour( getHour() + 1 );
	}
}