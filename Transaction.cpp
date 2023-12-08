// ---------------------------- Transaction.cpp -------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a parent class of the Borrow, Return, and History classes.
//          The class processes the items from the movie file depending on the actiontype.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Transaction.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize variables 
// ----------------------------------------------------------------------------
Transaction::Transaction() {
  actionType = "Transaction";
  mediaType = "";
  anItem = nullptr;
}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy datas from the file into a new Transaction object 
// ----------------------------------------------------------------------------
Transaction::Transaction(const Transaction& rhs){
	actionType = rhs.actionType;
	mediaType = rhs.mediaType;
	anItem = rhs.anItem;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Transaction::~Transaction(){}

//------------------------------ setData --------------------------------------
// Discription: function to set the data of the Transaction object from the 
//              inventory item and customer 
//-----------------------------------------------------------------------------
bool Transaction::setData(string media, Inventory* movieItem, Customer* aCustomer){
	mediaType = media;
	anItem = movieItem;
	return true;
}	

//------------------------------- display ------------------------------------
// Discription: function to display the mediaType and the actionType
//----------------------------------------------------------------------------
void Transaction::display() const{
	cout << mediaType << " " << actionType << ": ";
}

//-------------------------- createNewTransaction ----------------------------
// Discription: function to create a new Transaction object for Factory class
//----------------------------------------------------------------------------
Transaction* Transaction::createNewTransaction() {
	return new Transaction();
}


