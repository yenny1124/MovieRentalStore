// ----------------------------- Return.cpp -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child flass of Transaction class. Each object holds 
//          a returned object and contains all data members from the Transection 
//          object. The Return object updates itself to the inventory and adds 
//          to the customer's transaction history. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Return.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a variable 
// ----------------------------------------------------------------------------
Return::Return(): Transaction() {actionType = "Return";}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy datas from the file into a new Return object 
// ----------------------------------------------------------------------------
Return::Return(const Return& rhs){
	mediaType = rhs.mediaType;
	actionType = rhs.actionType;
	anItem = rhs.anItem;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
 Return::~Return(){}

//------------------------------ setData --------------------------------------
// Discription: function to set the data of the Return object 
//-----------------------------------------------------------------------------
bool Return::setData(string media, Inventory* movieItem, Customer* aCustomer) {

	if (movieItem != nullptr){
		mediaType = media;
		anItem = movieItem;

		if (mediaType != ""){anItem->increaseNumStock();}		
	}
	return true;
}

//------------------------------- display ------------------------------------
// Discription: function to display the mediaType(D) and the actionType(R)  
//----------------------------------------------------------------------------
void Return::display() const{
	cout << mediaType << " " << actionType << " ";
} 

//-------------------------- createNewTransaction ----------------------------
// Discription: function to create a new Return object for Factory class
//----------------------------------------------------------------------------
Transaction * Return::createNewTransaction(){ 
	return new Return(); 
} 
