// ------------------------------ Return.h ------------------------------------
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

#ifndef RETURN_H
#define RETURN_H
#include "Transaction.h"
#include "Customer.h"

class Return: public Transaction {

public:
  // Constructors and Destructor
	Return();
	Return(const Return&);
	virtual ~Return(); 

  // Member functions
	virtual bool setData(string, Inventory*, Customer*);
	virtual void display() const;
	virtual Transaction* createNewTransaction(); 

};
#endif

