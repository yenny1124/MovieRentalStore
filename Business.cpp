// ---------------------------- Business.cpp ----------------------------------
// Jamie Choi, CSS 343, Spring 2021, Assignment 4
// Created on:         May 28, 2021
// Last Modified:   June 10, 2021
// ----------------------------------------------------------------------------
// Purpose: The class has responsibility to properly manage all customers, all 
//          movie's inventory, and transaction with all given external files.
//          It is in charge of creating, maintaining and modifying all possible
//          data related to the class. 
// ----------------------------------------------------------------------------
// Assumptions: All datas from the external file are assumed to be correctly 
//              formatted and valid. 

#include "Business.h"

// ---------------------------- Constructor -----------------------------------
// Default constructor
// Discription: constructor to initialize a variable of Business object 
// ----------------------------------------------------------------------------
Business::Business() {
  name = "";
}

// ---------------------------- Constructor -----------------------------------
// Name constructor
// Discription: constructor to assign the store name. The name is 
//              necessary to display the store's header 
// ----------------------------------------------------------------------------
Business::Business(string N): name(N) {}

// ---------------------------- Constructor -----------------------------------
// Copy Constructor
// Description: constructor to use the copy of state of the store 
// ----------------------------------------------------------------------------
Business::Business(const Business& rhs) {}

// ---------------------------- Destructor ------------------------------------
// Discription: destructor to deallocate memory on the heap
// ----------------------------------------------------------------------------
Business::~Business() {}

// -------------------------- structCustomer ----------------------------------
// Discription: function to build Customer objects from the external customer file
//              and reserve them in the store's customer list 
// ----------------------------------------------------------------------------
void Business::structCustomer(istream& custfile){	
	// build customers from the external customer file
	while (true){
		Customer* customer = new Customer();
		customer->setData(custfile);

		if (custfile.eof()){
			delete customer;
			customer = nullptr;
			break;
		}
		custList.addItem(customer->getCustomerID(), customer);
	}
}

// ---------------------------- structInventory -------------------------------
// Discription: function to produce Inventory objects from Factory object and 
//              reserve them in the inventoryList. 
// ----------------------------------------------------------------------------
void Business::structInventory(istream& invenfile){		
	// build inventory from the external inventory file
	char cha = ' ';

	while (true){
		invenfile >> cha;

		if (invenfile.eof()){ break; }

    // create a new movie item through the Factory class
		Inventory* updateMovie = factory.createMovie(cha, invenfile);

		if (updateMovie != nullptr){
			updateMovie->setData(invenfile);

			bool insertion = inventoryList[factory.toSubscript(cha)].insert(updateMovie, 10);

			if (!insertion){
				delete updateMovie;
				cout << "The Movie Cannot Be Inserted" << endl;
			}
		}
	  updateMovie = nullptr;
	  delete updateMovie;
	} 
}

