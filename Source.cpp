

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "LinkedList.h"
#include "Node.h"
#include "Admin.h"
#include "Customer.h"

// This class manages the input file
class FileManager
{
public:
	//Default constructor
	FileManager(){}

	/*read products file to linked list.
	*This function will read in the name of the file  
	*and will accept a linked list to add the products to linkeds list
	*/
	void fileToLinkedList(std::string fName, Admin& Administrador)
	{
		std::ifstream inputFile; // Define file stream object for the input file
		inputFile.open(fName); // Open the input file

		if (inputFile.fail()) // If the input file failed to open
		{
			std::cout << "The file could not be opened" << std::endl; // Display an error message
			inputFile.close(); // Close the input file
			return;//exit function
		}

		//variables to hold data from file
		std::string num = " ", nm = " ", ct = " ", q = " ";

		//read in file until empty
		while (inputFile.good()) {
			  
			//create a node ptr for each product in file
			Node* newNode = new Node;

			getline(inputFile, num, ',');
			if (num.size() == 0) break;//checking for null terminator
			newNode->setNumber(num);

			getline(inputFile, nm, ',');
			newNode->setName(nm);

			getline(inputFile, ct, ',');
			newNode->setCost(stod(ct));

			getline(inputFile, q, '\n');
			newNode->setQty(stoi(q));

			//after reading all of the data to new node we will only add if the quantity is bigger than 0.
			if (stoi(q) != 0) Administrador.insert_back(newNode);
		}
		//close file
		inputFile.close();
	}

//This function output the data to the output file
	void createFile(Customer& customerInfo)
	{
		std::string Name = customerInfo.getFirstName() + " " + customerInfo.getLastName();
		std::string Address = customerInfo.getAddress();
		std:: string CityStateZip = customerInfo.getCity() + ", " +
			customerInfo.getState() + " " + customerInfo.getZip();
		std::string fileName = customerInfo.getLastName() + "_Invoice.txt";

		// Display the customer informations
		std::cout << std::endl;
		std::cout << "Customer Name: " << Name << std::endl;
		std::cout << "Customer Address: " << Address << std::endl;
		std::cout << "                  " << CityStateZip << std::endl;
		std::cout << std::endl;

		customerInfo.printReceipt();
		customerInfo.createFileReceipt(fileName, Name, Address, CityStateZip);
	}

	// This function update the inventory file
	void updateProductFile(Admin& Administrador)
	{
		Administrador.updateProductFile();
	}

private:
	// NONE 
};

//This function will be used to control the administration menu so the the admin can add,delete and update
void adminMenu(Admin& Administrador)
{
	std::string menuOption = "a"; // Holds the menu option
	std::string productNum = "\0", productName = "\0";// Name and number of the product
	double productCost = 0.00; // Cost of the product
	int productQty = 0; // Qty of the product
	int updateQty = 0; // Updated version of the Qty
	std::string pNumDelete; // Hold the product number that will be deleted
	
	// Admin menu
	while (menuOption != "0") {
		std::cout << "**************************************";
		std::cout << "\nHello Admin," << std::endl;
		std::cout << "Press 1 to add a new product.\n"
			<< "Press 2 to delete a product.\n"
			<< "Press 3 to update quantity of product.\n"
			<< "Press 0 to quit.\n";
		std::cout << "**************************************" << std::endl;

		std::cin >> menuOption;

		//checking if the user input 1,2,3
		if (menuOption == "1") {
			//add stuff
			std::cout << "Enter the product number: ";
			std::cin >> productNum;

			std::cout << "Enter the product name: ";
			std::cin >> productName;

			std::cout << "Enter the product cost: ";
			//flushing previous cin
			std::cin.ignore();
			std::cin >> productCost;

			std::cout << "Enter the product quantity: ";
			std::cin.ignore();
			std::cin >> productQty;

			//creating a new node
			Node* newProduct = new Node;
			newProduct->setNumber(productNum);
			newProduct->setName("Product " + productName);
			newProduct->setCost(productCost);
			newProduct->setQty(productQty);

			//adding newly created node to linkedlist
			Administrador.insert_back(newProduct);
		}
		else if (menuOption == "2") {

			bool foundFlag = false;

			while (foundFlag == false) {
				std::cout << "Enter product number: ";
				std::cin >> pNumDelete;
				//chcking if the product exists
				if (Administrador.search(pNumDelete))
					foundFlag = 1;
			}

			//after the while loop we are guaranteed the product exists so we delete.
			Administrador.deleteNode(pNumDelete);

		}
		else if (menuOption == "3") {

			bool foundFlag = false;
			std::string pNum = "\0";

			while (foundFlag == false) {
				std::cout << "Enter product number: ";
				std::cin >> pNum;
				//chcking if the product exists
				if (Administrador.search(pNum))
					foundFlag = 1;
			}

			// Prompts the user to enter qty
			std::cout << "Enter the new quantity of the product: ";
			std::cin >> updateQty;

			//call update quantity
			Administrador.updateQuantityOfProduct(pNum, updateQty);
		}
	}
}

