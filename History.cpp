// ---------------------------- History.cpp -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Transaction class. It displays 
//          the history of each customer's transaction. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "History.h"
#include "Customer.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a variable 
// ----------------------------------------------------------------------------
History::History(): Transaction() {actionType = "History";}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy datas from the file into a new History object 
// ----------------------------------------------------------------------------
History::History(const History& rhs) {
	actionType = rhs.actionType;
	mediaType = rhs.mediaType;
	anItem = rhs.anItem;
}

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
History::~History(){}

//------------------------------ setData --------------------------------------
// Discription: function to set the data of the History object and display 
//              the history of a customer's transaction through polymorphism            
//-----------------------------------------------------------------------------
bool History::setData(string media, Inventory* movieItem, Customer* aCustomer) {
	aCustomer->displayCustomersInformation();
	return false; 
}

//-------------------------- createNewTransaction -----------------------------
// Discription: function to create a new History object for Factory class
//-----------------------------------------------------------------------------
Transaction* History::createNewTransaction(){ 
	return new History(); 
}

