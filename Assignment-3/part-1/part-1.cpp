// CIS 2541
// Assignmnet-3_part-1
// Hong Zhang

// This is a program to help elementary school students   
// in learning addition, subtraction, multiplication, 
// division and modulus. Through the mani menu,   
// the user chooses the type of problems to study. 
// If the user enters "-1", the program will end 
// and show a summary, then return to main menu. 

#include "stdafx.h"
#include <iostream> // For input and output
#include <cstdlib> // For rand and srand
using namespace std;

// Function prototypes
void showMenu();
void addition();
void subtraction();
void multiplication();
void division();
void modulus();

//Program starts here   
int _tmain(int argc, _TCHAR* argv[])
{
	int choice;   // To hold a menu choice

	// Constants for the menu choices
	const int ADDITION_CHOICE = 1,
              SUBTRACTION_CHOICE = 2,
              MULTIPLICATION_CHOICE = 3,
              DIVISION_CHOICE = 4,
              MODULUS_CHOICE = 5,
           	  QUIT_CHOICE = 6;

	cout << "\n\t*********Welcome to the Arithmetic quiz *******\n\n";

do
{
	// Display the menu and get the user's choice
	showMenu();
	cout << " \n\n";
	cin >> choice;

    // Validate the menu selection.
      while (choice < ADDITION_CHOICE || choice > QUIT_CHOICE)
      {
         cout << "Please enter a valid menu choice: ";
         cin >> choice;
      }
      
      // If the user does not want to quit, proceed.
      if (choice != QUIT_CHOICE)
      {
          switch (choice)
          {
             case ADDITION_CHOICE:  
                  addition();
                  break;
             case SUBTRACTION_CHOICE:
                  subtraction();
                  break;
             case MULTIPLICATION_CHOICE:
                  multiplication();
				  break;
		     case DIVISION_CHOICE:  
                  division();
                  break;
             case MODULUS_CHOICE:
                  modulus();
           }
      }
   } while (choice != QUIT_CHOICE);
   return 0;
}// end of main

//Function Definitions
void showMenu()
{
   cout << "MENU: \n\n"
	    << "1. Enter 1 for Addition\n"
        << "2. Enter 2 for Subtraction\n"
        << "3. Enter 3 for Multiplication\n"
        << "4. Enter 4 for Division\n"
        << "5. Enter 5 for Modulus\n"
        << "6. Enter 6 to Exit";
}

void addition()
{
    int num1, num2;   // The random numbers to form an arithmetic operation
	int answer;       // The correct answer   
	int guess;        // The user's answer
	int right=0;      // The number of questions answered correctly by the user
	int wrong=0;      // The number of questions answered incorrectly by the user
	int total=0;      // The total numbers of questions answered by the user
	   
	// Get two random numbers
	num1 = 10 + rand() % 89;
    num2 = 10 + rand() % 89;
	// Get the correct answer
	answer = num1 + num2; 
	// Display the question and input user's answer
	cout << "How much is " << num1 <<" plus " << num2 << "?"<< endl;
	cout << "Enter your answer (-1 to return to the menu):\n";
	cin >> guess;

	while (guess != -1)
	{
		while(guess != answer)
		{
            while (guess != -1)
	        {
			    cout << "No. Please try again.\n";
		        cout << "Enter your answer (-1 to return to the menu):\n";
		        cin >> guess;
			    wrong++;
			}
			// Calculate the numbers of questions and display the summary
		    total = right + wrong;
            cout << "\nSUMMARY:\n"
	        << "Addition Problems Played: " << total << endl
	        << "Number of times answered correctly: " << right << endl
	        << "Number of times answered incorrectly: " << wrong << endl
	        << " \n";
	        return;
		    }
		  	cout << "Very good!\n";
            right++;
			// Caculate another problem
			num1 = 10 + rand() % 89;
    	    num2 = 10 + rand() % 89;
	        answer = num1 + num2; 
		    cout << "How much is " << num1 <<" plus " << num2 << "?"<< endl;
	        cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
  	 }
	 // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Addition Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
}

void subtraction()
{
    int num1, num2;   // The random numbers to form an arithmetic operation
	int answer;       // The correct answer   
	int guess;        // The user's answer
	int right=0;      // The number of questions answered correctly by the user
	int wrong=0;      // The number of questions answered incorrectly by the user
	int total=0;      // The total numbers of questions answered by the user
	   
	// Get two random numbers
	num1 = 10 + rand() % 89;
    num2 = 10 + rand() % 89;
	// Get the correct answer
	answer = num1 - num2; 
	// Display the question and input user's answer
	cout << "How much is " << num1 <<" minus " << num2 << "?"<< endl;
	cout << "Enter your answer (-1 to return to the menu):\n";
	cin >> guess;

	while (guess != -1)
	{
		while(guess != answer)
		{
		    while (guess != -1)
	        {
			cout << "No. Please try again.\n";
		    cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
			wrong++;
			}
             // Calculate the numbers of questions and display the summary
		     total = right + wrong;
             cout << "\nSUMMARY:\n"
	         << "Subtraction Problems Played: " << total << endl
	         << "Number of times answered correctly: " << right << endl
	         << "Number of times answered incorrectly: " << wrong << endl
	         << " \n";
	         return;
		}
		  	cout << "Very good!\n";
            right++;
			// Caculate another problem
			num1 = 10 + rand() % 89;
    	    num2 = 10 + rand() % 89;
	        answer = num1 - num2; 
		    cout << "How much is " << num1 <<" minus " << num2 << "?"<< endl;
	        cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
  	 }
	 // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Subtraction Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
}

