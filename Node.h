#pragma once
#include <string>

class Node
{
public:
	friend class LinkedList;

	Node();
	//overloaded copy constructor
	Node(const Node& rightObj);
	Node& operator=(const Node& rightObj);
	//getter functions
	std::string getNumber();
	std::string getName();
	double getCost();
	int getQty();
	void setNumber(std::string n);
	void setName(std::string na);
	void setQty(int Q);
	void setCost(double C);
	Node* getNext();

private:
	std::string number; // Item number of the product
	std::string name; // Name of the product
	double cost; //Cost of the product
	int qty; // Quantity of the product
	Node* Next;//ptr to next node or null if end of list
};

