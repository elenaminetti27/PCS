#include <iostream>
#include <concepts>
#include "rational.hpp"

int main(void)
{
	rational<int> a(-2,4);
	rational<int> b(3,5);
	rational<int> c(4,9);
	rational<int> e(0,0);
	rational<int> f(6,0);
	rational<int> m(0,7);
	rational<int> n(9,0);
	rational<int> d= a+b+c; 
	rational<int> g=a-c; 
	rational<int> h=d*a; 
	rational<int> i=a/b;
	rational<int> j=a/e;
	rational<int> k= b*f; 
	rational<int> l=e+f;
	std::cout << a.num() << "\n"; //-1
	std::cout << a.den() << "\n"; //2
	std::cout << d << "\n"; //49/90
	std::cout << g << "\n"; //-17/18
	std::cout << h << "\n"; //-49/180
	std::cout << i << "\n"; //-5/6
	std::cout << j << "\n"; // NaN
	std::cout << k << "\n"; //inf
	std::cout << a.operator+(e) << "\n"; //NaN
	std::cout << b.operator*(f) << "\n"; //inf
	std::cout << (a += b) << "\n"; //a è diventato 1/10
	std::cout << (c *= e) << "\n"; // c è diventato NaN
	std::cout << (b -= a) << "\n"; // b è diventato 1/2
	std::cout << (d /= f) << "\n"; //d è diventato 0
	std::cout << l << "\n"; // NaN
	std::cout << (m*f) << "\n"; //NaN=0*inf
	std::cout << (n-f) << "\n"; // inf-inf=NaN
	
	return 0;
};