#if !defined iostream
#include <iostream>
#endif
#if !defined string
#include <string>
#endif
#if !defined cmath
#include <cmath>
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
		Rational numerator,denominator;
		for (int i = 0; i < arrSize; i++)
		{
			numerator = numerator + Rational(grades[i] * Rational(credit_Hours[i],1));
			denominator = denominator + Rational(credit_Hours[i], 1);
		}
		return numerator / denominator;
	};
	friend ostream& operator << (ostream& out, Student& BRUH)
	{
		for (int i = 0; i < BRUH.arrSize; i++) 
		{
			out << BRUH.credit_Hours[BRUH.arrSize] << endl;
			out << BRUH.grades[BRUH.arrSize].toString() << endl;
		}
		return out;
	}
	friend istream& operator >> (istream& in, Student& BRUH)
	{
		cout << "TYPE IN THE NUMBER OF COURSES FOLLOWED BY THE ID NOW." << endl;
		cin >> BRUH.arrSize >> BRUH.ID;
		for (int i = 0; i < BRUH.arrSize; i++)
		{
			cout << "TYPE IN THE CREDIT HOURS OF COURSE "<<i+1<< " NOW." << endl;
			in >> BRUH.credit_Hours[BRUH.arrSize];
			int numerator; int denominator;
			cout << "TYPE IN THE GRADES OF COURSE " << i+1 << " NOW. (TYPE THE STUDENT SCORE THEN THE MAX GRADE)" << endl;
			in >> numerator >> denominator;
			BRUH.grades[BRUH.arrSize]=Rational(numerator,denominator);
		}
		return in;
	}
};

