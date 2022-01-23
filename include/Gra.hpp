#include <iostream>
#include "Plansza.hpp"
#include "Przeciwnik.hpp"


class Gra() {
	char znak_gracza;
	char znak_przeciwn;
	Przeciwnik& komp;


public:
	Gra(){}
	~Gra(){}
	Gra(const char znak) {
		ustaw_znak(znak);
	}

	void ustaw_znak(const char znak) {
		znak_gracza = znak;
		if (znak_gracza == 'X')
			znak_przeciwn = 'O';
		else
			znak_przeciwn = 'X';
	};
};