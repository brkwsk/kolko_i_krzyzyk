#include <iostream>
#include "include/Gra.hpp"
#include <algorithm>
#include <vector>

int main()
{
	Gra* gra;
	char znak;
	std::string typ_przeciwnika;
	std::vector<std::string> typy = { "pro", "normalny", "chaotyczny" };
	bool start;
	bool rozgrywka = 1;
	while (rozgrywka) {
		std::cout << "\nWitaj w grze w O i X!\n\nWybierz swoj znak (O, X)\n";
		std::cin >> znak;
		if (islower(znak))
			znak = toupper(znak);
		while (znak != 'X' && znak != 'O') {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Wybierz X lub O\n";
			std::cin >> znak;
			if (islower(znak))
				znak = toupper(znak);
		};

		std::cout << "\nWybierz typ przeciwnika (pro, normalny, chaotyczny)\n";
		std::cin >> typ_przeciwnika;
		while (std::find(typy.begin(),typy.end(), typ_przeciwnika) == typy.end()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Wpisz pro, normalny, albo chaotyczny\n";
			std::cin >> typ_przeciwnika;
		};

		gra = new Gra(znak,typ_przeciwnika);

		std::cout << "\nCzy chcesz wykonac pierwszy ruch? (0 - nie, 1 - tak)\n";
		//std::cin >> start;
		while (!(std::cin >> start)) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Wpisz 0 lub 1\n";
		};
		while (start != 1 && start != 0) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Wpisz 0 lub 1\n";
			std::cin >> start;
		};

		gra->podaj_plansze().print();
		if (!start) {
			gra->podaj_komputer()->tura();
			gra->podaj_plansze().count_turn();
		};

		while (gra->podaj_zwyciestwo() != 0 && gra->podaj_zwyciestwo() != 1 && gra->podaj_plansze().get_turn() < 9) {
			gra->tura();
		};

		std::cout << "\nWpisz 1, aby zagrac ponownie lub 0, aby zakonczyc\n";
		while (!(std::cin >> rozgrywka)) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Wpisz 0 lub 1\n";
		};
	};
};