#include <vector>
#include <algorithm>

template<typename T>
void InsertionSort(std::vector<T>& vec, int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T valore = vec[i];
        int k = i - 1;
        while (k >= p && vec[k] > valore) {
            vec[k + 1] = vec[k];
            k = k - 1;
        }
        vec[k + 1] = valore;
    }
}

template<typename T>
int Partition_new(std::vector<T>& vec, int p, int r) {
    T x = vec[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (vec[j] <= x) {
            i = i + 1;
            T valore = vec[j];
			vec[j]=vec[i];
			vec[i] = valore;;
        }
    }
    T numero = vec[r];
	vec[r]=vec[i+1];
	vec[i+1] = numero;
    return i + 1;
}
template<typename T>
void Quicksort_new(std::vector<T>& v, int p, int r) {
    if (p < r) {
        if (r - p < 21) {
            InsertionSort(v, p, r);
        } else {
            int q = Partition(v, p, r);
            Quicksort(v, p, q - 1);
            Quicksort(v, q + 1, r);
        }
    }
}
