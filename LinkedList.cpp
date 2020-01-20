#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <fstream>

LinkedList::LinkedList()
{
	//initializing private variables
	head = nullptr;
	numOfElements = 0;
	isEmpty = true;
}

//copy constructors
LinkedList :: LinkedList(const LinkedList& rightObject)
{
	/*example Obj a; //rightHandSideObj
			  Obj b(a);// b is this obj
	*/
	//copying private variables from LL
	this->numOfElements = rightObject.numOfElements;
	this->isEmpty = rightObject.isEmpty;
	//Everything from rightHandSideObj is now copied into this obj.
	copyLL(rightObject);
}

LinkedList& LinkedList :: operator=(const LinkedList& rightHandSideObj)
{
	//checking if we are copying the same object
	if (this == &rightHandSideObj) {
		return *this;
	}
	/*example Obj a;
			  Obj b;
			  b = a;
	*/
	//deleting previously delclared private data and nodes from this LL.
	//In this case everything in b will be deleted.
	deleteLL();
	//copying private variables from LL
	this->numOfElements = rightHandSideObj.numOfElements;
	this->isEmpty = rightHandSideObj.isEmpty;
	//now we copy everything from right object to left.
	copyLL(rightHandSideObj);

	return *this;
}

LinkedList :: ~LinkedList()
{
	//call the clear linked list function to delete all dynamic memory.
	deleteLL();
}

LinkedList& LinkedList :: operator+=(const LinkedList& rightHandSideObj)
{
	//returning this if righthand side is empty
	if (rightHandSideObj.head == nullptr)
		return *this;

	//This pointer will point to the LL that is being copied.
	Node* Iterator = rightHandSideObj.head;

	//iterating through the ll and copying every node from rightHandSide to this obj
	while (Iterator != nullptr) {
		//storing elements from Linked list to a nod
		Node* rightListNode = new Node;
		rightListNode->number = Iterator->number;
		rightListNode->name = Iterator->name;
		rightListNode->cost = Iterator->cost;
		rightListNode->qty = Iterator->qty;
		//add node to this object
		this->insert_back(rightListNode);

		//Moving to next element in ll. If there is none it wont go into while loop.
		Iterator = Iterator->Next;
	}
	return *this;
}

void LinkedList::copyLL(const LinkedList& rightHandSideObj)
{
	//checking if the Linked List is empty
	if (rightHandSideObj.head == nullptr) {
		//Initializing lhs private data to an empty list
		this->head == nullptr;
		return;// done
	}
	else {

		//This pointer will point to the LL that is being copied.
		Node* Iterator = rightHandSideObj.head;

		//iterating through the ll and copying every node from rightHandSide to this obj
		while (Iterator != nullptr) {
			//storing elements from Linked list to a nod
			Node* rightListNode = new Node;
			rightListNode->number = Iterator->name;
			rightListNode->name = Iterator->name;
			rightListNode->cost = Iterator->cost;
			rightListNode->qty = Iterator->qty;
			//add node to this object
			this->insert_back(rightListNode);

			//Moving to next element in ll. If there is none it wont go into while loop.
			Iterator = Iterator->Next;
		}
		this->isEmpty = rightHandSideObj.isEmpty;
		this->numOfElements = rightHandSideObj.numOfElements;

	}
}

void LinkedList::deleteLL()
{
	if (head == nullptr)
		return;//exit

	//accesing beggining of list
	Node* currentNode = head;

	//deleteing each node
	while (currentNode != nullptr) {
		//create temp node to point to next of current.
		Node* temp = currentNode->Next;
		//delete currentNode
		delete currentNode;
		//current points to next node (temp)
		currentNode = temp;
	}

	delete currentNode;

	head = nullptr;
	isEmpty = true;
	numOfElements = 0;
}

