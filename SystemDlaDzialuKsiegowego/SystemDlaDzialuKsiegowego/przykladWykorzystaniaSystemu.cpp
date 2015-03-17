#include <iostream>

#include "Firma.h"

using namespace std;

int main()
{
	// Let's create an exemplary firma
	Firma firma;

	// Reading the data from file
	firma.readDataFromFile("firma.data");

	// Print all information
	firma.printInformation();

	// Lets compute the sum of all salaries
	std::cout << "The total sum of salaries = " << firma.computeSumOfPensja() << std::endl;

	// Add employee from user
	std::cout << std::endl << "Adding from keyboard" << std::endl;
	firma.addEmployeeFromKeyboard();

	// Remove employee
	std::cout << std::endl << "Removing" << std::endl;
	firma.removeEmployee();

	// Saving the database to file
	firma.saveDataToFile("firmaOut.data");
}