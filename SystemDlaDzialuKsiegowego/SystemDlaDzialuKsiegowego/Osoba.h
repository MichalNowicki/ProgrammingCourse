#ifndef _OSOBA_
#define _OSOBA_

#include <string>
#include <iostream>

class Osoba {

public:
	struct AdresZamieszkania {
		std::string ulica, nrDomu, nrMieszkania, kodPocztowy, miejscowosc;
	};

	enum POZYCJA {
		PREZES, KIEROWNIK, PRACOWNIK, PORTIER
	};

protected:
	std::string imie, nazwisko;
	int staz;
	AdresZamieszkania adresZamieszkania;
	POZYCJA pozycja;

	// Initializes osoba fields with provided data
	void initOsobaData(std::string _imie, std::string _nazwisko, int _staz, AdresZamieszkania _adresZamieszkania);

	// Return the stored data in proposed file format
	std::string getOsobaDataInFileFormat();

	// Return the stored data in human readable format
	std::string getOsobaDataInHumanFormat();

public:

	// Several methods to access commonly needed fields
	std::string getImie();
	std::string getNazwisko();
	POZYCJA getPozycja();

	// To avoid nasty dynamic_cast, it is possible to create a method available for all, but working only in wanted case
	virtual bool increaseSuperivsedWorkers();
	virtual bool decreaseSuperivsedWorkers();

	// Just preparing for implementation in which everyone has a kierownik
	virtual std::string getSupervisorImie();
	virtual std::string getSupervisorNazwisko();

	// Abstract methods that have to be overloaded
	// - getting the salary
	// - gettint the data in file format
	virtual float getPensja() = 0;
	virtual std::string getDataInFileFormat() = 0;
	virtual std::string getDataInHumanFormat() = 0;
};

#endif // _OSOBA_
