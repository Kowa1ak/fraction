#include "Fraction.h"
ostream& operator<<(std::ostream& out, const Fraction& frac)
{
	out << frac.Numerator << "/" << frac.Denominator;
	return out;
}
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
long Fraction::GetNumerator()
{
	return Numerator;
}
long Fraction::GetDenominator()
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
	return Fraction(Numerator * frac.Denominator + frac.Numerator * Denominator, Denominator * frac.Denominator);
}

Fraction Fraction::operator-()
{
	return Fraction(-Numerator, Denominator);
}

Fraction Fraction::operator-(Fraction& frac2)
{
	return Fraction(Numerator * frac2.Denominator - frac2.Numerator * Denominator, Denominator * frac2.Denominator);
}

Fraction Fraction::operator*(Fraction& frac2)
{
	return Fraction(Numerator * frac2.Numerator, Denominator * frac2.Denominator);
}

Fraction Fraction::operator/(Fraction& frac2)
{
	return Fraction(Numerator * frac2.Denominator, Denominator * frac2.Numerator);
}

bool Fraction::operator==(Fraction& frac2)
{
	return (Numerator == frac2.Numerator && frac2.Denominator == Denominator);
}

bool Fraction::operator!=(Fraction& frac2)
{
	return (Numerator != frac2.Numerator && frac2.Denominator != Denominator);
}

bool Fraction::operator>(Fraction& frac2)
{
	if ((Numerator * frac2.Denominator - frac2.Numerator * Denominator) > 0)
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
	if ((Numerator * frac2.Denominator - frac2.Numerator * Denominator) < 0)
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
