 #ifndef _TIMECARD_H
#define _TIMECARD_H
#include "Time2.h"

class TimeCard
{
private:
	string workerID;                     // SS Number
	Time2 punchInTime, punchOutTime;	 // Time2 objects
    double payrate;                      // hourly pay
	bool hasPunched;                     // set to true after worker punches out

public:
	TimeCard(const string& ssno, double rate, int punchInHour, int punchInMinute, int punchInSecond);

	// assign t to punchOutTime and set hasPunched to true
	void punchOut(const Time2& t);
		
	// output a log that includes the beginning and ending times for
	// the day's work, the amount of time worked, the pay rate
	// and the earnings.
	void writeSalaryInfo();		
};

#endif