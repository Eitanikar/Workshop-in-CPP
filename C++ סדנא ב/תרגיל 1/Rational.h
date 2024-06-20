#pragma once
#include "rational.cpp"
#include<cmath>

//EITAN IKAR / EXC.1 Q.1 / 213450661
class Rational {
private:
	int numerator;
	int denumirator;
public:
	Rational();  //default constructor

	Rational(int x, int y); //constructor

	Rational(const Rational& r); //copy constructor

	 void setNumerator(int numerator);

	 int getNumerator();

	 void setDenominator(int denumirator);

	 int getDenominator();

	 void print();

	 bool equal(const Rational& r);
		
	 void makeEquals(Rational& r) {
		 r.numerator = this->numerator;
		 r.denumirator = this->denumirator;
	 }

	void reduce();

	Rational add(Rational r);

	Rational addOne();





	//void minuscheck(this->numerator, this->denumirator) {	//the method check if the numerator/denominator are positive and change them according to the instructions

	//	if (this->numerator < 0 && this->denumirator < 0) {
	//		this->numerator *= -1; this->denumirator *= -1;
	//	}
	//	if(this->numerator >= 0 && this->denumirator < 0)
	//		this->denumirator *= -1;

	//	if (this->numerator <= 0 && this->denumirator > 0)
	//		this->numerator *= -1;
	//}
	
	//OPERTORS:
	//Rational operator+ (const Rational r) {
	//	Rational temp;
	//	const int x = numirator * r.denumirator;
	//	const int y = denumirator * r.numerator;
	//	temp.numerator = x + y;
	//	temp.denumirator = r.denumirator * denumirator;
	//	temp.reduce();
	//	return temp;
	//};

	//Rational operator- (const Rational r) {
	//	Rational temp;
	//	const int x = numirator * r.denumirator;
	//	const int y = denumirator * r.numerator;
	//	temp.numerator = x - y;
	//	temp.denumirator = r.denumirator * denumirator;
	//	temp.reduce();
	//	return temp;
	//}

	//Rational operator* (const Rational r) {
	//	Rational temp;
	//	temp.numerator = numirator * r.numerator;
	//	temp.denumirator = denumirator * r.denumirator;
	//	temp.reduce();
	//	return temp;
	//}

	//Rational operator/ (const Rational r) {
	//	Rational temp;
	//	temp.numerator = numirator * r.denumirator;
	//	temp.denumirator = denumirator * r.numerator; 
	//	temp.reduce();
	//	return temp;
	//}

	//bool  operator==(const Rational r) {
	//	Rational temp1 = *this;
	//	Rational temp2 = r;
	//	temp1.reduce();
	//	temp2.reduce();
	//	if (temp1.numerator == temp2.numerator && temp1.denumirator == temp2.denumirator)
	//		return true;
	//	return false;
	//}

	//bool operator!=(const Rational r) {
	//	Rational temp1 = *this;
	//	Rational temp2 = r;
	//	temp1.reduce();
	//	temp2.reduce();
	//	if (temp1.numerator != temp2.numerator || temp1.denumirator != temp2.denumirator)
	//		return true;
	//	return false;
	//}
	//
	//Rational operator++() { //pre ++ operator
	//	this->numerator = numerator + denumirator;
	//	this->denumirator = denumirator;
	//	return *this;
	//}

	//Rational operator++(int) { //post ++ operator
	//	Rational temp(*this);
	//	this->numerator = numerator + denumirator;
	//	this->denumirator = denumirator;
	//	return temp;
	//}

	//Rational operator--() { //pre -- operator
	//	this->numerator = numerator - denumirator;
	//	this->denumirator = denumirator;
	//	return *this;
	//}

	//ratinal operator--(int) { //post -- operator
	//	Rational temp(*this);
	//	this->numerator = numerator - denumirator;
	//	this->denumirator = denumirator;
	//	return temp;
	//}

	//bool operator<(const Rational r) {
	//	Rational temp1 = *this;
	//	Rational temp2 = r;
	//	temp1.reduce();
	//	temp2.reduce();
	//	if (this->denumirator >= r.denumirator) {
	//		if (this->numerator < numerator) {
	//			return true;
	//		}
	//	}
	//	return temp;
	//}

	//bool operator<=(const Rational r) {
	//	return !(*this > r)
	//}

	//bool operator>(const Rational r) {
	//	Rational temp1 = *this;
	//	Rational temp2 = r;
	//	temp1.reduce();
	//	temp2.reduce();
	//	if (this->denumirator <= r.denumirator) {
	//		if (this->numerator > numerator) {
	//			return true;
	//		}
	//	}
	//	return temp;
	//}

	//bool operator>=(const Rational r) {
	//	return !(*this < r)
	//}
};