#include <iostream>
#include <vector>

class Plansza() {
	std::vector<char,3> A = {.,.,.};
	std::vector<char,3> B = {.,.,.};
	std::vector<char,3> C = {.,.,.};
	std::vector<std::vector<char>&,3> rzedy = {A,B,C};

public:
	Plansza() {};
	~Plansza() {};

	void print() {
		std::cout << "    1 2 3\nA: |" << rzedy[0][0] << "|" << rzedy[0][1] << "|" << rzedy[0][2] << "|\n";
		std::cout << "B: |" << rzedy[1][0] << "|" << rzedy[1][1] << "|" << rzedy[1][2] << "|\n";
		std::cout << "C: |" << rzedy[2][0] << "|" << rzedy[2][1] << "|" << rzedy[2][2] << "|\n";
	};
	
	void set(char znak, int x, int y) {
		rzedy[y][x] = znak;
	};

	char get(int x, int y) {
		return rzedy[y][x];
	};
}
