#include <iostream>
#pragma once
template<typename I> requires std::integral<I>
class rational
{	I num_;
	I den_;
	bool inf;
	bool NaN;
public:
	rational()
		: num_(0),den_(1), inf(false), NaN(false)
	{}
	rational(const I& n, const I& d):
		num_(n), den_(d),inf(false), NaN(false)
	{	if (d==0){
			if(n!=0) inf=true;
			else NaN=true;
		} else {riduzione();}
	}
private:
	I mcd(I a, I b) const {
		if (a < 0) {
			a= -a;
		}
		if (b < 0) {
			b= -b;
		}
		while (b != 0) {
			I r = a % b;
			a=b;
			b=r;
		}
		return a;
	}
	void riduzione() {
		if (NaN == true || inf == true)
			return;
		if (num_ == 0)  {
			den_=1;
			return;
		}
		I risultato = mcd(num_, den_);
		num_ /= risultato;
		den_ /= risultato;
		if (den_<0) {
			num_ = -num_;
			den_= -den_;
		}
	}
public:
	I num() const {
		return num_;
		}
	I den() const {
		return den_;
		}
	bool is_inf() const {
		return inf;
		}
	bool is_NaN() const {
		return NaN;
		}
	
	rational& operator+=(const rational& other){
		if (NaN==true || other.NaN == true) {
			NaN = true;
			return *this;
		}
		if (inf == true && other.inf == true) {
			if ((num_>0 && other.num_<0) || (num_ < 0 && other.num_ >0)) {
				NaN= true;
				inf = false;
				return *this;
			}
			return *this;
		}
		if (inf==true || other.inf == true) {
			inf = true;
			return *this;
		}
		num_= num_*other.den_ + other.num_*den_;
		den_ = den_*other.den_;
		riduzione();
		return *this;
	}
	rational operator+ (const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	rational& operator-= (const rational& other){
		if (NaN==true || other.NaN == true) {
			NaN = true;
			return *this;
		}
		if (inf == true && other.inf == true) {
			if ((num_<0 && other.num_ < 0) || (num_>0 && other.num_>0)) {
				NaN = true;
				inf = false;
				return *this;
			}
		}
		else if (inf== true) {
			inf = true;
			return *this;
		}
		else if (other.inf == true) {
			inf=true;
			return *this;
		}
		else if (inf == true) {
			return *this;
		}
		num_=num_*other.den_-den_*other.num_;
		den_=den_*other.den_;
		riduzione();
		return *this;
	}
	rational operator- (const rational& other) const {
		rational ret= *this;
		ret -= other;
		return ret;
	}
	rational& operator*=(const rational& other) {
		if (NaN==true || other.NaN == true) {
			NaN = true;
			return *this;
		}
		if ((inf == true && other.num_ == 0) || (other.inf == true && num_==0)) {
			inf = false;
			NaN = true;
			return *this;
		}
		else if (inf == true || other.inf==true) {
			inf = true;
			return *this;
		}
		num_=num_*other.num_;
		den_=den_*other.den_;
		riduzione();
		return *this;
	}
	rational operator* (const rational& other) const{
		rational ret= *this;
		ret *= other;
		return ret;
	}
	rational& operator/=(const rational& other) {
		if (NaN==true || other.NaN == true) {
			NaN = true;
			return *this;
		}
		if (inf == true && other.inf == true) {
			inf = false;
			NaN = true;
			return *this;
		}
		else if (inf == true) {
			inf= true;
			return *this; 
		}
		else if (other.inf == true) {
			num_=0;
			den_=1;
			inf = false;
			return *this;
		}
		else if (other.num_ == 0) {
			inf= true;
			return *this;
		}
		num_=num_*other.den_;
		den_=other.num_*den_;
		riduzione();
		return *this;
	}
	rational operator/ (const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
};
template<typename I> 
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {   
 		if (r.is_NaN()==true) {
			os << "NaN";
		}                           
		else if (r.is_inf()==true) {
			os << "inf";
		}
		else if (r.den()==1) {
			os << r.num();
		}
		else {
			os<< r.num() << "/" << r.den();
		}
		return os;
}
