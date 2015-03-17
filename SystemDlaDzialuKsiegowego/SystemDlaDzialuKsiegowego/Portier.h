#ifndef _PORTIER_
#define _PORTIER_

#include <string>

#include "Osoba.h"

class Portier : public Osoba {
public:
	// Constructor
	Portier(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) {
		pozycja = PORTIER;
		initOsobaData(imie, nazwisko, staz, adresZamieszkania);
	}

	// The portier salary is constant
	float getPensja() {
		return 1500.0f;
	};

	// Just return the data in file format, it nicely uses base call method to get the data from base class
	std::string getDataInFileFormat() {
		return "PORTIER;" + getOsobaDataInFileFormat() + "\n";
	}

	// Return data in human format
	std::string getDataInHumanFormat() {
		return "PORTIER " + getOsobaDataInHumanFormat();
	}

};

#endif // _PORTIER_