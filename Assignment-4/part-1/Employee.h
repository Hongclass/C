// This file contains structures and data type definitions needed for the program in file part-1.cpp

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>

struct Employee{
	std::string firstName;
	char lastName[16];
	char status[10];
	int ID;
	int hours;
	double payRate;
	double grossPay;
};

typedef struct Employee Employee;

//Global Constants
# define MAX 500
int    numberOfEmps;    //count of how many employees were loaded into structure
int    totalHours = 0, averagHours = 0;

//Function Prototypes
void searchByName(Employee files[],int i, int numberOfEmps);

void sortByName(Employee files[], int numberOfEmps, int i);
void swapValues(Employee files[], int i, int minIndex);

void listEmployeesHeadings( );
void listEmployeesDetails(Employee files[], int i, int numberOfEmps);

void sortByID(Employee files[], int numberOfEmps);
void swapValues_Id(Employee files[], int startScan, int minIndex);

void searchByActive(Employee files[],int i, int numberOfEmps);

void searchByInactive(Employee files[],int i, int numberOfEmps);

#endif