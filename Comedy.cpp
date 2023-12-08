// ----------------------------- Comedy.cpp -----------------------------------
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

#include "Comedy.h"

// ---------------------------- Constructor ----------------------------------
// Default constructor
// Discription: constructor to initialize a genre variable of Comedy object 
// ----------------------------------------------------------------------------
Comedy::Comedy(): Movie(), genre("COMEDY") {}

// ----------------------------- Constructor ----------------------------------
// Copy Constructor
// Description: constructor to copy an existing Comedy object into 
//              a new comedy object 
// ----------------------------------------------------------------------------
Comedy::Comedy(const Comedy& rhs){
	title = rhs.title;
	year = rhs.year;
	director = rhs.director;
} 

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
//-----------------------------------------------------------------------------
Comedy::~Comedy() {}

//------------------------------- display ------------------------------------
// Discription: function to display all the information about comedy movie 
//              in proper order
//----------------------------------------------------------------------------
void Comedy::display() const { 	
	cout << left << setw(22) << title << " " << setw(18) 
  << director << " " << setw(5) << year << endl;
}

//---------------------------- displayHeader ---------------------------------
// Discription: function to display a specific header for the inventory 
//              for comedy movie 
//----------------------------------------------------------------------------
void Comedy::displayHeader() const {
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*COMEDY MOVIES*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;

  cout << "In/Out  TITLE                  DIRECTOR           YEAR   "<<endl;
  cout<<
  "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
}

//-------------------------------- setData -----------------------------------
// Discription: function to grab the proper data of comedy movies from 
//              the external file into appropreate variables. 
//----------------------------------------------------------------------------
void Comedy::setData(istream& infile) {
	string s = "";

	infile.get();
	infile.get();
	infile.get();
	getline(infile, s, ',');

	infile.get();
	getline(infile, director, ',');
	if (director.size() > 18){ title.resize(18);}

	infile.get();
	getline(infile, title, ',');
	if (title.size() > 22){ title.resize(22);}
	
	infile.get();
	infile >> year;
}

//--------------------------- setDataTransaction -----------------------------
// Discription: function to grab updated data to process transaction with 
//              the external file (commands file)
//----------------------------------------------------------------------------
void Comedy::setDataTransaction(istream& infile) {
	infile.get();
	getline(infile, title, ',');
	infile >> year;
}

//----------------------------- operator== -----------------------------------
// Discription: function to check the order in the list of comedy movie  
//              in terms of title 
//----------------------------------------------------------------------------
bool Comedy::operator==(const Inventory& rhs) const {
  //cast Inventory down to Comedy
	const Comedy& comedyMov = static_cast<const Comedy&>(rhs);
	return (title == comedyMov.title && year == comedyMov.year);
}

//------------------------------- operator< ----------------------------------
// Discription: function to check the order in the list of comedy movie  
//              in terms of title
//----------------------------------------------------------------------------
bool Comedy::operator<(const Inventory& rhs) const {
	//static cast down to ComedyMovie
	const Comedy& comedyMov = static_cast<const Comedy&>(rhs);

	if (title < comedyMov.title){
		return true;

  }else if (title == comedyMov.title){
		return (year < comedyMov.year);
	}else{
		return false;
  }
}

//--------------------------- createNewMovie ---------------------------------
// Discription: function to create a new comedy movie object for Factory class 
//----------------------------------------------------------------------------
Inventory* Comedy::createNewMovie(){ 
	return new Comedy();
}