void multiplication()
{
    int num1, num2;   // The random numbers to form an arithmetic operation
	int answer;       // The correct answer   
	int guess;        // The user's answer
	int right=0;      // The number of questions answered correctly by the user
	int wrong=0;      // The number of questions answered incorrectly by the user
	int total=0;      // The total numbers of questions answered by the user
	   
	// Get two random numbers
	num1 = 10 + rand() % 89;
    num2 = 10 + rand() % 89;
	// Get the correct answer
	answer = num1 * num2; 
	// Display the question and input user's answer
	cout << "How much is " << num1 <<" multiply " << num2 << "?"<< endl;
	cout << "Enter your answer (-1 to return to the menu):\n";
	cin >> guess;

	while (guess != -1)
	{
		while(guess != answer)
		{
			while (guess != -1)
	        {
		    cout << "No. Please try again.\n";
		    cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
			wrong++;
			}
			// Calculate the numbers of questions and display the summary
		    total = right + wrong;
            cout << "\nSUMMARY:\n"
	        << "Multiplication Problems Played: " << total << endl
	        << "Number of times answered correctly: " << right << endl
	        << "Number of times answered incorrectly: " << wrong << endl
	        << " \n";
	        return;
		}
		  	cout << "Very good!\n";
            right++;
			// Caculate another problem
			num1 = 10 + rand() % 89;
    	    num2 = 10 + rand() % 89;
	        answer = num1 * num2; 
		    cout << "How much is " << num1 <<" multiply " << num2 << "?"<< endl;
	        cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
  	 }
	 // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Multiplication Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
}

void division()
{
    int num1, num2;   // The random numbers to form an arithmetic operation
	int answer;       // The correct answer   
	int guess;        // The user's answer
	int right=0;      // The number of questions answered correctly by the user
	int wrong=0;      // The number of questions answered incorrectly by the user
	int total=0;      // The total numbers of questions answered by the user
	   
	// Get two random numbers
	num1 = 10 + rand() % 89;
    num2 = 10 + rand() % 89;
	// Get the correct answer
	answer = num1 / num2; 
	// Display the question and input user's answer
	cout << "How much is " << num1 <<" divide " << num2 << "?"<< endl;
	cout << "Enter your answer (-1 to return to the menu):\n";
	cin >> guess;

	while (guess != -1)
	{
		while(guess != answer)
		{
		    while (guess != -1)
         	{
			cout << "No. Please try again.\n";
		    cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
			wrong++;
			}
        // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Division Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
		}
		  	cout << "Very good!\n";
            right++;
			// Caculate another problem
			num1 = 10 + rand() % 89;
    	    num2 = 10 + rand() % 89;
	        answer = num1 / num2; 
		    cout << "How much is " << num1 <<" divide " << num2 << "?"<< endl;
	        cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
  	 }
	 // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Division Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
}

void modulus()
{
    int num1, num2;   // The random numbers to form an arithmetic operation
	int answer;       // The correct answer   
	int guess;        // The user's answer
	int right=0;      // The number of questions answered correctly by the user
	int wrong=0;      // The number of questions answered incorrectly by the user
	int total=0;      // The total numbers of questions answered by the user
	   
	// Get two random numbers
	num1 = 10 + rand() % 89;
    num2 = 10 + rand() % 89;
	if (num1 >= num2)
	{
		// Get the correct answer
	    answer = num1 % num2; 
	   // Display the question and input user's answer
	   cout << "How much is the remainder if " << num1 <<" divide " << num2 << "?"<< endl;
	}
	else
	{
		// Get the correct answer
	    answer = num2 % num1; 
	   // Display the question and input user's answer
	   cout << "How much is the remainder if " << num2 <<" divide " << num1 << "?"<< endl;
	}
	cout << "Enter your answer (-1 to return to the menu):\n";
	cin >> guess;

	while (guess != -1)
	{
		while(guess != answer)
		{
			while (guess != -1)
	        {
		    cout << "No. Please try again.\n";
		    cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
			wrong++;
			}
         // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Modulus Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
		}
		  	cout << "Very good!\n";
            right++;
			// Caculate another problem
			num1 = 10 + rand() % 89;
            num2 = 10 + rand() % 89;
	        if (num1 >= num2)
	        {
		         // Get the correct answer
	             answer = num1 % num2; 
	             // Display the question and input user's answer
	             cout << "How much is the remainder if " << num1 <<" divide " << num2 << "?"<< endl;
	         }
	         else
	         {
		         // Get the correct answer
	             answer = num2 % num1; 
	             // Display the question and input user's answer
	             cout << "How much is the remainder if " << num2 <<" divide " << num1 << "?"<< endl;
	         }
	        cout << "Enter your answer (-1 to return to the menu):\n";
		    cin >> guess;
  	}
	 // Calculate the numbers of questions and display the summary
		total = right + wrong;
        cout << "\nSUMMARY:\n"
	     << "Modulus Problems Played: " << total << endl
	     << "Number of times answered correctly: " << right << endl
	     << "Number of times answered incorrectly: " << wrong << endl
	     << " \n";
	    return;
}
