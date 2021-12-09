#include "Fraction.h"

void Fraction::SetNumerator(long numerator)
{
	Numerator = numerator;
}
void Fraction::SetDenominator(long denominator)
{
	if (denominator == 0)
	{
		throw("wrong value of denominator");
	}
	Denominator = denominator;
}
Fraction::Fraction()
{
	Numerator = 1;
	Denominator = 1;

}
Fraction::Fraction(long numerator, long denominator)
{
	SetNumerator(numerator);
	SetDenominator(denominator);
}
long Fraction::GetNumerator() const
{
	return Numerator;
}
long Fraction::GetDenominator() const
{
	return Denominator;
}
 double Fraction::GetDouble()
{
	return (Numerator * 1.0 / Denominator);
}
void Fraction::reduction_Fraction(long dop)
{
	while (dop != 1)
	{
		if (Denominator % dop == 0 && Numerator % dop == 0)
		{
			Numerator /= dop;
			Denominator /= dop;
		}
		dop--;
	}
}
Fraction Fraction::operator+(Fraction& frac)
{
	return Fraction(Numerator * frac.GetDenominator() + frac.GetNumerator() * GetDenominator(), Denominator * frac.GetDenominator());
}

Fraction Fraction::operator-()
{
	return Fraction(-Numerator, Denominator);
}

Fraction Fraction::operator-(Fraction& frac2)
{
	return Fraction(Numerator * frac2.GetDenominator() - frac2.GetNumerator() * Denominator, Denominator * frac2.GetDenominator());
}

Fraction Fraction::operator*(Fraction& frac2)
{
	return Fraction(Numerator * frac2.GetNumerator(), Denominator * frac2.GetDenominator());
}

Fraction Fraction::operator/(Fraction& frac2)
{
	return Fraction(Numerator * frac2.GetDenominator(), Denominator * frac2.GetNumerator());
}

bool Fraction::operator==(Fraction& frac2)
{
	return (Numerator == frac2.GetNumerator() && frac2.GetDenominator() == Denominator);
}

bool Fraction::operator!=(Fraction& frac2)
{
	return (Numerator != frac2.GetNumerator() && frac2.GetDenominator() != Denominator);
}

bool Fraction::operator>(Fraction& frac2)
{
	if ((Numerator * frac2.GetDenominator() - frac2.GetNumerator() * Denominator) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
bool Fraction::operator<(Fraction& frac2)
{
	if ((Numerator * frac2.GetDenominator() - frac2.GetNumerator() * Denominator) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Fraction::operator<=(Fraction& frac2)
{
	return ((*this == frac2) || (*this < frac2));
}
bool Fraction::operator>=(Fraction& frac2)
{
	return ((*this == frac2) || (*this > frac2));
}
ostream& operator<<(std::ostream& out, const Fraction& frac)
{
	
	out << frac.GetNumerator() << "/" << frac.GetDenominator();
	return out;
}
