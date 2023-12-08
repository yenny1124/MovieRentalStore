// ----------------------------- History.h ------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Transaction class. It displays 
//          the history of each customer's transaction. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef HISTORY_H
#define HISTORY_H
#include "Transaction.h"
#include "Customer.h"

class History: public Transaction{

public:
  // Constructors and Destructor
	History();
	History(const History& rightSide);
	virtual ~History(); 

  // Member functions
	virtual bool setData(string, Inventory*, Customer*);
	virtual Transaction* createNewTransaction();

};
#endif
