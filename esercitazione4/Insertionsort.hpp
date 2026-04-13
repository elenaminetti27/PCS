#pragma once
#include <vector>

template<typename T>
void Insertionsort(std::vector<T>& vec) {
	if (vec.size() <= 1) {
		return;
	}
	int N = (vec.size());
	for (int i=1; i < N; i++) {
		T valore = vec[i];
		int k = i -1;
		while (k >= 0 && vec[k] > valore) {
			vec[k+1] = vec[k];
			k = k -1;
		}
		vec[k+1]=valore;
	}
}
