// CIS 2451
// Assignment-5_part-1
// Hong Zhang
// This program uses a class named Plane to implement 
// the functionality of the Airline Reservation System.

#include "stdafx.h"
#include "plane.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Plane plan; // Definde an instance of the Plane class

	int choice = 0; // to hold the selection to check in the seat 
	bool seats[10] = {false}; 
    int chk_first = 0;
	int chk_eco = 0;

	// store seats which need to check in the plan object.
	plan.setSeats(seats);

	do 
	{
	cout << "Enter 1 to select First Class Seat (Choice: 1)\n"
		 << "Enter 2 to select Economy Seat (Choice: 2)\n"
		 << "Please enter your choice: ";
    cin >> choice;

	// for first class
	if (choice == 1)
	{
		// store some variables in the plan object
		plan.setChecked(chk_first);
	    plan.setStartCount(0);
	    plan.setEndCount(5);
		// handle the first class's check in
		chk_first=plan.checkIn(chk_first, seats, 0, 5);
	}

	//for economy class
	else if (choice == 2)
	{
		// store some variables in the plan object
	    plan.setChecked(chk_eco);
	    plan.setStartCount(5);
	    plan.setEndCount(10);
		// handle the economy class's check in
		chk_eco=plan.checkIn(chk_eco, seats, 5, 10);
	}

	// for default
	else if (choice != 2 && choice != 1)
	{
		cout<< "Invaild input!\n\n"; 
	}

	} while((chk_first+chk_eco) < 11); 

	return 0;
}