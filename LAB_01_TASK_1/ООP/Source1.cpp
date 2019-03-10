#include <iostream>
#include <cmath>

using namespace std;

class Rectangle 
{
private:
	int height;
	int width;

public:

	Rectangle(int a, int b);

	~Rectangle(); //деструктор

	int GetHeight();  // функція для отриманя значення висоти
	int GetWidth(); // функція для отриманя значення ширини

	void SetHeight(int a); // функція для зміни значення висоти 
	void SetWidth(int b);  // функція для зміни значення ширини

	void Print(void); // функція виведення полів класу
	int Area(Rectangle obj); //функція знаходження площі
	int Perymetr(Rectangle obj); //функція знаходження периметра
};


int main()
{
	int a, b;
	cout << "Enter height: ";
	cin >> a;
	cout << "Enter width: ";
	cin >> b;
	Rectangle obj1(a, b);
	cout << endl;
	cout << "GetHeight: " << obj1.GetHeight() << endl;
	cout << "GetWidth: " << obj1.GetWidth() << endl << endl;

	obj1.Print();

	cout << "Area: " << obj1.Area(obj1) << endl;
	cout << "Perimetr: " << obj1.Perymetr(obj1) << endl << endl;

	obj1.SetHeight(a + 5);
	obj1.SetWidth(b + 8);

	cout << "New Height = height + 5 " << endl;
	cout << "New Width = width + 8 " << endl << endl;

	obj1.Print();

	cout << "New Area: " << obj1.Area(obj1) << endl;
	cout << "New Perimetr: " << obj1.Perymetr(obj1) << endl;

	system("pause");
	return 0;
}

Rectangle::Rectangle(int a, int b)
{
	this->height = a;
	this->width = b;
}


Rectangle::~Rectangle() //деструктор
{
}

int Rectangle::GetHeight()  // функція для отриманя значення висоти
{
	return height;
}

int Rectangle::GetWidth() // функція для отриманя значення ширини
{
	return width;
}


void Rectangle::SetHeight(int a) // функція для зміни значення висоти
{
	if (height > 0) // перевірка коректності
	{
		height = a;
	}
	else
	{
		cout << " Incorrect value";
	}
}

void  Rectangle::SetWidth(int b)  // функція для зміни значення ширини
{
	if (width > 0)
	{
		width = b;
	}
	else
	{
		cout << " Incorrect value";
	}
}


void Rectangle::Print(void)
{
	cout << "Height: " << height << endl << "Width :" << width << endl << endl;
}

int Rectangle::Area(Rectangle obj) 
{
	return height * width;
}

int Rectangle::Perymetr(Rectangle obj) 
{
	return (height + width) * 2;
}
