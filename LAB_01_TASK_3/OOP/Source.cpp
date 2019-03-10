
#include <iostream>
#include <time.h>   //бібліотека для підключення генератора випадкових чисел
using namespace std;

class Matrix 
{
private:
	int MAT[25][25];                               //двовимірний масив
	int M;                                         //кількість рядків
	int N;                                         //кількість стовпців

public:
	Matrix(int m, int n); //конструктор з двома параметрами
	
	~Matrix(); //деструктор         

	void GetMatrix();  //ввід матриці
	
	void ShowMatrix(); //вивід матриці
	
	void GetElements(int z, int y);  //отримання елемента за індексами

	void MultiplyingMatrixByNumber(int x);  //множення матриці на число
	
	void AddingMatrices(Matrix object1);   //додавання двох матриць
	
	void SubtractionMatrices(Matrix object2); //віднімання двох матриць
	
	void MultiplyingMatrices(Matrix object1_2, Matrix object2_2);   //множення двох матриць
	
};

int main() 
{
	srand(time(NULL));   //генератор випадкових чисел

	Matrix obj1(3, 3);      //створення матриці 1
	obj1.GetMatrix();      //виклик функції вводу матриці 1
	cout << "Matrix 1:" << endl;
	obj1.ShowMatrix();      //виклик функції виводу матриці 1

	obj1.GetElements(2, 2);    //виклик функції отримання значення елемента за індексами

	obj1.MultiplyingMatrixByNumber(5);   //виклик функції множення матриці 1 на число
	obj1.ShowMatrix();       //виклик функції виводу результату множення матриці 1 на число
	cout << endl;

	Matrix obj2(3, 3);      //створення матриці 2
	obj2.GetMatrix();      //виклик функції вводу матриці 2
	cout << "Matrix 2:" << endl;
	obj2.ShowMatrix();      //виклик функції виводу матриці 2
	

	obj2.AddingMatrices(obj1);   //виклик функції додавання матриці 1 та матриці 2
	obj2.ShowMatrix();      //виклик функції виводу результату додавання матриць 1 та 2

	obj1.SubtractionMatrices(obj2); //виклик функції віднімання матриці 1 та матриці 2
	obj1.ShowMatrix();      //виклик функції виводу результату копій матриць 1 та 2

	Matrix obj3(3, 3);  //створення матриці 3,в якій будемо зберігати результат множення матриці 1 на матрицю 2
	obj3.MultiplyingMatrices(obj1, obj2);//виклик функції множення матриці 1 та матриці 2 та показ результату
	
	system("PAUSE");                            //затримка результатів
	return 0;         //завершення програми
}

Matrix::Matrix(int m, int n) 
{
	this->M = m;
	this->N = n;
}

Matrix::~Matrix() 
{
}

void Matrix:: GetMatrix()  
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			MAT[i][j] = 1 + rand() % 10;
		}
	}
}

void Matrix::ShowMatrix() 
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << MAT[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}

void Matrix::GetElements(int z, int y)   //отримання елемента за індексами
{
	cout << endl << "Table of elements" << endl << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			z = i;
			y = j;
			cout << "Value[" << i << "][" << j << "] = " << MAT[z][y] << endl;
		}
	}
}

void Matrix:: MultiplyingMatrixByNumber(int x) 
{
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			MAT[i][j] *= x;
		}
	}
	cout << endl;
	cout << endl;
	cout << "Matrix 1 * 5:" << endl;
}

void Matrix:: AddingMatrices(Matrix object1)   
{
	cout << endl << endl;
	cout << "Matrix 1 + Matrix 2: " << endl;
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			MAT[i][j] += object1.MAT[i][j];
		}
	}
}

void Matrix:: SubtractionMatrices(Matrix object2) 
{
	cout << endl << endl;
	cout << "Matrix 1 - Matrix 2:" << endl;
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			MAT[i][j] -= object2.MAT[i][j];
		}
	}
}

void Matrix:: MultiplyingMatrices(Matrix object1, Matrix object2) 
{   
	cout << endl << endl;
	cout << "Matrix 1 * Matrix 2:" << endl;
	int Q[3][3];
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			Q[i][j] = 0;
			Q[i][j] += (object1.MAT[i][j] * object2.MAT[i][j]);
		}
	}
	for (int i = 0; i < M; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cout << Q[i][j];
			cout << "\t";
		}
		cout << endl;
	}
}