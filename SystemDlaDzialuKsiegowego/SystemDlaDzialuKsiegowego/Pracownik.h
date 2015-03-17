#ifndef _PRACOWNIK_
#define _PRACOWNIK_

#include <string>

#include "Osoba.h"

class Pracownik : public Osoba
{
protected:
	std::string kierownikImie, kierownikNazwisko;

public:
	// Constructor of pracownik -> uses intialization from Osoba and additional kierownik information
	Pracownik(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania, std::string _kierownikImie, std::string _kierownikNazwisko) {
		pozycja = PRACOWNIK;
		kierownikImie = _kierownikImie;
		kierownikNazwisko = _kierownikNazwisko;
		initOsobaData(imie, nazwisko, staz, adresZamieszkania);
	}

	// Returns salary based on equation in task
	float getPensja() {

		float dodatek = 0.0f;
		if (adresZamieszkania.miejscowosc != "Poznan")
			dodatek = 100;

		return 2000 + 75 * staz + dodatek;
	}

	// Just return the data in file format, it nicely uses base call method to get the data from base class
	std::string getDataInFileFormat() {
		return "PRACOWNIK;" + getOsobaDataInFileFormat() + kierownikImie + ";" + kierownikNazwisko + ";\n";
	}

	// Return data in human format
	std::string getDataInHumanFormat() {
		return "PRACOWNIK " + getOsobaDataInHumanFormat() + "\tKierownik: " + kierownikImie + " " + kierownikNazwisko;
	}

	// Return kierownik imie i nazwisko
	std::string getSupervisorImie() {
		return kierownikImie;
	}

	std::string getSupervisorNazwisko() {
		return kierownikNazwisko;
	}

};

#endif // _PRACOWNIK