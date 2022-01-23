#include <iostream>
#include "include/Plansza.hpp"
#include "Przeciwnik.hpp"


class Gra {
	char znak_gracza;
	char znak_przeciwn;
	Przeciwnik* komp;
	Plansza& plansza = Plansza();
	int zwyciestwo = 2;
	char rzad;
	int kolumna;


public:
	Gra(){
	
	}
	~Gra(){
		delete komp;
	}
	Gra(const char znak) {
		ustaw_znak(znak);
	}

	void ustaw_znak(const char znak) {
		znak_gracza = znak;
		if (znak_gracza == 'X')
			znak_przeciwn = 'O';
		else
			znak_przeciwn = 'X';
		komp = new Przeciwnik(znak_przeciwn, plansza);
	};

	Plansza& podaj_plansze() {
		return plansza;
	};

	Przeciwnik* podaj_komputer() {
		return komp;
	};

	int podaj_zwyciestwo() {
		return zwyciestwo;
	};

	void tura() {
		if (plansza.check_win(znak_przeciwn)) {
			std::cout << "\nNiestety, przegrana.\n\n";
			zwyciestwo = 0;
		}
		else {
			std::cout << "Wybierz kolumne (1,2,3)\n";
			std::cin >> kolumna;
			std::cout << "Wybierz rzad (A,B,C)\n";
			std::cin >> rzad;
			plansza.set(znak_gracza, plansza.get_cell(rzad, kolumna));
			plansza.print();
			std::cout << zwyciestwo << "\n";
			zwyciestwo = komp->tura();
		};
	};

};