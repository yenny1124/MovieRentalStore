// ------------------------------ BStree.cpp ----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: The program implements a binary search tree to hold movies and 
//          retrive them in properly sorted orders.
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "BStree.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize the root as nullptr
// ----------------------------------------------------------------------------
BStree::BStree() : root(nullptr) {}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: copy constructor to complete inventory 
// ----------------------------------------------------------------------------
BStree::BStree(const BStree& rhs){ *this = rhs;} //end copy constructor

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory in heap by calling destructTree
//              function 
// ----------------------------------------------------------------------------
BStree::~BStree(){
	if (root != nullptr){
  	destructTree(root);
  } 
} 

// ------------------------------ Insert --------------------------------------
// Discription: function to insert a movie object in proper location and retrive 
//              this correctly
// ----------------------------------------------------------------------------
bool BStree::insert(Inventory* MovieInsertion, const int numMstock){
	Node* NodePtr = new Node();    
	NodePtr->movie = MovieInsertion; 
	NodePtr->movie->setNumMaxCopy(numMstock);
	MovieInsertion = nullptr; 
	NodePtr->left = NodePtr->right = nullptr;

	if (isEmpty()){
		root = NodePtr; 
	
  }else{
		Node* cur = root;
		bool insertion = false;

		while (!insertion){
			if (*NodePtr->movie == *cur->movie){ 
				delete NodePtr; 
				NodePtr = nullptr;
				return false;
			}else if (*NodePtr->movie < *cur->movie){
				if (cur->left == nullptr){
					cur->left = NodePtr;
					insertion = true;
			  }else{
					cur = cur->left;
				}
			}else{
				if (cur->right == nullptr) {
					cur->right = NodePtr;
					insertion = true;
				}else{
					cur = cur->right;
				}	            
			}
		}
	}
	return true;
} 

// ------------------------------- isEmpty ------------------------------------
// Discription: functio to check if the tree is empty or not 
// ----------------------------------------------------------------------------
bool BStree::isEmpty() const {
	return (root == nullptr); 
} 

// --------------------------- destructTree -----------------------------------
// Discription: function to delete the node in the tree calling by the destructor 
// ----------------------------------------------------------------------------
void BStree::destructTree(Node*& T){
	if (T!= nullptr){
		destructTree(T->left); // destroy left child 
		destructTree(T->right); // destroy right child 

		delete T->movie; // delete Node 
		T->movie = nullptr;
		delete T; // delete Node
		T = nullptr;
	}
} 

// ----------------------------- retrieve -------------------------------------
// Discription: function to check if a movie title is found or not 
// ----------------------------------------------------------------------------
bool BStree::retrieve(const Inventory& dataMovie, Inventory*& movieFound) const{
	retrieveHelper(root, dataMovie, movieFound);

	if (movieFound != nullptr){
		return true;
	}else{
		return false;
	}	
} 

// -------------------------- retrieveHelper ----------------------------------
// Discription: function to recursively help the retrive function check if a movie 
//              is in the tree 
// ----------------------------------------------------------------------------
void BStree::retrieveHelper(Node* currentPtr, const Inventory & dataMovie, Inventory*& movieFound) const{
	if (currentPtr == nullptr){
		movieFound = nullptr;
	}	
	else if (dataMovie == *currentPtr->movie){
		movieFound = currentPtr->movie;
	}
	else if (dataMovie < *currentPtr->movie){
		retrieveHelper(currentPtr->left, dataMovie, movieFound);
	}else{
		retrieveHelper(currentPtr->right, dataMovie, movieFound);
	}	
}

// -------------------------- inorderDisplay ---------------------------------
// Discription: function to display all movie titles by the number of each stock 
// ---------------------------------------------------------------------------
void BStree::inorderDisplay(Node * cur) const{
	if (cur == root){
		cur->movie->displayHeader(); 
  }

	if (cur != nullptr){
		inorderDisplay(cur->left);

		cout << right << setw(2) << cur->movie->getAmountIn() << "  " <<
			left << setw(3) << cur->movie->getAmountOut() << " ";
		
		cur->movie->display();
		inorderDisplay(cur->right);
	}
}

