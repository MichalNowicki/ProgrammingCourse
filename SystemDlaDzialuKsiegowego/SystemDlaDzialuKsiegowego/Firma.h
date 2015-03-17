#ifndef _FIRMA_
#define _FIRMA_

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>

#include "Osoba.h"
#include "Prezes.h"
#include "Portier.h"
#include "Pracownik.h"
#include "Kierownik.h"

class Firma {

private:
	std::vector<Osoba*> listaPracownikow;

	// Methods used to add employees
	void addPrezesToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania);
	void addPortierToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania);
	void addKierownikToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania);
	void addPracownikToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania, std::string kierownikImie, std::string kierownikNazwisko);

public:
	Firma() {};

	// Reading firma information from file
	void readDataFromFile(std::string fileName);

	// Add employee
	void addEmployeeFromKeyboard();

	// Remove employee
	void removeEmployee();

	// Method used to print information about all employees
	void printInformation();

	// Method used to store information of all employees in wanted file
	void saveDataToFile(std::string fileName);

	// Method used to compute the salary of all employees
	float computeSumOfPensja();
};

#endif // _FIRMA_