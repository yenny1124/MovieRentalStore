// ------------------------------ Drama.h -------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Movie class and grandchild class of 
//          Inventory. The program functions for Drama movies. It takes 
//          proper data from the external movie file and display them as
//          inventory for drama movie. The data is sorted by Bineary Search tree.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef DRAMA_H
#define DRAMA_H
#include "Movie.h"

using namespace std;

class Drama: public Movie {
  
public:
  // Constructors and Destructor 
	Drama();
	Drama(const Drama&); 
	virtual ~Drama(); 

	// Member functions
	virtual void display() const; // virtual is inherited
	virtual void displayHeader() const;
	virtual void setData(istream&);
  virtual void setDataTransaction(istream&);
	virtual bool operator==(const Inventory&) const;
	virtual bool operator<(const Inventory&) const;
	virtual Inventory* createNewMovie(); 

private:
	const string genre;	
};
#endif

