#ifndef PLANE_H
#define PLANE_H
#include <iostream>
using namespace std;

// Plane class declaration
class Plane
{
private:
	bool seats_occ[10]; // to hold the whole seats to check in
	int checked;        // to hole the seats which are checked
	int startCount;     
	int endCount;
	int i;
	int j;
	
public:
	// constructor
	Plane();           
	// mutator functions
	void setSeats(bool sts[10]);
	void setChecked(int chk);
	void setStartCount(int start);
	void setEndCount(int end);
	// accessor functions
	int checkIn(int checked, bool seats_occ[10], int startCount, int endCount) const;// check in the seat
};

#endif