void LinkedList :: insert_back(Node* &newNode)
{
	Node* current = nullptr;					//Create a temporary node to use to transverse through the linked list

	if (!head) {									//Check to see if linked list is empty
		head = newNode;								//If it is append the new node onto the empty list
		isEmpty = false;
	}
	else {
		current = head;								//Set the current node to the head node

		while (current->Next) {						//Traverse the linked list until you reach the end
			current = current->Next;
		}
		current->Next = newNode;					//At the end set the current to point to the new node.
	}
	//increment the number of nodes
	++numOfElements;
}

void LinkedList :: PrintLinkedList()
{
	PrintLinkedList(head);
}

void LinkedList :: PrintLinkedList(Node* &h) {
	Node* current = h;					//Create a temporary node to use to transverse through the linked list
	
	std::cout << "{ ";

	while (current != nullptr) {			//Loop through the list until we find the end
		std::cout << current->number << " ";
		std::cout << current->name << " ";
		std::cout << current->cost << " ";
		std::cout << current->qty << " ";
		std::cout << std::endl;
		
		//move to next node
		current = current->Next;
	}
	std::cout << "}" << std::endl;
}

//This search function is only used to check if struct exists.
bool LinkedList :: search(std::string productNumber)
{
	if (head == nullptr)
		return false;

	Node* current = head;

	while (current != nullptr)
	{
		if (current->number == productNumber)
			return true;
		current = current->Next;
	}
	return false;
}

// This function removes the element from the specific location from Product Linked List.
void LinkedList :: deleteNode(std::string productNm)
{
	bool nodeExists = false;
	Node* currentNode = nullptr;
	Node* previsousNode = nullptr;

	//getting both pointers to beginning of list
	previsousNode = currentNode = head;

	//the linked list is empty
	if (head == nullptr) {
		return;
	}
	else//the node that neads to be deleted is head
		if (currentNode->number == productNm) {

			//checking if there is only one element in linked list
			if (currentNode->Next == nullptr) {
				//head is now empty
				head = nullptr;
				return;
			}

			//making the previous equal to head
			previsousNode = head;
			//chaning the address of head to the next struct
			head = head->Next;
			//delete previous
			delete previsousNode;
			//we are done
			return;
		}
		else {

			//find the struct weneed to delete
			while (currentNode != nullptr)
			{
				if (currentNode->number == productNm) {
					nodeExists = true;
					break;
				}
				//keeping track of previous
				previsousNode = currentNode;
				//moving current to next struct
				currentNode = currentNode->Next;
			}

			//if the struct does not exist then we are done
			if (nodeExists == false)
				return;

			//switching pointer
			previsousNode->Next = currentNode->Next;
			//deleting node
			delete currentNode;
		}
}

// Update the quantity in Admin mode
void LinkedList :: updateQuantityOfProductAdmin(std::string productNm, int qty)
{
	//find struct in customer linked list
	Node* current = head;

	while (current != nullptr)
	{
		//updating quantity of customer cart
		if (current->number == productNm)
			current->qty = qty;

		current = current->Next;
	}
}

// Update the quantity in the cart
void LinkedList :: updateQuantityOfProductCustomer(std::string productNm, int qty)
{
	//find struct in customer linked list
	Node* current = head;

	while (current != nullptr)
	{
		//updating quantity of customer cart
		if (current->number == productNm)
			current->qty += qty;

		current = current->Next;
	}
}

//WARNING ONLY USE IF THE PRODUCTNUMBER EXISTS
int LinkedList :: subtractQuantity(std::string productNumber, int cusQty)
{
	int finalQty = 0;
	Node* current = head;

	while (current != nullptr)
	{
		//find it
		if (current->number == productNumber) {
			//substrcat qty
			current->qty -= cusQty;
			//store it
			finalQty = current->qty;
			//return it
			return finalQty;
		}

		current = current->Next;
	}
}

std::string LinkedList :: getNumber(std::string productNumber)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->number == productNumber)
			return current->number;

		current = current->Next;
	}
}

