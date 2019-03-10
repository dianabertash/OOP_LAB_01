/*Створити клас – дріб(раціональне число, що є відношенням двох цілих чисел).Визначити конструктор, 
деструктор, функції додавання, віднімання, множення і ділення дробів.*/

#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(); //конструктор без параметрів

	Fraction(int n, int d); //конструктор з двома параметрами
	
	~Fraction(); //деструктор
	
	Fraction Sum(Fraction otherFraction); //додавання дробів
	Fraction Difference(Fraction otherFraction); //віднімання
	Fraction Product(Fraction otherFraction); //множення
	Fraction Division(Fraction otherFraction); //ділення

	int change(int n, int d); //скорочення дробу
	void show();
};

int main()
{
	Fraction a(12, 18);
	Fraction b(9, 36);
	Fraction c;
	
	c = a.Sum(b); 
	c.show();

	c = a.Difference(b); 
	c.show();

	c = a.Product(b); 
	c.show();

	c = a.Division(b); 
	c.show();

	c = b.Division(a);
	c.show();

	system("pause");
	return 0;
}

Fraction::Fraction() 
{
	numerator = 0;
	denominator = 1;
}

Fraction:: Fraction(int n, int d)
{
	this->numerator = n;
	this->denominator = d;
}

Fraction:: ~Fraction()
{
}

Fraction Fraction:: Sum(Fraction otherFraction)
{
	cout << "Sum: ";
	int n = numerator * otherFraction.denominator + otherFraction.numerator*denominator;
	int d = denominator * otherFraction.denominator;
	return Fraction(n / change(n, d), d / change(n, d));
}

Fraction Fraction:: Difference(Fraction otherFraction)
{
	cout << "Difference: ";
	int n = numerator * otherFraction.denominator - otherFraction.numerator*denominator;
	int d = denominator * otherFraction.denominator;
	return Fraction(n / change(n, d), d / change(n, d));
}

Fraction Fraction:: Product(Fraction otherFraction)
{
	cout << "Product: ";
	int n = numerator * otherFraction.numerator;
	int d = denominator * otherFraction.denominator;
	return Fraction(n / change(n, d), d / change(n, d));
}

Fraction Fraction:: Division(Fraction otherFraction)
{
	cout << "Division: ";
	int n = numerator * otherFraction.denominator;
	int d = denominator * otherFraction.numerator;
	return Fraction(n / change(n, d), d / change(n, d));
}

int Fraction:: change(int n, int d) 
{
	int remainder;
	while (d != 0)
	{
		remainder = n % d;
		n = d;
		d = remainder;
	}
	return n;
}

void Fraction:: show()
{
     cout << numerator << "/" << denominator << endl;
}