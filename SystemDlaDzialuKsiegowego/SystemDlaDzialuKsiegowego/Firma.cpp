#include "Firma.h"


void Firma::addPrezesToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) {
	Prezes * prezes = new Prezes(imie, nazwisko, staz, adresZamieszkania);
	listaPracownikow.push_back(prezes);
}

void Firma::addPortierToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) {
	Portier * portier = new Portier(imie, nazwisko, staz, adresZamieszkania);
	listaPracownikow.push_back(portier);
}

void Firma::addKierownikToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) {
	Kierownik * kierownik = new Kierownik(imie, nazwisko, staz, adresZamieszkania);
	listaPracownikow.push_back(kierownik);
}

void Firma::addPracownikToList(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania, std::string kierownikImie, std::string kierownikNazwisko) {
	// Checking if kierownik exists
	bool kierownikExists = false;
	for (std::vector<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
		if ((*it)->getImie() == kierownikImie && (*it)->getNazwisko() == kierownikNazwisko)
			kierownikExists = (*it)->increaseSuperivsedWorkers();
	}

	if (kierownikExists)
	{
		Pracownik * pracownik = new Pracownik(imie, nazwisko, staz, adresZamieszkania, kierownikImie, kierownikNazwisko);
		listaPracownikow.push_back(pracownik);
	}
	else
		std::cout << "Kierownik with wanted name does not exist! Add kierownik first" << std::endl;
}


void Firma::readDataFromFile(std::string fileName) {
	std::ifstream file(fileName);

	if (file.is_open()) {

		while (!file.eof()){
			std::string pozycja;
			getline(file, pozycja, ';');

			// Remove additional newline character
			pozycja.erase(std::remove(pozycja.begin(), pozycja.end(), '\n'), pozycja.end());

			// Stop if there is no new information
			if (pozycja.size() < 1)
				break;

			// Read data to temporal variables
			std::string imie, nazwisko, stazString;
			Osoba::AdresZamieszkania adres;

			getline(file, imie, ';');
			getline(file, nazwisko, ';');
			getline(file, stazString, ';');
			int staz = atoi(stazString.c_str());

			getline(file, adres.ulica, ';');
			getline(file, adres.nrDomu, ';');
			getline(file, adres.nrMieszkania, ';');
			getline(file, adres.kodPocztowy, ';');
			getline(file, adres.miejscowosc, ';');


			// Create appioprate classes
			if (pozycja == "PREZES") {
				addPrezesToList(imie, nazwisko, staz, adres);
			}
			else if (pozycja == "PORTIER") {
				addPortierToList(imie, nazwisko, staz, adres);
			}
			else if (pozycja == "KIEROWNIK") {
				addKierownikToList(imie, nazwisko, staz, adres);
			}
			else if (pozycja == "PRACOWNIK") {
				std::string kierownikImie, kierownikNazwisko;
				getline(file, kierownikImie, ';');
				getline(file, kierownikNazwisko, ';');

				addPracownikToList(imie, nazwisko, staz, adres, kierownikImie, kierownikNazwisko);
			}
		}
	}
	else
		std::cout << "Could not open the file: " << fileName << std::endl << "Pleace recheck the path of the file" << std::endl;

}

