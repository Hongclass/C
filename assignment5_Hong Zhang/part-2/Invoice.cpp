#include "stdafx.h"
#include "Invoice.h"

Invoice::Invoice() // Default constructor
{
	PartNumber = 0; 
	Partdescription = " "; 
	Quantity = 0;
	Price = 0.0; 
}

Invoice::Invoice (int n, string d, int q, double p) // 4 argument constructor
 { 
	PartNumber = n; 
	Partdescription = d; 
	Quantity = q;
	Price = p;
 }

// Add methods setNumber, setDescription, setQuantity and setPrice here.
// Get functions to retrieve member variable values
int Invoice::getNumber()
 { 
	 int n = PartNumber;
	 return n;
 }

string Invoice::getDescription()
 { 
	 string d = Partdescription;
	 return d;
 }

int Invoice::getQuantity()
 {
	 int q = Quantity;
	 return q;
 }

double Invoice::getPrice()
 { 
	 double p = Price;
	 return p;
 }

// calculates and returns the invoice amount
 double Invoice::getAmount() 
 {
	 return getQuantity() * getPrice();
 }// End Invoice class


 /*******************************************************
 *                      displayInvoice                  *
 * This function displays the entire array.             *
 *******************************************************/
void displayInvoice(Invoice object[], int size)
{
	for (int index = 0; index < size; index++)
	{ 
		cout << setw(2) << right << object[index].getNumber()
			 << setw(2) << left<< ""
             << setw(16) << left << object[index].getDescription()
			 << setw(3) << right << object[index].getQuantity()
			 << setw(2) << left<< ""
			 << setprecision(2) << fixed
             << "$" << right << object[index].getPrice() << endl;
	}
}// End displayInvoice

/*******************************************************
 *                      displayTotal                   *
 * This function displays description and total.       *
 *******************************************************/
void displayTotal(Invoice object[], int size)
{
	for (int index = 0; index < size; index++)
	{ 
		cout << setw(18) << left << object[index].getDescription()
			 << setprecision(2) << fixed
             << "$" << right << object[index].getAmount() << endl;
	}
}// End displayTotal

 /*************************************************************
 * selectionSort                                              *
 * This function performs a selection sort on Invoice         *
 * objects, arranging them in ascending PartDescription order.*
 **************************************************************/
void selectionSort(Invoice inv[], int size)
{
	Invoice  minValue; // Holds an Inventory object
    int startScan, minIndex;
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
	       minIndex = startScan;
		   minValue = inv[startScan];
		   for(int index = startScan + 1; index < size; index++)
		   {
			   if (inv[index].getDescription() < minValue.getDescription())
			   {
				   minValue = inv[index];
				   minIndex = index;
			   }
			}
		   inv[minIndex] = inv[startScan];
		   inv[startScan] = minValue;
	}
}// End selectionSort

/*******************************************************
 * insertionSort                                       *
 * This function performs a insertion sort on Invoice  *
 * objects, arranging them in descending Price order.  *
 *******************************************************/
void insertionSort(Invoice inv[], int size)
{
	Invoice temp; // Holds an Inventory object
	int i, j;

	for ( i = 1; i < size; i++ )
	{
		j = i;
		temp = inv[i];
		while ( j > 0  && temp.getPrice() > inv[j-1].getPrice()) 
		{
			inv[j] = inv[j-1];
			j--;
		}
		inv[j] = temp;	
	}
}// End insertionSort

/********************************************************
* bubbleSort                                            *
* This function performs a bubble sort on Invoice       *
* objects, arranging them in ascending amount order.    *
********************************************************/
void bubbleSort(Invoice inv[], int size)
{
	Invoice temp; // Holds an Inventory object
    bool swap;

    do
	{ 
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (inv[count].getAmount() > inv[count + 1].getAmount())
			{
				temp = inv[count];
				inv[count] = inv[count + 1];
				inv[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}// End bubbleSort
