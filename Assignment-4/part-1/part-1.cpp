// CIS 2451
// Assignment-4_part-1
// Hong Zhang
// This program uses data structures to build employee files
// and allowws the user to choose an option from a menu.
// The choices are:
// A. Employee Report in original format 
// B. Search for an Employee 
// C. Employee Report in Sorted based on Last Name 
// D. Employee Report in Sorted based on ID 
// E. Employee Report for active employees 
// F. Employee Report for inactive employees
// X. Quit

#include "stdafx.h"
#include "Employee.h" // Header file
#include <fstream>  // file processing
#include <iostream> // cin and cout
#include <cctype>   // toupper
#include <iomanip>  // setw
#include <cstring>  // cstring functions strlen, strcmp, strcpy stored in string.h
#include <string>   // string class

using namespace std; 

int _tmain(int argc, _TCHAR* argv[])
{
	Employee files[MAX];

//Declare and initialize local main variables
    char choice;   
  
//Load the structure with data from the file
//Open the file for input; 
    ifstream fileIn;
    fileIn.open("P5.txt");
//If there are any errors, display an error message and return.
    if (fileIn.fail())
    {
        cout << endl << endl
             << "Error: Input file NOT found. " << endl << endl;
        numberOfEmps = 0;
    } 

//Intialize 
    int i = 0;

//Read the records.
   fileIn >> files[i].firstName >> files[i].lastName >> files[i].ID >> files[i].hours;

//Process the remaining records
    while (! fileIn.eof())
    {
        i++;
        if (i == MAX)
        {
            cout << endl << endl
                 << "Warning: Array Size Exceeded! Size = " << MAX 
                 << "Processing will continue.  Proceed with caution." << endl << endl;
            break;  // get out of while loop
        }
        fileIn >> files[i].firstName >> files[i].lastName >> files[i].ID >> files[i].hours;
    }

//Save the number of records loaded
    numberOfEmps = i;

//close the file
    fileIn.close();

//Compute the average hours
    int totalHours = 0, count = 0; // Accumulator
    for (int count = 0; count < numberOfEmps; count++)
   	    totalHours += files[count].hours;
	averagHours = totalHours / numberOfEmps;

//Input employee's status and hours rate,
//then calculate the grosspay
	for (int j = 0 ; j < numberOfEmps; j++)
		{
			cout << files[j].firstName<< " " << files[j].lastName << ": \n"
				 << "Enter the status (active or inactive): ";
			cin >> files[j].status;
			cin.ignore();
			cout << "Enter the hourly pay rate: ";
	        cin >> files[j].payRate;
			files[j].grossPay = files[j].payRate * files[j].hours;
			cout << "The grossPay is: " << files[j].grossPay << endl<< endl;
	    }

// Write the structure to the file
	// Output file stream object
	ofstream outputFile;
	// Open the file for output
	outputFile.open("P5.txt");
	// Write 
	for (count = 0; count < numberOfEmps;count++)
		outputFile << files[count].firstName << " "<< files[count].lastName << " "
		           << files[count].ID << " " << files[count].hours << " "
				   << files[count].payRate << " " << files[count].grossPay<< " "
				   << files[count].status << endl;
	// Close the file
	outputFile.close();

	//check to see what the user wants to do
    do  // while (choice != 'X')
    {
        cout << "\n\tMain Menu\n\n";

        cout << "Enter the letter of the desired menu option. \n"
             << "Press the Enter key after entering the letter. \n \n"

             << " A. Employee Files in original format \n"
             << " B: Search for an Employee \n"
			 << " C. Employee Report in Sorted based on Last Name \n"
			 << " D. Employee Report in Sorted based on ID \n"
			 << " E. Employee Report for active employees \n"
			 << " F. Employee Report for inactive employees \n"
             << " X: Exit the Payroll Information Module \n \n"

             << "Choice: ";

        cin >> choice;
        choice =toupper(choice);

        switch (choice)
        {
            case 'A':
				{
					//Open the file; 
					int count = 0;
					ifstream fileIn;
					fileIn.open("P5.txt");
					while (count < numberOfEmps && fileIn >>files[count].firstName 
						   >> files[count].lastName >> files[count].ID >> files[count].hours
						   >> files[count].payRate >> files[count].grossPay >> files[count].status)
						count++;
					fileIn.close();

					//Display the original format
					cout << "Employee Files in original format: \n";
					for (count = 0 ; count < numberOfEmps; count++)
						cout << files[count].firstName << " "<< files[count].lastName << " "
		                << files[count].ID << " " << files[count].hours << endl;
					cout << endl;
				}
                break;
            case 'B':
				{
					sortByName(files, numberOfEmps, i);
					searchByName(files,i, numberOfEmps);
				}
                break;
			case 'C':
				{
					sortByName(files, numberOfEmps, i);
			        listEmployeesHeadings();
	                listEmployeesDetails(files, i, numberOfEmps); 
					cout << "\n\nAverage Hours Worked: " << averagHours << " Hrs/Week\n";
				}
                break;
			case 'D':
				{
					sortByID(files, numberOfEmps);
					listEmployeesHeadings();
	                listEmployeesDetails(files, i, numberOfEmps); 	
					cout << "\n\nAverage Hours Worked: " << averagHours << " Hrs/Week\n";
				}
                break;
			case 'E':
				{
					sortByID(files, numberOfEmps);
				    searchByActive(files, i, numberOfEmps);
				    cout << "\n\nAverage Hours Worked: " << averagHours << " Hrs/Week\n";
				}
				break;
			case 'F':
				{
					sortByID(files, numberOfEmps);
					searchByInactive(files,i, numberOfEmps);
					cout << "\n\nAverage Hours Worked: " << averagHours << " Hrs/Week\n";
				}
                break;
            case 'X':
				cout << "\n\nNow exiting Main Menu...please wait.\n\n";
                break;
            default:
                cout << "\a\n\n Invalid Option Entered - Please try again. \n\n";
        } // end of switch

    } while (choice != 'X');

	return 0;
}

