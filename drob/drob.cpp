#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
	long numerator, denominator;
	cout << "enter numerator:";
	cin >> numerator;
	cout << "Enter denominator:";
	cin >> denominator;
	Fraction frac(numerator, denominator), frac2(5, 4);
	frac.SetNumerator(numerator);
	try
	{
		frac.SetDenominator(denominator);
	}
	catch (const std::exception& ex)
	{
		cout << "second input error:" << ex.what();
	}
	frac.SetDenominator(denominator);
	frac.reduction_Fraction(denominator);
	cout << "your first Fraction:" << frac << endl;
	cout << "your second Fraction:" << frac2 << endl;
	Fraction fracsum = frac + frac2;
	fracsum.reduction_Fraction(fracsum.GetDenominator());
	cout << "sum:" << fracsum << endl;
	Fraction change = -frac;
	cout << "change of sign:" << change << endl;
	Fraction fracresidual = frac - frac2;
	fracresidual.reduction_Fraction(fracresidual.GetDenominator());
	cout << "residual:" << fracresidual << endl;
	Fraction composition = frac * frac2;
	composition.reduction_Fraction(composition.GetDenominator());
	cout << "composition:" << composition << endl;
	Fraction division = frac / frac2;
	division.reduction_Fraction(division.GetDenominator());
	cout << "division:" << division << endl;
	if (frac == frac2)
	{
		cout << "firts Fraction = second Fraction" << endl;
	}
	if (frac != frac2)
	{
		cout << "firts Fraction != second Fraction" << endl;
	}
	if ((frac > frac2))
	{
		cout << "firts Fraction > second Fraction" << endl;
	}
	if ((frac < frac2))
	{
		cout << "firts Fraction < second Fraction" << endl;
	}
	cout << "frac >= frac2:" << (frac >= frac2) << endl;
	cout << "frac <= frac2:" << (frac <= frac2) << endl;
	cout << "double:" << frac.GetDouble();
	return 0;
}
