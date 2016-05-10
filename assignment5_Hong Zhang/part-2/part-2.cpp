// CIS 2451
// Assignment5_part-2
// This program uses some different sorts to sort an array of objects, as follows:
// 1. selection sort: places Inventory objects in ascending order by their PartDescription.
// 2. insertion sort: places Inventory objects in descending order by their Price.
// 3 calculate the total amount for each invoice amount
// and display the description and totals in ascending order by the total.

#include "stdafx.h"
#include "Invoice.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const int SIZE = 8;

    // Create and initialize the array of Invoice objects
    Invoice invoices[SIZE] = 
                      { Invoice( 83, "Electric sander", 7,  57.98 ),
                        Invoice( 24, "Power saw",       18, 99.99 ),
                        Invoice( 7,  "Sledge hammer",   11,  21.5 ),
                        Invoice( 77, "Hammer",          76, 11.99 ),
                        Invoice( 39, "Lawn mower",      3,   79.5 ),
                        Invoice( 68, "Screwdriver",     106, 6.99 ),
                        Invoice( 56, "Jig saw",         21,    11 ),
                        Invoice( 3,  "Wrench",          34,   7.5 ) };

    // Sort the objects by their PartDescription
    selectionSort(invoices, SIZE);
    // Display the inventory 
    cout << "\nSorted by description ascending order:\n";
    displayInvoice(invoices, SIZE);

	// Sort the objects by their Price
	insertionSort(invoices, SIZE);
	// Display the inventory 
    cout << "\nSorted by price in descending order:\n";
    displayInvoice(invoices, SIZE);

	// Sort the objects by their amount
	bubbleSort(invoices, SIZE);
	// Display the inventory 
	cout << "\nSorted by totals ascending order:\n";
	displayTotal(invoices, SIZE);
	cout << endl;

	return 0;
} // End main

