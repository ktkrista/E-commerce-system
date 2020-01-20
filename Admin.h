#pragma once
#include "LinkedList.h"
#include "Node.h"

class Admin
{
public:
	Admin();
	//getters and setters for private variables
	void setpassWord(std::string p);
	void setuserName(std::string n);
	std::string getpassWord();
	std::string getuserName();
	bool validateUserNameAndPassword(std::string uName, std::string passW);
	
	//Functions to Manipulate Products List
	void insert_back(Node* n);
	bool search(std::string pN);
	void deleteNode(std::string pN);
	void PrintLinkedList();
	void updateQuantityOfProduct(std::string pN, int q);
	int subtractQuantity(std::string pN, int q);

	//functions to return private variables from node
	std::string getNumber(std::string n);
	std::string getName(std::string na);
	double getCost(std::string c);
	int getQuantity(std::string q);
	void updateProductFile();

private:
	std::string userName; // Admin's username
	std::string passWord; // Admin's password
	LinkedList AdminList; // Admin's linked list
};

