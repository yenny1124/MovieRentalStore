// ---------------------------- Driver.cpp ------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This is a driver file to test a Business object by reading the three 
//          given external files.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 
 
#include "Business.h"

using namespace std;

int main() {

	// Call a business instance
	Business jamjamStore("MOVIE");
	ifstream fileForCustomers("data4customers.txt");
	ifstream fileForMovies("data4movies.txt");
	ifstream fileForTransactions("data4commands.txt");


	if ((!fileForCustomers) || (!fileForMovies) || (!fileForTransactions)){
		cout << "#### Error! : The File Cannot Be Read ####" << endl;
		return 1;
	}
	
	jamjamStore.structCustomer(fileForCustomers);
	jamjamStore.structInventory(fileForMovies);
	jamjamStore.structCommands(fileForTransactions);

	return 0;
}



