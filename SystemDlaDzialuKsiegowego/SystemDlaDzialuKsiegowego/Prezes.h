#ifndef _PREZES_
#define _PREZES_

#include <string>

#include "Osoba.h"

class Prezes : public Osoba
{
public:
	// Constructor
	Prezes(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) {
		pozycja = PREZES;
		initOsobaData(imie, nazwisko, staz, adresZamieszkania);
	}

	// Prezes salary is constant
	float getPensja() {
		return 20000;
	};

	// Just return the data in file format, it nicely uses base call method to get the data from base class
	std::string getDataInFileFormat() {
		return "PREZES;" + getOsobaDataInFileFormat() + "\n";
	}

	// Return data in human format
	std::string getDataInHumanFormat() {
		return "PREZES " + getOsobaDataInHumanFormat();
	}
};

#endif // _PREZES