// ----------------------------- Factory.h ------------------------------------
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

#ifndef FACTORY_H
#define FACTORY_H
#include "Classic.h"
#include "Drama.h"
#include "Comedy.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"
using namespace std;

static const int MAXNUMITEMS = 26;
static const int CLASSIC = 2;
static const int DRAMA = 3;
static const int COMEDY = 5;
static const int BORROW = 1;
static const int HISTORY = 7;
static const int RETURN = 17;

class Movie; // forward declaration
class Transaction; // forward declaration

class Factory {

public:
  // Constructor and Destructor
	Factory();
	~Factory();

  // Member functions 
	Inventory* createMovie(char, istream&);
	Transaction* createTransaction(char, istream&);
	int toSubscript(char);
	string getMediaType(char);
	
private:
	Inventory* storeInventory[MAXNUMITEMS];
	Transaction* transactionInventory[MAXNUMITEMS];
	string mediaType[MAXNUMITEMS];

	int hash(char) const;	//implemented by the transaction and inventory
};
#endif
