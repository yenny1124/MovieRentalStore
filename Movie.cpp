// ------------------------------ Movie.cpp -----------------------------------
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

#include "Movie.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize variables of Movie object respectively 
// ----------------------------------------------------------------------------
Movie::Movie(): Inventory(), title(""), director(""), year(0){}

// ----------------------------- Constructor ----------------------------------
// Copy Constructor
// Description: constructor to copy an existing Movie object into 
//              a new Movie object 
// ----------------------------------------------------------------------------
Movie::Movie(const Movie& rhs){
	title = rhs.title;
	director = rhs.director;
	year = rhs.year;
}

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
// ----------------------------------------------------------------------------
Movie::~Movie(){}

// ------------------------------- display ------------------------------------
// Discription: function to display all the information for specific movie 
// ----------------------------------------------------------------------------
void Movie::display() const { 
	cout << title << " " << director << " " << year << endl;
}

// ---------------------------- displayHeader ---------------------------------
// Discription: function to display a specific header for Mobie objects.
// ----------------------------------------------------------------------------
void Movie::displayHeader() const {
	cout << " ************ MOVIE TITLE *********** " << endl;
}	

// -------------------------------- setData -----------------------------------
// Discription: function to grab the proper data of all movie objects from 
//              the external file into appropreate variables. 
// ----------------------------------------------------------------------------
void Movie::setData(istream& infile){
	infile.get();
	getline(infile, director, ',');

	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
} 
