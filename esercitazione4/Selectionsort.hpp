#pragma once
#include <vector>
template<typename T>
void Selectionsort (std::vector<T>& vec) {
	if (vec.size()<=1) {
		return;
	}
	int N = (vec.size());
	for (int i=0; i< N-1; i++) {
		int min = i;
		for (int j=i+1; j < N; j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
		}
		T valore = vec[i];
		vec[i]=vec[min];
		vec[min]=valore;
	}
}