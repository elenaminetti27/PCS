#pragma once
#include <vector>

template<typename T>
void Bubblesort(std::vector<T>& vec) {
	if (vec.size() <= 1) {
		return;
	}
	bool scambio = true;
	int N= (vec.size());
	while (scambio == true) {
		scambio = false;
		for (int i = 0; i< N-1; i++) {
			if (vec[i] > vec[i+1]) {
				T valore =vec[i+1];
				vec[i+1] = vec[i];
				vec[i]=valore;
				scambio = true;
			}
		}
	}
}

	
	

	