#include ""
#include<iostream>
using namespace std;

Rational::Rational()
{
	this->numerator = 0;
	this->denumirator = 1;
	cout << "print: in constructor" << endl;
}

Rational::Rational(int x, int y) {//parametric constructor
	if (y < 0 && x < 0) {
		y = -y;
		x = -x;
	}
	if (y < 0 && x > 0) {
		y = -y;
	}
	if (y == 0) {
		y = 1;
	}
	this->numerator = x;
	this->denumirator = y;
	cout << "print: in constructor" << endl;
}	

Rational::Rational(const Rational& r) { // copy constructor
	this->numerator = r.numerator;
	this->denumirator = r.denumirator;
	cout << "print: in copy constructor" << endl;
}

void Rational::setNumerator(int numerator) {
	this->numerator = numerator;
}

int Rational::getNumerator() {
	return numerator;
}

void Rational::setDenominator(int denominator) {
	if (denumirator == 0)
		this->denumirator = 1;
	else
	this->denumirator = denumirator;
	//minuscheck(this->numerator, this->denumirator);
}

int Rational::getDenominator() {
	return denumirator;
}

void Rational::print() {
	if (denumirator == 1) {
		cout << getNumerator() << endl;
		return;
	}
	cout << getNumerator() << '/' << getDenominator() << endl;
	return;
}

bool Rational::equal(const Rational& r) {
	if (this->numerator == r.numerator && this->denumirator == r.denumirator)
		return true;
	return false;
}

void Rational::reduce() {
	 //the method reduct the fraction
		if (numerator % denumirator == 0) {
			numerator /= denumirator;
			denumirator = 1;
		}
		if (denumirator % numerator == 0) {
			denumirator /= numerator;
			numerator = 1;
		}
		int maximum = max(numerator, denumirator);
		for (int i = maximum; i > 0; i--) {
			if (numerator % i == 0 && denumirator % i == 0) {
				numerator /= i;
				denumirator /= i;
			}
		}
	/*int x = 1, max, min;
	if (this->numerator < 0 && this->denominator > 0)
		if (this->numerator * (-1) < this->denominator)
			max = numerator * (-1);
		else
			max = denominator;
	if (this->numerator > 0 && this->denominator < 0)
		if (this->numerator < this->denominator * (-1))
			max = numerator;
		else
			max = denominator * (-1);
	if (this->numerator < 0 && this->denominator < 0)
		if (this->numerator * (-1) < this->denominator * (-1))
			max = numerator * (-1);
		else
			max = denominator * (-1);
	if (this->numerator > 0 && this->denominator > 0)
		if (this->numerator < this->denominator)
			max = numerator;
		else
			max = denominator;
	for (size_t i = max; i > 1; i--)
		if (this->numerator % i == 0 && this->denominator % i == 0) {
			Rational r;
			r.setNumerator(this->numerator / i);
			r.setDenominator(this->denominator / i);
			return r;
		}*/
}

Rational Rational::add(Rational r) {
	Rational ans;
	ans.setNumerator(this->numerator * r.getDenominator() + this->denumirator * r.getNumerator());
	ans.setDenominator(r.getDenominator() * this->denumirator);
	ans.reduce();
	return ans;
}

Rational Rational::addOne() {
	Rational ans;
	ans.numerator = (this->numerator + this->denumirator);
	ans.denumirator = this->denumirator;
	return ans;
}