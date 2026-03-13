#include <iostream>
#include <fstream>
#include <string>

int main(void)
{std::cout << "Nome del file:\n";
std::string name;
std::cin >> name;
	std::ifstream ifs(name);
	if (ifs.is_open()) {
		std::string location;
		while (ifs >> location) {
			double temp;
			double somma = 0;
			for (int i= 0; i < 4; i++){
				ifs >> temp;
				somma = somma + temp;
				}
				double media =somma / 4;
		std::cout << "La temperatura media a " << location << " è " << media << "\n"; 
	}
}
	else std::cout << "Il file non è stato aperto correttamente \n";	
}