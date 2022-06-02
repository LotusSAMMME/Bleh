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
	{grades = new Rational();credit_Hours = new int();
		Rational numerator, denominator;
		for (int i = 0; i < arrSize-1; i++)
		{
			
			int cH = credit_Hours[i];
			
			numerator = numerator + Rational(grades[i] * Rational(cH, 1));
			denominator = denominator + Rational(credit_Hours[i], 1);
		}
		return numerator / denominator;
	};
	friend ostream& operator << (ostream& out, Student& BRUH)
	{
		for (int i = 0; i < BRUH.arrSize; i++)
		{
			out << BRUH.credit_Hours[i] << endl;
			out << BRUH.grades[i].toString() << endl;
		}
		return out;
	}
	friend istream& operator>> (istream& in, Student& s);
};

istream& operator>> (istream& in, Student& s)
{
	// int arrSize;
	// int ID;
	// Rational grades[10];
	cout << "TYPE IN THE NUMBER OF COURSES FOLLOWED BY THE ID NOW." << endl;
	cin >> s.arrSize >> s.ID;
	cout << "done1";
	int* credit_Hours = new int();
	Rational* grades = new Rational();
	s.grades = grades;
	for (int i = 0; i < s.arrSize; i++)
	{
		cout << "TYPE IN THE CREDIT HOURS OF COURSE " << i + 1 << " NOW." << endl;
		in >> credit_Hours[i];
		s.credit_Hours = &credit_Hours[i];
		int numerator; int denominator;
		cout << "TYPE IN THE GRADES OF COURSE " << i + 1 << " NOW. (TYPE THE STUDENT SCORE THEN THE MAX GRADE)" << endl;
		in >> numerator >> denominator;
		grades[i] = Rational(numerator, denominator);
		s.grades[i] = Rational (grades[i]);
	}
	return in;
}
