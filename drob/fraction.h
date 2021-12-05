#pragma once
#include <ostream>
#include <iostream>
using namespace std;
class Fraction
{
	long Numerator;
	long Denominator;
public:
	void SetNumerator(long numerator);
	void SetDenominator(long denominator);
	Fraction();
	Fraction(long numerator, long denominator);
	long GetNumerator();
	long GetDenominator();
	double GetDouble();
	void reduction_Fraction(long dop);
	friend ostream& operator<< (std::ostream& out, const Fraction& frac);
	Fraction operator+(Fraction& frac);
	Fraction operator-();
	Fraction operator-(Fraction& frac2);
	Fraction operator*(Fraction& frac2);
	Fraction operator/(Fraction& frac2);
	bool operator == (Fraction& frac2);
	bool operator != (Fraction& frac2);
	bool operator> (Fraction& frac2);
	bool operator< (Fraction& frac2);
	bool operator<= (Fraction& frac2);
	bool operator>= (Fraction& frac2);
};