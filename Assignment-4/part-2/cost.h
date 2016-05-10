// This file contains structures and data type definitions needed for the program in file part-2.cpp

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// data structures
struct Cost {
  string desc;
  double amount;
  int item_no;
}; 

// function prototypes
Cost &parse_account(const string &line);
double sum_accounts(const int n, const Cost costs[]);
int pushToV(const int n, Cost costs[], const Cost cost);