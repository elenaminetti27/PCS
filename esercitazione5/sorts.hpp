#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void Merge(vector<T>& vec, int p, int q, int r) {
int n1 = q-p+1;
int n2 = r-q;
vector<T> L(n1+1), R(n2+1);
	for (int i = 0; i < n1; i++) {
		L[i] = vec[p+i]; 
	}
	for (int j = 0; j < n2; j++) {
		R[j] = vec[q+j+1];
		}
		if constexpr(is_same<T, string>::value) {
			L[n1] = (T)"\xff\xff\xff";  //ho preso la stringa più alta
			R[n2] = (T)"\xff\xff\xff";
		} else {
			L[n1] = numeric_limits<T>::max();
			R[n2] = numeric_limits<T>::max();
		}
		int i = 0;
		int j = 0;
		for (int k =p; k <= r; k++) {
			if (L[i] <= R[j]) {
				vec[k] = L[i];
				i = i+1;
			}
			else {
				vec[k] = R[j];
				j = j+1;
			}
		}
}

template<typename T>
void Mergesort(vector<T>& vec, int p, int r) {
	if (p < r) {
		int q = floor((p+r)/2);
		Mergesort(vec,p,q);
		Mergesort(vec,q+1,r);
		Merge(vec,p,q,r);
	}
}


template<typename T>
int Partition(vector<T>& vec, int p, int r) {
	T x = vec[r];
	double i = p -1;
	for (int j=p; j <r; j++) {
		if (vec[j] <= x) {
			i=i+1;
			T valore = vec[j];
			vec[j]=vec[i];
			vec[i] = valore;
		}
	}
	T numero = vec[r];
	vec[r]=vec[i+1];
	vec[i+1] = numero;
	return i+1;
}

template<typename T>
void Quicksort(vector<T>& vec, int p, int r) {
	if (p<r) {
		int q= Partition(vec,p,r);
		Quicksort(vec,p, q-1);
		Quicksort(vec,q+1,r);
	}
}

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

			






