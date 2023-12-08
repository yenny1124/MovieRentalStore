// ----------------------------- Business.h -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: The class has responsibility to properly manage all customers, all 
//          movie's inventory, and transaction with all given external files.
//          It is in charge of creating, maintaining and modifying all possible
//          data related to the class. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef BUINESS_H
#define BUINESS_H
#include <fstream>
#include <vector>
#include <istream>
#include <string>
#include "Customer.h"
#include "Factory.h"
#include "BStree.h"
#include "Hash.h"

static const int MAXNUMCUSTOMER = 50;
static const int MAXNUMINVENTORY = 53;

using namespace std;

class Business {

public:
  // Constructors and Destructor
	Business();
	Business(string);
	Business(const Business&);
	~Business();	

  // Member functions 
	void structCustomer(istream&);
	void structInventory(istream&);
	void structCommands(istream&);
	void displayInventory() const;
	bool lookUpCustomer(int) const;

  // Description: function to return business name 
	string getBusinessName() const {	
    return name; 
  }

  // Description: function to return the customer in the list with the customerID
	Customer getCustomer(const int IDNum) const { 
    return *custList.getItem(IDNum);
  }

private:
	HashTable<Customer> custList;
	BStree inventoryList[MAXNUMINVENTORY]; // implement set of sorting attributes 
	vector<Transaction> storeTransactionHistory;
	Factory factory;

	string name;
};
#endif



