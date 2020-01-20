#include "Customer.h"
#include "Admin.h"

Customer::Customer()
{
	firstName = lastName = Address = City = State = Zip = "\0";
}

// Overloaded constructor
Customer::Customer(std::string f, std::string l, std::string a, std::string c, std::string s, std::string z)
{
	firstName = f;
	lastName = l;
	Address = a;
	City = c;
	State = s;
	Zip = z;
}

// Setter functions
void Customer::setFirstName(std::string f) { firstName = f;}
void Customer::setLastName(std::string l) { lastName = l;}
void Customer::setAddress(std::string a) { Address = a; }
void Customer::setCity(std::string c) {City = c; }
void Customer::setState(std::string s) { State = s; }
void Customer::setZip(std::string z) { Zip = z; }

// Getter functions
std::string Customer::getFirstName() { return firstName;}
std::string Customer::getLastName() { return lastName; }
std::string Customer::getAddress() { return Address; }
std::string Customer::getCity() { return City; }
std::string Customer::getState() { return State; }
std::string Customer::getZip() { return Zip; }

//These functions are used to modify linked list from class
void Customer::insert_back(Node* n) { cusList.insert_back(n); }
bool Customer::search(std::string pN) { return cusList.search(pN); }
void Customer::deleteNode(std::string pN) { cusList.deleteNode(pN); }
void Customer::PrintLinkedList() { cusList.PrintLinkedList(); }
void Customer::updateQuantityOfProduct(std::string pN, int q) { cusList.updateQuantityOfProductCustomer(pN, q); }
int Customer::subtractQuantity(Admin& Administrador,std::string pN, int q){return Administrador.subtractQuantity(pN, q);}

// These functions output the data
void Customer::printReceipt() { cusList.printReceipt(); }
void Customer :: createFileReceipt(std::string fN, std::string n, std::string a, std::string csz){cusList.createFileReceipt(fN, n,a,csz);}
