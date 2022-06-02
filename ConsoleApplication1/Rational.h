
#if !defined iostream
#include <iostream>
#endif
#if !defined string
#include <string>
#endif
#if !defined cmath
#include <cmath>
#endif

class Rational
{
protected: int numerator=1;
	int denominator=1;
	private:
int gcd(int n, int d)
	{
		if (n==d&&d==0)
		{
			return 1;
		}else
		if (n == 0)
		{
			return abs(d);
		}
		else
			if (d == 0)
			{
				return abs(n);
			}
			else
				if (abs(n) == abs(d))
				{
					return abs(n);
				}
				else
				{
					return abs(gcd(d, n % d));
				}

	}

public:
	Rational()
	{
		numerator = 1;
		denominator = 1;
	}
	Rational(int numera, int denomi)
	{

		if (denomi != 0)
		{
			denominator = denomi;
		}
		else
		{
			denominator = 1;
		}
		numerator = numera;
		numerator /= gcd(numera, denomi);
		denominator /= gcd(numera, denomi);
		if ((denominator < 0)) { denominator = -denominator; numerator = -numerator; }
	}

	int getNumerator()
	{
		return numerator;
	}
	int getDenominator() { return denominator; }
	Rational add(Rational secondRational)
	{
		int n1 = secondRational.getNumerator();
		int n2 = getNumerator();
		int d1 = secondRational.getDenominator();
		int d2 = getDenominator();
		int d3_D = d1 * d2;
		int n3_D = ((n1 * d2) + (n2 * d1));
		int lCMM = gcd(d3_D, n3_D);
		d3_D /= lCMM;
		n3_D /= lCMM;
		return  Rational(n3_D, d3_D);
	}
	Rational subtract(Rational secondRational)
	{
		int n1 = secondRational.getNumerator();
		int n2 = getNumerator();
		int d1 = secondRational.getDenominator();
		int d2 = getDenominator();
		int d3_D = d1 * d2;
		int n3_D = ((-n1 * d2) + (n2 * d1));
		int lCMM = gcd(d3_D, n3_D);
		d3_D /= lCMM;
		n3_D /= lCMM;
		return  Rational(n3_D, d3_D);
	}
	Rational multiply(Rational secondRational)
	{
		int n1 = secondRational.getNumerator();
		int n2 = getNumerator();
		int d1 = secondRational.getDenominator();
		int d2 = getDenominator();
		int d3_D_b_LCM = d1 * d2 / gcd(d1, d2);
		int n3_D_b_LCM = ((n2) * (n1)) / gcd(d1, d2);
		return  Rational(n3_D_b_LCM, d3_D_b_LCM);
	}
	Rational divide(Rational secondRational)
	{
		int n1 = secondRational.getNumerator();
		int n2 = getNumerator();
		int d1 = secondRational.getDenominator();
		int d2 = getDenominator();
		int d3_D = (d2 * n1);
		int n3_D = (d1 * n2);
		int lCMM = gcd(d3_D, n3_D);
		d3_D /= lCMM;
		n3_D /= lCMM;
		return Rational(n3_D, d3_D);
	}
	int compareTo(Rational secondRational)
	{
		if (subtract(secondRational).numerator < 0) { return -1; }
		if (subtract(secondRational).numerator == 0) { return 0; }
		if (subtract(secondRational).numerator > 0) { return 1; }
		return 10;
	}
	bool equals(Rational secondRational)
	{
		return (subtract(secondRational).numerator == 0);
	}
	bool operator ==   (Rational right) { return equals(right); }
	bool operator !=   (Rational right) { return !equals(right); }
	Rational operator *(Rational right) { return multiply(right); }
	Rational operator /(Rational right) { return divide(right); }
	Rational operator +(Rational right) { return add(right); }
	Rational operator -(Rational right) { return subtract(right); }
	int intValue() { return int(round(numerator / denominator)); }
	double doubleValue() { return (numerator / denominator); }
	string toString() { if (denominator != 1) 
	{ return to_string(numerator) + "/" + to_string(denominator) + "\n"; } 
	return to_string(numerator) + "\n"; }
};
