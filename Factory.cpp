// ---------------------------- Factory.cpp -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: The class is created to build Inventory and Transaction objects. 
//          It utilizes pre-defined indexes depending on the data type and 
//          pre-defined max number of each item per HashTable. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Factory.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize objects within arrays of HashTable
// ----------------------------------------------------------------------------
Factory::Factory(){

  for (int i = 0; i < MAXNUMITEMS; i++){
		storeInventory[i] = nullptr;
		transactionInventory[i] = nullptr;
		mediaType[i] = "";
	}

  	storeInventory[COMEDY] = new Comedy();
	storeInventory[DRAMA] = new Drama();
  	storeInventory[CLASSIC] = new Classic();

	transactionInventory[BORROW] = new Borrow();
	transactionInventory[HISTORY] = new History();
	transactionInventory[RETURN] = new Return();

	mediaType[DRAMA] = "DVD";
}

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
// ----------------------------------------------------------------------------
Factory::~Factory(){
	for (int i = 0; i < MAXNUMITEMS; i++){
		if (storeInventory[i] != nullptr){
			delete storeInventory[i];
			storeInventory[i] = nullptr;
		}//end if store inventory

		if (transactionInventory[i] != nullptr){
			delete transactionInventory[i];
			transactionInventory[i] = nullptr;
		}//end if transaction inventory
	}
} 

// ------------------------------ createMovie ---------------------------------
// Discription: function to create movie objects adjusting the location within 
//              array 
// ----------------------------------------------------------------------------
Inventory * Factory::createMovie(char cha, istream& infile) {
	string tmp;

	int subscript = hash(cha);	
	if (storeInventory[subscript] == nullptr){
		getline(infile, tmp, '\n');
		return nullptr;

	}else{
		return storeInventory[subscript]->createNewMovie();
	}
}

// --------------------------- createTransaction ------------------------------
// Discription: function to create transaction objects adjusting the location 
//              within array 
// ----------------------------------------------------------------------------
Transaction * Factory::createTransaction(char cha, istream& infile) {
	string tmp;

	int subscript = hash(cha);
	if (transactionInventory[subscript] == nullptr){
		getline(infile, tmp, '\n');
		return nullptr;
	
  }else{
		return transactionInventory[subscript]->createNewTransaction();
	}	
}	

// ---------------------------- toSubscript -----------------------------------
// Discription: function to return the Hash of cha passed in and translate it 
//              as array subscript 
// ----------------------------------------------------------------------------
int Factory::toSubscript(char cha){
	return hash(cha);
}

// ----------------------------- getMediaType ---------------------------------
// Discription: function to return media type depending on the cha passed in 
// ----------------------------------------------------------------------------
string Factory::getMediaType(char cha) {
	return mediaType[hash(cha)];
}

// --------------------------------- hash -------------------------------------
// Discription: finction to compute int value of a character
// ----------------------------------------------------------------------------
int Factory::hash(char cha) const{ 
	if (cha < 'a') { return cha - 'A'; } 
	else { return 0; }
}

