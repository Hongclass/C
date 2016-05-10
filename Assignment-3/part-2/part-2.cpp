// CIS 2451
// Assignment-3_part-2
// Hong Zhang
// This program allows the user to choose an option from a menu.
// The choices are:
// A. Employee Report in original format 
// B. Search for an Employee 
// C. Employee Report in Sorted based on Last Name 
// D. Employee Report in Sorted based on ID 
// F. Calculate the pay
// X. Quit

#include "stdafx.h"
#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <cctype>   // toupper
#include <iomanip>  // setw
#include <cstring>  // cstring functions strlen, strcmp, strcpy stored in string.h
#include <string>   // string class

using namespace std;

//Global Constants
const int  ARRAY_SIZE = 20,  
		   NAME_SIZE = 16; 

//Declare arrays as global so I don't have to pass the arrays to each function
string firstName[ARRAY_SIZE];
char lastName[ARRAY_SIZE][NAME_SIZE];
int    employeeId[ARRAY_SIZE];
int    hours[ARRAY_SIZE];
double payRate[ARRAY_SIZE] = {0};
double grossPay[ARRAY_SIZE] = {0};

int    numberOfEmps;    //count of how many employees were loaded into arrays

int    totalHours = 0, averagHours = 0;

//Function Prototypes
void loadArray();

void show( );

void listByName( );
void searchByName( );
void sortByName( );
void swapValues(int i, int minIndex);

void listEmployees( );
void listEmployeesHeadings( );
void listEmployeesDetails(int i);

void listByID( );
void sortByID();
void swapValues_Id(int startScan,int minIndex);

void calcPay( );

void displayContinuePrompt( );

//Program starts here   
int _tmain(int argc, _TCHAR* argv[])
{
//Declare and initialize local main variables
    char choice;          

//Load the arrays with data
    loadArray();

//Compute the average hours
    int totalHours = 0, count = 0; // Accumulator
    for (int count = 0; count < numberOfEmps; count++)
   	    totalHours += hours[count];
	averagHours = totalHours / numberOfEmps;

// Input hours rate and calculate the gross pay
void calcPay( );

//check to see what the user wants to do
    do  // while (choice != 'X')
    {
        cout << "\n\tMain Menu\n\n";

        cout << "Enter the letter of the desired menu option. \n"
             << "Press the Enter key after entering the letter. \n \n"

             << " A. Employee Report in original format \n"
             << " B: Search for an Employee \n"
			 << " C. Employee Report in Sorted based on Last Name \n"
			 << " D. Employee Report in Sorted based on ID \n"
             << " X: Exit the Payroll Information Module \n \n"

             << "Choice: ";

        cin >> choice;
        choice =toupper(choice);

        switch (choice)
        {
            case 'A':
                show( );
                break;
            case 'B':
                searchByName( );
                break;
			case 'C':
				listByName( );
                break;
			case 'D':
                listByID( );
                break;
            case 'X':
				cout << "\n\nNow exiting Main Menu...please wait.\n\n";
                break;
            default:
                cout << "\a\n\n Invalid Option Entered - Please try again. \n\n";
        } // end of switch

    } while (choice != 'X');

return 0; 
} // end of main


//Function Definitions
void loadArray( )
{
//Open the file for input; 
    ifstream fileIn;
    fileIn.open("P5.txt");
//If there are any errors, display an error message and return.
    if (fileIn.fail())
    {
        cout << endl << endl
             << "Error: Input file NOT found. " << endl << endl;
        numberOfEmps = 0;
        return;
    }

//Intialize index to load the 1st record into the 1st row of the array 
    int i = 0;

//Read the first record.  Reads into the arrays
    fileIn >> firstName[i] >> lastName[i] >> employeeId[i] >> hours[i];

//Process the remaining records
    while (! fileIn.eof())
    {
        i++;
        if (i == ARRAY_SIZE)
        {
            cout << endl << endl
                 << "Warning: Array Size Exceeded! Size = " << ARRAY_SIZE 
                 << "Processing will continue.  Proceed with caution." << endl << endl;
            break;  // get out of while loop
        }
        fileIn >> firstName[i] >> lastName[i] >> employeeId[i] >> hours[i];
    }

//Save the number of records loaded
    numberOfEmps = i;

//close the file
    fileIn.close();

    return;
}

void show( )
{
	loadArray( );
	listEmployees( );
	return;
}

void listByName( )
{
    sortByName( );
    listEmployees( );
    displayContinuePrompt( );
    return;
}

void searchByName( )
{
//To facilitate the early exit logic, data must be sorted by name 
    sortByName( );

//declare searching variables
    int  stringLength;
    char searchName[NAME_SIZE];
    bool recordFound = false;
    bool headingsDisplayed = false;

//This is a wildcard search
    cout << "\n\nEnter the Employee Last Name to search for: ";
    cin  >> searchName;

//Compare upto the length of the search string
    stringLength = strlen(searchName);     // '\0' not included in length

//strncmp is case sensitive and strnicmp ignores case 
    for (int i = 0; i < numberOfEmps; i++) //walk through the array
    {
        if (strnicmp(lastName[i],searchName, stringLength) == 0) 
        {
            if (! headingsDisplayed)
            {
                listEmployeesHeadings();   //display the headings to cout 
                headingsDisplayed = true;  //only after 1st match
            }                               //display the record found
            recordFound = true;
            listEmployeesDetails(i); 
            //don't get out of the for-loop, because there may be more matches
        }
        else if (strnicmp(lastName[i],searchName, stringLength) > 0)  //early exit 
        {
            cout << endl << "Early exit...";
            break;                            //get out of for-loop
        }
    }

    if (false == recordFound)
    {
        cout << "Employee Name not on file. \n";
    }

    displayContinuePrompt();
    return;
}

