#include <iostream>
#include <vector>
#include "Plansza.hpp"

class Przeciwnik {
	char znak;
	char znak_gracza;
	Plansza& plansza;
	std::vector<int> liczniki_rzedow = { 0,0,0 };
	std::vector<int> liczniki_kolumn = { 0,0,0 };
	int licznik_diag_1 = 0;
	int licznik_diag_2 = 0;

public:
	~Przeciwnik() {
	}
	Przeciwnik(const char symbol, Plansza& siatka) : plansza(siatka) {
		znak = symbol;
		//plansza = siatka;
		if (znak == 'X')
			znak_gracza = 'O';
		else
			znak_gracza = 'X';

	}

	int tura() {
		if (plansza.check_win(znak_gracza)) {
			std::cout << "\nGratulacje, zwyciêstwo!\n\n";
			plansza.print();
			return 1;
		}
		else {
			plansza.set(znak, locate());
			plansza.print();
			return 2;
		};

	};



	char& locate() {
		//ostatni ruch komputera
		for (int i = 0; i < 3; i++) {
			liczniki_rzedow[i] = plansza.count(znak, 0, i);
			liczniki_kolumn[i] = plansza.count(znak, 1, i);
			if (liczniki_rzedow[i] == 2)
			{
				for (char& pole : plansza.rzedy[i]) {
					if (pole == '.')
						return pole;
				};
			}
			else if (liczniki_kolumn[i] == 2)
			{
				for (std::array<char, 3>&rzad : plansza.rzedy) {
					if (rzad[i] == '.')
						return rzad[i];
				};
			};
			/*else if (plansza.count_diag(znak, 1) == 2)
			{
				for (char& pole : plansza.diag) {
					if (pole == '.')
						return pole;
				};
			}
			else if (plansza.count_diag(znak, 0) == 2)
			{
				for (char& pole : plansza.diag) {
					if (pole == '.')
						return pole;
				};
			};*/
		};
		//defensywa
		for (int i = 0; i < 3; i++) {
			liczniki_rzedow[i] = plansza.count(znak_gracza, 0, i);
			liczniki_kolumn[i] = plansza.count(znak_gracza, 1, i);
			if (liczniki_rzedow[i] == 2)
			{
				for (char& pole : plansza.rzedy[i]) {
					if (pole == '.')
						return pole;
				};
			}
			else if (liczniki_kolumn[i] == 2)
			{
				for (std::array<char, 3>&rzad : plansza.rzedy) {
					if (rzad[i] == '.')
						return rzad[i];
				};
			};
		};
		//rozegranie
		if (plansza.rzedy[1][1] == '.')
			return plansza.rzedy[1][1];
		for (std::array<char, 3>& rzad : plansza.rzedy) {
			for (int i = 0; i < 3; i++)
				if (rzad[i] == '.')
					return rzad[i];

		};
	};




};