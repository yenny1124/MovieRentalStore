// ----------------------------- Drama.cpp ------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This class is a child class of Movie class and grandchild class of 
//          Inventory. The program functions for Drama movies. It takes 
//          proper data from the external movie file and display them as inventory 
//          for drama movie. The data is sorted by Bineary Search Tree. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Drama.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a genre variable of Drama object 
// ----------------------------------------------------------------------------
Drama::Drama(): Movie(), genre("DRAMA"){}

// ----------------------------- Constructor ----------------------------------
// Copy Constructor
// Description: constructor to copy an existing Drama object into 
//              a new drama object 
// ----------------------------------------------------------------------------
Drama::Drama(const Drama& rhs){
	director = rhs.director;
  title = rhs.title;
	year = rhs.year;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Drama::~Drama() {}

//------------------------------- display ------------------------------------
// Discription: function to display all the information about drama movie 
//              in proper order
//----------------------------------------------------------------------------
void Drama::display() const{ 
	cout << left << setw(22) << title << " " << setw(18) << director << " " << setw(5) << year << endl;
}

//---------------------------- displayHeader ---------------------------------
// Discription: function to display a specific header for the inventory 
//              for drama movie 
//----------------------------------------------------------------------------
void Drama::displayHeader() const {
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*DRAMA MOVIES *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
  cout << "In/Out  TITLE                  DIRECTOR           YEAR   "<<endl;
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
}

//-------------------------------- setData -----------------------------------
// Discription: function to grab the proper data of drama movies from 
//              the external file into appropreate variables. 
//----------------------------------------------------------------------------
void Drama::setData(istream& infile) {
	string s = "";

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
} 

//--------------------------- setDataTransaction -----------------------------
// Discription: function to grab updated data to process transaction with 
//              the external file (commands file)
//----------------------------------------------------------------------------
void Drama::setDataTransaction(istream& infile) {
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');
}

//----------------------------- operator== -----------------------------------
// Discription: function to check the order in the list of drama movie  
//              in terms of director's name
//----------------------------------------------------------------------------
bool Drama::operator==(const Inventory& rhs) const{
	//cast Inventory down to Drama
	const Drama& DramaMov = static_cast<const Drama&>(rhs);
	return (title == DramaMov.title && director == DramaMov.director);
} 

//------------------------------- operator< ----------------------------------
// Discription: function to check the order in the list of drama movie  
//              in terms of director's name
//----------------------------------------------------------------------------
 bool Drama::operator<(const Inventory& rhs) const {
	const Drama& DramaMov = static_cast<const Drama&>(rhs);

	if (director < DramaMov.director){
		return true;

	}else if (director == DramaMov.director){
		return (title < DramaMov.title);
	}else{
		return false;
  }
}

//--------------------------- createNewMovie ---------------------------------
// Discription: function to create a new drama movie object for Factory class 
//----------------------------------------------------------------------------
 Inventory * Drama::createNewMovie() {
	 return new Drama(); 
 }

