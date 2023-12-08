// -------------------------------- Borrow.cpp --------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child flass of Transaction class. Each object reserves 
//          a borrowed item and contains all data members from the Transaction object. 
//          The Borrow object updates itself to the inventory and adds to the customer's 
//          transaction history. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Borrow.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a variable 
// ----------------------------------------------------------------------------
Borrow::Borrow(): Transaction() {actionType = "Borrow";} 

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy datas from the file into a new Borrow object 
// ----------------------------------------------------------------------------
Borrow::Borrow(const Borrow& rhs) {
	actionType = rhs.actionType;
	mediaType = rhs.mediaType;
	anItem = rhs.anItem;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Borrow::~Borrow() {}

//------------------------------ setData --------------------------------------
// Discription: function to set the data of the Borrow object 
//-----------------------------------------------------------------------------
bool Borrow::setData(string media, Inventory* movieItem, Customer* aCustomer){
	if (movieItem != nullptr){
		mediaType = media;
		anItem = movieItem;

		if (mediaType != ""){anItem->decreaseNumStock();}
	}
	return true;
}

//------------------------------- display ------------------------------------
// Discription: function to display the mediaType(D) and the actionType(B)  
//----------------------------------------------------------------------------
void Borrow::display() const{
	cout << mediaType << " " << actionType << " ";
}

//-------------------------- createNewTransaction ----------------------------
// Discription: function to create a new Borrow object for Factory class
//----------------------------------------------------------------------------
Transaction* Borrow::createNewTransaction(){
	return new Borrow();
}

