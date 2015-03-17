#ifndef _KIEROWNIK_
#define _KIEROWNIK_

#include <string>

#include "Osoba.h"

class Kierownik : public Osoba
{
protected:
	int superivedWorkersCount;

public:
	// Constructor using shared method in Osoba
	Kierownik(std::string imie, std::string nazwisko, int staz, Osoba::AdresZamieszkania adresZamieszkania) : superivedWorkersCount(0) {
		pozycja = KIEROWNIK;
		initOsobaData(imie, nazwisko, staz, adresZamieszkania);
	}

	// Salary computed as in provided task
	float getPensja() {
		return (float) (5000 + 100 * staz + 50 * superivedWorkersCount);
	};
	
	// If we add the new worker that kierownik supervises - the counter is increased
	bool increaseSuperivsedWorkers() {
		superivedWorkersCount++;
		return true;
	}

	// If we remove the worker that kierownik supervises - the counter is decreased
	bool decreaseSuperivsedWorkers() {
		superivedWorkersCount--;
		return true;
	}

	// Just return the data in file format, it nicely uses base call method to get the data from base class
	std::string getDataInFileFormat() {
		return "KIEROWNIK;" + getOsobaDataInFileFormat() + "\n";
	}

	// Return data in human format
	std::string getDataInHumanFormat() {
		return "KIEROWNIK " + getOsobaDataInHumanFormat() + " LiczbaPodwladnych:" + std::to_string(superivedWorkersCount);
	}

};

#endif // _KIEROWNIK