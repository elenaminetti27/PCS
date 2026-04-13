#include <vector>
#include <iostream>
#include <string>
#include "randfiller.h"
#include "is_sorted.hpp"
#include "Bubblesort.hpp"
#include <cstdlib>
bool test_Bubblesort() {
	randfiller rf;
	int superi=0;
	for (int i =0 ; i <= 32; i++) {
		int N = i*10;
		std::vector<int> v;
		v.resize(N);
		rf.fill(v, - 10000, 10000);
		Bubblesort(v);
		if (is_sorted(v) == true) {
			superi++;
		}
	}
	for (int i =0 ; i <= 33; i++) {
		int N = i*9;
		std::vector<float> v;
		v.resize(N);
		rf.fill(v, - 10000.0f, 10000.0f);
		Bubblesort(v);
		if (is_sorted(v) == true) {
			superi++;
		}
	}
	for (int i =0 ; i <= 32; i++) {
		int N= i*11;
		std::vector<double> v;
		v.resize(N);
		rf.fill(v, - 10000.0, 10000.0);
		Bubblesort(v);
		if (is_sorted(v) == true) {
			superi++;
		}
	}
	if (superi == 100) {
		return true;
	}
	return false;
}
bool test_stringhe() {
	std::vector<std::string> v =  {"comico", "casa", "animale", "ciao", "esame", "quaderno", "computer", "tastiera", "tavolo", "quaderni"};
	Bubblesort(v);
	if (is_sorted(v) == true) {
		return true;
	}
	return false;
}

int main() {
	bool ok_Bubblesort = test_Bubblesort();
	bool ok_stringhe= test_stringhe();
	if (ok_Bubblesort == false|| ok_stringhe==false) {
		std::cout<< "errore\n";
		return EXIT_FAILURE;
	}
	std::cout << "test superati\n";
	return EXIT_SUCCESS;	
}
	
		
	
	
	