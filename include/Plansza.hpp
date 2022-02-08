#ifndef Plansza_class
#define Plansza_class
#include <iostream>
#include <array>

class Plansza {
	std::array<char,3> A = { '.','.','.' };
	std::array<char,3> B = { '.','.','.' };
	std::array<char,3> C = { '.','.','.' };
	std::array<std::array<char,3>,3> rzedy = { A,B,C };
	int l_tur = 0;
	friend class Przeciwnik;

public:
	Plansza() {}
	~Plansza() {}

	void print() {
		std::cout << "\n    1 2 3\nA: |" << rzedy[0][0] << "|" << rzedy[0][1] << "|" << rzedy[0][2] << "|\n";
		std::cout << "B: |" << rzedy[1][0] << "|" << rzedy[1][1] << "|" << rzedy[1][2] << "|\n";
		std::cout << "C: |" << rzedy[2][0] << "|" << rzedy[2][1] << "|" << rzedy[2][2] << "|\n\n";
	};

	std::array<std::array<char, 3>, 3>& get_board() {
		return rzedy;
	}

	void set(const char znak, char& pole) {
		pole = znak;
	};

	char get(char& pole) {
		return pole;
	};

	int get_turn() {
		return l_tur;
	};

	void count_turn() {
		l_tur++;
	};

	char& get_cell(char rzad, int kolumna) {
		if (rzad == 'A')
			return rzedy[0][kolumna-1];
		else if (rzad == 'B')
			return rzedy[1][kolumna-1];
		else
			return rzedy[2][kolumna-1];
	}

	char& get_cell_nums(int rzad, int kolumna) {
		return rzedy[rzad][kolumna];
	}

	int count(const char znak, const bool pion, const int pozycja) {
		int count = 0;
		if (pion) {
			for (std::array<char, 3>&rzad : rzedy)
				if (rzad[pozycja] == znak) {
					count++;
				};

		}
		else {
			for (char& pole : rzedy[pozycja])
				if(pole == znak)
					count++;
		};
		return count;
	};

	int count_diag(const char znak, const bool naroznik_lewo_gora) {
		int count = 0;
		if (naroznik_lewo_gora) {
			for (int i = 0; i < 3; i++) {
				if (rzedy[i][i] == znak)
					count++;
			};
		}
		else {
			for (int i = 0; i < 3; i++) {
				if (rzedy[i][2-i] == znak)
					count++;
			};
		};
		return count;
	};

	bool check_win(char znak) {
		int licznik_x;
		int licznik_y;
		for (int i = 0; i < 3; i++) {
			licznik_x = count(znak, 0, i);
			licznik_y = count(znak, 1, i);
			if (licznik_x == 3)
			{
				return true;
			}
			else if (licznik_y == 3)
			{
				return true;
			};
		};
		if (count_diag(znak, 1) == 3)
			return true;

		if(count_diag(znak, 0) == 3)
			return true;
		return false;
	};
};

#endif
