#include "timecounter.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "randfiller.h"
#include "sorts.hpp"
#include "Quicksort_migliorato.hpp"

int main() {
    randfiller rf;
    timecounter tc;
    int prove = 100; 
    for (int i = 1; i <= 12; i++) {
        int N = 8*i;
        std::vector<std::vector<int>> dati(prove, std::vector<int>(N));
        for (int j = 0; j < prove; ++j) {
            rf.fill(dati[j], -10000, 10000);
        }

        std::cout << "\n>>> TEST DIMENSIONE N = " << N << " <<<\n";

        std::vector<std::vector<int>> vB = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            Bubblesort(vB[j]);
        }
        std::cout << "Bubblesort medio:    " << tc.toc() / prove << " s\n";
        std::vector<std::vector<int>> vS = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            Selectionsort(vS[j]);
        }
        std::cout << "Selectionsort medio: " << tc.toc() / prove << " s\n";
        std::vector<std::vector<int>> vI = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            Insertionsort(vI[j]);
        }
        std::cout << "Insertionsort medio: " << tc.toc() / prove << " s\n";
        std::vector<std::vector<int>> vM = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            Mergesort(vM[j], 0, N - 1);
        }
        std::cout << "Mergesort medio:     " << tc.toc() / prove << " s\n";
        std::vector<std::vector<int>> vQ = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            Quicksort(vQ[j], 0, N - 1);
        }
        std::cout << "Quicksort medio:     " << tc.toc() / prove << " s\n";
        std::vector<std::vector<int>> vSo = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            std::sort(vSo[j].begin(), vSo[j].end());
        }
        std::cout << "Sort medio:     " << tc.toc() / prove << " s\n";
		std::vector<std::vector<int>> vQM = dati; 
        tc.tic();
        for (int j = 0; j < prove; ++j) {
            std::sort(vQM[j].begin(), vQM[j].end());
        }
        std::cout << "QMigliorato medio:     " << tc.toc() / prove << " s\n";
    }

    return 0;
}