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
	Rational* grades=new Rational(1,0);
	int* credit_Hours=new int(0);
	int arrSize =1;
	string ID="";
public:
	Rational calculateGPA()
	{
		Rational numerator = Rational(0, 1);Rational denominator = Rational(0, 1);
		for (int i = 0; i < arrSize; i++)
		{
			numerator = numerator + (Rational(credit_Hours[i],1)*grades[i]);
			denominator = denominator + Rational(credit_Hours[i], 1);
			//cout <<endl<< (numerator / denominator).getNumerator()<< endl<< (numerator / denominator).getDenominator() << endl;
		}
		return numerator / denominator;
	};
	friend ostream& operator << (ostream& out, Student& BRUH)
	{
		for (int i = 0; i < BRUH.arrSize; i++)
		{
			out << endl << "CREDIT HOUR(S) OF COURSE" << i + 1 << ": " <<BRUH.credit_Hours[i] << endl;
			out << "GRADE OF COURSE"<<i+1<<": " << BRUH.grades[i].toString() << endl;
		}
		out << "GPA: " << BRUH.calculateGPA().toString() << endl;
		out << "ID: " <<string(BRUH.ID) << endl;

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
	int arrayS =1;
	cin >> arrayS;
	cin>>s.ID;
	s.arrSize = arrayS;
	int* credit_Hours = new int(0);
	Rational* grades = new Rational(0,1);
	s.grades = grades;
	for (int i = 0; i < s.arrSize; i++)
	{
		cout << "TYPE IN THE CREDIT HOURS OF COURSE " << i + 1 << " NOW." << endl;
		in >> credit_Hours[i];
		s.credit_Hours[i] = credit_Hours[i];
		int numerator; int denominator;
		cout << "TYPE IN THE GRADES OF COURSE " << i + 1 << " NOW. (TYPE THE STUDENT SCORE THEN THE MAX GRADE)" << endl;
		in >> numerator >> denominator;
		grades[i] = Rational(numerator, denominator);
		s.grades[i] = Rational (grades[i]);
	}
	return in;
}
