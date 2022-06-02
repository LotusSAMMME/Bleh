using namespace std;
#include "Rational.h"
#include "Student.h"
int main()
{
	/*Rational Rat = Rational(13, 23) + Rational(3, 13);
	Rational Rat2 = Rational(13, 23) - Rational(3, 13);
	Rational Rat3 = Rational(13, 23) * Rational(3, 13);
	Rational Rat4 = Rational(13, 23) / Rational(3, 13);
	cout << Rational(6, 9).toString();
	cout << Rational(-6, 9).toString();
	cout << Rational(6, -9).toString();
	cout << Rational(-6, -9).toString();
	cout << Rational(2, 2).toString();
	cout << Rational(2, 1).toString();
	cout << Rat.toString();
	cout << Rat2.toString();
	cout << Rat3.toString();
	cout << Rat4.toString();*/
	cout << "TYPE IN THE NUMBER OF STUDENTS NOW." << endl;
	int n;
	cin >> n;
	Student* BRUH=nullptr;
	for (int i = 0; i < n; i++)
	{
		cin >> BRUH[n];
	}
	for (int i = 0; i < n; i++)
	{
		cout << BRUH[n].calculateGPA().toString();
		cout << &BRUH[n];
	}

}
