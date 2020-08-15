#ifndef Time1
#define Time1

class Time {
public:
	Time( int = 0, int = 0, int = 0 );
	void setTime( int, int, int );
	void setHour( int );
	void setMinute( int );
	void setSecond( int );
	int getHour( void );
	int getMinute( void );
	int getSecond( void );
	void printStandard( void );
	void tick( void );
private:
	int hour;
	int minute;
	int second;
};

#endif