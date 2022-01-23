#include <iostream>
#include "include/Gra.hpp"

int main()
{
	Gra* gra;
	char znak;
	bool start;
	std::cout << "\nWitaj w grze w O i X!\n\nWybierz swoj znak (O, X)\n";
	std::cin >> znak;

	gra = new Gra(znak);

	std::cout << "\nCzy chcesz zaczynac? (0 - nie, 1 - tak)\n";
	std::cin >> start;

	if (!start)
		gra->podaj_komputer()->tura();

	while (gra->podaj_zwyciestwo() != 0 && gra->podaj_zwyciestwo() != 1) {
		gra->tura();
	};

};