// Function Definitions
void listEmployeesHeadings()
{
	cout << endl << "     MARKETING COMPANY REPORT PROGRAM" << endl << endl;
	cout << left;
	cout << setw(16) << "LAST NAME" << setw(8)<< "F."   
		 << setw(8) << "ID" << setw(14) << "HOURS WORKED"  
		 << setw (14) << "HOURLY RATE" << setw(10) << "TOTAL PAY" 
		 << setw(10) << "Status" << endl;
    return;
}

void listEmployeesDetails(Employee files[], int i, int numberOfEmps)
{
	for (int i =0 ; i < numberOfEmps ; i++)
	{ 
	cout.setf(ios::left);
    cout << setw(16) 
         << files[i].lastName
         << files[i].firstName[0] << ".";
    cout.unsetf(ios::left);	     
	cout << setw(10) << files[i].ID << setw(14) << files[i].hours 
		 << setw(14) << files[i].payRate << setw(10) << files[i].grossPay
		 << setw(12) << files[i].status << endl;
	}
	
    return;
}

void sortByName(Employee files[], int numberOfEmps, int i)
{
	//First for-loop walks through the entire array 
//The current entry is saved as the min value

//Second for-loop looks for values lower than the
//current value.  If one is found, then all values are swapped.
    int    minIndex;
    char   minName[16];

    for (int i = 0; i < (numberOfEmps - 1); i++)
    {
        minIndex = i;
        strcpy(minName,files[i].lastName);

        for (int i2 = i + 1; i2 < numberOfEmps; i2++)
        {
            if (stricmp(files[i2].lastName,minName) < 0) //if str1 < str2  
            {                                     //a neg number returned 
                minIndex = i2;
                strcpy(minName,files[i2].lastName);
            }
        }
        swapValues(files, i, minIndex);
    }
    return;
}

void swapValues(Employee files[],int i, int minIndex)
{
//temp holding variables
    int    holdInt;
    char   holdName[16];
    string holdStr;
    int    holdDbl;
	double holdRate;
	double holdPay;
	char   holdStat[10];

    holdInt = files[i].ID;
    files[i].ID = files[minIndex].ID;
    files[minIndex].ID = holdInt;

//lastName is a cstring - use functions to manipulate
    strcpy(holdName,files[i].lastName);
    strcpy(files[i].lastName,files[minIndex].lastName);
    strcpy(files[minIndex].lastName,holdName);

//firstName is a string object - use overloaded operators
    holdStr = files[i].firstName;
    files[i].firstName = files[minIndex].firstName;
    files[minIndex].firstName = holdStr;

    holdDbl = files[i].hours;
    files[i].hours = files[minIndex].hours;
    files[minIndex].hours = holdDbl;

	holdRate = files[i].payRate;
	files[i].payRate = files[minIndex].payRate;
	files[minIndex].payRate = holdRate;

	holdPay = files[i].grossPay;
	files[i].grossPay = files[minIndex].grossPay;
	files[minIndex].grossPay = holdPay;

	strcpy(holdStat,files[i].status);
	strcpy(files[i].status,files[minIndex].status);
	strcpy(files[minIndex].status,holdStat);

    return;
}

void sortByID(Employee files[], int numberOfEmps)
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
        minId = files[startScan].ID;

        for (int index = startScan + 1; index < numberOfEmps; index++)
        {
            if (files[index].ID < minId  ) //if str1 < str2  
            {                                     //a neg number returned 
                minIndex = index;
                minId = files[index].ID;
            }
        }
        swapValues_Id(files, startScan, minIndex);
    }
    return;
}

