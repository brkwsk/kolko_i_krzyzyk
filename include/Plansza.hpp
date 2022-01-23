#ifndef Plansza_class
#define Plansza_class
#include <iostream>
#include <array>

class Plansza {
	std::array<char,3> A = { '.','.','.' };
	std::array<char,3> B = { '.','.','.' };
	std::array<char,3> C = { '.','.','.' };
	//std::array<char, 3> diag1 = { A[0],B[1],C[2]};
	//std::array<char, 3> diag2 = { A[2],B[1],C[0] };
	std::array<std::array<char,3>,3> rzedy = { A,B,C };
	//std::array<char, 3> diag = {'.','.','.'};
	friend class Przeciwnik;

public:
	Plansza() {}
	~Plansza() {}

	void print() {
		std::cout << "    1 2 3\nA: |" << rzedy[0][0] << "|" << rzedy[0][1] << "|" << rzedy[0][2] << "|\n";
		std::cout << "B: |" << rzedy[1][0] << "|" << rzedy[1][1] << "|" << rzedy[1][2] << "|\n";
		std::cout << "C: |" << rzedy[2][0] << "|" << rzedy[2][1] << "|" << rzedy[2][2] << "|\n";
	};

	void set(const char znak, char& pole) {
		pole = znak;
	};

	char get(char& pole) {
		return pole;
	};

	char& get_cell(char rzad, int kolumna) {
		if (rzad == 'A')
			return rzedy[0][kolumna-1];
		else if (rzad == 'B')
			return rzedy[1][kolumna-1];
		else
			return rzedy[2][kolumna-1];
	}

	int count(const char znak, const bool pion, const int pozycja) {
		int count = 0;
		if (pion) {
			for (std::array<char,3>& rzad : rzedy)
				if(rzad[pozycja] == znak)
					count++;
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
			if (A[0] == znak)
				count++;
			if (B[1] == znak)
				count++;
			if (C[2] == znak)
				count++;
		}
		else {
			if (A[2] == znak)
				count++;
			if (B[1] == znak)
				count++;
			if (C[0] == znak)
				count++;
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
