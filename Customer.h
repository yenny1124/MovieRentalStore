// ---------------------------- Customer.h ------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This is a class that reserves information of customer's variables 
//          and transaction from the external data files. It also displays the 
//          transaction history of each customer based on customerID, firstName,
//          and lastName. A hash function is implemented to reserve customer's name 
//          based on the customerID.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"
#include "Transaction.h"

using namespace std;

class Customer {

public:
  // Constructors and Destructor
	Customer();
	Customer(istream&);
	Customer(const Customer&);
	virtual ~Customer();

	// Member functions
	void setData(istream& infile);
  	void displayCustomersInformation() const;
	void addTransaction(Transaction&);
	virtual void display() const;

	int getCustomerID() const { 
	  return customerID;
  }

	string getFirstName() const { 
	  return firstName;
  }
	string getLastName() const {
    return lastName; 
  }

	virtual bool operator==(const Customer&) const;	
  	virtual bool operator!=(const Customer&) const;
  	void setFirstName(string);
	void setLastName(string);

private:
	int customerID;
	string firstName;
	string lastName;
	vector<Transaction> transHistory;

};
#endif


