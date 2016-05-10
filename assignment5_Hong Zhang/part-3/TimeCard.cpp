#include "stdafx.h"
#include "TimeCard.h"

// ***********************************************************
//      TimeCard class implementation
// ***********************************************************

// use initialization list to initialize data members
TimeCard::TimeCard(const string& ssno, double rate, int punchInHour,  int punchInMinute, int punchInSecond)
{
	workerID = ssno;
    payrate = rate;
    hasPunched = false;
	punchInTime = Time2(punchInHour, punchInMinute, punchInSecond);
	punchOutTime = Time2();
}

void TimeCard::punchOut(const Time2& t)
{
	punchOutTime = t;
	hasPunched = true;
}

void TimeCard::writeSalaryInfo()
{
	// total time worked
	Time2 timeWorked = punchInTime.duration(punchOutTime);
	// hours and fraction of an hour worked
	double hoursWorked = timeWorked.getHour() + timeWorked.getMinute()/60.0 + timeWorked.getSecond()/3600.0;

	// format the output
	// format the output
	cout << "Worker  ID: " << workerID << endl;
	cout << "Start Time: ";
	punchInTime.writeTime();
	cout << endl;
	cout << "  End Time: ";
	punchOutTime.writeTime();
	cout << endl;
	cout << setprecision(2) << fixed;
	cout << "At Pay Rate: $" << payrate << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Per hour, the days earnings are: $" << payrate * hoursWorked << endl;
}