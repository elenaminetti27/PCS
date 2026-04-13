#include "timecounter.h"
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include "randfiller.h"
#include "Bubblesort.hpp"
#include "Selectionsort.hpp"
#include "Insertionsort.hpp"
#include <algorithm>

int main() {
	randfiller rf;
	timecounter tc;
	for (int i = 2; i <= 13; i++) {
		int N = (std::pow(2,i));
		std::vector<int> v(N);
		rf.fill(v, -10000,10000);
		std::vector<int> vB = v;
		std::vector<int> vI = v;
		std::vector<int> vS = v;
		std::cout << "test con dimensione: " <<N << "\n";
		tc.tic();
		Bubblesort(vB);
		double timeB = tc.toc();
		tc.tic();
		Selectionsort(vS);
		double timeS = tc.toc();
		tc.tic();
		Insertionsort(vI);
		double timeI=tc.toc();
		tc.tic();
		std::sort(v.begin(), v.end());
		double time = tc.toc();
		std::cout << "Bubblesort ha impiegato: " << timeB << "\n";
		std::cout << "Selectionsort ha impiegato: " << timeS <<"\n";
		std::cout << "Insertionsort ha impiegato: " << timeI << "\n";
		std::cout << "sort ha impiegato: " << time << "\n";
	}
	return EXIT_SUCCESS;
}
		
	
