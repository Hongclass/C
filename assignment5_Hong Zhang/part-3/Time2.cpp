#include "stdafx.h"
#include "Time2.h"

// ***********************************************************
//      Time2 class implementation
// ***********************************************************

// set second, minute and hour within their proper ranges
void  Time2::normalizeTime()
{
   int extraMinutes = second /60;
   second %= 60;
   minute = minute + extraMinutes;
   int extraHours = minute / 60;
   minute %= 60;
   hour = (hour + extraHours) % 24;
}
	
// constructor. initialize time data
Time2::Time2(int h, int m, int s) 
{
   hour = h;
   minute = m;
   second = s;
   // put hour and minute in correct range
   normalizeTime();
}

// assign values to hour, minute and second
void Time2::setHour(int h)
{
	hour = h;
}

void Time2::setMinute(int m)
{
	minute = m;
}

void Time2::setSecond(int s)
{
	second = s;
}

Time2 Time2::duration(const Time2& t)
{
	// convert current time and time t to second
	int currTime = hour * 3600 + minute * 60 + second;
	int tTime = t.hour * 3600 + t.minute * 60 + second;
	return Time2(0, 0, tTime-currTime);
}

// output time in the format <hour>:<minute>:<second> AM or PM
void Time2::writeTime() const
{
	cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
         << ":" << ( minute < 10 ? "0" : "" ) << minute
         << ":" << ( second < 10 ? "0" : "" ) << second
         << ( hour < 12 ? " AM" : " PM" );
}

int Time2::getHour() const
{
   return hour;
}

int Time2::getMinute() const
{
   return minute;
}

int Time2::getSecond() const
{
   return second;
}
