// ------------------------------- Hash.h -------------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: This hashtable class facilitates storing customer's information.
//          It functions as a data structure to sort by according to the
//          customerID. It quickly looks of items and map them into a unique 
//          order, which is custmoerID. Since the array will not always filled,
//          there can be possibly some memory leak. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Customer.h"
using namespace std;

template <class ItemType>
class HashTable {
  
public:
// Constructor and Destructor
HashTable(){constructTable();}
~HashTable(){makeEmpty();}

// Member functions
// ------------------------------- getItem ------------------------------------
// Description: function to return items we're searching. If nothing found, it
//              returns nullptr 
// ----------------------------------------------------------------------------
Customer* getItem(int X) const{
	int hashT = (X % TABLE_SIZE);              

	if (table[hashT] == nullptr){         
		return nullptr;
	}else{
		itemList* node = table[hashT];
		while (node != nullptr){
			if (X == node->X){
				return node->data;
      }
			node = node->next;
		}
	}
	return nullptr;                           
}

// -------------------------------- addItem -----------------------------------
// Description: function to add the item to the hashtable with checking
//              duplicates 
// ----------------------------------------------------------------------------
void addItem(int X, ItemType* item){
	int hashT = (X % TABLE_SIZE);             

	itemList* node = new itemList;      
	node->data = item;               
	node->X = X;                     
	node->next = nullptr;                 

	if (table[hashT] == nullptr){
		node->next = table[hashT];
		table[hashT] = node;
	}else{
		itemList* cur = table[hashT];
    while (cur->next != nullptr){
			if (X == cur->X){
				delete node->data;      
				delete node;            
				throw logic_error("cannot add same X twice");
			}
			cur = cur->next;
		}
		cur->next = node; 
	}
}

private:
	struct itemList {
		Customer* data;   // pointer to customer
		int X;           // X == customerID
		itemList* next;  // next
	};

	static const int TABLE_SIZE = 50; // doubling the number of customer base
  itemList* table[TABLE_SIZE];   // hastable array

// Helper functions
// ----------------------------- constructTable -------------------------------
// Description: function to create an empty table 
// ----------------------------------------------------------------------------
void constructTable(){
	for (int i = 0; i < TABLE_SIZE; ++i) {
		table[i] = nullptr;
	}
}

// ------------------------------ makeEmpty -----------------------------------
// Description: function to delete all items in the table
// ----------------------------------------------------------------------------
void makeEmpty(){
	for (int i = 0; i < TABLE_SIZE; ++i) {
		if (table[i] != nullptr) {
			itemList* temp = table[i];             
			while (table[i] != nullptr) {
				table[i] = table[i]->next;   
				delete temp->data;                      
				delete temp;                           
				temp = nullptr;
				temp = table[i];	               
			}
		}
	}
}
};
#endif