void sortByName( )
{
//First for-loop walks through the entire array 
//The current entry is saved as the min value

//Second for-loop looks for values lower than the
//current value.  If one is found, then all values are swapped.
    int    minIndex;
    char   minName[NAME_SIZE];

    for (int i = 0; i < (numberOfEmps - 1); i++)
    {
        minIndex = i;
        strcpy(minName,lastName[i]);

        for (int i2 = i + 1; i2 < numberOfEmps; i2++)
        {
            if (stricmp(lastName[i2],minName) < 0) //if str1 < str2  
            {                                     //a neg number returned 
                minIndex = i2;
                strcpy(minName,lastName[i2]);
            }
        }
        swapValues(i, minIndex);
    }
    return;
}

void swapValues(int i, int minIndex)
{
//temp holding variables
    int    holdInt;
    char   holdName[NAME_SIZE];
    string holdStr;
    int holdDbl;

    holdInt = employeeId[i];
    employeeId[i] = employeeId[minIndex];
    employeeId[minIndex] = holdInt;

//lastName is a cstring - use functions to manipulate
    strcpy(holdName,lastName[i]);
    strcpy(lastName[i],lastName[minIndex]);
    strcpy(lastName[minIndex],holdName);

//firstName is a string object - use overloaded operators
    holdStr = firstName[i];
    firstName[i] = firstName[minIndex];
    firstName[minIndex] = holdStr;

    holdDbl = hours[i];
    hours[i] = hours[minIndex];
    hours[minIndex] = holdDbl;
    return;
}

void sortByID()
{
//First for-loop walks through the entire array 
//The current entry is saved as the min value

//Second for-loop looks for values lower than the
//current value.  If one is found, then all values are swapped.
    int minIndex;
    int minId;
	int startScan;

    for (int startScan = 0; startScan < (numberOfEmps - 1); startScan++)
    {
        minIndex = startScan;
        minId = employeeId[startScan];

        for (int index = startScan + 1; index < numberOfEmps; index++)
        {
            if (employeeId[index] < minId  ) //if str1 < str2  
            {                                     //a neg number returned 
                minIndex = index;
                minId = employeeId[index];
            }
        }
        swapValues_Id(startScan, minIndex);
    }
    return;
}

void swapValues_Id(int startScan, int minIndex)
{
//temp holding variables
    int    holdInt;
    char   holdName[NAME_SIZE];
    string holdStr;
    int holdDbl;

    holdInt = employeeId[startScan];
    employeeId[startScan] = employeeId[minIndex];
    employeeId[minIndex] = holdInt;

//lastName is a cstring - use functions to manipulate
    strcpy(holdName,lastName[startScan]);
    strcpy(lastName[startScan],lastName[minIndex]);
    strcpy(lastName[minIndex],holdName);

//firstName is a string object - use overloaded operators
    holdStr = firstName[startScan];
    firstName[startScan] = firstName[minIndex];
    firstName[minIndex] = holdStr;

    holdDbl = hours[startScan];
    hours[startScan] = hours[minIndex];
    hours[minIndex] = holdDbl;
    return;
}


// List by employeeId
void listByID( )
{
	sortByID( );
    listEmployees( );
    return;
}

void listEmployees( )
{
    listEmployeesHeadings();

    for (int i = 0; i < numberOfEmps; i++)
    {
        listEmployeesDetails(i);
    }
	cout << "\n\nAverage Hours Worked: " << averagHours << " Hrs/Week\n";
    return;
}


void listEmployeesHeadings()
{
	cout << endl<< "        MARKETING COMPANY REPORT PROGRAM" << endl << endl;
	cout << left;
	cout << setw(16) << "FIRST NAME" << setw(16) << "LAST NAME" 
		 << setw(10) << "ID" << setw(14) << "HOURS WORKED"  
		 << setw (14) << "HOURLY RATE" << setw(10) << "TOTAL PAY";
    return;
}

void listEmployeesDetails(int i)
{
	cout << left;    
	cout << setw(16) << firstName[i] << setw(16) << lastName[i] 
	     << setw(10) << employeeId[i] << setw(14) << hours[i] 
		 << setw(14)<< endl;
    return;
}

void calcPay( )
{
	// Get each employee's pay rate and calculate the gross pay
	for (int i = 0 ; i < numberOfEmps; i++)
		{
			cout << "Enter the hourly pay rate for " << lastName[i] << ": ";
	        cin >> payRate[i];
			grossPay[i]=payRate [i] * hours[i];
	    }

	// Write the array to the file
	int count;
	ofstream outputFile;
	outputFile.open("P5.txt");
	for (count =0 ; count < numberOfEmps; count++)
		outputFile << firstName[count] << lastName[count] << employeeId[count]
	               << hours[count] << payRate[count] << grossPay[count] << endl;
    outputFile.close();
}


void displayContinuePrompt()
{
    char prompt;

    cout << "\n\nProcedure completed. Press Enter to continue: ";
    cin.ignore();
    prompt = cin.get();

    system("cls");   //clear screen - DOS

    return;
}
