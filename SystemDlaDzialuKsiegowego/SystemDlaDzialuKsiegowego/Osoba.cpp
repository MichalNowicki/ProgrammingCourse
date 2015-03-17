#include "Osoba.h"

// Protected:
void Osoba::initOsobaData(std::string _imie, std::string _nazwisko, int _staz, AdresZamieszkania _adresZamieszkania) {
	imie = _imie;
	nazwisko = _nazwisko;
	staz = _staz;
	adresZamieszkania = _adresZamieszkania;
}

std::string Osoba::getOsobaDataInFileFormat() {
	return imie + ";" + nazwisko + ";" + std::to_string(staz) + ";" +
		adresZamieszkania.ulica + ";" + adresZamieszkania.nrDomu + ";" +
		adresZamieszkania.nrMieszkania + ";" + adresZamieszkania.kodPocztowy +
		";" + adresZamieszkania.miejscowosc + ";";
}

std::string Osoba::getOsobaDataInHumanFormat() {
	return "Imie:" + imie + " Nazwisko:" + nazwisko + " Staz:" + std::to_string(staz) + " Ulica:" +
		adresZamieszkania.ulica + " NrDomu:" + adresZamieszkania.nrDomu + " NrMieszkania:" +
		adresZamieszkania.nrMieszkania + " KodPocztowy:" + adresZamieszkania.kodPocztowy +
		" Miejscowosc:" + adresZamieszkania.miejscowosc;
}


// Public:
std::string Osoba::getImie() {
	return imie;
}
std::string Osoba::getNazwisko() {
	return nazwisko;
}
Osoba::POZYCJA Osoba::getPozycja() {
	return pozycja;
}

bool Osoba::increaseSuperivsedWorkers() {
	std::cout << "The person is not a supervisor! The file contains error!" << std::endl;
	return false;
}

bool Osoba::decreaseSuperivsedWorkers() {
	std::cout << "The person is not a supervisor! The file contains error!" << std::endl;
	return false;
}

std::string Osoba::getSupervisorImie() {
	return "";
}
std::string Osoba::getSupervisorNazwisko() {
	return "";
}