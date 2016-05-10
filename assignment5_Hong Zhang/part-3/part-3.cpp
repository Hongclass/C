// CIS 2451
// Assignment5_part-3
// Hong Zhang
// This program designs a TimeCard class that allows a company 
// to pay a worker for a day’s labor. The worker uses the time 
// card to punch in at the beginning of the day and punch out 
// upon quitting. The company immediately pays the worker based 
// on the hourly rate and the length of time on the job. Besiede,
// this program Uses composition and incorporate the Time2 class 
// to keep track of the punchInTime (start time) and punchOutTime 
// (end time) in the TimeCard class. 

#include "stdafx.h"
#include "TimeCard.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const double PAYRATE = 12.50; // posted pay rate

	string id_1, id_2;                    // employee data input from the keyboard
	int inHour_1  = 0,  inMinute_1 = 0, inSecond_1  = 0;
	int outHour_1 = 0, outMinute_1 = 0, outSecond_1 = 0;
	int inHour_2  = 0,  inMinute_2 = 0, inSecond_2  = 0;
	int outHour_2 = 0, outMinute_2 = 0, outSecond_2 = 0;
	
	// input the data of first employee
	cout << "Enter the employee's Worker ID: ";
	cin >> id_1;

	cout << "Enter arrival Time: " << endl;
	cout << "Hour: ";
	cin >> inHour_1; 
    cout << "Minute: ";		
	cin >> inMinute_1;
	cout << "Second: ";
	cin >> inSecond_1;
	
	cout << "Enter end Time: " << endl;
	cout << "Hour: ";
	cin >> outHour_1; 
    cout << "Minute: ";		
	cin >> outMinute_1;
	cout << "Second: ";
	cin >> outSecond_1;
	cout << endl;

	// input the data of second employee
	cout << "Enter the employee's Worker ID: ";
	cin >> id_2;

	cout << "Enter arrival Time: " << endl;
	cout << "Hour: ";
	cin >> inHour_2; 
    cout << "Minute: ";		
	cin >> inMinute_2;
	cout << "Second: ";
	cin >> inSecond_2;

	cout << "Enter end Time: " << endl;
	cout << "Hour: ";
	cin >> outHour_2; 
    cout << "Minute: ";		
	cin >> outMinute_2;
	cout << "Second: ";
	cin >> outSecond_2;
	cout << endl;

	// declare a TimeCard object for the first employee
	TimeCard employee_1(id_1, PAYRATE, inHour_1, inMinute_1, inSecond_1);
	// declare two Time2 objects for the first employee's punch in and punch out
	Time2 checkIn_1(inHour_1, inMinute_1, inSecond_1);
	Time2 checkOut_1(outHour_1, outMinute_1, outSecond_1);
	// calculate the time that first employee has worked
	employee_1.punchOut(checkOut_1);
	// output
	employee_1.writeSalaryInfo();
	cout << endl;

	// declare a TimeCard object for the second employee
	TimeCard employee_2(id_2, PAYRATE, inHour_2, inMinute_2, inSecond_2);
	// declare two Time2 objects for the second employee's punch in and punch out
	Time2 checkIn_2(inHour_2, inMinute_2, inSecond_2);
	Time2 checkOut_2(outHour_2, outMinute_2, outSecond_2);
	// calculate the time that second employee has worked
	employee_2.punchOut(checkOut_2);
	// output
	employee_2.writeSalaryInfo();

	return 0;
}
