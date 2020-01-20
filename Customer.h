#pragma once
#include <string>
#include "LinkedList.h"
#include "Admin.h"

class Customer
{
public:
	Customer();
	// Overloaded constructor
	Customer(std::string f, std::string l, std::string a, std::string c, std::string s, std::string z);
	//getters and setters for private variables
	void setFirstName(std::string f);
	void setLastName(std::string l);
	void setAddress(std::string a);
	void setCity(std::string c);
	void setState(std::string s);
	void setZip(std::string z);
	std::string getFirstName();
	std::string getLastName();
	std::string getAddress();
	std::string getCity();
	std::string getState();
	std::string getZip();
	
	//functions to add items to list
	void insert_back(Node* n);
	bool search(std::string pN);
	void deleteNode(std::string pN);
	void PrintLinkedList();
	void updateQuantityOfProduct(std::string pN, int q);
	int subtractQuantity(Admin& Administrador,std::string pN, int q);

	void printReceipt();
	void createFileReceipt(std::string fN, std::string n, std::string a, std::string csz);

private:
	// Customer Information
	std::string firstName; 
	std::string lastName; 
	std::string Address;
	std::string City;
	std::string State;
	std::string Zip;
	// Customer linked list
	LinkedList cusList;
};

