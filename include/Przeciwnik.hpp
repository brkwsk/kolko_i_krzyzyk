#include <iostream>
#include <vector>
#include "Plansza.hpp"

class Przeciwnik() {
	char znak;
	char znak_gracza;
	Plansza& plansza;
	std::vector<int, 3> liczniki_rzedow = { 0,0,0 };
	std::vector<int, 3> liczniki_kolumn = { 0,0,0 };

public:
	Przeciwnik() {}
	~Przeciwnik() {}
	Przeciwnik(char symbol, Plansza& siatka) {
		znak = symbol;
		plansza = siatka;
		if (znak == 'X')
			znak_gracza = 'O';
		else
			znak_gracza = 'X';

	}

	void turn() {
		char& pole = locate();
		pole = znak;
	};

	char& locate() {
		//char& pozycja_x;
		//std::vector<char>& pozycja_y;
		for (int i; i == 3; i++) {
			liczniki_rzedow[i] = plansza.count(znak_gracza, 0, i);
			liczniki_kolumn[i] = plansza.count(znak_gracza, 1, i);
			if (liczniki_rzedow[i] == 2)
			{
				//pozycja_y = i;
				for (auto pole : plansza.rzedy[i]) {
					(pole == '.') ? return pole;
				};
			}
			else if (liczniki_kolumn[i] == 2)
			{
				for (auto pole : plansza.rzedy) {
					(pole[i] == '.') ? return pole[i];
				};
			};
		};
		for (auto rzad : plansza.rzedy) {
			for (auto pole : rzad)
				(pole == '.') ? return pole;
		};
	};




}