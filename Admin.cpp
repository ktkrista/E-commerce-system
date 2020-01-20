#include "Admin.h"
#include "LinkedList.h"
#include "Node.h"

//constructor
Admin::Admin(){userName = passWord = "\0";}

//getters and setters
void Admin::setpassWord(std::string p) {passWord = p;}
std::string Admin::getpassWord() { return passWord; }

void Admin::setuserName(std::string n) { userName = n; }
std::string Admin::getuserName() { return userName; }

//This function will determine if username and password match
bool Admin::validateUserNameAndPassword(std::string uName, std::string passW)
{
	if ((userName == uName) && (passWord == passW))
		return true;
	else
		return false;
}

//These functions are used to modify linked list from class
void Admin::insert_back(Node* n) { AdminList.insert_back(n);}
bool Admin::search(std::string pN) { return AdminList.search(pN); }
void Admin::deleteNode(std::string pN) { AdminList.deleteNode(pN); }
void Admin::PrintLinkedList() { AdminList.PrintLinkedList(); }
void Admin::updateQuantityOfProduct(std::string pN, int q) { AdminList.updateQuantityOfProductAdmin(pN, q); }
int Admin::subtractQuantity(std::string pN, int q) { return AdminList.subtractQuantity(pN, q); }

// Getter functions
std::string Admin::getNumber(std::string n) { return AdminList.getNumber(n); }
std::string Admin::getName(std::string na) { return AdminList.getName(na); }
double Admin::getCost(std::string c) { return AdminList.getCost(c); }
int Admin::getQuantity(std::string q) { return AdminList.getQuantity(q); }

// This function updates the inventory file
void Admin::updateProductFile() { AdminList.updateProductFile(); }

