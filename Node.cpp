#include "Node.h"

// Default constructor
Node::Node()
{
	Next = nullptr;
	name = "\0";
	number = "\0";
	cost = qty = 0;
}

//copying everything from right hand side to this object
Node::Node(const Node& rightObj)
{
	Next = rightObj.Next;
	name = rightObj.name;
	number = rightObj.number;
	cost = rightObj.cost;
	qty = rightObj.qty;
}

// Overloaded operator
Node& Node ::operator=(const Node& rightObj)
{
	Next = rightObj.Next;
	name = rightObj.name;
	number = rightObj.number;
	cost = rightObj.cost;
	qty = rightObj.qty;

	return *this;
}

//getter functions returns private variables 
std::string Node ::  getNumber() { return number; }
std::string Node :: getName() { return name; }
double Node :: getCost() { return cost; }
int Node::getQty() { return qty; }

//Setter funtions to set the private variables
void Node::setQty(int Q) { qty = Q; }
void Node::setCost(double C) { cost = C; }
void Node::setNumber(std::string n) { number = n; }
void Node::setName(std::string na) { name = na; }
Node* Node::getNext() { return Next; }



