// --------------------------- Customer.cpp -----------------------------------
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

#include "Customer.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a variable and size of the vector
// ----------------------------------------------------------------------------
Customer::Customer(): customerID(-1), firstName(""), lastName(""){
	transHistory.reserve(10);	
}

// ---------------------------- Constructor -----------------------------------
// Constructor from istream
// Description: constructor to set datas from the file into Customer object 
// ----------------------------------------------------------------------------
Customer::Customer(istream& infile){ setData(infile); }

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy datas from the file into a new Customer object 
// ----------------------------------------------------------------------------
Customer::Customer(const Customer& rhs){
	customerID = rhs.customerID;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Customer::~Customer(){}

//------------------------------ setData --------------------------------------
// Discription: function to grab the data of customers from the external file
//-----------------------------------------------------------------------------
void Customer::setData(istream& infile){
	infile >> customerID;
	if (infile.eof()) return;

	infile.get();
	infile >> lastName;

	infile.get();
	infile >> firstName;
}

//------------------------ displayCustomesTransaction ------------------------
// Discription: function to display all the transactions of a customer 
//              in chronological
//----------------------------------------------------------------------------
void Customer::displayCustomersInformation() const {
  cout <<
	"----------------------------Customer's Information---------------------------"
  << endl;
	cout << "*CUSTOMER ID: " << customerID << "      *CUSTOMER NAME: " << lastName 
  << " " << firstName << endl;
	cout <<
	"-----------------------------------------------------------------------------"
  <<endl;

	int transSize = transHistory.size();
	if (transSize > 0){
		for (int i = 0; i < transSize; i++){
			transHistory[i].display();
			transHistory[i].getItem()->display();
		}
	cout << endl;

	}else{
		cout << "#### No Transaction for This Customer ####" << endl;
	}	
cout << endl;
} 

//--------------------------- addTransaction ---------------------------------
// Discription: function to add each transaction of a customer into 
//              the transHistory vector 
//----------------------------------------------------------------------------
void Customer::addTransaction(Transaction& trans) {
	transHistory.push_back(trans);
}

//------------------------------- display ------------------------------------
// Discription: function to display the history of a customer's transaction 
//              with a helper function
//----------------------------------------------------------------------------
void Customer::display() const {
	displayCustomersInformation();
}

//----------------------------- operator== -----------------------------------
// Discription: operator function to test equality between two objects 
//----------------------------------------------------------------------------
bool Customer::operator==(const Customer& rhs) const {
	return (customerID == rhs.customerID);
} 

//----------------------------- operator!= -----------------------------------
// Discription: operator function to test inequality between two objects 
//----------------------------------------------------------------------------
bool Customer::operator!=(const Customer& rhs) const {
	return (customerID != rhs.customerID);
}

// ---------------------------- setFirstName ---------------------------------
// Description: function to set the variable firtName as the string newFName 
//----------------------------------------------------------------------------
void Customer::setFirstName(string newFName){
  firstName = newFName;
}

// ---------------------------- setLastName ----------------------------------
// Description: function to set the variable lastName as the string newLName 
//----------------------------------------------------------------------------
void Customer::setLastName(string newLName){
  lastName = newLName;
}


