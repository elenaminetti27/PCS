#include <iostream>

int main() {
static const int N = 8;
double arr[N]= {1,4.7,3,9.5,2,7.1,6,8.3};
bool scambio = true;
while (scambio == true) {
	scambio = false;
	for(int i = 0; i < N-1; i++){	
		if (arr[i]<arr[i+1]) {
		}
		else {
			double valore = arr[i+1];
			arr[i+1]=arr[i];
			arr[i]=valore;
			scambio=true;}
	}
}
for (int k=0; k<N; k++) {
	std::cout << arr[k] << "\n";
}
	
}

	
	

	