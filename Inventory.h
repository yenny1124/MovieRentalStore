// ---------------------------- Inventory.h -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a parent class of movie and all genre classes. It 
//          implements pure vitural functions for transactions of each movie.
//          It manages the number of DVD movie stocks for Borrow and Return.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory {

public:
  // Constructors and Destructor
  Inventory(): numStock(-1), maxStock(0){}
  Inventory(const Inventory& rhs) {} 
  virtual ~Inventory() {} 
  
  // Member functions
  	virtual void display() const = 0;	// pure virtual functions 
	virtual void displayHeader() const = 0;
	virtual void setData(istream&) = 0; 
	virtual void setDataTransaction(istream&) = 0;
	virtual string getItem() const = 0;	

	void setNumMaxCopy(const int maxCopy){ // sets the max num of copies 
    maxStock = maxCopy;
    if (numStock < 0){numStock = maxCopy;}		
  }

	void increaseNumStock(){ // increases the num of copies from returning DVD
	  if (numStock != maxStock){numStock++;}		
  }

	void decreaseNumStock(){ // decreases the num of copies from borrowing DVD
	  if (numStock != 0){numStock--;}		
  }
  
	int getAmountIn(){ // returns current num of stock 
	  return numStock; 
  }
  		
	int getAmountOut(){ // returns current num of stock 
	  return (maxStock - numStock); 
  }
	
	virtual bool operator==(const Inventory&) const = 0;	
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* createNewMovie() = 0;

private:
	int numStock;
	int maxStock;

};

#endif


