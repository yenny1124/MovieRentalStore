// ---------------------------- Classic.h -------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Movie class and grandchild class of 
//          Inventory. The program functions for Classic movies. It takes 
//          proper data from the external movie file and display them as inventory 
//          for classic movie. The data is sorted by Bineary Search Tree. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef CLASSIC_H
#define CLASSIC_H
#include <string>
#include "Movie.h"

class Classic: public Movie {

public:
  	// Constructors and Destructor
	Classic();
	Classic(const Classic&);
	virtual ~Classic();

	// Member functions
  	virtual void display() const; // virtual is inherited
	virtual void displayHeader() const;
	virtual void setData(istream&);
  	virtual void setDataTransaction(istream&);
	virtual bool operator==(const Inventory&) const;
	virtual bool operator<(const Inventory&) const;
	virtual Inventory* createNewMovie();

private:
	string actorFirstName;
  	string actorLastName;
	int month;
	const string genre;
};
#endif
