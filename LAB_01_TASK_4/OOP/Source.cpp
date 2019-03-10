#include <iostream>

using namespace std;

class Time 
{
private: 
	int hour;
	int minute;
	int second;

public:
	Time(int a, int b, int c); //конструктор з трьома параметрами
	~Time(); //деструктор

	int GetHour(); //отримати години
	int GetMinute(); //отримати хвилини
	int GetSecond(); //отримати сеунди

	void SetHour(int a); //зміна години
	void SetMinute(int a); //зміна хвилин
	void SetSecond(int a); //зміна секунд

	void Full(); //повна форма 
	void Short(); //коротка форма
};


int main()
{
	Time time(10, 5, 20);
	cout<<"GetHour: " << time.GetHour()<<endl;
	cout << "Full Time:" << endl;
	time.Full();
	cout << "Short Time:" << endl;
	time.Short();
	cout << "After change seconds:" << endl;
	time.SetMinute(68);


	system("pause");
	return 0;
}

Time::Time(int a, int b, int c)
{
	this->hour = a;
	this->minute = b;
	this->second = c;
}

Time::~Time()
{
}

int Time:: GetHour()
{
	return hour;
}

int Time:: GetMinute()
{
	return minute;
}

int Time:: GetSecond()
{
	return second;
}

void Time:: SetHour(int a)
{
	if (a > 24 || a < 0)
	{
		cout << "Incorrect value" << endl;;
	}
	else
	{
		hour = a;
	}
}

void Time:: SetMinute(int a)
{
	if (a > 60 || a < 0)
	{
		cout << "Incorrect value" << endl;;
	}
	else
	{
		minute = a;
	}
}

void Time:: SetSecond(int a)
{
	if (a > 60 || a < 0)
	{
		cout << "Incorrect value" << endl;;
	}
	else
	{
		second = a;
	}
}

void Time:: Full()
{
	cout << hour << " hours " << minute << " minutes " << second << " seconds" << endl;
}

void Time:: Short()
{
	cout << hour << ":" << minute << ":" << second << endl;
}