std::string LinkedList :: getName(std::string productNumber)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->number == productNumber)
			return current->name;

		current = current->Next;
	}
}

double LinkedList :: getCost(std::string productNumber)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->number == productNumber)
			return current->cost;

		current = current->Next;
	}
}


//ONLY USE IF THE PRODUCTNUMBER EXISTS
int LinkedList :: getQuantity(std::string productNumber)
{
	Node* current = head;

	while (current != nullptr)
	{
		if (current->number == productNumber)
			return current->qty;

		current = current->Next;
	}
}

void LinkedList :: printReceipt()
{
	double totalCustomer = 0;
	Node* current = head;

	std::cout << std::left << std::setw(22) << "Item Number";
	std::cout << std::left << std::setw(22) << "Item Name";
	std::cout << std::left << std::setw(17) << "Qty";
	std::cout << std::left << std::setw(24) << "Unit Cost";
	std::cout << std::left << std::setw(16) << "Total";
	std::cout << std::endl << "------------------------------------------------------";
	std::cout << "------------------------------------------------------" << std::endl;

	while (current != nullptr)
	{
		std::cout << std::left << std::setw(12) << "Item Number " << std::left << std::setw(10) << current->getNumber();
		std::cout << std::left << std::setw(13) << std::left << std::setw(22) << current->getName();
		std::cout << std::left << std::setw(17) << current->getQty();
		std::cout << std::left << std::setw(24) << current->getCost();
		std::cout << std::left << std::setw(16) << current->getQty() * current->getCost() << std::endl;
		totalCustomer += current->getQty() * current->getCost();
		current = current->getNext();
		std::cout << std::endl;
	}
	std::cout << "------------------------------------------------------";
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << std::right << std::setw(85) << "Total: $" << totalCustomer;
	std::cout << std::endl << std::endl;
}

void LinkedList :: createFileReceipt(std::string fN, std::string n, std::string a, std::string csz)
{
	double totalCustomer = 0;
	Node* current = head;
	std::ofstream outFile;
	outFile.open(fN);

	// Display the customer informations
	outFile << std::endl;
	outFile << "Customer Name: " << n << std::endl;
	outFile << "Customer Address: " << a << std::endl;
	outFile << "                  " << csz << std::endl;
	outFile << std::endl;
	outFile << std::left << std::setw(22) << "Item Number";
	outFile << std::left << std::setw(22) << "Item Name";
	outFile << std::left << std::setw(17) << "Qty";
	outFile << std::left << std::setw(24) << "Unit Cost";
	outFile << std::left << std::setw(16) << "Total";
	outFile << std::endl << "------------------------------------------------------";
	outFile << "------------------------------------------------------" << std::endl;

	while (current != nullptr)
	{
		outFile << std::left << std::setw(12) << "Item Number " << std::left << std::setw(10) << current->getNumber();
		outFile << std::left << std::setw(13) << std::left << std::setw(22) << current->getName();
		outFile << std::left << std::setw(17) << current->getQty();
		outFile << std::left << std::setw(24) << current->getCost();
		outFile << std::left << std::setw(16) << current->getQty() * current->getCost() << std::endl;
		totalCustomer += current->getQty() * current->getCost();
		current = current->getNext();
		outFile << std::endl;
	}
	outFile << "------------------------------------------------------";
	outFile << "------------------------------------------------------" << std::endl;
	outFile << std::right << std::setw(85) << "Total: $" << totalCustomer;
	outFile << std::endl << std::endl;

	//closing file
	outFile.close();
}

void LinkedList::updateProductFile()
{
	Node* current = head;

	std::ofstream outFile;
	outFile.open("ProductData.txt");

	while (current != nullptr) {

		outFile << current->number << ",";
		outFile << current->name << ",";
		outFile << current->cost << ",";
		outFile << current->qty << std::endl;
		current = current->Next;
	}

	//closing file
	outFile.close();
}