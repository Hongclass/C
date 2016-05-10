#include "stdafx.h"
#include "Plane.h"

// ***********************************************************
//      Plane class implementation
// ***********************************************************

Plane::Plane()
{
	bool seats_occ[10]={false};
	int checked=0;
	int startCount=0;
	int endCount=0;
	int i=0;
	int j=0;
}

// set an array named seats to hold the whole seats needed to check in
void Plane::setSeats(bool sts[10])  
{	
	for(int j = 0; j < 10; j++)        // set false before no one check in
	seats_occ[j] = sts[j];
}

// set the seats which are checked
void Plane::setChecked(int chk)
{
	checked = chk;
}

void Plane::setStartCount(int start)
{
	startCount = start;
}

void Plane::setEndCount(int end)
{
	endCount = end;
}

// check in the seats and return the checked numbers
int Plane::checkIn(int checked, bool seats[10], int startCount, int endCount) const
{
	// check in available seats 
	if (checked != 5)
	{
		for (int i = startCount; i < endCount; i++)
		{
			if(seats[i] == false)
			{
				seats[i] = true;
				checked++;
				cout << "Seat #" << i+1 << " is selected.\n\n";
				break;
			}
		}
	}
	// shows no seats to check in 
	else if(checked == 5)
	cout << "No more seats are available for your selection.\n\n";

	return checked;
}
