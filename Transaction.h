// ---------------------------- Transaction.h ---------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a parent class of the Borrow, Return, and History classes.
//          The class processes the items from the movie file depending on the actiontype.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Movie.h"

class Customer; // forward declaration
class Transaction {

public:
  // Constructors and Destructor
	Transaction();
	Transaction(const Transaction&); 
	virtual ~Transaction(); 

  // Member functions
	virtual bool setData(string, Inventory*, Customer*);	
	virtual void display() const;
	virtual Transaction* createNewTransaction();

	string getMediaType(){
    return mediaType; 
  }

	string getTransactionType() {
    return actionType; 
  }

	Inventory* getItem() const {
    return anItem; 
  }

protected:
	string actionType; // type of customer's action
	string mediaType; // type of movie media
	Inventory* anItem; // an item

};
#endif



