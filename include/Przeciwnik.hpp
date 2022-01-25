#include <iostream>
#include <vector>
#include "Plansza.hpp"

class Przeciwnik {
	char znak;
	char znak_gracza;
	Plansza& plansza;
	std::vector<int> liczniki_rzedow = { 0,0,0 };
	std::vector<int> liczniki_kolumn = { 0,0,0 };
	std::vector<int> liczniki_rzedow_gracz = { 0,0,0 };
	std::vector<int> liczniki_kolumn_gracz = { 0,0,0 };
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
		std::cout << "Tura przeciwnika \n";
		if (plansza.check_win(znak_gracza)) {
			std::cout << "\nGratulacje, zwyciestwo!\n\n";
			plansza.print();
			return 1;
		}
		else {
			plansza.set(znak, locate());
			plansza.print();
			return 2;
		};

	};


	//algorytm wyboru pola
	char& locate() {
		//stawianie 3 znaku
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
		};
		if (plansza.count_diag(znak, 1) == 2)
		{
			for (int i = 0; i < 3; i++) {
				if (plansza.get_cell_nums(i, i) == '.')
					return plansza.get_cell_nums(i, i);
			};
		}
		else if (plansza.count_diag(znak, 0) == 2)
		{
			for (int i = 0; i < 3; i++) {
				if (plansza.get_cell_nums(i, 2 - i) == '.')
					return plansza.get_cell_nums(i, 2 - i);
			};
		};
		//blokowanie 3 znaku
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
		if (plansza.count_diag(znak_gracza, 1) == 2)
		{
			for (int i = 0; i < 3; i++) {
				if (plansza.get_cell_nums(i, i) == '.')
					return plansza.get_cell_nums(i, i);
			};
		}
		else if (plansza.count_diag(znak_gracza, 0) == 2)
		{
			for (int i = 0; i < 3; i++) {
				if (plansza.get_cell_nums(i, 2 - i) == '.')
					return plansza.get_cell_nums(i, 2 - i);
			};
		};
		//stawianie 2 znaku, z priorytetem na srodku i w naroznikach
		if (plansza.count_diag(znak, 1) == 1 && plansza.count_diag(znak_gracza, 1) == 0)
		{
			if (plansza.get_cell_nums(1, 1) == '.')
				return plansza.get_cell_nums(1, 1);
			for (int i = 0; i < 3; i+=2) {
				if (plansza.get_cell_nums(i, i) == '.')
					return plansza.get_cell_nums(i, i);
			};
		}
		else if (plansza.count_diag(znak, 0) == 1 && plansza.count_diag(znak_gracza, 0) == 0)
		{
			if (plansza.get_cell_nums(1, 1) == '.')
				return plansza.get_cell_nums(1, 1);
			for (int i = 0; i < 3; i+=2) {
				if (plansza.get_cell_nums(i, 2 - i) == '.')
					return plansza.get_cell_nums(i, 2 - i);
			};
		};

		for (int i = 0; i < 3; i++) {
			liczniki_rzedow[i] = plansza.count(znak, 0, i);
			liczniki_kolumn[i] = plansza.count(znak, 1, i);
			liczniki_rzedow_gracz[i] = plansza.count(znak_gracza, 0, i);
			liczniki_kolumn_gracz[i] = plansza.count(znak_gracza, 1, i);
			if (liczniki_rzedow[i] == 1 && liczniki_rzedow_gracz[i] == 0)
			{
				if (plansza.rzedy[i][0] == '.')
					return plansza.rzedy[i][0];
				else if (plansza.rzedy[i][2] == '.')
					return plansza.rzedy[i][2];
				else
					return plansza.rzedy[i][0];
			}
			else if (liczniki_kolumn[i] == 1 && liczniki_kolumn_gracz[i] == 0)
			{
				for (std::array<char, 3>&rzad : plansza.rzedy) {
					if (rzad[0] == '.')
						return rzad[0];
					else if (rzad[2] == '.')
						return rzad[2];
					else
						return rzad[1];
				};
			};
		};
			

		//srodkowe pole
		if (plansza.rzedy[1][1] == '.')
			return plansza.rzedy[1][1];
		//dowolne puste pole
		for (std::array<char, 3>& rzad : plansza.rzedy) {
			for (int i = 0; i < 3; i++)
				if (rzad[i] == '.')
					return rzad[i];

		};

	};

};