#pragma once
#include "Node.h"

class LinkedList
{
public:
	//default constructor
	LinkedList();
	
	//copy constructor
	LinkedList(const LinkedList& rightObject);
	//destructor
	~LinkedList();

	//overloaded operators
	LinkedList& operator=(const LinkedList& rightObject);
	LinkedList& operator+=(const LinkedList& rightObject);

	//pust to back of linkedlist function
	void insert_back(Node* &newNode);
	//function that will delete a certain node
	void deleteNode(std::string pN);
	//display the entire list
	void PrintLinkedList();
	//functions to manipulate linked list
	bool search(std::string productNumber);
	//update qty for LL
	void updateQuantityOfProductAdmin(std::string productNm, int qty);
	void updateQuantityOfProductCustomer(std::string productNm, int qty);
	int subtractQuantity(std::string productNumber, int cusQty);

	//getters functions
	std::string getNumber(std::string n);
	std::string getName(std::string na);
	double getCost(std::string c);
	int getQuantity(std::string p);

	//other utility functions for Customer
	void printReceipt();
	void createFileReceipt(std::string fN, std::string n, std::string a, std::string csz);
	void updateProductFile();
	
private:
	//copy function used in copy constructor and = operator
	void copyLL(const LinkedList& rightObject);
	//clear function used to delete entire list
	void deleteLL();
	//private print function
	void PrintLinkedList(Node* &h);

	//node to beginning of list
	Node* head;
	//keeping track of number of elements
	int numOfElements;
	//checking if list is empty
	bool isEmpty;
};

