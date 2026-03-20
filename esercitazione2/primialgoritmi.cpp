#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
static const int N = 8;
double arr[N]= {1,4.7,3,9.5,2,7.1,6,8.3};
double minimo = arr[0];
double massimo =arr[0];
double somma = arr[0];
for (int i=1;i<N;i++)
	minimo= std::min(minimo,arr[i]);
std::cout << "il minimo è: " << minimo << "\n";
for (int j=1;j<N;j++)
	massimo = std::max(massimo,arr[j]);
std::cout << "il massimo è: " << massimo << "\n";
for (int k=1;k<N; k++)
	somma = somma + arr[k];
double media = somma/N;
std::cout << "La media è: " << media << "\n";
double quadrato = pow(arr[0]-media,2);
for ( int i=1; i<N; i++)
	quadrato= quadrato+ pow(arr[i]-media,2);
double var = quadrato/N;
double deviazione = std::sqrt(var);
std::cout << "La deviazione standard è: " << deviazione << "\n";
}