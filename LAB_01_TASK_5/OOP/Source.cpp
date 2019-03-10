#include <iostream>
using namespace std;
#include <math.h>

class Vector
{
private:
	int n = 0;
	int vect[2];

public:
	Vector(); //����������� ��� ���������

	~Vector(); //����������
	
	void AddItem(int item); //��������� �� ������ �������

	int Get(int index); //��������� �������� �������� ������� �� ��������

	int GetLength(); //������� ������� �����

	Vector Add(Vector other); //��������� �������

	Vector Minus(Vector other); //�������� �������

	double dovzhyna(); //����������� �������

	int skalyar(Vector other); // ��������� �������
	
};

void main()
{
	Vector a;
	a.AddItem(5);
	a.AddItem(8);
	
	Vector b;
	b.AddItem(3);
	b.AddItem(4);

	Vector c = a.Add(b);


	for (int i = 0; i < c.GetLength(); i++) 
	{
		cout << c.Get(i) << " ";
	}
	cout << endl;


	Vector d = a.Minus(b); 

	for (int i = 0; i < d.GetLength(); i++) 
	{
		cout << d.Get(i) << " ";
	}
	cout << endl;

	cout  << a.dovzhyna() << endl;

	cout  << a.skalyar(b) << endl;

	system("pause");
}

Vector::Vector()
{
}

Vector:: ~Vector()
{
}

void Vector:: AddItem(int item) 
{
	vect[n++] = item;
}

int Vector:: Get(int index) 
{
	return vect[index];
}

int Vector::GetLength() 
{
	return n;
}

Vector Vector:: Add(Vector other) 
{
	Vector result;
	cout << "Sum: ";
	for (int i = 0; i < n; i++)
	{
      result.AddItem(other.Get(i) + vect[i]);
	}
	return result;
}

Vector Vector:: Minus(Vector other) 
{
	Vector result;
	cout << "Difference: ";
	for (int i = 0; i < n; i++)
	{
		result.AddItem(other.Get(i) - vect[i]);
	}
	return result;
}

double Vector:: dovzhyna()
{
	cout << "Length: ";
	return sqrt(pow((vect[0]), 2) + pow((vect[1]), 2));
}

int Vector:: skalyar(Vector other)
{
	cout << "Scalar product: ";
	return(other.Get(0) * vect[0] + other.Get(1) * vect[1]);
}