void Firma::addEmployeeFromKeyboard() {
	// Read data to temporal variables
	std::string imie, nazwisko;
	int staz;
	Osoba::AdresZamieszkania adres;

	std::cout << "Imie" << std::endl;
	getline(std::cin, imie);
	std::cout << "Nazwisko" << std::endl;
	getline(std::cin, nazwisko);
	std::cout << "Staz" << std::endl;
	std::cin >> staz;
	std::cin.ignore();

	std::cout << "Ulica" << std::endl;
	getline(std::cin, adres.ulica);
	std::cout << "Numer domu" << std::endl;
	getline(std::cin, adres.nrDomu);
	std::cout << "Numer mieszkania" << std::endl;
	getline(std::cin, adres.nrMieszkania);
	std::cout << "Kod pocztowy" << std::endl;
	getline(std::cin, adres.kodPocztowy);
	std::cout << "Miejscowosc" << std::endl;
	getline(std::cin, adres.miejscowosc);

	int pozycja = -1;
	while (pozycja < 0 || pozycja > 3)
	{
		std::cout << "Pozycja: 0 - PREZES, 1 - PORTIER, 2 - KIEROWNIK, 3 - PRACOWNIK" << std::endl;
		std::cin >> pozycja;
	}

	// Create appioprate classes
	if (pozycja == 0)
		addPrezesToList(imie, nazwisko, staz, adres);
	else if (pozycja == 1)
		addPortierToList(imie, nazwisko, staz, adres);
	else if (pozycja == 2)
		addKierownikToList(imie, nazwisko, staz, adres);
	else if (pozycja == 3)
	{
		std::string kierownikImie, kierownikNazwisko;
		std::cout << "Imie kierownika" << std::endl;
		getline(std::cin, kierownikImie);
		std::cout << "Nazwisko kierownika" << std::endl;
		getline(std::cin, kierownikNazwisko);

		addPracownikToList(imie, nazwisko, staz, adres, kierownikImie, kierownikNazwisko);
	}
}

void Firma::removeEmployee() {
	int id = -1;
	while (id < 0 || id > listaPracownikow.size())
	{
		std::cout << "Which employee to remove (ids start from 0 to " << listaPracownikow.size() << ")" << std::endl;
		std::cin >> id;
	}

	// When we remove employee - we need to decrease the counter of kierownik
	if (listaPracownikow[id]->getPozycja() == Osoba::PRACOWNIK) {

		for (int i = 0; i < listaPracownikow.size(); i++) {
			if (listaPracownikow[i]->getPozycja() == Osoba::KIEROWNIK
				&& listaPracownikow[i]->getImie() == listaPracownikow[id]->getSupervisorImie()
				&& listaPracownikow[i]->getNazwisko() == listaPracownikow[id]->getSupervisorNazwisko())
			{
				listaPracownikow[i]->decreaseSuperivsedWorkers();
			}
		}
	}

	// When we remove kierownik - we need to remove all its employees
	if (listaPracownikow[id]->getPozycja() == Osoba::KIEROWNIK) {

		std::vector<int> idsToRemove;
		idsToRemove.push_back(id);

		for (int i = 0; i < listaPracownikow.size(); i++) {
			if (listaPracownikow[i]->getPozycja() == Osoba::PRACOWNIK
				&& listaPracownikow[id]->getImie() == listaPracownikow[i]->getSupervisorImie()
				&& listaPracownikow[id]->getNazwisko() == listaPracownikow[i]->getSupervisorNazwisko())
			{
				idsToRemove.push_back(i);
			}
		}

		std::sort(idsToRemove.begin(), idsToRemove.end(), std::greater<int>());
		for (int i = 0; i < idsToRemove.size(); i++) {
			delete listaPracownikow[idsToRemove[i]];
			listaPracownikow.erase(listaPracownikow.begin() + idsToRemove[i]);
		}
	}
	else
	{
		delete listaPracownikow[id];
		listaPracownikow.erase(listaPracownikow.begin() + id);
	}

}

void Firma::printInformation() {

	for (std::vector<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
		std::cout << (*it)->getDataInHumanFormat() << std::endl << std::endl;
	}

}


void Firma::saveDataToFile(std::string fileName) {
	std::ofstream saveFile(fileName);

	// Saving kierownik first
	for (std::vector<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
		if ((*it)->getPozycja() == Osoba::KIEROWNIK)
			saveFile << (*it)->getDataInFileFormat();
	}

	// Then save the rest
	for (std::vector<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
		if ((*it)->getPozycja() != Osoba::KIEROWNIK)
			saveFile << (*it)->getDataInFileFormat();
	}

	saveFile.close();
}

float Firma::computeSumOfPensja() {
	float sum = 0;
	for (std::vector<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
		std::cout << (*it)->getImie() << " " << (*it)->getNazwisko() << " " << (*it)->getPensja() << std::endl;
		sum += (*it)->getPensja();
	}
	return sum;
}