// ---------------------------- structCommands --------------------------------
// Discription: function to process the history of customer's transaction and 
//              movie inventory. It also handles the possible errors and display 
//              them in the screen 
// ----------------------------------------------------------------------------
void Business::structCommands(istream& commandsfile) {
	char actionCode = ' ';
	char genreCode = ' ';
	char mediaCode = ' ';
	int customerID = 0;
	bool found = false;
	string mediaType = "";
	Inventory* itemLocation = nullptr;
	Customer* tmpCust = nullptr;
	Inventory* tmpItem = nullptr;

	while (true){
		commandsfile >> actionCode;

		if (commandsfile.eof()){ break; } 
		if (actionCode == 'I'){
			displayInventory();
			actionCode = ' ';
			
		}else if (commandsfile.get() == '\n'){
			actionCode =' ';

		}else{
			Transaction* processingTran = factory.createTransaction(actionCode, commandsfile);

			if (processingTran != nullptr){ 
				commandsfile >> customerID;

				if (commandsfile.eof()){ break; } 

				if (lookUpCustomer(customerID)){
					tmpCust = custList.getItem(customerID);

					bool isTransaction = processingTran->setData(mediaType, itemLocation, tmpCust);

					if (commandsfile.get() != '\n' && isTransaction){ 

						commandsfile >> mediaCode;
						mediaType = factory.getMediaType(mediaCode);

						if (mediaType != ""){  

							commandsfile >> genreCode;
							tmpItem = factory.createMovie(genreCode, commandsfile);

							if (tmpItem != nullptr){
								tmpItem->setDataTransaction(commandsfile);

								found = inventoryList[factory.toSubscript(genreCode)].retrieve(*tmpItem, itemLocation);

								if (found == false)	{ 
									cout << "#### ERROR! " << tmpItem->getItem() << " -> Invalid Movie Title Request ####" << endl;
								}

								delete tmpItem;
								tmpItem = nullptr;

								bool found2 = processingTran->setData(mediaType, itemLocation, tmpCust);
		
								if ((found && found2) && mediaType != ""){
									custList.getItem(customerID)->addTransaction(*processingTran);	
								}
								delete processingTran;
								processingTran = nullptr;

							}else{
								cout << "#### ERROR! " << genreCode << " -> Invalid Movie Genre Request ####" << endl;

								if (processingTran != nullptr){
									delete processingTran;
								}
								processingTran = nullptr;
							}

							string tmp;
							getline(commandsfile, tmp, '\n');
							delete tmpItem;
							tmpItem = nullptr;

						}else{
							string tmp;
							getline(commandsfile, tmp, '\n');

							cout << "#### ERROR! " << mediaCode << " -> Invalid Media Code Request #### "<<endl;

							if (processingTran != nullptr){
								delete processingTran;
							}	
							processingTran = nullptr;
						}

					}else{
						if (processingTran != nullptr){
							delete processingTran;
						}	
						processingTran = nullptr;
					}

				}else{
					cout << "#### ERROR! " << customerID << " -> Invalid Customer ID Request ####" << endl;

					if (processingTran != nullptr){
						delete processingTran;
					}	
					processingTran = nullptr;

					string tmp;
					getline(commandsfile, tmp, '\n');
				}
			
      }else{
				cout << "#### ERROR! " << actionCode << " -> Invalid Action Code Request ####" << endl;

				if (processingTran != nullptr){
					delete processingTran;
				}	
				processingTran = nullptr;
			}
		}

		found = false;
		customerID = 0;
		itemLocation = nullptr;
		tmpCust = nullptr;
		tmpItem = nullptr;
	}//end while loop
}

// ---------------------------- displayInventory ------------------------------
// Discription: function to display all movie items in the store's inventory 
//              with the stock remaining 
// ----------------------------------------------------------------------------
void Business::displayInventory() const{
  // display customer base 
  for (int i = 0; i < MAXNUMCUSTOMER; i++){
		if (lookUpCustomer(i)){
			getCustomer(i).display();
		}
	}

  // display the store's inventory
	if (name != ""){
	  cout <<
  	"\n----------------------->> JamJam Movie Rental Store <<-----------------------"<<endl;
		cout << "Display Inventory for "<< name << endl;
	}

	for (int i = 0; i < MAXNUMINVENTORY; i++){
		if (!inventoryList[i].isEmpty()){ // BS Tree
			inventoryList[i].inorderDisplay(inventoryList[i].getRoot());
		  cout << endl;
		}
	}
}

// -------------------------- lookUpCustomer ----------------------------------
// Discription: function to check if a customer is in the store's customer list 
//              or not through checking their customer ID
// ----------------------------------------------------------------------------
bool Business::lookUpCustomer(int custID) const {
	if (custList.getItem(custID) == nullptr){
		return false;
	}
		
	if (custList.getItem(custID)->getCustomerID() == -1){
		return false;

	}else{
		return true;
	}		
} 


