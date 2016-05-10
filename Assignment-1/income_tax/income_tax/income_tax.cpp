// CIS2541
// Assignment-1
// Hong Zhang
// This program will compute personal income tax 
// based on the filing status and taxable income. 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int choice; // To hold a menu choice
	int income; // To hold the number of income
	double income_tax; // To hold the personal income tax
	string name; // To hold the name who need to 
                 // calculate the US federal income tax 

	// Constants for marginal tax rate
	const double RATE_1 = 0.35,
	             RATE_2 = 0.33,
				 RATE_3 = 0.28,
				 RATE_4 = 0.25,
				 RATE_5 = 0.15,
				 RATE_6 = 0.10;

	// Constants for income range.
	const int SINGER_INCOME_1 = 372950,
		      SINGER_INCOME_2 = 171550,
			  SINGER_INCOME_3 = 82250,
			  SINGER_INCOME_4 = 33950,
		      SINGER_INCOME_5 = 8350,

			  MARRIED_JOINTLY_INCOME_1 = 372950,
			  MARRIED_JOINTLY_INCOME_2 = 208850,
			  MARRIED_JOINTLY_INCOME_3 = 137050,
			  MARRIED_JOINTLY_INCOME_4 = 67900,
			  MARRIED_JOINTLY_INCOME_5 = 16700,

			  MARRIED_SEPARATELY_INCOME_1 = 186475,
			  MARRIED_SEPARATELY_INCOME_2 = 104425,
			  MARRIED_SEPARATELY_INCOME_3 = 68525,
			  MARRIED_SEPARATELY_INCOME_4 = 33950,
			  MARRIED_SEPARATELY_INCOME_5 = 8350,

			  HEAD_OF_HOUSEHOLD_INCOME_1 = 372950,
			  HEAD_OF_HOUSEHOLD_INCOME_2 = 190200,
			  HEAD_OF_HOUSEHOLD_INCOME_3 = 117450,
			  HEAD_OF_HOUSEHOLD_INCOME_4 = 45500,
			  HEAD_OF_HOUSEHOLD_INCOME_5 = 11950,

			  MIN_INCOME = 0;


	// Constant for menu choices
	const int SINGLE_CHOICE = 1,
		      MARRIED_JOINTLY_CHOICE = 2,
		      MARRIED_SEPARATELY_CHOICE =3,
		      HEAD_OF_HOUSEHOLD_CHOICE = 4,
			  QUIT_CHOICE = 5;
	
	// Display the menu and get a choice.	
	cout << "This program calculates personal income tax \n";
	cout << "based on the filing status and taxable income.\n";
	cout << " \n";
	
	cout << "Enter your name: ";
			getline(cin, name);
	cout << " \n";

	cout << "\tUS Federal Personal Income Tax Menu\n\n"
		 << "1. Single\n"
		 << "2. Married Filing Jointly or Qualifying Widow(er)\n"
		 << "3. Married Filing Separately\n"
		 << "4. Head of Household\n"
		 << "5. Quit the Program\n\n"
		 << "Enter your choice: ";
	cin >> choice;
	
	// Set the numeric output formatting
	cout << fixed << showpoint << setprecision(2);

	// Respond to the user's menu selection.
	switch (choice)
	{
    	case SINGLE_CHOICE:
			cout << "Enter your income: $";
			cin >> income;
			// Validate the input and determine the income tax
			if (income >= MIN_INCOME)
			{
    	// Determine the income tax
				if (income > SINGER_INCOME_1)
					{
						income_tax = income * RATE_1;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > SINGER_INCOME_2)
					{
						income_tax = income * RATE_2;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > SINGER_INCOME_3)
					{
						income_tax = income * RATE_3;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > SINGER_INCOME_4)
					{
						income_tax = income * RATE_4;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > SINGER_INCOME_5)
					{
						income_tax = income * RATE_5;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else 
					{
						income_tax = income * RATE_6;
				        cout << "Your income tax is $" << income_tax << endl;
				}
			}
			else 
			{
				// An invalid income was entered.
				cout << "That is an invalid income. Run the program\n"
					<< "again and enter a value greater than zero.\n";
			}
				break;

		case MARRIED_JOINTLY_CHOICE:
			cout << "Enter your income: ";
			cin >> income;
			// Validate the input and determine the income tax
			if (income >= MIN_INCOME)
			{
    	// Determine the income tax
				if (income > MARRIED_JOINTLY_INCOME_1)
					{
						income_tax = income * RATE_1;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_JOINTLY_INCOME_2)
					{
						income_tax = income * RATE_2;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_JOINTLY_INCOME_3)
					{
						income_tax = income * RATE_3;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_JOINTLY_INCOME_4)
					{
						income_tax = income * RATE_4;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_JOINTLY_INCOME_5)
					{
						income_tax = income * RATE_5;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else 
					{
						income_tax = income * RATE_6;
				        cout << "Your income tax is $" << income_tax << endl;
				}
			}
			else 
			{
				// An invalid income was entered.
				cout << "That is an invalid income. Run the program\n"
					<< "again and enter a value greater than zero.\n";
			}
				break;

		case MARRIED_SEPARATELY_CHOICE:
			cout << "Enter your income: ";
			cin >> income;
						// Validate the input and determine the income tax
			if (income >= MIN_INCOME)
			{
    	// Determine the income tax
				if (income > MARRIED_SEPARATELY_INCOME_1)
					{
						income_tax = income * RATE_1;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_SEPARATELY_INCOME_2)
					{
						income_tax = income * RATE_2;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_SEPARATELY_INCOME_3)
					{
						income_tax = income * RATE_3;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_SEPARATELY_INCOME_4)
					{
						income_tax = income * RATE_4;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > MARRIED_SEPARATELY_INCOME_5)
					{
						income_tax = income * RATE_5;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else 
					{
						income_tax = income * RATE_6;
				        cout << "Your income tax is $" << income_tax << endl;
				}
			}
			else 
			{
				// An invalid income was entered.
				cout << "That is an invalid income. Run the program\n"
					<< "again and enter a value greater than zero.\n";
			}
				break;

		case HEAD_OF_HOUSEHOLD_CHOICE:
			cout << "Enter your income: ";
			cin >> income;
			// Validate the input and determine the income tax
			if (income >= MIN_INCOME)
			{
    	// Determine the income tax
				if (income > HEAD_OF_HOUSEHOLD_INCOME_1)
					{
						income_tax = income * RATE_1;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > HEAD_OF_HOUSEHOLD_INCOME_2)
					{
						income_tax = income * RATE_2;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > HEAD_OF_HOUSEHOLD_INCOME_3)
					{
						income_tax = income * RATE_3;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > HEAD_OF_HOUSEHOLD_INCOME_4)
					{
						income_tax = income * RATE_4;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else if (income > HEAD_OF_HOUSEHOLD_INCOME_5)
					{
						income_tax = income * RATE_5;
				        cout << "Your income tax is $" << income_tax << endl;
				}
				else 
					{
						income_tax = income * RATE_6;
				        cout << "Your income tax is $" << income_tax << endl;
				}
			}
			else 
			{
				// An invalid income was entered.
				cout << "That is an invalid income. Run the program\n"
					<< "again and enter a value greater than zero.\n";
			}
				break;
		
		case QUIT_CHOICE:
			cout << "Program ending.\n";
			break;

		default:
			cout << "The valid choices are 1 through 4. Run the\n"
				 << "program again and select one of those.\n";
	}
	return 0;
}

