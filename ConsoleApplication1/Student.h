#if !defined iostream
#include <iostream>
#endif
#if !defined string
#include <string>
#endif
#if !defined cmath
#include <cmath>
#endif
#if !defined Rational
#include "Rational.h"
#endif
#if !defined std
using namespace std;
#endif
class Student
{
private:
	Rational* grades;
	int* credit_Hours;
	int arrSize;
	string ID;
public:
	Rational calculateGPA() 
	{
		return Rational();
	};
	ostream& operator << (ostream& out)
	{
		for (int i = 0; i > arrSize; i++) 
		{
			out << credit_Hours[arrSize] << endl;
			out << grades[arrSize].toString() << endl;
		}
		return out;
	}
	istream& operator >> (istream& in)
	{
		cout << "TYPE IN THE NUMBER OF COURSES FOLLOWED BY THE ID NOW." << endl;
		cin >> arrSize >> ID;
		for (int i = 0; i > arrSize; i++)
		{
			cout << "TYPE IN THE CREDIT HOURS OF COURSE "<<i+1<< " NOW." << endl;
			in >> credit_Hours[arrSize];
			int numerator; int denominator;
			cout << "TYPE IN THE GRADES OF COURSE " << i+1 << " NOW. (TYPE THE STUDENT SCORE THEN THE MAX GRADE)" << endl;
			in >> numerator >> denominator;
			grades[arrSize]=Rational(numerator,denominator);
		}
		return in;
	}
};

