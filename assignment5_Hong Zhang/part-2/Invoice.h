#ifndef _INVOICE_H
#define _INVOICE_H
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Invoice class declaration
class Invoice 
{ 
private:
	int PartNumber;
	string Partdescription;
	int Quantity;
    double Price;

public:
	Invoice(); // Default constructor
	Invoice (int n, string d, int q, double p); // 4 argument constructor

   // Add methods setNumber, setDescription, setQuantity and setPrice here.
   // Get functions to retrieve member variable values
	int getNumber();
	string getDescription();
	int getQuantity();
	double getPrice();
	double getAmount(); 
}; // End Invoice class declaration

 // Function prototype
 void displayInvoice(Invoice[], int);
 void displayTotal(Invoice[], int);
 void selectionSort(Invoice[], int);
 void insertionSort(Invoice[], int);
 void bubbleSort(Invoice[], int);


#endif