void userMenu(Customer& User, Admin& Administrador)
{
	//creating a pointer to the product the customer choses
	std::string itemNumber = " ";

	while (true) {

		// Prompts the user to enter the item number
		std::cout << "Please enter the product number, enter 0 to quit, or type \"cart\""
				  << "to see the current items in the cart: ";
		std::cin >> itemNumber;

		if (itemNumber == "cart")
		{
			std::cout << "\nCART CONTENT:" << std::endl;
			User.printReceipt();
		}

		if (itemNumber == "0")
		{
			//Creating a file manager to handle all instances of files in the program
			FileManager Manager;

			std::cin.ignore(); // Flush the buffer

			std::string firstName;
			std::string lastName;
			std::string Address;
			std::string City;
			std::string State;
			std::string Zip;

			// Prompts the user to input the name
			std::cout << "Please enter the customer first name: ";
			std::getline(std::cin, firstName);
			std::cout << "Please enter the customer last name: ";
			std::getline(std::cin, lastName);
			// Prompts the user to input the street address
			std::cout << "Please enter the street address: ";
			std::getline(std::cin, Address);
			// Prompts the user to input the city, state and zipcode 
			std::cout << "Please enter city: ";
			std::getline(std::cin, City);
			std::cout << "Please enter state: ";
			std::getline(std::cin, State);
			std::cout << "Please enter Zip code: ";
			std::getline(std::cin, Zip);

			//updating variables for user
			User.setFirstName(firstName);
			User.setLastName(lastName);
			User.setAddress(Address);
			User.setCity(City);
			User.setState(State);
			User.setZip(Zip);
			
			//create receipt from customer linked list
			Manager.createFile(User);

			//update file from admin linkedlist
			Manager.updateProductFile(Administrador);

			break; // Break the loop
		}

		//checking if the value exists
		if (Administrador.search(itemNumber) == true) {
			//value exists
			//storing quantity of product
			std::string productNumber = Administrador.getNumber(itemNumber);
			std::string productName = Administrador.getName(itemNumber);
			double productCost = Administrador.getCost(itemNumber);
			int prodcutQty = Administrador.getQuantity(itemNumber);

			int customerQty = -1;

			//making sure customerQuantity is a valid input
			while (customerQty < 0 || customerQty > prodcutQty) {

				// Prompts the user to enter the item number
				std::cout << "Please enter quantity : (max of " << prodcutQty << ") : ";
				std::cin >> customerQty;
			}

			//decrease from cart the quantity the user entered and check if we need to delete product
			int isProductEmpty = Administrador.subtractQuantity(itemNumber, customerQty);

			//checking the remaning quantity of product
			if (isProductEmpty == 0) {
				//delete node from product list
				Administrador.deleteNode(itemNumber);
			}

			//checking if the item exists in customers cart
			if (User.search(itemNumber) == true) {
				//updating item in customers cart
				User.updateQuantityOfProduct(itemNumber, customerQty);
			}
			else {
				//adding a new item to customer cart
				//add node to customer list
				//1)Create a struct to add to customer list
				Node* temp = new Node;
				//2)Copy evertything from rightStrcut to this struct
				temp->setNumber(productNumber);
				temp->setName(productName);
				temp->setCost(productCost);
				temp->setQty(customerQty);
				//3)add strcuct to customer linkedlist
				User.insert_back(temp);
			}
		}
	}
}

// Main function 
int main()
{
	//Creating a file manager to handle all instances of files in the program
	FileManager Manager;

	//Create an admin object
	Admin Administrador;

	//create temp variables for each customer
	std::string name, street, cityZip;

	//file name
	std::string fileName = "ProductData.txt";

	//read in file into admin linked list passing linked list by reference
	Manager.fileToLinkedList(fileName, Administrador);

	std::string username = " ", pw = " "; // Admin's username and password

	std::string menuOption = "a";

	while (menuOption != "0") {

		//ask user to enter the option for menu
		std::cout << "***************************************************************";
		std::cout << "\nEnter:"
			"\n1 for administrative services (add, delete and update product)"
			<< "\n2 for to perchase product(s): \n"
			<< "0 to quit.\n";
		std::cout << "***************************************************************" << std::endl;
		std::cin >> menuOption;

		//checking if the user entered 1 or 2
		if (menuOption == "1") {

			// Set username and password
			Administrador.setuserName("admin");
			Administrador.setpassWord("admin");
			// Validate username and password 
			while (Administrador.validateUserNameAndPassword(username, pw) == false)
			{
				std::cout << "Please enter Username and Password " << std::endl;
				std::cout << "Username: ";
				std::cin >> username;
				std::cout << "Password: ";
				std::cin >> pw;
			}

			//call admin menu
			adminMenu(Administrador);
			Manager.updateProductFile(Administrador); 

			// Reset the username and password for the next use
			username = " ";
			pw = " ";
		}

		else if (menuOption == "2") {
			Customer User;  // Customer object
			//calling adminMenu
			userMenu(User, Administrador);
		}
	}

	return 0;
} // End of the main function