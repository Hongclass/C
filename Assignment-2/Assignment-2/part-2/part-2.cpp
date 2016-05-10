// CIS 2541
// Assignment-2_Part-2
// Hong Zhang
// This program prints four triangles, 
// one below the other

#include "stdafx.h"
#include <iostream>
using namespace std;

// draw four triangles
int _tmain(int argc, _TCHAR* argv[])
{
	int row; // the row position
	int column; // the column position
	int space; // number of spaces to print

	// first triangle
	for (row = 1; row <= 10 ; row++ )
	{
		for ( column = 1; column <= row; column++ )
			cout<<"*";
            cout<<"\n";
    }
   
	cout<<"\n\n";

	// second triangle
	for ( row = 10; row >= 1; row-- )
	{
		for ( column = 1; column <= row; column++ )
			cout<<"*";
            cout<<"\n";
	}

	cout<<"\n\n";

	// third triangle
	for ( row = 10; row >= 1; row-- )
	{
		for ( space = 10; space > row; space-- )
			cout<<" ";
		for ( column = 1; column <= row; column++ )
			cout<<"*";
            cout<<"\n";
	}

	cout<<"\n\n";

	// fourth triangle
	for ( row = 10; row >= 1; row-- )
	{
		for ( space = 1; space < row; space++ )
			cout<<" ";
		for ( column = 10; column >= row; column-- )
            cout<<"*";
            cout<<"\n";
	}

	cout<<"\n\n";
	return 0;
}



