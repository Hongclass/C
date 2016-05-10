// CIS 2451
// Assignment-4_part-2
// Hong Zhang
// This program open a file, reads records into a container of 
// data structures, and prints out the sum in order.

#include "StdAfx.h"
#include "cost.h"
#include <fstream>

int main(int argc, char * argv[]) {
  Cost costs[500];
  int n = 0;

  ifstream filesIn("costfile.txt");
  while(true) {
    string line;
    getline (filesIn, line);
    if (filesIn.eof()) break;
    cout << "From orignal file: " << line << "\n";
    Cost &cost = parse_account(line);
    cout << "Description: " << cost.desc<< endl
		 << "Amount:      " << cost.amount<<endl
		 << "Item Number: " << cost.item_no << "\n\n";
    n = pushToV(n, costs, cost);
  }
  filesIn.close();
   
  cout << "TOTAL AMOUNT: " << sum_accounts(n, costs)<< "\n\n";

  return 0;
}

Cost &parse_account(const string &line) {
  Cost &cost = *(new Cost());

  istringstream is(line);

  is >> cost.desc >> cost.amount >> cost.item_no;

  return cost;
}

double sum_accounts(const int n, const Cost costs[]) {
  double total = 0.0;
  for (int i=0; i<n; i++) {
    total += costs[i].amount;
  }
  return total;
}

int pushToV(const int n, Cost costs[], const Cost cost) {
  costs[n] = cost;
  return n+1;
}