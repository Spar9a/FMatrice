// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian"); // add locale language
	cout << "Здравствуй, я помогу тебе решить матрицу." << endl; // Добавил перенос строки
	int method;
	cout << "Выбери метод решения матрицы. Введи цифру (1) для метода Гаусса, цифру (2) для другого." << endl;
	cin >> method;
	while (method != 1 && method != 2) // Цикл который заставляет выбрать один из методов 
	{
		cin >> method;
	}
	if (method == 1)                   
	{
		cout << "Ты выбрал метод Гаусса!" << endl; // Тут будет решение матрцы по методу Гаусса
	}
	else
	{
		cout << "Ты выбрал другой метод!" << endl;
	}
	system("pause");
    return 0;
}

