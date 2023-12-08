// ------------------------------- BStree.h -----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: The program implements a binary search tree to hold movies and 
//          retrive them in properly sorted orders.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#ifndef BSTREE_H
#define BSTREE_H
#include "Movie.h"
using namespace std;

class BStree {
	struct Node;
  
public:

  // Constructors and Destructor
	BStree(); 
	BStree(const BStree&); 
	~BStree(); 

	// Member functions 
	bool insert(Inventory*, const int);
	bool isEmpty() const;
	bool retrieve(const Inventory&, Inventory*&) const;
	void retrieveHelper(Node*, const Inventory&, Inventory*&) const;
	void inorderDisplay(Node*) const;

	Node *getRoot() const{ // function to return the root of tree 
	  return this->root; 
  };

private:
	// Struct to reserve pointers to movie data and tree childs 
	struct Node {
		Inventory *movie; // pointer to movie item
		Node *left;   // leftchild 
    	Node *right;  // rightchild 
	};
	Node *root; // root of the BStree

	// Helper function
	void destructTree(Node*&);
};
#endif
