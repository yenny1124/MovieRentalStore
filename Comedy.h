// ------------------------------ Comedy.h ------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Movie class and grandchild class of 
//          Inventory. The program functions for Comedy movies. It takes 
//          proper data from the external movie file and display them as inventory 
//          for comedy movie. The data is sorted by Bineary Search Tree. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef COMEDY_H
#define COMEDY_H
#include "Movie.h"

class Comedy : public Movie {

public: 
  // Constructors and Destructor
	Comedy();
	Comedy(const Comedy&);
	virtual ~Comedy();

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

