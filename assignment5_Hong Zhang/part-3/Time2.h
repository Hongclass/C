#ifndef _TIME2_H
#define _TIME2_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Time2
{
private:
	int hour, minute, second;	// data members

	// utility function sets the hour value in the range 0 to 23,
	// the minute value in the range 0 to 50 and 
    // the second value in the range 0 to 50
	void normalizeTime(); 

public:
	// constructor initializes hour, minute and second
	Time2(int h = 0, int m = 0, int s =0);
	      
	// assign a value to hour
	void setHour(int h);

	// assign a value to minute
	void setMinute(int m);

	// assign a value to second
	void setSecond(int s);

    // return the length of time from the current time to some later
	// time t as a time24 value
	Time2 duration(const Time2& t);

	// display on the screen the current time in standard-time format (hh:mm:ss AM or PM)
    void writeTime() const;
		
	// return the hour value for the current time
    int getHour() const;
	
	// return the minute value for the current time    
    int getMinute() const;
		
	// return the second value for the current time    
	int getSecond() const;
};


#endif