void swapValues_Id(Employee files[], int startScan, int minIndex)
{
//temp holding variables
    int    holdInt;
    char   holdName[16];
    string holdStr;
    int holdDbl;
	double holdRate;
	double holdPay;
	char holdStat[10];

    holdInt = files[startScan].ID;
    files[startScan].ID = files[minIndex].ID;
    files[minIndex].ID = holdInt;

//lastName is a cstring - use functions to manipulate
    strcpy(holdName,files[startScan].lastName);
    strcpy(files[startScan].lastName,files[minIndex].lastName);
    strcpy(files[minIndex].lastName,holdName);

//firstName is a string object - use overloaded operators
    holdStr = files[startScan].firstName;
    files[startScan].firstName = files[minIndex].firstName;
    files[minIndex].firstName = holdStr;

    holdDbl = files[startScan].hours;
    files[startScan].hours = files[minIndex].hours;
    files[minIndex].hours = holdDbl;

	holdRate = files[startScan].payRate;
	files[startScan].payRate = files[minIndex].payRate;
	files[minIndex].payRate = holdRate;

	holdPay = files[startScan].grossPay;
	files[startScan].grossPay = files[minIndex].grossPay;
	files[minIndex].grossPay = holdPay;

	strcpy(holdStat,files[startScan].status);
	strcpy(files[startScan].status,files[minIndex].status);
	strcpy(files[minIndex].status,holdStat);

    return;
}

void searchByName(Employee files[],int i, int numberOfEmps)
{
//declare searching variables
    int  stringLength;
    char searchName[16];
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
        if (strnicmp(files[i].lastName, searchName, stringLength) == 0) 
        {
            if (! headingsDisplayed)
            {
                listEmployeesHeadings();   //display the headings to cout 
                headingsDisplayed = true;  //only after 1st match
            }                               //display the record found
            recordFound = true;
	        cout.setf(ios::left);
            cout << setw(16) 
                 << files[i].lastName
                 << files[i].firstName[0] << ".";
            cout.unsetf(ios::left);	     
	        cout << setw(10) << files[i].ID << setw(14) << files[i].hours 
		         << setw(14) << files[i].payRate << setw(10) << files[i].grossPay
		         << setw(12) << files[i].status << endl;
            //don't get out of the for-loop, because there may be more matches
        }
        else if (strnicmp(files[i].lastName, searchName, stringLength) > 0)  //early exit 
        {
            cout << endl << "Early exit...\n";
            break;                            //get out of for-loop
        }
    }

    if (false == recordFound)
    {
        cout << "Employee Name not on file. \n";
    }


    return;
}

void searchByActive(Employee files[],int i, int numberOfEmps)
{
	// Declare searching variables
	int sLength;
	char searchA[10] = "active";
	sLength = strlen(searchA);
	bool recordFound = false;
 
	listEmployeesHeadings();

	sLength = strlen(searchA);
	
	for (int i = 0; i < numberOfEmps ; i++)
	{
		if (strnicmp(files[i].status, searchA, sLength) == 0) 
        {
            recordFound = true;
	        cout.setf(ios::left);
            cout << setw(16) 
                 << files[i].lastName
                 << files[i].firstName[0] << ".";
            cout.unsetf(ios::left);	     
           	cout << setw(10) << files[i].ID << setw(14) << files[i].hours 
	        	 << setw(14) << files[i].payRate << setw(10) << files[i].grossPay
	         	 << setw(12) << files[i].status << endl;
            //don't get out of the for-loop, because there may be more matches
        }
    }

    if (false == recordFound)
    {
        cout << "This status is not on file. \n";
    }

    return;
}

void searchByInactive(Employee files[],int i, int numberOfEmps)
{
	// Declare searching variables
	int sLength;
	char searchB[10] = "inactive";
	sLength = strlen(searchB);
	bool recordFound = false;
 
	listEmployeesHeadings();

	sLength = strlen(searchB);
	
	for (int i = 0; i < numberOfEmps ; i++)
	{
		if (strnicmp(files[i].status, searchB, sLength) == 0) 
        {
            recordFound = true;
	        cout.setf(ios::left);
            cout << setw(16) 
                 << files[i].lastName
                 << files[i].firstName[0] << ".";
            cout.unsetf(ios::left);	     
	        cout << setw(10) << files[i].ID << setw(14) << files[i].hours 
	        	 << setw(14) << files[i].payRate << setw(10) << files[i].grossPay
	        	 << setw(12) << files[i].status << endl;
            //don't get out of the for-loop, because there may be more matches
        }
    }

    if (false == recordFound)
    {
        cout << "This status is not on file. \n";
    }

    return;
}