// ------------------------------ Movie.h -------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Inventory and a parent class of Classic,
//          Comedy, and Drama. The program takes proper Movie data from the external 
//          movie file and process them by each genre. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef MOVIE_H
#define MOVIE_H
#include "Inventory.h"

using namespace std;

class Movie : public Inventory {
  
public:
  // Constructors and Destructor
	Movie();	
	Movie(const Movie&);
	virtual ~Movie();	

  // Member functions
	virtual void display() const; // virtual is inherited
	virtual void displayHeader() const = 0;
	virtual void setData(istream&);
	virtual void setDataTransaction(istream&) = 0;

	virtual string getItem() const{ 
    return title; 
  };

	string getDirector(){ 
    return director; 
  }; 

	string getTitle(){ 
    return title; 
  };	

	int getYear(){ 
    return year; 
  };	

  	virtual bool operator==(const Inventory&) const = 0;
	virtual bool operator<(const Inventory&) const = 0;
	virtual Inventory* createNewMovie() = 0;

protected:
	string title;		// title of movie
	string director;	// director of movie
	int year;			// year released
	
};

#endif

