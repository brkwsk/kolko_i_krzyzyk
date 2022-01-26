#include <iostream>
#include "include/Plansza.hpp"
#include "Przeciwnik.hpp"
#include <vector>


class Gra {
	char znak_gracza;
	char znak_przeciwn;
	Przeciwnik* komp;
	Plansza& plansza = Plansza();
	int zwyciestwo = 2;
	char rzad;
	int kolumna;
	std::vector<int> kolumny = { 1,2,3 };
	std::vector<char> wiersze = { 'A','B','C' };


public:
	Gra() {

	}
	~Gra() {
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
		else if (plansza.get_turn() < 9) {
			std::cout << "Wybierz kolumne (1,2,3): ";
			std::cin >> kolumna;
			while (std::find(kolumny.begin(), kolumny.end(), kolumna) == kolumny.end()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Wybierz poprawna kolumne (1,2,3): ";
				std::cin >> kolumna;
			};
			std::cout << "Wybierz rzad (A,B,C): ";
			std::cin >> rzad;
			if(islower(rzad))
				rzad = toupper(rzad);
			while (std::find(wiersze.begin(), wiersze.end(), rzad) == wiersze.end()) {
				std::cout << "Wybierz poprawny rzad (A,B,C): ";
				std::cin >> rzad;
				if(islower(rzad))
					rzad = toupper(rzad);
			};
			while (plansza.get_cell(rzad, kolumna) != '.') {
				std::cout << "\nPole zajete, wybierz wolne pole\n";
				std::cout << "Wybierz kolumne (1,2,3): ";
				std::cin >> kolumna;
				while (std::find(kolumny.begin(), kolumny.end(), kolumna) == kolumny.end()) {
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Wybierz poprawna kolumne (1,2,3): ";
					std::cin >> kolumna;
				};
				std::cout << "Wybierz rzad (A,B,C): ";
				std::cin >> rzad;
				if (islower(rzad))
					rzad = toupper(rzad);
				while (std::find(wiersze.begin(), wiersze.end(), rzad) == wiersze.end()) {
					std::cout << "Wybierz poprawny rzad (A,B,C): ";
					std::cin >> rzad;
					if (islower(rzad))
						rzad = toupper(rzad);
				};
			};
			plansza.set(znak_gracza, plansza.get_cell(rzad, kolumna));
			plansza.print();
			plansza.count_turn();
			if (plansza.get_turn() < 9) {
				zwyciestwo = komp->tura();
				plansza.count_turn();
			}
			else
				std::cout << "Remis, dobra rozgrywka!\n";
		}
		else
			std::cout << "Remis, dobra rozgrywka!\n";
	};

};