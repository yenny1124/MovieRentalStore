// ---------------------------- Classic.cpp -----------------------------------
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

#include "Classic.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize variables of Classic object 
// ----------------------------------------------------------------------------
Classic::Classic(): Movie(), actorFirstName(""), actorLastName(""), month(0), genre("CLASSIC"){}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to copy an existing Classic object into 
//              a new classic object 
// ----------------------------------------------------------------------------
Classic::Classic(const Classic& rhs){
	month = rhs.month;
	year = rhs.year;
  	title = rhs.title;
  	director = rhs.director;
	actorFirstName = rhs.actorFirstName;
	actorLastName = rhs.actorLastName;
}

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Classic::~Classic() {}

//------------------------------- display ------------------------------------
// Discription: function to display all the information about classic movie 
//              in proper order
//----------------------------------------------------------------------------
void Classic::display() const {
	cout << left << setw(22) << title << " "
		 << setw(18) << director << " "
		 << setw(3) << month << " "
		 << setw(5) << year << " "
		 << actorFirstName << " " << actorLastName << endl;
}

//---------------------------- displayHeader ---------------------------------
// Discription: function to display a specific header for the inventory 
//              for classic movie 
//----------------------------------------------------------------------------
void Classic::displayHeader() const {
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*CLASSIC MOVIES-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
  cout << "In/Out  TITLE                  DIRECTOR           MO  YEAR  " <<
		"ACTOR-NAME  " << endl;
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
}

//-------------------------------- setData -----------------------------------
// Discription: function to grab the proper data of classic movies from 
//              the external file into appropreate variables. 
//----------------------------------------------------------------------------
void Classic::setData(istream& infile){
	string s = ""; 

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18){
		title.resize(18);		
	}

	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22){
		title.resize(22);		
	}

	infile.get();
	infile >> actorFirstName >> actorLastName;
	infile >> month >> year;
}

//--------------------------- setDataTransaction -----------------------------
// Discription: function to grab updated data to process transaction with 
//              the external file (commands file)
//----------------------------------------------------------------------------
void Classic::setDataTransaction(istream& infile){
	infile >> month;
	infile >> year;
	infile >> actorFirstName;
	infile >> actorLastName;
}

//----------------------------- operator== -----------------------------------
// Discription: function to check the order in the list of classic movie  
//              in terms of released date 
//----------------------------------------------------------------------------
 bool Classic::operator==(const Inventory& rhs) const{
	// cast Inventory down to Classic
	const Classic& classicMov = static_cast<const Classic&>(rhs);

	return (year == classicMov.year && month == classicMov.month
		&& actorFirstName == classicMov.actorFirstName &&
		actorLastName == classicMov.actorLastName);
}

//------------------------------- operator< ----------------------------------
// Discription: function to check the order in the list of classic movie  
//              in terms of released date 
//----------------------------------------------------------------------------
 bool Classic::operator<(const Inventory& rhs) const {
	const Classic& classicMov = static_cast<const Classic&>(rhs);

	if (year < classicMov.year){
		return true;

  	}else if (year == classicMov.year){
		if (actorFirstName < classicMov.actorFirstName){
			return true;
		}
		else if (actorFirstName == classicMov.actorFirstName){
			return (actorLastName < classicMov.actorLastName);
		}else{
			return false;
    }
	}else{
		return false;
  }
}

//--------------------------- createNewMovie ---------------------------------
// Discription: function to create a new classic movie object for Factory class 
//----------------------------------------------------------------------------
Inventory* Classic::createNewMovie(){ 
	return new Classic(); 
}

